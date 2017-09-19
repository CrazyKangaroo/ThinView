#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QWidget>
#include "ini.h"
#include <QProcess>
#include <QDebug>
#include <QTextStream>
#include <QList>

enum PageIndex
{
    page0 = 0,
    page1,
    page2,
};

namespace Ui {
class CustomTab;
}

class CustomTab : public QWidget
{
    Q_OBJECT

public:
    explicit CustomTab(QWidget *parent = 0);
    ~CustomTab();

private:
    Ui::CustomTab *ui;
    void UIIint();
    QString serverAddr;
    int port;
    QProcess * processResolution;
    QList<int> resolutionList;
    QProcess * processSystem;
    QString resolutionArray[5] = {"1920x1080", "1440x900", "1024x768", "1280x1024", "1280x720"};
public slots:
    void slot_ReadSystemResolution();
    void slot_ReadSystem();
    void onCheckBoxAutoClick();
    void onCheckBoxManualClick();
};

#endif // CUSTOMTAB_H
