#include "threaddialogtimer.h"

ThreadDialogTimer::ThreadDialogTimer(QString info, unsigned int time)
{
    this->info = info;
    this->time = time;
}

void ThreadDialogTimer::run()
{
    dialogTimer = new DialogTimer;
    dialogTimer->SetInfo(info, time);
    dialogTimer->SetTimer(time);
    dialogTimer->exec();
}

void ThreadDialogTimer::CloseWindow()
{
    dialogTimer->close();
}
