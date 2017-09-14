#include "autosize.h"

AutoSize::AutoSize()
{

}

void AutoSize::AutoChangeSize(QWidget *widget, int screenWidth, int screenHeight, int baseWidth, int baseHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();
    int widgetWid = widget->width();
    int widgetHei = widget->height();

    double herizontalRatio = screenWidth / (double)baseWidth;
    double verticalRatio = screenHeight / (double)baseHeight;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    int newWidgetWid = (int)(widgetWid * herizontalRatio);
    int newWidgetHei = (int)(widgetHei * verticalRatio);

    widget->setGeometry(newWidgetX, newWidgetY, newWidgetWid, newWidgetHei);
}

void AutoSize::AutoMove(QWidget *widget, int screenWidth, int screenHeight, int baseWidth, int baseHeight)
{
    int widgetX = widget->x();
    int widgetY = widget->y();

    double herizontalRatio = screenWidth / (double)baseWidth;
    double verticalRatio = screenHeight / (double)baseHeight;

    int newWidgetX = (int)(widgetX * herizontalRatio);
    int newWidgetY = (int)(widgetY * verticalRatio);

    widget->move(newWidgetX, newWidgetY);
}
