/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QPushButton *pushButton_close;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_searchname;
    QLineEdit *lineEdit;
    QPushButton *pushButton_search;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_searchsongs;
    QTextBrowser *textBrowser;
    QListWidget *listWidget_history;
    QSlider *horizontalSlider_song;
    QLabel *label_4;
    QSlider *horizontalSlider_voice;
    QPushButton *pushButton_voice;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_before;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_next;
    QPushButton *pushButton_loop;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName("MainWidget");
        MainWidget->resize(749, 531);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        MainWidget->setFont(font);
        pushButton_close = new QPushButton(MainWidget);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setGeometry(QRect(672, 0, 81, 61));
        pushButton_close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/close.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_close->setIcon(icon);
        pushButton_close->setIconSize(QSize(150, 150));
        groupBox = new QGroupBox(MainWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 50, 751, 91));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 741, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_searchname = new QPushButton(layoutWidget);
        pushButton_searchname->setObjectName("pushButton_searchname");
        pushButton_searchname->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"background-color:rgba(255,255,50);"));
        pushButton_searchname->setIconSize(QSize(20, 50));

        horizontalLayout->addWidget(pushButton_searchname);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255);\n"
"background-color:rgba(255,255,50);"));
        pushButton_search->setIconSize(QSize(20, 50));

        horizontalLayout->addWidget(pushButton_search);

        label = new QLabel(MainWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 150, 91, 19));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)\n"
""));
        label_2 = new QLabel(MainWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 150, 69, 19));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)\n"
""));
        label_3 = new QLabel(MainWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(540, 150, 91, 19));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)\n"
""));
        groupBox_2 = new QGroupBox(MainWidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(0, 170, 751, 271));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 721, 241));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget_searchsongs = new QListWidget(layoutWidget1);
        listWidget_searchsongs->setObjectName("listWidget_searchsongs");

        horizontalLayout_2->addWidget(listWidget_searchsongs);

        textBrowser = new QTextBrowser(layoutWidget1);
        textBrowser->setObjectName("textBrowser");

        horizontalLayout_2->addWidget(textBrowser);

        listWidget_history = new QListWidget(layoutWidget1);
        listWidget_history->setObjectName("listWidget_history");

        horizontalLayout_2->addWidget(listWidget_history);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 7);
        horizontalLayout_2->setStretch(2, 4);
        horizontalSlider_song = new QSlider(MainWidget);
        horizontalSlider_song->setObjectName("horizontalSlider_song");
        horizontalSlider_song->setGeometry(QRect(10, 450, 661, 22));
        horizontalSlider_song->setMaximum(100);
        horizontalSlider_song->setOrientation(Qt::Orientation::Horizontal);
        label_4 = new QLabel(MainWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(680, 450, 61, 19));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)\n"
""));
        horizontalSlider_voice = new QSlider(MainWidget);
        horizontalSlider_voice->setObjectName("horizontalSlider_voice");
        horizontalSlider_voice->setGeometry(QRect(620, 480, 84, 22));
        horizontalSlider_voice->setOrientation(Qt::Orientation::Horizontal);
        pushButton_voice = new QPushButton(MainWidget);
        pushButton_voice->setObjectName("pushButton_voice");
        pushButton_voice->setGeometry(QRect(560, 470, 61, 51));
        pushButton_voice->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/voice.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_voice->setIcon(icon1);
        pushButton_voice->setIconSize(QSize(100, 100));
        label_5 = new QLabel(MainWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(708, 481, 31, 25));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(255,255,255)\n"
""));
        layoutWidget2 = new QWidget(MainWidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(150, 460, 439, 102));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_before = new QPushButton(layoutWidget2);
        pushButton_before->setObjectName("pushButton_before");
        pushButton_before->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/before.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_before->setIcon(icon2);
        pushButton_before->setIconSize(QSize(100, 100));

        horizontalLayout_3->addWidget(pushButton_before);

        pushButton_pause = new QPushButton(layoutWidget2);
        pushButton_pause->setObjectName("pushButton_pause");
        pushButton_pause->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/pause.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_pause->setIcon(icon3);
        pushButton_pause->setIconSize(QSize(100, 100));

        horizontalLayout_3->addWidget(pushButton_pause);

        pushButton_next = new QPushButton(layoutWidget2);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/next.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_next->setIcon(icon4);
        pushButton_next->setIconSize(QSize(100, 100));

        horizontalLayout_3->addWidget(pushButton_next);

        pushButton_loop = new QPushButton(layoutWidget2);
        pushButton_loop->setObjectName("pushButton_loop");
        pushButton_loop->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:0px;\n"
"background-repeat:no-repeat;\n"
"border:none;\n"
"background-position:center center;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:rgba(230,0,0,5);\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgba(95,95,95,100);\n"
"border-color:rgba(255,255,255,30);\n"
"border-style:insert;\n"
"color:rgba(0,0,0,100);\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/C:/Users/24332/Desktop/MyMusicPlayer/loop.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_loop->setIcon(icon5);
        pushButton_loop->setIconSize(QSize(100, 100));

        horizontalLayout_3->addWidget(pushButton_loop);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QCoreApplication::translate("MainWidget", "MainWidget", nullptr));
        pushButton_close->setText(QString());
        groupBox->setTitle(QString());
        pushButton_searchname->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262\345\220\215\347\247\260", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242", nullptr));
        label->setText(QCoreApplication::translate("MainWidget", "\346\220\234\347\264\242\346\255\214\346\233\262", nullptr));
        label_2->setText(QCoreApplication::translate("MainWidget", "\346\255\214\350\257\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWidget", "\345\216\206\345\217\262\346\222\255\346\224\276", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWidget", "00:00", nullptr));
        pushButton_voice->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWidget", "0", nullptr));
        pushButton_before->setText(QString());
        pushButton_pause->setText(QString());
        pushButton_next->setText(QString());
        pushButton_loop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
