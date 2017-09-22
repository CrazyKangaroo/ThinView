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
#include <QButtonGroup>
#include <QFile>
#include "threaddialogtimer.h"

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
    QProcess * processIP;
    QProcess * processDNS;
    LoadingDialog * loadingDialog;
    ThreadLoading threadLoading;
    QButtonGroup * buttonGroupIP;
    QButtonGroup * buttonGroupDNS;
    ThreadDialogTimer * threadDialogTimer;
    QString IPaddr = QString::null;
    QString subnetMask = QString::null;
    QString gateway = QString::null;
    QString DNS1 = QString::null;
    QString DNS2 = QString::null;
    QString DNS3 = QString::null;
    QString resolutionArray[5] = {"1920x1080", "1440x900", "1024x768", "1280x1024", "1280x720"};
    void SetResolutionIndex();
    void StaticIPInit();
    void DhcpInit();
    void AutoDNSInit();
    void ManualDNSInit();
    void SetDNS();
    void DataInit();
    void GetPlatformInfo();
    void GetNetwordInfo();
    void IPInit();
    void DNSInit();
    void SetDhcp();
    void SetStaticIP();
    void SetAutoDNS();
    void SetManualDNS();
public slots:
    void slot_ReadSystemResolution();
    void slot_ReadPaltFormInfo();
    void onCheckBoxAutoClick();
    void onCheckBoxManualClick();
    void onBtnBasicSaveClick();
    void slot_WriteBasicIniFinish();
    void onRadioButtonDhcpClick();
    void onRadioButtonStaticIPClick();
    void onRadioButtonAutoDNSClick();
    void onRadioButtonManualDNSClick();
    void onBtnNetworkSaveClick();
    void slot_IPFinished();
    void slot_DNSFinished();
signals:
    void CloseWindow();
};

#endif // CUSTOMTAB_H
