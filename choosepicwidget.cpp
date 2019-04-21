#include "choosepicwidget.h"

ChoosePicWidget::ChoosePicWidget(QWidget *parent) : QWidget(parent)
{
    qInstallMessageHandler(myMessageOutput);

    hBoxLayout = new QHBoxLayout();
    vBoxLayout = new QVBoxLayout();

    choosePicBtn = new QPushButton();
    exitBtn = new QPushButton();
    exitToMainWidgetBtn = new QPushButton();

    displayPicLabel = new QLabel();

    showTextLabel = new QLabel();
    showTextLabel->setFixedSize(350, 350);

    displayOpenFileName = new QLineEdit();

    vBoxLayout->addWidget(showTextLabel);
    vBoxLayout->addWidget(displayOpenFileName);
    vBoxLayout->addWidget(choosePicBtn);
    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(exitToMainWidgetBtn);


    hBoxLayout->addWidget(displayPicLabel);
    hBoxLayout->addStretch(1);
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
    if (nullptr != displayOpenFileName)
    {
        delete displayOpenFileName;
    }

    if (nullptr != showTextLabel)
    {
        delete showTextLabel;
    }

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

    displayOpenFileName->setText("Waiting to Choose Picture ...");
    showTextLabel->setText("Attention:---");

    return;
}

void ChoosePicWidget::sendSignalsToReturnMainWidget()
{
    emit mySignal();
    emit mySignalParm(SIGNAL_CHOOSE_WIDGET, "已经从ChoosePicWidget切换到主窗口");

    return;
}

void ChoosePicWidget::choosePicture()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"), QDir::homePath(), tr("jpg格式文件(*.jpg);;png格式文件(*.png);;所有文件(*.*)"));
    if( fileName.isEmpty() )
    {
        qDebug() << "fileName is Empty";
        QMessageBox messageBox(QMessageBox::NoIcon, "Fail", "Open fail!");
        messageBox.exec();
        return;
    }

    qDebug() << "choosePicture: " << fileName;
    displayOpenFileName->setText(fileName);

//    //显示gif可以用这个
//    QMovie *movie = new QMovie(fileName);
//    displayPicLabel->setMovie(movie);

//    QPicture Picture;        运行不起来---有空再找原因吧
//    Picture.load(fileName);
//    displayPicLabel->setPicture(Picture);

    QPixmap pixmap;
    pixmap.load(fileName);
    displayPicLabel->setPixmap(pixmap);

    displayPicLabel->setScaledContents(true);   //缩放内容！！这样可使图片填充label


    return;
}
