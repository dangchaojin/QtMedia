#include "choosepicwidget.h"

ChoosePicWidget::ChoosePicWidget(QWidget *parent) : QWidget(parent)
{
    hBoxLayout = new QHBoxLayout();
    vBoxLayout = new QVBoxLayout();

    choosePicBtn = new QPushButton();
    exitBtn = new QPushButton();
    exitToMainWidgetBtn = new QPushButton();

    displayPicLabel = new QLabel();

    vBoxLayout->addWidget(choosePicBtn);
    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(exitToMainWidgetBtn);


    hBoxLayout->addWidget(displayPicLabel);
    hBoxLayout->addLayout(vBoxLayout);
    this->setLayout(hBoxLayout);


    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();

    QObject::connect(this->choosePicBtn, SIGNAL(clicked()), this, SLOT(choosePicture()));
    QObject::connect(this->exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    //欲使信号直接驱动非槽函数，可以这样做！！！！！！
    //QObject::connect(exitToMainWidgetBtn, SIGNAL(clicked()), this, SLOT(sendSignalsToReturnMainWidget()));
    QObject::connect(exitToMainWidgetBtn, &QPushButton::clicked, this, &ChoosePicWidget::sendSignalsToReturnMainWidget);
}

ChoosePicWidget::~ChoosePicWidget()
{
    if (nullptr != displayPicLabel)
    {
        delete displayPicLabel;
    }

    if (nullptr != exitToMainWidgetBtn)
    {
        delete exitToMainWidgetBtn;
    }

    if (nullptr != exitBtn)
    {
        delete exitBtn;
    }

    if (nullptr != choosePicBtn)
    {
        delete choosePicBtn;
    }

    if (nullptr != vBoxLayout)
    {
        delete vBoxLayout;
    }

    if (nullptr != hBoxLayout)
    {
        delete hBoxLayout;
    }
}

void ChoosePicWidget::TranslateLanguage()
{
    choosePicBtn->setText("Choose Picture");
    exitBtn->setText("Close Widget");
    exitToMainWidgetBtn->setText("Go Back");

    displayPicLabel->setText("Waiting to Choose Picture ...");

    return;
}

void ChoosePicWidget::sendSignalsToReturnMainWidget()
{
    emit mySignal();
    emit mySignalParm(2, "已经从ChoosePicWidget切换到主窗口");   //2表示为ChoosePicWidget发过去的

    return;
}

void ChoosePicWidget::choosePicture()
{
    //QString fileName = QFileDialog::getSaveFileName(this, tr("保存到文件"), QDir::homePath(), tr("jpg格式文件(*.jpg);;png格式文件(*.png)"));
    if( 1 )
    {
        //
    }
    else
    {
        //
    }

    return;
}
