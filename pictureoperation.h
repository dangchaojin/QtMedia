#ifndef PICTUREOPERATION_H
#define PICTUREOPERATION_H

#include "common.h"

class pictureoperation : public QWidget
{
    Q_OBJECT
public:
    explicit pictureoperation(QWidget *parent = nullptr);
    ~pictureoperation();



signals:

public slots:

private slots:
    void ReturnMainWidget();

private:
    void TranslateLanguage();


private:
    QPushButton *exitBtn;
    QPushButton *backMainWidBtn;

    QVBoxLayout *vBoxLayout;
};

#endif // PICTUREOPERATION_H
