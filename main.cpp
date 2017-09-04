#include "widget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator * translator = new QTranslator;
    translator->load(":/language/ThinView_zh_CN.qm");
    a.installTranslator(translator);

    Widget w;
    w.show();

    return a.exec();
}
