#ifndef THREADWRITEBASICINI_H
#define THREADWRITEBASICINI_H

#include <QThread>
#include "ini.h"

class ThreadWriteBasicIni : public QThread
{
public:
    ThreadWriteBasicIni();
protected:
    void run();
};

#endif // THREADWRITEBASICINI_H
