#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QPainter>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QEventLoop>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QMediaPlayer>
//空掉的qmediaplaylist
#include<QDebug>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlRecord>
#include<QMessageBox>
#include<QTime>
#include<math.h>
#include<QApplication>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    //处理窗口
    void paintEvent(QPaintEvent *event);


signals:
    void finish(QByteArray &data);
    void lyricShow(QString);


private slots:



    void on_pushButton_close_clicked();

    void on_pushButton_search_clicked();

    void on_horizontalSlider_voice_valueChanged(int value);

    void on_pushButton_before_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_next_clicked();

    void on_pushButton_loop_clicked();

    void on_horizontalSlider_song_valueChanged(int value);

    void on_horizontalSlider_song_sliderPressed();

    void on_horizontalSlider_song_sliderReleased();
    //更新播放进度条
    void updateDuration(qint64);
    //读取网络数据的槽函数
    void netReply(QNetworkReply *);
    //显示歌词槽函数
    void lyricTextShow(QString);
    //音乐播放
    void playSearchMusic();
    void playHistory();

protected:
    //下载歌曲
    void downloadPlayer(QString album_id,QString hash);
    //访问http网页
    void httpAccess(QString);
    //音乐的hash和alum_id解析，用json
    void hashJsonAnalysis(QByteArray);
    //搜索的音乐数据信息json解析，解析出真正的音乐文件和歌词
    QString musicJsonAnalysis(QByteArray);



private:
    Ui::MainWidget *ui;
    //网络 播放器 sqlite
    QNetworkRequest *request;
    QNetworkAccessManager *manager;
    QMediaPlayer *player;
    //QMediaplaylist *playlist
    QSqlDatabase db;
    int num,row;
   //鼠标拖
    private:
    QPoint m_mousePoint;
    QPoint m_movePoint;
    bool mousePress;
    QByteArray JsonData;
    QEventLoop loop;
    bool i;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);


};
#endif // MAINWIDGET_H
