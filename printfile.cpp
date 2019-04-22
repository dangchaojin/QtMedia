#include "printfile.h"

//参考： https://blog.csdn.net/xiaoyink/article/details/79721481


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //加锁
    static QMutex mutex;
    mutex.lock();


    QDir dir("log");
    if (!dir.exists())
    {
        QDir dir;
        dir.mkdir("log");
    }

    QString currentDate = QDateTime::currentDateTime().toString("yyyyMMdd");
    QString logName = "log" + currentDate + ".txt";
    QString logFileName = "log/" + logName;

    //记下最近一周的日志
    if (!QFile::exists(logFileName))
    {
        QFileInfoList fileList = dir.entryInfoList(QStringList() << "*.txt", QDir::NoFilter, QDir::Time);
        if (fileList.size() >= LOG_FILE_KEEP_NUM)
        {
            int i = 1;
            foreach(QFileInfo fileInfo , fileList)
            {
                if (i >= LOG_FILE_KEEP_NUM)
                {
                    QString fileName = fileInfo.absoluteFilePath();
                    QFile::remove(fileName);
                }
                i++;
            }
        }
    }

    QFile file(logFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        file.close();
        return;
    }

    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString logMsg;


    //QByteArray localMsg = msg.toLocal8Bit();
    //QString strMsg("");

    switch (type)
    {
    case QtDebugMsg:
        logMsg = QString("%1: [Debug]: %2  Function: %3  File: %4  Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtInfoMsg:
        logMsg = QString("%1: [Info]: %2  Function: %3  File: %4  Line: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtWarningMsg:
        logMsg = QString("%1: [Warning]: %2 Function: %3 Line: %4 File: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtCriticalMsg:
        logMsg = QString("%1: [Critical]: %2 Function: %3 Line: %4 File: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        break;
    case QtFatalMsg:
        logMsg = QString("%1: [Fatal]: %2 Function: %3 Line: %4 File: %5\n").arg(currentDateTime).arg(msg).arg(context.function).arg(context.file).arg(context.line);
        abort();
        break;
    default:
        break;
    }

    //#5 log message out to file
    QTextStream ts(&file);
    ts << logMsg << "\r\n";

    file.flush();
    file.close();


    //解锁
    mutex.unlock();
}
