#include "customtab.h"
#include "ui_customtab.h"
#include "customtabstyle.h"

CustomTab::CustomTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTab)
{
    ui->setupUi(this);

    Ini::ReadBasicIni(serverAddr, port, autoEnable, resolutionIndex);
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
    }
    else
    {
        ui->cco_manual->setChecked(true);
    }
}

void CustomTab::slot_ReadSystemResolution()
{
    QByteArray text = processResolution->readAllStandardOutput();
    processResolution->close();
    QTextStream in(&text);
    bool result = in.seek(153);

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
              resolutionList.append(x);
              resolutionList.append(y);
          }
        }
//        qDebug()<<resolutionList.size();
//        for (int i = 0; i < resolutionList.size(); i++)
//        {
//            qDebug()<<resolutionList[i];
//        }

        for (int i = 0; i < resolutionList.size(); i+=2)
        {
            QString strResolution(QString::number(resolutionList[i])+"x"+QString::number(resolutionList[i + 1]));
            ui->cbo_resolution->addItem(strResolution);
        }
        ui->cbo_resolution->setCurrentIndex(resolutionIndex);
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
        ui->cbo_resolution->setCurrentIndex(resolutionIndex);
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
