#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();

    cameraBtn = new QPushButton();
    choosePicBtn = new QPushButton();
    countBtn = new QPushButton();
    exitBtn = new QPushButton();

    //后续任务：

    //1、使窗口等比缩放拉伸！！！！！！！！

    //2、目前cameraWidget是连同mainWidget创建而一起创建
    //   后续看看可不可以放到goCameraWidget()中构造？？？？？？？？？？？
    cameraWidget = new CameraWidget();
    pictureWidget = new ChoosePicWidget();

    vBoxLayout->addWidget(cameraBtn);
    vBoxLayout->addWidget(choosePicBtn);
    vBoxLayout->addWidget(countBtn);
    vBoxLayout->addWidget(exitBtn);


    this->setLayout(vBoxLayout);
    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();


    QObject::connect(cameraBtn, SIGNAL(released()), this, SLOT(goCameraWidget()));

    QObject::connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    QObject::connect(choosePicBtn, SIGNAL(released()), this, SLOT(choosePicture()));
    //QObject::connect(choosePicBtn, SIGNAL(released()), exitBtn, SLOT(hide()));

    QObject::connect(countBtn, SIGNAL(clicked()), this, SLOT(clickedCount()));

    //cameraWidget窗口发到主页的信号
    QObject::connect(cameraWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(cameraWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));

    //pictureWidget窗口发到主页的信号
    QObject::connect(pictureWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(pictureWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));
}

MainWindow::~MainWindow()
{    
    if (nullptr != pictureWidget)
    {
        //qDebug() << "delete cameraButton";
        delete pictureWidget;
    }

    if (nullptr != cameraWidget)
    {
        //qDebug() << "delete cameraButton";
        delete cameraWidget;
    }

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

    if (nullptr != choosePicBtn)
    {
        //qDebug() << "delete choosePicBtn";
        delete choosePicBtn;
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
    choosePicBtn->setText("Choose Picture");
    countBtn->setText("Clicked Count");
    exitBtn->setText("Close Widget");

    return;
}

void MainWindow::choosePicture()
{
    if ( nullptr != choosePicBtn )
    {
        choosePicBtn->setText(tr("choosePicture..."));
    }

    this->hide();
    pictureWidget->show();

    return;    //这样也可以,不要这一句也可以！！！！
}

void MainWindow::goCameraWidget()
{
    this->hide();
    cameraWidget->show();

    return;
}

void MainWindow::returnMainWidget()
{
    this->show();
    cameraWidget->hide();
    pictureWidget->hide();

    return;
}

void MainWindow::returnMainWidgetParm(int num, QString str)
{
    if (num == 1)
    {
        qDebug() << "从cameraWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
//        qDebug() << "num: " << num << " str: " << str.toStdString().c_str();
//        qWarning() << "num: " << num << " str: " << str.toUtf8().data();
//        qInfo() << "num: " << num << " str: " << str.toUtf8().data();
    }
    else if (num == 2)
    {
        qDebug() << "从pictureWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
    }
    else
    {
        qDebug() << "----------------------------";
    }

    return;
}

void MainWindow::clickedCount()
{
    count++;
    //countBtn->setText(QString::fromLocal8Bit("点击次数") + QString::number(count));
    countBtn->setText("点击次数 :" + QString::number(count));
    qDebug() << "这是一个Lambda表达式测试输出";

    return;
}
