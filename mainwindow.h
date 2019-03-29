#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void TranslateLanguage();

private:
    QHBoxLayout *hBoxLayout;
    QPushButton *cameraButton;
};

#endif // MAINWINDOW_H
