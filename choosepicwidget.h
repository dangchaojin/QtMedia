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


public slots:

private slots:
    void choosePicture();
    void ReturnMainWidget();


signals:
    void mySignal();
    void mySignalParm(int, QString);

private:
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    QLabel *showTextLabel;
    QPushButton *choosePicBtn;
    QPushButton *exitBtn;
    QPushButton *backMainWidBtn;

    QLabel *displayPicLabel;

    QLineEdit *displayOpenFileName;

};

#endif // CHOOSEPICWIDGET_H
