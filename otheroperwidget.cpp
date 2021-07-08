#include "otheroperwidget.h"

OtherOperWidget::OtherOperWidget(QWidget *parent) : QWidget(parent)
{
    vBoxLayout = new QVBoxLayout();
    showDlgBtn = new QPushButton();
    exitBtn = new QPushButton();
    backMainWidBtn = new QPushButton();





    vBoxLayout->addWidget(showDlgBtn);
    vBoxLayout->addWidget(exitBtn);
    vBoxLayout->addWidget(backMainWidBtn);

    this->setLayout(vBoxLayout);
    this->setGeometry(AXSIZE, AYSIZE, AWSIZE, AHSIZE);
    this->TranslateLanguage();

    //欲使信号直接驱动非槽函数，可以这样做！！！！！！
    //QObject::connect(backMainWidBtn, SIGNAL(clicked()), this, SLOT(ReturnMainWidget()));
    QObject::connect(backMainWidBtn, &QPushButton::clicked, this, &OtherOperWidget::ReturnMainWidget);
    QObject::connect(showDlgBtn, &QPushButton::clicked, this, &OtherOperWidget::ShowDialog);
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

void OtherOperWidget::ShowDialog()
{
    PopupWidget popupWidget(TipsType::TipsType_Unknown, "test");
//    popupWidget.show();
    popupWidget.setAttribute(Qt::WA_ShowModal, true);
    popupWidget.startTimer(3000);
    popupWidget.exec();
}

void OtherOperWidget::TranslateLanguage()
{
    this->setWindowTitle("Other Operation");
    showDlgBtn->setText("Show Dialog");
    exitBtn->setText("Close Widget");
    backMainWidBtn->setText("Go Back");

    return;
}
