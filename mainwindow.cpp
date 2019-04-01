#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();

    cameraBtn = new QPushButton();
    toDoBtn = new QPushButton();
    countBtn = new QPushButton();
    exitBtn = new QPushButton();

    //后续任务：

    //1、使窗口等比缩放拉伸！！！！！！！！

    //2、目前cameraWidget是连同mainWidget创建而一起创建
    //   后续看看可不可以放到goCameraWidget()中构造？？？？？？？？？？？
    cameraWidget = new CameraWidget();

    vBoxLayout->addWidget(cameraBtn);
    vBoxLayout->addWidget(toDoBtn);
    vBoxLayout->addWidget(countBtn);
    vBoxLayout->addWidget(exitBtn);


    this->setLayout(vBoxLayout);
    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();


    QObject::connect(cameraBtn, SIGNAL(released()), this, SLOT(goCameraWidget()));

    QObject::connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    QObject::connect(toDoBtn, SIGNAL(released()), this, SLOT(myBtnReleasedSlot()));
    QObject::connect(toDoBtn, SIGNAL(released()), exitBtn, SLOT(hide()));

    QObject::connect(countBtn, SIGNAL(clicked()), this, SLOT(clickedCount()));

    //cameraWidget窗口发来的返回主页的信号
    QObject::connect(cameraWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(cameraWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));
}

MainWindow::~MainWindow()
{
    if (nullptr != exitBtn)
    {
        //qDebug() << "delete exitBtn";
        delete exitBtn;
    }

    if (nullptr != countBtn)
    {
        //qDebug() << "delete countBtn";
        delete countBtn;
    }

    if (nullptr != toDoBtn)
    {
        //qDebug() << "delete aaaaaBtn";
        delete toDoBtn;
    }

    if (nullptr != cameraBtn)
    {
        //qDebug() << "delete cameraButton";
        delete cameraBtn;
    }
    if (nullptr != vBoxLayout)
    {
        //qDebug() << "delete hBoxLayout";
        delete vBoxLayout;
    }
}

void MainWindow::TranslateLanguage()
{
    this->setWindowTitle(tr("MainWidget"));
    cameraBtn->setText("Camera Widget");
    toDoBtn->setText("Hide");
    countBtn->setText("Count");
    exitBtn->setText("Close Widget");
}

void MainWindow::myBtnReleasedSlot()
{
    if ( toDoBtn != nullptr )
    {
        toDoBtn->setText(tr("发送信号，槽处理完成..."));
    }
}

void MainWindow::goCameraWidget()
{
    this->hide();
    cameraWidget->show();
}

void MainWindow::returnMainWidget()
{
    this->show();
    cameraWidget->hide();
}

void MainWindow::returnMainWidgetParm(int num, QString str)
{
    qDebug() << "从cameraWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
//    qDebug() << "num: " << num << " str: " << str.toStdString().c_str();
//    qWarning() << "num: " << num << " str: " << str.toUtf8().data();
//    qInfo() << "num: " << num << " str: " << str.toUtf8().data();
}

void MainWindow::clickedCount()
{
    count++;
    //countBtn->setText(QString::fromLocal8Bit("点击次数") + QString::number(count));
    countBtn->setText("点击次数 :" + QString::number(count));
    qDebug() << "这是一个Lambda表达式测试输出";

}
