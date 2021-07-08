/*
 *在实际开发中，我们会有这样一种需求，一个提示框，用户可以手动关闭，或者在用户没有操作的情况下，显示3秒钟然后自动关闭，这样应该怎样做呢？
  我们的思路应该是这样的：
  1.对话框构造函数里，设置一个定时器
  2.定时器槽函数设置为close()
 */

#ifndef POPUPWIDGET_H
#define POPUPWIDGET_H

#include "common.h"

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
