#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "camerawidget.h"
#include "choosepicwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void TranslateLanguage();

protected:

private:

/* 槽不需要信号传过来的参数时，可以不要参数；但槽函数一旦要参数，其参数个数，
 * 类型，顺序必须要和对应的信号保持一致。另外，槽函数的参数不能有缺省值。
 * 由于信号的返回值为void, 槽必须和信号的返回值保持一致, 因此槽的返回值为void      */
public slots:
    void choosePicture();
    void goCameraWidget();
    void returnMainWidget();
    void returnMainWidgetParm(int, QString);

private slots:
    void clickedCount();


signals:


//以下为变量
public:

protected:

private:
    QVBoxLayout *vBoxLayout;

    QPushButton *cameraBtn;
    QPushButton *choosePicBtn;
    QPushButton *countBtn;
    QPushButton *exitBtn;

    CameraWidget *cameraWidget;
    ChoosePicWidget *pictureWidget;

    int count = 0;
};

#endif // MAINWINDOW_H
