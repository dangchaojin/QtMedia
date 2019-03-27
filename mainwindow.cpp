#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    //C++标准规定，本地对象的析构函数的调用顺序与他们的构造顺序相反

    camera = new QCamera();
    viewFinder = new QCameraViewfinder();     //摄像取景器
    cameraImageCapture = new QCameraImageCapture(camera);

    label = new QLabel();
    label->setFixedSize(350, 350);

    captureButton = new QPushButton();
    saveButton = new QPushButton();
    saveButton->setDisabled(true);
    exitButton = new QPushButton();

    vBoxLayout->addWidget(label);
    vBoxLayout->addStretch(1);
    vBoxLayout->addWidget(captureButton);
    vBoxLayout->addWidget(saveButton);
    vBoxLayout->addWidget(exitButton);

    hBoxLayout->addWidget(viewFinder);
    hBoxLayout->addStretch(1);
    hBoxLayout->addLayout(vBoxLayout);

    setLayout(hBoxLayout);
    //QWidget::setGeometry(int ax, int ay, int aw, int ah)
    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();

    QObject::connect(this->cameraImageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(DisplayImage(int, QImage)));

    QObject::connect(this->captureButton, SIGNAL(clicked()), this, SLOT(CaptureImage()));
    QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(SaveImage()));
    QObject::connect(this->exitButton, SIGNAL(clicked()), this, SLOT(close()));

    camera->setViewfinder(viewFinder);
    camera->start();
}

MainWindow::~MainWindow()
{
    //QObject及其派生类的对象，如果其parent非0，那么其parent析构时会析构该对象。
    if (nullptr != exitButton)
    {
        delete exitButton;
    }
    //#define NULL ((void *)0)     所以用nullptr
    if (nullptr != saveButton)
    {
        delete saveButton;
    }

    if (nullptr != captureButton)
    {
        delete captureButton;
    }

    if (nullptr != label)
    {
        delete label;
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

void MainWindow::TranslateLanguage() //TranslateLanguage
{
    this->setWindowTitle("TestCapture");
    label->setText("Waiting to Capture ...");
    captureButton->setText("capture");
    saveButton->setText("save");
    exitButton->setText("exit");
}

void MainWindow::DisplayImage(int, QImage image)   //参数用不到可以这样
{
    qDebug() << "DisplayImage1";
    label->setPixmap(QPixmap::fromImage(image));
    qDebug() << "DisplayImage2";

    return;
}

void MainWindow::CaptureImage()
{
    if (!saveButton->isEnabled())
    {
        saveButton->setEnabled(true);
        //saveButton->setDisabled(false);
    }

//    QMessageBox messageBox(QMessageBox::NoIcon, "Title", "Contect");
//    messageBox.exec();

    cameraImageCapture->capture();

    return;
}

void MainWindow::SaveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存到文件"), QDir::homePath(), tr("jpg格式文件(*.jpg);;png格式文件(*.png)"));
    if( !fileName.isEmpty() )
    {
        const QPixmap* pixmap = label->pixmap();
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
