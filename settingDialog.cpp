#include "settingDialog.h"
#include "ui_setting.h"

settingDialog::settingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingDialog)
{
    ui->setupUi(this);
    ui->lab_password->setText(tr("Please enter password"));
    ui->btn_accept->setText(tr("OK"));
    ui->btn_cancle->setText(tr("Cancle"));
}

setting::~setting()
{
    delete ui;
}
