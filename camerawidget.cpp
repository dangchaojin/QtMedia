#include "camerawidget.h"
#include <QDebug>

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    //C++标准规定，本地对象的析构函数的调用顺序与他们的构造顺序相反

    camera = new QCamera();
    viewFinder = new QCameraViewfinder();     //摄像取景器
    cameraImageCapture = new QCameraImageCapture(camera);

    showLabel = new QLabel();
    showLabel->setFixedSize(350, 350);
    showLabel->setScaledContents(true);    //缩放内容！！

    captureBtn = new QPushButton();
    saveBtn = new QPushButton();
    saveBtn->setDisabled(true);
    exitBtn = new QPushButton();
    exitToMainWidgetBtn = new QPushButton();

    vBoxLayout->addWidget(showLabel);
    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(captureBtn);
    vBoxLayout->addWidget(saveBtn);
    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(exitToMainWidgetBtn);

    hBoxLayout->addWidget(viewFinder);
    hBoxLayout->addStretch(1);
    hBoxLayout->addLayout(vBoxLayout);

    setLayout(hBoxLayout);
    //QWidget::setGeometry(int ax, int ay, int aw, int ah)
    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();

    QObject::connect(this->cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(DisplayImage(int, QImage)));

    QObject::connect(this->captureBtn, SIGNAL(clicked()), this, SLOT(CaptureImage()));
    QObject::connect(this->saveBtn, SIGNAL(clicked()), this, SLOT(SaveImage()));
    QObject::connect(this->exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    //欲使信号直接驱动非槽函数，可以这样做！！！！！！
    //QObject::connect(exitToMainWidgetBtn, SIGNAL(clicked()), this, SLOT(sendSignals()));
    QObject::connect(exitToMainWidgetBtn, &QPushButton::clicked, this, &CameraWidget::sendSignals);

//    cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
//    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(viewFinder);
    camera->start();
}

CameraWidget::~CameraWidget()
{
    //QObject及其派生类的对象，如果其parent非0，那么其parent析构时会析构该对象。
    if (nullptr != exitToMainWidgetBtn)
    {
        delete exitToMainWidgetBtn;
    }

    if (nullptr != exitBtn)
    {
        delete exitBtn;
    }
    //#define NULL ((void *)0)     所以用nullptr
    if (nullptr != saveBtn)
    {
        delete saveBtn;
    }

    if (nullptr != captureBtn)
    {
        delete captureBtn;
    }

    if (nullptr != showLabel)
    {
        delete showLabel;
    }

    if (nullptr != cameraImageCapture)
    {
        delete cameraImageCapture;
    }

    if (nullptr != viewFinder)
    {
        delete viewFinder;
    }

    if (nullptr != camera)
    {
        delete camera;
    }

//    if (nullptr != hBoxLayout)
//    {
//        delete hBoxLayout;
//    }

//    if (nullptr != vBoxLayout)
//    {
//        delete vBoxLayout;
//    }
    //两个boxlayout只能析构一个，出现两个运行时会报错“pure virtual method called”
    //这是因为  在基类析构函数中调用纯虚函数 ？？
}

void CameraWidget::TranslateLanguage() //TranslateLanguage
{
    this->setWindowTitle("TestCapture");
    showLabel->setText("Waiting to Capture ...");
    captureBtn->setText("Capture");
    saveBtn->setText("Save");
    exitBtn->setText("Close");
    exitToMainWidgetBtn->setText("Go Back");
}

void CameraWidget::sendSignals()
{
    emit mySignal();
    emit mySignalParm(300, "已经切换到主窗口");
}

void CameraWidget::DisplayImage(int, QImage image)   //参数用不到可以这样！！
{
    qDebug() << "DisplayImage1";
    showLabel->setPixmap(QPixmap::fromImage(image));
    qDebug() << "DisplayImage2";

    return;
}

void CameraWidget::CaptureImage()
{
    if (!saveBtn->isEnabled())
    {
        saveBtn->setEnabled(true);
        //saveButton->setDisabled(false);
    }

//    QMessageBox messageBox(QMessageBox::NoIcon, "Title", "Contect");
//    messageBox.exec();

    cameraImageCapture->capture();

    return;
}

void CameraWidget::SaveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存到文件"), QDir::homePath(), tr("jpg格式文件(*.jpg);;png格式文件(*.png)"));
    if( !fileName.isEmpty() )
    {
        const QPixmap* pixmap = showLabel->pixmap();
        if (pixmap)
        {
            pixmap->save(fileName);
            QMessageBox messageBox(QMessageBox::NoIcon, "Succeed", "Save succeed!");
            messageBox.exec();
        }
        else
        {
            QMessageBox messageBox(QMessageBox::NoIcon, "Fail", "Save fail!");
            messageBox.exec();
        }
    }
    else
    {
        QMessageBox messageBox(QMessageBox::NoIcon, "Save Fail", "FileName is empty!");
        //messageBox.setIconPixmap(QPixmap("icon.png"));
        messageBox.exec();
        //return;
    }

    return;
}
