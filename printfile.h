#ifndef PRINTFILE_H
#define PRINTFILE_H

#include "common.h"

//打印到文件
//不要把全局变量以及全局方法的定义放在头文件里!!!!!
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);


#endif // PRINTFILE_H
