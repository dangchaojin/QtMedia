#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    //explicit Widget(QWidget *parent = nullptr);
    ~MainWindow();

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

#endif // MAINWINDOW_H
