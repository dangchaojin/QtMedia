#ifndef CHOOSEPICWIDGET_H
#define CHOOSEPICWIDGET_H

#include "common.h"

class ChoosePicWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChoosePicWidget(QWidget *parent = nullptr);
    ~ChoosePicWidget();

    void TranslateLanguage();
    void sendSignalsToReturnMainWidget();


public slots:

private slots:
    void choosePicture();


signals:
    void mySignal();
    void mySignalParm(int, QString);

private:
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    QPushButton *choosePicBtn;
    QPushButton *exitBtn;
    QPushButton *exitToMainWidgetBtn;

    QLabel *displayPicLabel;

    QLineEdit *displayOpenFileName;

};

#endif // CHOOSEPICWIDGET_H
