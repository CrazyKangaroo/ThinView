#include "customtab.h"
#include "ui_customtab.h"
#include "customtabstyle.h"

CustomTab::CustomTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTab)
{
    ui->setupUi(this);

    Ini ini;
    ini.ReadBasicIni(serverAddr, port, autoEnable);
    UIIint();
    ui->lei_serverAddr->setText(serverAddr);
    ui->lei_port->setText(QString::number(port));
    processSystem = new QProcess(this);
    connect(processSystem, SIGNAL(readyReadStandardOutput()), this, SLOT(slot_ReadSystem()));
    QStringList arguments;
    arguments.append("-a");
    processSystem->start("uname", arguments, QIODevice::ReadOnly);


}

CustomTab::~CustomTab()
{
    delete ui;
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

void CustomTab::slot_ReadSystem()
{
    QByteArray text = processSystem->readAllStandardOutput();
    processSystem->close();
    //qDebug()<<text;

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
