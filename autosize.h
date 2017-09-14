#ifndef AUTOSIZE_H
#define AUTOSIZE_H

#include <QWidget>

class AutoSize
{
public:
    AutoSize();
    static void AutoChangeSize(QWidget *widget, int screenWidth, int screenHeight, int baseWidth, int baseHeight);
    static void AutoMove(QWidget *widget, int screenWidth, int screenHeight, int baseWidth, int baseHeight);
};

#endif // AUTOSIZE_H
