#ifndef THREADLOADING_H
#define THREADLOADING_H

#include <QThread>
#include "loadingdialog.h"

class ThreadLoading : public QThread
{
public:
    ThreadLoading();
private:
    LoadingDialog * loadingDialog;
protected:
    void run();
};

#endif // THREADLOADING_H
