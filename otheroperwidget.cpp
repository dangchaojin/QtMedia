#include "otheroperwidget.h"

OtherOperWidget::OtherOperWidget(QWidget *parent) : QWidget(parent)
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
    QObject::connect(backMainWidBtn, &QPushButton::clicked, this, &OtherOperWidget::ReturnMainWidget);
    QObject::connect(this->exitBtn, SIGNAL(clicked()), this, SLOT(close()));
}

OtherOperWidget::~OtherOperWidget()
{
    //QObject及其派生类的对象，如果其parent非0，那么其parent析构时会析构该对象。
    if (nullptr != backMainWidBtn) { delete backMainWidBtn; }

    if (nullptr != exitBtn) { delete exitBtn; }

    if (nullptr != vBoxLayout) { delete vBoxLayout; }
}

void OtherOperWidget::ReturnMainWidget()
{
    qDebug() << "from otherOperWidget to MainWidget";
    emit mySignal();
    emit mySignalParm(SIGNAL_OTHER_OPER_WIDGET, "已经从otherOperWidget切换到主窗口");
    return;
}

void OtherOperWidget::TranslateLanguage()
{
    this->setWindowTitle("Other Operation");
    exitBtn->setText("Close Widget");
    backMainWidBtn->setText("Go Back");

    return;
}
