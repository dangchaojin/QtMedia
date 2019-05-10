#include "camerawidget.h"

CameraWidget::CameraWidget(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    //C++标准规定，本地对象的析构函数的调用顺序与他们的构造顺序相反

    camera = new QCamera();
    viewFinder = new QCameraViewfinder();     //摄像取景器
    cameraImageCapture = new QCameraImageCapture(camera);

    showLabel = new QLabel();
    showLabel->setFixedSize(SHOW_LABEL_SIZE, SHOW_LABEL_SIZE);
    showLabel->setScaledContents(true);    //缩放内容!!!

    captureBtn = new QPushButton();
    saveBtn = new QPushButton();
    saveBtn->setDisabled(true);
    exitBtn = new QPushButton();
    backMainWidBtn = new QPushButton();

    vBoxLayout->addWidget(showLabel);
    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(captureBtn);
    vBoxLayout->addWidget(saveBtn);
    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(backMainWidBtn);

    hBoxLayout->addWidget(viewFinder);
    hBoxLayout->addStretch(1);
    hBoxLayout->addLayout(vBoxLayout);

    this->setLayout(hBoxLayout);
    this->setGeometry(AXSIZE, AYSIZE, AWSIZE, AHSIZE);
    this->TranslateLanguage();

    QObject::connect(this->cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(DisplayImage(int, QImage)));

    QObject::connect(this->captureBtn, SIGNAL(clicked()), this, SLOT(CaptureImage()));
    QObject::connect(this->saveBtn, SIGNAL(clicked()), this, SLOT(SaveImage()));
    QObject::connect(this->exitBtn, SIGNAL(clicked()), this, SLOT(close()));

    //欲使信号直接驱动非槽函数，可以这样做！！！！！！
    //QObject::connect(backMainWidBtn, SIGNAL(clicked()), this, SLOT(ReturnMainWidget()));
    QObject::connect(backMainWidBtn, &QPushButton::clicked, this, &CameraWidget::ReturnMainWidget);

//    cameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
//    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->setViewfinder(viewFinder);
    camera->start();
}

CameraWidget::~CameraWidget()
{
    //QObject及其派生类的对象，如果其parent非0，那么其parent析构时会析构该对象。
    if (nullptr != backMainWidBtn) { delete backMainWidBtn; }

    if (nullptr != exitBtn) { delete exitBtn; }
    //#define NULL ((void *)0)     所以用nullptr
    if (nullptr != saveBtn) { delete saveBtn; }

    if (nullptr != captureBtn) { delete captureBtn; }

    if (nullptr != showLabel) { delete showLabel; }

    if (nullptr != cameraImageCapture) { delete cameraImageCapture; }

    if (nullptr != viewFinder) { delete viewFinder; }

    if (nullptr != camera) { delete camera; }

//    if (nullptr != hBoxLayout) { delete hBoxLayout; }

//    if (nullptr != vBoxLayout) { delete vBoxLayout; }
    //两个boxlayout只能析构一个，出现两个运行时会报错“pure virtual method called”
    //这是因为  在基类析构函数中调用纯虚函数 ？？
}

void CameraWidget::TranslateLanguage() //TranslateLanguage
{
    this->setWindowTitle("TestCapture");
    showLabel->setText("Waiting to Capture ...");
    captureBtn->setText("Capture Picture");
    saveBtn->setText("Save Picture");
    exitBtn->setText("Close Widget");
    backMainWidBtn->setText("Go Back");

    return;
}

void CameraWidget::ReturnMainWidget()
{
    emit mySignal();
    emit mySignalParm(SIGNAL_CAMERA_WIDGET, "已经从CameraWidget切换到主窗口");

    return;
}

void CameraWidget::DisplayImage(int, QImage image)   //参数用不到可以这样！！
{
    qDebug() << "DisplayImage1";
    showLabel->setPixmap(QPixmap::fromImage(image));

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
    if( fileName.isEmpty() )
    {
		QMessageBox messageBox(QMessageBox::NoIcon, "Save Fail", "FileName is empty!");
        //messageBox.setIconPixmap(QPixmap("icon.png"));
        messageBox.exec();
		return;    //!!!!注意  其他的类似这个if的情况，避免此时错误执行后面的代码
    }
	
    const QPixmap* pixmap = showLabel->pixmap();
    if (pixmap)
    {
        pixmap->save(fileName);
        QMessageBox messageBox(QMessageBox::NoIcon, "Succeed", "Save succeed!");
        messageBox.exec();
    }
    else
    {
        QMessageBox messageBox(QMessageBox::NoIcon, "Fail", "pixmap is empty!");
        messageBox.exec();
    }

    return;
}
