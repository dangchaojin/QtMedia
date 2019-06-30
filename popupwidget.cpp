#include "popupwidget.h"

PopupWidget::PopupWidget(TipsType type, const QString &msg, QWidget *parent) : QDialog (parent), m_type(type)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool |Qt::WindowStaysOnTopHint);          //whis this
    setAttribute(Qt::WA_TranslucentBackground);          //whis this

    this->initFrame(msg);

    m_pTimer = new QTimer(this);
    m_pTimer->setSingleShot(true);
    connect(m_pTimer, &QTimer::timeout, this, [=](){this->close();});
}

PopupWidget::~PopupWidget()
{
    if(nullptr != m_pTimer) m_pTimer->deleteLater();
}

void PopupWidget::startTimer(int time)
{
    m_pTimer->start(time);

    return;
}

void PopupWidget::initFrame(const QString &msg)
{
//    if(TipsType_Warnning == m_type)   //警告
//        this->setStyleSheet("QLabel{background-repeat:no-repeat;}");
//    else if (TipsType_Ok == m_type)   //成功
//        this->setStyleSheet("QLabel{background-repeat:no-repeat;}");

    this->setWindowTitle(msg);
    //this->setStatusTip(msg);
    //this->setWhatsThis(msg);

    return;
}
