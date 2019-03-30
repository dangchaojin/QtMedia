#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    hBoxLayout = new QHBoxLayout();

    cameraButton = new QPushButton();

    hBoxLayout->addWidget(cameraButton);

    this->setLayout(hBoxLayout);
    this->setGeometry(250, 250, 1024, 500);
    this->TranslateLanguage();
}

MainWindow::~MainWindow()
{
    if (nullptr != cameraButton)
    {
        qDebug() << "delete cameraButton";
        delete cameraButton;
    }

    if (nullptr != hBoxLayout)
    {
        qDebug() << "delete hBoxLayout";
        delete hBoxLayout;
    }
}

void MainWindow::TranslateLanguage()
{
    cameraButton->setText("Camera");
}
