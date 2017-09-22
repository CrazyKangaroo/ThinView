#include "customtab.h"
#include "ui_customtab.h"
#include "customtabstyle.h"

CustomTab::CustomTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTab)
{
    ui->setupUi(this);

    UIIint();
    DataInit();
}

CustomTab::~CustomTab()
{
    delete ui;
}

void CustomTab::DNSInit()
{
    QFile file("/etc/resolvconf/resolv.conf.d/tail");
    if (file.open(QIODevice::ReadOnly))
    {
        ManualDNSInit();
        bool result = file.seek(11);
        if (result == true)
        {
            DNS1 = file.readLine();
            file.seek(file.pos() + 11);
            DNS2 = file.readLine();
            file.seek(file.pos() + 11);
            DNS3 = file.readLine();

            file.close();

            DNS1.replace(QString("\n"), QString(""));
            DNS2.replace(QString("\n"), QString(""));
            DNS3.replace(QString("\n"), QString(""));

            ui->lei_dnsAddr1->setText(DNS1);
            ui->lei_dnsAddr2->setText(DNS2);
            ui->lei_dnsAddr3->setText(DNS3);
        }
    }
    else
    {
        AutoDNSInit();
    }
}

void CustomTab::IPInit()
{
    system("sudo cat /etc/network/interfaces > net_tmp.txt");
    QFile file("net_tmp.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray text = file.readAll();
        if (text.indexOf("dhcp") >= 0)
        {
            DhcpInit();
        }
        else if (text.indexOf("static") >= 0)
        {
            StaticIPInit();
            ui->lei_ipAddr->setText(IPaddr);
            ui->lei_subnetMask->setText(subnetMask);
            ui->lei_gateway->setText(gateway);
        }

        file.close();
        system("rm -rf net_tmp.txt");
    }
}

void CustomTab::DataInit()
{
    Ini ini;
    ini.ReadBasicIni(serverAddr, port, autoEnable);

    ui->lei_serverAddr->setText(serverAddr);
    ui->lei_port->setText(QString::number(port));

    GetPlatformInfo();
    GetNetwordInfo();
    IPInit();
    DNSInit();
}

void CustomTab::GetNetwordInfo()
{
    system("chmod +x netget.sh");
    system("sudo ./netget.sh");

    QFile file("nettmp.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        IPaddr = file.readLine();
        subnetMask = file.readLine();
        gateway = file.readLine();

        file.close();
        system("rm -rf nettmp.txt");

        IPaddr.replace(QString("\n"), QString(""));
        subnetMask.replace(QString("\n"), QString(""));
        gateway.replace(QString("\n"), QString(""));
    }
}

void CustomTab::GetPlatformInfo()
{
    processSystem = new QProcess(this);
    connect(processSystem, SIGNAL(readyReadStandardOutput()), this, SLOT(slot_ReadPaltFormInfo()));
    QStringList arguments;
    arguments.append("-a");
    processSystem->start("uname", arguments, QIODevice::ReadOnly);
}

void CustomTab::UIIint()
{
    ui->tabWidget->setTabText(page0, tr("Basic settings"));
    ui->tabWidget->setTabText(page1, tr("Network"));
    ui->tabWidget->setTabText(page2, tr("About"));
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);

    ui->lab_note->setText(tr("note"));
    ui->lab_serverAddr->setText(tr("server address"));
    ui->lab_port->setText(tr("port"));
    ui->cco_auto->setText(tr("Auto adjust resolution"));
    ui->cco_manual->setText(tr("Manual adjust resolution"));
    connect(ui->cco_auto, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxAutoClick()));
    connect(ui->cco_manual, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxManualClick()));
    ui->cco_auto->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtnset_nor.png);}"
                                 "QCheckBox::indicator:checked{image:url(:/image/checkbtnset_press.png);}");
    ui->cco_manual->setStyleSheet("QCheckBox::indicator:unchecked{image:url(:/image/checkbtnset_nor.png);}"
                                  "QCheckBox::indicator:checked{image:url(:/image/checkbtnset_press.png);}");
    ui->btn_basic_save->setText(tr("Save"));
    connect(ui->btn_basic_save, SIGNAL(clicked(bool)), this, SLOT(onBtnBasicSaveClick()));

    ui->rbn_dhcp->setText(tr("Automatic access using DHCP"));
    ui->rbn_staticIP->setText(tr("Using a static IP address"));
    ui->lab_ipAddr->setText(tr("IP address"));
    ui->lab_subnetMask->setText(tr("Subnet mask"));
    ui->lab_gateway->setText(tr("Default gateway"));

    ui->rbn_autoDNS->setText(tr("Automatically get the DNS server address"));
    ui->rbn_manualDNS->setText(tr("Manually set the DNS server adress"));

    ui->lab_dnsAddr1->setText(tr("The first DNS server"));
    ui->lab_dnsAddr2->setText(tr("The second DNS server"));
    ui->lab_dnsAddr3->setText(tr("The third DNS server "));
    ui->btn_network_save->setText(tr("Save"));

    ui->lab_AppName->setText(tr("Terminal login software"));
    ui->lab_version->setText(tr("Version : "));

    if (autoEnable == true)
    {
        ui->cco_auto->setChecked(true);
        ui->cbo_resolution->setDisabled(true);
    }
    else
    {
        ui->cco_manual->setChecked(true);
        ui->cbo_resolution->setDisabled(false);
    }

    buttonGroupIP = new QButtonGroup(this);
    buttonGroupIP->addButton(ui->rbn_dhcp);
    buttonGroupIP->addButton(ui->rbn_staticIP);
    buttonGroupDNS = new QButtonGroup(this);
    buttonGroupDNS->addButton(ui->rbn_autoDNS);
    buttonGroupDNS->addButton(ui->rbn_manualDNS);

    connect(ui->rbn_dhcp, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonDhcpClick()));
    connect(ui->rbn_staticIP, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonStaticIPClick()));
    connect(ui->rbn_autoDNS, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonAutoDNSClick()));
    connect(ui->rbn_manualDNS, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonManualDNSClick()));

    connect(ui->btn_network_save, SIGNAL(clicked(bool)), this, SLOT(onBtnNetworkSaveClick()));
}

void CustomTab::AutoDNSInit()
{
    ui->rbn_autoDNS->setChecked(true);
    ui->lei_dnsAddr1->setDisabled(true);
    ui->lei_dnsAddr2->setDisabled(true);
    ui->lei_dnsAddr3->setDisabled(true);
}

void CustomTab::ManualDNSInit()
{
    ui->rbn_manualDNS->setChecked(true);
    ui->lei_dnsAddr1->setDisabled(false);
    ui->lei_dnsAddr2->setDisabled(false);
    ui->lei_dnsAddr3->setDisabled(false);
}

void CustomTab::DhcpInit()
{
    ui->rbn_dhcp->setChecked(true);
    ui->lei_ipAddr->setDisabled(true);
    ui->lei_subnetMask->setDisabled(true);
    ui->lei_gateway->setDisabled(true);
    ui->rbn_autoDNS->setDisabled(false);
}

void CustomTab::StaticIPInit()
{
    ui->rbn_staticIP->setChecked(true);
    ui->lei_ipAddr->setDisabled(false);
    ui->lei_subnetMask->setDisabled(false);
    ui->lei_gateway->setDisabled(false);
}

void CustomTab::onRadioButtonDhcpClick()
{
    ui->lei_ipAddr->setDisabled(true);
    ui->lei_subnetMask->setDisabled(true);
    ui->lei_gateway->setDisabled(true);
    ui->rbn_autoDNS->setDisabled(false);

    ui->lei_ipAddr->clear();
    ui->lei_subnetMask->clear();
    ui->lei_gateway->clear();
}

void CustomTab::onRadioButtonStaticIPClick()
{
    ui->rbn_autoDNS->setDisabled(true);
    ui->lei_ipAddr->setDisabled(false);
    ui->lei_subnetMask->setDisabled(false);
    ui->lei_gateway->setDisabled(false);
    ui->rbn_manualDNS->setChecked(true);
    ui->lei_dnsAddr1->setDisabled(false);
    ui->lei_dnsAddr2->setDisabled(false);
    ui->lei_dnsAddr3->setDisabled(false);
}

void CustomTab::onRadioButtonAutoDNSClick()
{
    ui->lei_dnsAddr1->setDisabled(true);
    ui->lei_dnsAddr2->setDisabled(true);
    ui->lei_dnsAddr3->setDisabled(true);

    ui->lei_dnsAddr1->clear();
    ui->lei_dnsAddr2->clear();
    ui->lei_dnsAddr3->clear();
}

void CustomTab::onRadioButtonManualDNSClick()
{
    ui->lei_dnsAddr1->setDisabled(false);
    ui->lei_dnsAddr2->setDisabled(false);
    ui->lei_dnsAddr3->setDisabled(false);
}

void CustomTab::slot_ReadSystemResolution()
{
    QByteArray text = processResolution->readAllStandardOutput();
    processResolution->close();
    QTextStream in(&text);
    bool result = in.seek(153);

    QList<int> temp;
    if (result == true)
    {
        while (!in.atEnd())
        {
          int x, y;
          char ch;
          in>>x>>ch>>y;
          in.readLine();
          if (ch == 'x')
          {
              temp.append(x);
              temp.append(y);
          }
        }

        for (int i = 0; i < temp.size(); i+=2)
        {
            QString strResolution(QString::number(temp[i])+"x"+QString::number(temp[i + 1]));
            resolutionList.append(strResolution);
        }

        for (int i = 0; i < resolutionList.size(); i++)
        {
            ui->cbo_resolution->addItem(resolutionList[i]);
        }
        SetResolutionIndex();
    }
}

void CustomTab::onBtnNetworkSaveClick()
{
    threadDialogTimer = new ThreadDialogTimer(tr("Setting up system network"), 5);
    threadDialogTimer->start();

    SetDNS();
}

void CustomTab::SetDNS()
{
    if (ui->rbn_autoDNS->isChecked())
    {
        SetAutoDNS();
    }
    else
    {
        SetManualDNS();
    }
}
void CustomTab::SetManualDNS()
{
    DNS1 = ui->lei_dnsAddr1->text();
    DNS2 = ui->lei_dnsAddr2->text();
    DNS3 = ui->lei_dnsAddr3->text();

    QString strCmd ("sudo ./dns.sh " + DNS1 + " " + DNS2  + " " + DNS3);
    char * cmd;
    QByteArray temp = strCmd.toLatin1();
    cmd = temp.data();
    system("chmod +x dns.sh");
    processDNS = new QProcess(this);
    connect(processDNS, SIGNAL(finished(int)), this, SLOT(slot_DNSFinished()));
    processDNS->start(cmd);
}

void CustomTab::SetAutoDNS()
{
    processDNS = new QProcess(this);
    connect(processDNS, SIGNAL(finished(int)), this, SLOT(slot_DNSFinished()));
    processDNS->start("sudo ifdown eth0 \nifup eth0");
    QFile file("/etc/resolvconf/resolv.conf.d/tail");
    if (file.open(QIODevice::ReadOnly))
    {
        system("sudo rm -rf /etc/resolvconf/resolv.conf.d/tail");
    }
}

void CustomTab::SetDhcp()
{
    system("chmod +x dhcp.sh");
    processIP = new QProcess(this);
    connect(processIP, SIGNAL(finished(int)), this, SLOT(slot_IPFinished()));
    processIP->start("sudo ./dhcp.sh");
}

void CustomTab::SetStaticIP()
{
    IPaddr = ui->lei_ipAddr->text();
    subnetMask = ui->lei_subnetMask->text();
    gateway = ui->lei_gateway->text();

    system("chmod +x netstatic.sh");

    QString strCmd("sudo ./netstatic.sh " + IPaddr + " " + subnetMask + " " + gateway);
    char * cmd;
    QByteArray temp = strCmd.toLatin1();
    cmd = temp.data();
    processIP = new QProcess(this);
    connect(processIP, SIGNAL(finished(int)), this, SLOT(slot_IPFinished()));
    processIP->start(cmd);
}

void CustomTab::slot_DNSFinished()
{
    if (ui->rbn_dhcp->isChecked())
    {
        SetDhcp();
    }
    else
    {
        SetStaticIP();
    }
}


void CustomTab::slot_IPFinished()
{
    threadDialogTimer->CloseWindow();
    threadDialogTimer->wait();
    emit CloseWindow();
}

void CustomTab::slot_ReadPaltFormInfo()
{
    QByteArray text = processSystem->readAllStandardOutput();
    processSystem->close();

    if (text.indexOf("x86") >= 0)
    {
        processResolution = new QProcess(this);
        connect(processResolution, SIGNAL(readyReadStandardOutput()), this, SLOT(slot_ReadSystemResolution()));
        processResolution->start("xrandr", QIODevice::ReadOnly);
    }
    else
    {
        for (int i = 0; i < sizeof(resolutionArray) / sizeof(resolutionArray[0]); i++)
        {
            ui->cbo_resolution->addItem(resolutionArray[i]);
        }
        SetResolutionIndex();
    }
}

void CustomTab::onCheckBoxAutoClick()
{
    if (ui->cco_auto->isChecked())
    {
        ui->cco_manual->setChecked(false);
        ui->cbo_resolution->setDisabled(true);
    }
}

void CustomTab::onCheckBoxManualClick()
{
    if (ui->cco_manual->isChecked())
    {
        ui->cco_auto->setChecked(false);
        ui->cbo_resolution->setDisabled(false);
    }
}

void CustomTab::onBtnBasicSaveClick()
{
    serverAddr = ui->lei_serverAddr->text();
    port = ui->lei_port->text().toInt();
    autoEnable = ui->cco_auto->isChecked();
    resolutionIndex = ui->cbo_resolution->currentIndex();

    Ini * ini = new Ini(this);
    connect(ini, SIGNAL(WriteBasicIniFinish()), this, SLOT(slot_WriteBasicIniFinish()));

    QDesktopWidget * desktop = QApplication::desktop();
    QString currentResoluton(QString::number(desktop->width()) + "x" + QString::number(desktop->height()));

    if (autoEnable == true)
    {
        if (currentResoluton != resolutionList[0])
        {
            Dialog * dialog = new Dialog;
            dialog->SetInfo(tr("Be sure to change the resolution to ") + resolutionList[0] + "?");
            int result = dialog->exec();
            if (result == QDialog::Accepted)
            {
                QProcess * processChangeResolution = new QProcess(this);
                QStringList arguments;
                arguments.append("-s");
                arguments.append(resolutionList[0]);
                processChangeResolution->start("xrandr", arguments, QIODevice::ReadOnly);
                qApp->quit();
                QProcess::startDetached(qApp->applicationFilePath(), QStringList());
            }
        }
        else
        {
            threadLoading.start();
        }
    }
    else
    {
        if (currentResoluton != resolutionArray[resolutionIndex])
        {
            Dialog * dialog = new Dialog;
            dialog->SetInfo(tr("Be sure to change the resolution to ") + resolutionArray[resolutionIndex] + "?");
            int result = dialog->exec();
            if (result == QDialog::Accepted)
            {
                QProcess * processChangeResolution = new QProcess(this);
                QStringList arguments;
                arguments.append("-s");
                arguments.append(resolutionArray[resolutionIndex]);
                processChangeResolution->start("xrandr", arguments, QIODevice::ReadOnly);
                qApp->quit();
                QProcess::startDetached(qApp->applicationFilePath(), QStringList());
            }
        }
        else
        {
            threadLoading.start();
        }
    }

    ini->WriteBasicIni(serverAddr, port, autoEnable);
}

void CustomTab::SetResolutionIndex()
{
    QDesktopWidget * desktop = QApplication::desktop();
    QString currentResoluton(QString::number(desktop->width()) + "x" + QString::number(desktop->height()));

    if (autoEnable == true)
    {
        for (int i = 0; i < resolutionList.size(); i++)
        {
            if (resolutionList[i] == currentResoluton)
            {
                ui->cbo_resolution->setCurrentIndex(i);
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < sizeof(resolutionArray) / sizeof(resolutionArray[0]); i++)
        {
            if (resolutionArray[i] == currentResoluton)
            {
                ui->cbo_resolution->setCurrentIndex(i);
                break;
            }
        }
    }
}

void CustomTab::slot_WriteBasicIniFinish()
{
    threadLoading.terminate();
    threadLoading.wait();
    emit CloseWindow();
}
