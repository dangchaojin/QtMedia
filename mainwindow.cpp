#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();

    cameraBtn = new QPushButton();
    choosePicBtn = new QPushButton();
    picOperBtn = new QPushButton();
    otherOperBtn = new QPushButton();
    exitBtn = new QPushButton();

/*后续任务：
    1、使窗口等比缩放拉伸！！！！！！！！
    2、目前cameraWidget是连同mainWidget创建而一起创建
       后续看看可不可以放到goCameraWidget()中构造？？？？？？？？？？？
    3、优化日志模块
    4、有没有必要设置窗口基类，设置些通用设置，例：窗口位置大小、···
    5、是否要做成选项统一在左边的，窗口右边展开的样式？？
*/

    cameraWidget = new CameraWidget();
    picChooseWidget = new ChoosePicWidget();
    picOperWidget = new PicOperWidget();
    otherOperWidget = new OtherOperWidget();

    vBoxLayout->addWidget(cameraBtn);
    vBoxLayout->addWidget(choosePicBtn);
    vBoxLayout->addWidget(picOperBtn);
    vBoxLayout->addWidget(otherOperBtn);
    vBoxLayout->addWidget(exitBtn);

    this->setLayout(vBoxLayout);
    this->setGeometry(AXSIZE, AYSIZE, AWSIZE, AHSIZE);
    this->TranslateLanguage();


    QObject::connect(cameraBtn, SIGNAL(released()), this, SLOT(goCameraWidget()));
    QObject::connect(choosePicBtn, SIGNAL(released()), this, SLOT(goChoosePicture()));
    QObject::connect(picOperBtn, SIGNAL(released()), this, SLOT(goPicOPerWidget()));
    QObject::connect(otherOperBtn, SIGNAL(released()), this, SLOT(goOtherOperWidget()));

    //QObject::connect(choosePicBtn, SIGNAL(released()), exitBtn, SLOT(hide()));       //hide PushButton
    //QObject::connect(countBtn, SIGNAL(clicked()), this, SLOT(clickedCount()));

    //cameraWidget窗口发到主页的信号
    QObject::connect(cameraWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(cameraWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));

    //picChooseWidget窗口发到主页的信号
    QObject::connect(picChooseWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(picChooseWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));

    //picOperWidget窗口发到主页的信号
    QObject::connect(picOperWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(picOperWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));

    //otherOperWidget窗口发到主页的信号
    QObject::connect(otherOperWidget, SIGNAL(mySignal()), this, SLOT(returnMainWidget()));
    QObject::connect(otherOperWidget, SIGNAL(mySignalParm(int, QString)), this, SLOT(returnMainWidgetParm(int, QString)));

    QObject::connect(exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    //安装日志功能
    //qInstallMessageHandler(myMessageOutput);
}

MainWindow::~MainWindow()
{
    if (nullptr != otherOperWidget) { delete otherOperWidget; }

    if (nullptr != picOperWidget) { delete picOperWidget; }

    if (nullptr != picChooseWidget) { delete picChooseWidget; }

    if (nullptr != cameraWidget) { delete cameraWidget; }

    if (nullptr != exitBtn) { delete exitBtn; }

    if (nullptr != otherOperBtn) { delete otherOperBtn; }

    if (nullptr != picOperBtn) { delete picOperBtn; }

    if (nullptr != choosePicBtn) { delete choosePicBtn; }

    if (nullptr != cameraBtn) { delete cameraBtn; }

    if (nullptr != vBoxLayout) { delete vBoxLayout; }
}

void MainWindow::TranslateLanguage()
{
    //this->setWindowTitle("MainWidget");   //不设置就已经显示QtMedia
    cameraBtn->setText("Camera Widget");
    choosePicBtn->setText("Choose Picture");
    picOperBtn->setText("Picture Operation");
    otherOperBtn->setText("Other Operation");
    exitBtn->setText("Close Widget");

    return;
}

void MainWindow::goCameraWidget()
{
    this->hide();
    cameraWidget->show();
    return;
}

void MainWindow::goChoosePicture()
{
//    if ( nullptr != choosePicBtn )
//    {
//        choosePicBtn->setText(tr("choosePicture..."));
//    }

    this->hide();
    picChooseWidget->show();
    return;    //return这样也可以,不要这一句也可以!!!!
}

void MainWindow::goPicOPerWidget()
{
    this->hide();
    picOperWidget->show();
    return;
}

void MainWindow::goOtherOperWidget()
{
    this->hide();
    otherOperWidget->show();
    return;
}

void MainWindow::returnMainWidget()
{
    this->show();
    cameraWidget->hide();
    picChooseWidget->hide();
    picOperWidget->hide();
    otherOperWidget->hide();
//    choosePicBtn->setText("Choose Picture");
    return;
}

void MainWindow::returnMainWidgetParm(int num, QString str)
{
    switch (num)
    {
    case SIGNAL_CAMERA_WIDGET:
        qDebug() << "从cameraWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
//        qDebug() << "num: " << num << " str: " << str.toStdString().c_str();
//        qWarning() << "num: " << num << " str: " << str.toUtf8().data();
//        qInfo() << "num: " << num << " str: " << str.toUtf8().data();
        break;

    case SIGNAL_CHOOSE_PIC_WIDGET:
        qDebug() << "从picChooseWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
        break;

    case SIGNAL_PIC_OPER_WIDGET:
        qDebug() << "从picOperWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
        break;

    case SIGNAL_OTHER_OPER_WIDGET:
        qDebug() << "从otherOperWidget传回的参数 : " << "num: " << num << " str: " << str.toUtf8().data();
        break;
    default:
        qDebug() << "the post num is invaild: " << num << "str: " << str.toUtf8().data();
    }
    return;
}

/*void MainWindow::clickedCount()
{
    count++;
    countBtn->setText("点击次数 :" + QString::number(count));
    qDebug() << "这是一个Lambda表达式测试输出";
    return;
}*/
