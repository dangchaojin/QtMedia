#ifndef COMMON_H
#define COMMON_H

#define SIGNAL_CAMERA_WIDGET       1
#define SIGNAL_CHOOSE_PIC_WIDGET   2
#define SIGNAL_PIC_OPER_WIDGET     3
#define SIGNAL_OTHER_OPER_WIDGET   4

#define AXSIZE 250
#define AYSIZE 250
#define AWSIZE 1024
#define AHSIZE 500

#define SHOW_LABEL_SIZE 350

#define SOFT_VERSION "QtMedia dcj_1.0"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>

#include <QDebug>

#include <QFileDialog>
#include <QMessageBox>

//#include <QPicture>
//#include <QPainter>
//#include <QPicturePaintEngine>
//#include <QPaintEngine>


//在使用QCamera相关的类时，一定要加入: QT += multimedia multimediawidgets
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>



#include <QMutex>
#include <QDateTime>
#include <QFile>
#include <QFileInfo>




#endif // COMMON_H
