#include "mainwidget.h"
#include <QDebug>
#include <QPluginLoader>
#include <QSql>
#include <QSqlDatabase>
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
