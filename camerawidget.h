#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>

#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
//在使用QCamera相关的类时，一定要加入: QT += multimedia multimediawidgets

#include <QHBoxLayout>
//#include <QVBoxLayout>

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    CameraWidget(QWidget *parent = nullptr);
    ~CameraWidget();

    void TranslateLanguage();
    void sendSignals();

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
