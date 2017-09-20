#ifndef CUSTOMTAB_H
#define CUSTOMTAB_H

#include <QWidget>
#include "ini.h"
#include <QProcess>
#include <QDebug>
#include <QTextStream>
#include <QList>
#include <QDesktopWidget>
#include "dialog.h"
#include "loadingdialog.h"
#include "threadloading.h"

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
    bool autoEnable;
    int resolutionIndex;
    QProcess * processResolution;
    QList<QString> resolutionList;
    QProcess * processSystem;
    LoadingDialog * loadingDialog;
    ThreadLoading threadLoading;
    QString resolutionArray[5] = {"1920x1080", "1440x900", "1024x768", "1280x1024", "1280x720"};
    void SetResolutionIndex();
public slots:
    void slot_ReadSystemResolution();
    void slot_ReadSystem();
    void onCheckBoxAutoClick();
    void onCheckBoxManualClick();
    void onBtnBasicSaveClick();
    void slot_WriteBasicIniFinish();
signals:
    void CloseWindow();
};

#endif // CUSTOMTAB_H
