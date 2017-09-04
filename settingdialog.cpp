#include "settingdialog.h"
#include "ui_settingdialog.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->lab_password->setText(tr("please enter password"));
    ui->btn_ok->setText(tr("OK"));
    ui->btn_cancle->setText(tr("Cancle"));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
