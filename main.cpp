#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //qDebug() << "a.exec()的值: " << a.exec();   //不注释掉程序不能正常退出
    return a.exec();
}
