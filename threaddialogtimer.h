#ifndef THREADDIALOGTIMER_H
#define THREADDIALOGTIMER_H

#include <QThread>
#include "dialogtimer.h"

class ThreadDialogTimer : public QThread
{
public:
    ThreadDialogTimer(QString info, unsigned int time);
    void CloseWindow();
protected:
    void run();
private:
    DialogTimer * dialogTimer;
    QString info;
    unsigned int time;
};

#endif // THREADDIALOGTIMER_H
