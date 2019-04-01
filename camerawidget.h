#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include "common.h"

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    CameraWidget(QWidget *parent = nullptr);
    ~CameraWidget();

    void TranslateLanguage();
    void sendSignalsToReturnMainWidget();

protected:

private:


private slots:
    void CaptureImage();
    void SaveImage();
    void DisplayImage(int, QImage image);

signals:
    void mySignal();
    void mySignalParm(int, QString);

public:

protected:

private:
    QCamera *camera;
    QCameraViewfinder *viewFinder;
    QCameraImageCapture *cameraImageCapture;

    QLabel *showLabel;

    QPushButton *captureBtn;
    QPushButton *saveBtn;
    QPushButton *exitBtn;
    QPushButton *exitToMainWidgetBtn;

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
};

#endif // CAMERAWIDGET_H
