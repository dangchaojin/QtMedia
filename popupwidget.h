#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include "common.h"

enum TipsType
{
    TipsType_Unknown = 0,
    TipsType_Warnning = 1,       //警告
    TipsType_Ok = 2              //成功
};

class PopupWidget : public QDialog
{
    //Q_OBJECT
public:
    explicit PopupWidget(TipsType type, const QString &msg, QWidget *parent = nullptr);
    ~PopupWidget();

    void startTimer(int time);

private:
    void initFrame(const QString &msg);

private:
    TipsType m_type;
    QTimer *m_pTimer;
};

#endif // POPUPWIDGET_H
