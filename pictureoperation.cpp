#include "pictureoperation.h"

pictureoperation::pictureoperation(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();

    exitBtn = new QPushButton();
    backMainWidBtn = new QPushButton();

    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(backMainWidBtn);

    this->setLayout(vBoxLayout);
    this->setGeometry(AXSIZE, AYSIZE, AWSIZE, AHSIZE);
    this->TranslateLanguage();

    QObject::connect(backMainWidBtn, SIGNAL(clicked()), this, SLOT(ReturnMainWidget()));
}

pictureoperation::~pictureoperation()
{
    if (nullptr != backMainWidBtn) {delete backMainWidBtn; }
    if (nullptr != exitBtn) { delete exitBtn; }
    if (nullptr != vBoxLayout) { delete vBoxLayout; }
}

void pictureoperation::ReturnMainWidget()
{
    qDebug() << "ReturnMainWidget";

    return;
}

void pictureoperation::TranslateLanguage()
{
    this->setWindowTitle("Picture Operation");
    exitBtn->setText("Close Widget");
    backMainWidBtn->setText("Go Back");

    return;
}
