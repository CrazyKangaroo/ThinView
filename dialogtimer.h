#ifndef DIALOGTIMER_H
#define DIALOGTIMER_H

#include <QDialog>
#include "titlebar.h"
#include <QTimer>
#include <QDebug>
#include <QVBoxLayout>

namespace Ui {
class DialogTimer;
}

class DialogTimer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTimer(QWidget *parent = 0);
    ~DialogTimer();
    void SetTimer(unsigned int time);
    void SetInfo(QString info, unsigned int time = 0);

private:
    Ui::DialogTimer *ui;
    QTimer * timer;
    QString info;
    unsigned int time;
public slots:
    void slot_TimeOut();
};

#endif // DIALOGTIMER_H
