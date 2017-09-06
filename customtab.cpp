#include "customtab.h"
#include "ui_customtab.h"
#include "customtabstyle.h"

CustomTab::CustomTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomTab)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(page0, tr("Basic settings"));
    ui->tabWidget->setTabText(page1, tr("Network"));
    ui->tabWidget->setTabText(page2, tr("About"));
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);

    ui->lab_note->setText(tr("note"));
    ui->lab_serverAddr->setText(tr("server address"));
    ui->lab_port->setText(tr("port"));
    ui->cco_auto->setText(tr("Auto adjust resolution"));
    ui->cco_manual->setText(tr("Manual adjust resolution"));
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

}

CustomTab::~CustomTab()
{
    delete ui;
}
