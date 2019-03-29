#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include <QDebug>
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


private slots:
    void CaptureImage();
    void SaveImage();
    void DisplayImage(int, QImage image);


private:
    QCamera *camera;
    QCameraViewfinder *viewFinder;
    QCameraImageCapture *cameraImageCapture;

    QLabel *label;

    QPushButton *captureButton;
    QPushButton *saveButton;
    QPushButton *exitButton;

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;
};

#endif // CAMERAWIDGET_H
