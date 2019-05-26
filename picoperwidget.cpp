#include "picoperwidget.h"

PicOperWidget::PicOperWidget(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();

    exitBtn = new QPushButton();
    backMainWidBtn = new QPushButton();

    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(backMainWidBtn);

    this->setLayout(vBoxLayout);
    this->setGeometry(AXSIZE, AYSIZE, AWSIZE, AHSIZE);
    this->TranslateLanguage();

    //欲使信号直接驱动非槽函数，可以这样做！！！！！！
    //QObject::connect(backMainWidBtn, SIGNAL(clicked()), this, SLOT(ReturnMainWidget()));
    QObject::connect(backMainWidBtn, &QPushButton::clicked, this, &PicOperWidget::ReturnMainWidget);
    QObject::connect(this->exitBtn, SIGNAL(clicked()), this, SLOT(close()));
}

PicOperWidget::~PicOperWidget()
{
    if (nullptr != backMainWidBtn) {delete backMainWidBtn; }
    if (nullptr != exitBtn) { delete exitBtn; }
    if (nullptr != vBoxLayout) { delete vBoxLayout; }
}

void PicOperWidget::ReturnMainWidget()
{
    qDebug() << "from picOperationWidget to MainWidget";
    emit mySignal();
    emit mySignalParm(SIGNAL_PIC_OPER_WIDGET, "已经从picOperWidget切换到主窗口");
    return;
}

void PicOperWidget::TranslateLanguage()
{
    this->setWindowTitle("Picture Operation");
    exitBtn->setText("Close Widget");
    backMainWidBtn->setText("Go Back");

    return;
}
