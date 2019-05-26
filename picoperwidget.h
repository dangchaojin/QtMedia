#ifndef PICOPERWIDGET_H
#define PICOPERWIDGET_H

#include "common.h"

class PicOperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PicOperWidget(QWidget *parent = nullptr);
    ~PicOperWidget();


signals:
    void mySignal();
    void mySignalParm(int, QString);

public slots:

private slots:
    void ReturnMainWidget();

private:
    void TranslateLanguage();


private:
    QPushButton *exitBtn;
    QPushButton *backMainWidBtn;

    QVBoxLayout *vBoxLayout;
};

#endif // PICOPERWIDGET_H
