#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QVBoxLayout>
#include <QPalette>
#include "passworderror.h"

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    TitleBar * pTitleBar = new TitleBar(this);
    pTitleBar->SetButtonSize(10, 8);
    pTitleBar->SetButtonIcon(":/image/close_set_22.png");
    installEventFilter(pTitleBar);
    setWindowTitle(" ");
    setWindowIcon(QIcon(":/image/logothin.png"));

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(pTitleBar);
    pLayout->addStretch();
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(pLayout);

    ui->lab_password->setText(tr("please enter password"));
    ui->btn_ok->setText(tr("OK"));
    ui->btn_cancle->setText(tr("Cancle"));

    connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(onBtn_OKClick()));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::onBtn_OKClick()
{
    QString password = ui->lei_password->text();
    if (password == "wbxy1234")
    {

    }
    else
    {
        PasswordError * dialog = new PasswordError;
        int result = dialog->exec();

        if (result == QDialog::Accepted)
        {

        }
        else if (result == QDialog::Rejected)
        {

        }
    }
}
