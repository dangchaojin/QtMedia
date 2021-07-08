#ifndef OTHEROPERWIDGET_H
#define OTHEROPERWIDGET_H

#include "common.h"
#include "popupwidget.h"

class OtherOperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OtherOperWidget(QWidget *parent = nullptr);
    ~OtherOperWidget();


signals:
    void mySignal();
    void mySignalParm(int, QString);

public slots:

private slots:
    void ReturnMainWidget();
    void ShowDialog();

private:
    void TranslateLanguage();

private:
    QVBoxLayout *vBoxLayout;
    QPushButton *showDlgBtn;
    QPushButton *exitBtn;
    QPushButton *backMainWidBtn;
};

#endif // OTHEROPERWIDGET_H
