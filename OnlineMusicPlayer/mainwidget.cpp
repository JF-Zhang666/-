 #include "mainwidget.h"
#include "ui_mainwidget.h"
#include "apiurls.h"
#include<QApplication>
#include<QMouseEvent>
#include<QSqlDatabase>
#include <QWidget>
#include<QAudioOutput>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{

    ui->setupUi(this);
    this->setFixedSize(this->geometry().size());
    this->setWindowFlag(Qt::FramelessWindowHint);

    if(QSqlDatabase::contains("sql_default_connection")){
        db=QSqlDatabase::database("sql_default_connection");
    }
    else{
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("mp3listdatabase");
        db.setHostName("localhost"); // 本地数据库 远程DB是：ipaddress
        db.setPort(3306); // 设置端口号
        // 使用的数据库 sql = use '数据库名'
        db.setUserName("root");
        db.setPassword("123456");

    }
    if(!db.open()){
        QMessageBox::critical(0,QObject::tr("open database error"),db.lastError().text());

    }
    else{
        QSqlQuery query;
        QString sql="CREATE TABLE IF NOT EXISTS searchlist (id INT, songname TEXT, singername TEXT, album_id TEXT, hash TEXT)";
        if(!query.exec(sql)){
            QMessageBox::critical(0,QObject::tr("create searchlist error"),db.lastError().text());

        }
        sql="CREATE TABLE IF NOT EXISTS historysong ( id INT AUTO_INCREMENT PRIMARY KEY, songname TEXT,singername TEXT, album_id TEXT,hash TEXT)";
        if(!query.exec(sql)){
              QMessageBox::critical(0,QObject::tr("create historysong error"),db.lastError().text());
              qDebug() << "Create table error:" << query.lastError().text();

        }
        sql="select *from historysong;";
            if(!query.exec(sql)){
            QMessageBox::critical(0,QObject::tr("select historysong error"),db.lastError().text());

        }
            while(query.next()){
            QString songname,singername;
            QSqlRecord rec=query.record();
            int ablumkey=rec.indexOf("songname");
            int hashkey=rec.indexOf("singername");
            songname=query.value(ablumkey).toString();
            singername=query.value(hashkey).toString();
            QString showstr=songname+"---"+singername;
            QListWidgetItem *item=new QListWidgetItem(showstr);
            ui->listWidget_history->addItem(item);
            }

    }
    player=new QMediaPlayer;
 //palyerlist=new qmediaplaylist
    connect(player,SIGNAL(positionChanged(qint64)),this,SLOT(updateDuration(qint64)));
    connect(this,SIGNAL(lyricShow(QString)),this,SLOT(lyricTextShow(QString)));
    connect(ui->listWidget_searchsongs,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(playSearchMusic()));
    connect(ui->listWidget_history,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(playHistory()));
    num=0;

}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/C:/Users/24332/Desktop/MyMusicPlayer/background.jpg"));
}


void MainWidget::on_pushButton_close_clicked()
{
    close();
}


void MainWidget::on_pushButton_search_clicked()
{
    ui->listWidget_searchsongs->clear();
    QSqlQuery query;
    QString sql="delete from searchlist";
    if(!query.exec(sql)){
        QMessageBox::critical(0,QObject::tr("delete error"),db.lastError().text());
    }
    //输入的音乐发起请求
    QString url=QQMusicSearchApi + QString("format=json&keyword=%1&page=1&pagesize=20&showtype=1").arg(ui->lineEdit->text());
    httpAccess(url);

    auto c=connect(this,&MainWidget::finish,[&](const QByteArray &data){
        JsonData=data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(c);
    //解析网页数据，把音乐和列表索引存到数据库
    hashJsonAnalysis(JsonData);
}


void MainWidget::on_horizontalSlider_voice_valueChanged(int value)
{
    QAudioOutput *audioOutput = player->audioOutput();
    if (audioOutput) {
        audioOutput->setVolume(value / 100.0f); // Qt6 中音量值范围是 0.0 到 1.0，所以需要将百分比值转换为小数
    }
    ui->label_5->setText(QString::number(value)); // 更新标签文本显示音量值
}


void MainWidget::on_pushButton_before_clicked()
{
    row--;
    if(row<0){
        row=ui->listWidget_history->count();

    }
    QSqlQuery query;
    QString sql=QString("select *from history where id=%1").arg(row+1);
    if(!query.exec(sql)){
        QMessageBox::critical(0,QObject::tr("selecting historysong error"),db.lastError().text());

    }
    QString album_id,hash;
    while (query.next()) {
        QSqlRecord record=query.record();
        int albumkey=record.indexOf("album_id");
        int hashkey=record.indexOf("hash");
        album_id=query.value(albumkey).toString();
        hash=query.value(hashkey).toString();



    }
    downloadPlayer(album_id,hash);
}


void MainWidget::on_pushButton_pause_clicked()
{
    if(player->playbackState() == QMediaPlayer::PlayingState){
        player->pause();
    }
    else if(player->playbackState() == QMediaPlayer::PausedState){
        player->play();
    }
}


void MainWidget::on_pushButton_next_clicked()
{
    row++;
    if(row>ui->listWidget_history->count()){
        row=0;

    }
    QSqlQuery query;
    QString sql=QString("select *from history where id=%1").arg(row+1);
    if(!query.exec(sql)){
        QMessageBox::critical(0,QObject::tr("selecting historysong error"),db.lastError().text());

    }
    QString album_id,hash;
    while (query.next()) {
        QSqlRecord record=query.record();
        int albumkey=record.indexOf("album_id");
        int hashkey=record.indexOf("hash");
        album_id=query.value(albumkey).toString();
        hash=query.value(hashkey).toString();



    }
    downloadPlayer(album_id,hash);
}


void MainWidget::on_pushButton_loop_clicked()
{

}


void MainWidget::on_horizontalSlider_song_valueChanged(int value)
{
    QTime time(0,value/60000,qRound((value%60000)/1000.0));
    ui->label_4->setText(time.toString("mm:ss"));
    if(i=false){
        player->setPosition(qint64(value));
    }
}


void MainWidget::on_horizontalSlider_song_sliderPressed()
{
    i=false;
}


void MainWidget::on_horizontalSlider_song_sliderReleased()
{
    i=true;
}

void MainWidget::updateDuration(qint64 value)
{
    ui->horizontalSlider_song->setRange(0,player->duration());
    ui->horizontalSlider_song->setValue(value);
}

void MainWidget::netReply(QNetworkReply *reply)
{
    QVariant status_code=reply->attribute((QNetworkRequest::HttpStatusCodeAttribute));
    qDebug()<<status_code;
    reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if(reply->error()==QNetworkReply::NoError){
        QByteArray data=reply->readAll();
        emit finish(data);

    }
    else{
        qDebug()<<reply->errorString();

    }
    reply->deleteLater();

}

void MainWidget::lyricTextShow(QString lycris)
{
    ui->textBrowser->setFont(QFont("宋体",10,QFont::Bold));
    ui->textBrowser->setTextColor(Qt::white);
    ui->textBrowser->setText(lycris);
}

void MainWidget::playSearchMusic()
{
    int row=ui->listWidget_searchsongs->currentRow();
    qDebug()<<"row-->"<<row;
    QSqlQuery query;
    QString sql=QString("select *from searchlist where id=%1").arg(row);
    if(!query.exec(sql)){
        QMessageBox::critical(0,QObject::tr("searchlist table error"),db.lastError().text());

    }
    //存入历史数据表
    QString songname,singername,album_id,hash;
    while(query.next()){
        QSqlRecord record=query.record();
        int songkey=record.indexOf("songname");
        int singerkey=record.indexOf("singername");
        int albumkey=record.indexOf("album_id");
        int hashkey=record.indexOf("hash");
        songname=query.value(songkey).toString();
        singername=query.value(singerkey).toString();
        album_id=query.value(albumkey).toString();
        hash=query.value(hashkey).toString();
        sql=QString("select hash from historysong where hash='%1';").arg(hash);
        if(!query.exec(sql)){
            QMessageBox::critical(0,QObject::tr("select hash error"),db.lastError().text());
        }
        if(query.next()==NULL){
           sql=QString("INSERT INTO historysong (songname, singername, album_id, hash) VALUES ('%1', '%2', '%3', '%4')").arg(songname, singername, album_id, hash);
            if(!query.exec(sql)){
                QMessageBox::critical(0,QObject::tr("insert historysong error"),db.lastError().text());
                qDebug() << "insert historysong table error:" << query.lastError().text();


            }
            //保存到history中
            QString show=songname+"--"+singername;
            QListWidgetItem *item=new QListWidgetItem(show);
            ui->listWidget_history->addItem(item);

        }
        downloadPlayer(album_id,hash);
    }





}

void MainWidget::playHistory()
{
    row=ui->listWidget_history->currentRow();
    QSqlQuery query;
    QString sql=QString("selecting *from historysong where id=%1;").arg(row+1);
    if(!query.exec(sql)){
        QMessageBox::critical(0,QObject::tr("select history error"),db.lastError().text());

    }
    QString album_id,hash;
    while (query.next()) {
        QSqlRecord record=query.record();
        int albumkey=record.indexOf("album_id");
        int hashkey=record.indexOf("hash");
        album_id=query.value(albumkey).toString();
        hash=query.value(hashkey).toString();



    }
    downloadPlayer(album_id,hash);
}

void MainWidget::downloadPlayer(QString album_id, QString hash)
{
   QString url = "http://m.kugou.com/app/i/getSongInfo.php?cmd=playInfo&hash=" + hash;
    httpAccess(url);

    auto d=connect(this,&MainWidget::finish,[&](const QByteArray &data){
        JsonData=data;
        loop.exit(1);
    });
    loop.exec();
    disconnect(d);
    QString music=musicJsonAnalysis(JsonData);
    player->setSource(QUrl(music));
    // 假设player是您的QMediaPlayer对象
    QAudioOutput *audioOutput = player->audioOutput();
    if (audioOutput) {
        audioOutput->setVolume(1.0); // 设置音量为100%，Qt6中音量值范围是0.0到1.0
    }
    ui->horizontalSlider_voice->setValue(100);
    player->play();
}

void MainWidget::httpAccess(QString url)
{
    request=new QNetworkRequest;
    request->setUrl(url);
    manager=new QNetworkAccessManager;
    manager->get(*request);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(netReply(QNetworkReply*)));

}

void MainWidget::hashJsonAnalysis(QByteArray JsonData)
{
    QJsonDocument document=QJsonDocument::fromJson(JsonData);
    if(document.isObject()){
        QJsonObject data=document.object();
        if(data.contains("data")){
            QJsonObject objectInfo=data.value("data").toObject();
            if(objectInfo.contains("info")){
                QJsonArray objectHash=objectInfo.value("info").toArray();
                for(int i=0;i<objectHash.count();i++){
                    QString songname,singername,album_id,hash;
                    QJsonObject album=objectHash.at(i).toObject();
                    if(album.contains("album_id")){
                        album_id=album.value("album_id").toString();
                    }
                    if(album.contains("singername")){
                        singername=album.value("singername").toString();

                    }
                    if(album.contains("songname")){
                        songname=album.value("songname").toString();
                    }
                    if(album.contains("hash")){
                        hash=album.value("hash").toString();
                    }
                    QSqlQuery query;
                  QString sql=QString("INSERT INTO searchlist (id,songname, singername, album_id, hash) VALUES (%1, '%2', '%3', '%4','%5')").arg(QString::number(i),songname, singername, album_id, hash);
                    if(!query.exec(sql)){
                        QMessageBox::critical(0,QObject::tr("insert searchlist error"),db.lastError().text());
                         qDebug() << "insert searchlist table error:" << query.lastError().text();
                    }
                    QString show=songname+"--"+singername;
                    QListWidgetItem *item=new QListWidgetItem(show);
                    ui->listWidget_searchsongs->addItem(item);

                }

            }

        }
    }

    if(document.isArray()){
        qDebug()<<"Array";
    }



}

QString MainWidget::musicJsonAnalysis(QByteArray JsonData)
{
    QJsonDocument document=QJsonDocument::fromJson(JsonData);
    if(document.isObject()){
        QJsonObject data=document.object();
        if(data.contains("data")){
            QJsonObject objectPlayUrl=data.value("data").toObject();
            if(objectPlayUrl.contains("lyrics")){
                emit lyricShow(objectPlayUrl.value("lyrics").toString());
            }
            if(objectPlayUrl.contains("play_url")){
                return objectPlayUrl.value("play_url").toString();
            }
        }

        }
    if(document.isArray()){
        qDebug()<<"Array.";
    }

    return 0;
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
Q_UNUSED(event);
    if(mousePress){
    QPoint movepos=event->globalPosition().toPoint();
        move(movepos-m_movePoint);

    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    mousePress=false;
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        mousePress=true;
    }
   m_movePoint = event->globalPosition().toPoint() - pos();
}

