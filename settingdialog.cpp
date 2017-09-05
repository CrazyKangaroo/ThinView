#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QVBoxLayout>
#include <QPalette>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    pTitleBar = new TitleBar(this);
    pTitleBar->SetButtonSize(10, 8);
    pTitleBar->SetButtonIcon(":/image/close_set_22.png");
    installEventFilter(pTitleBar);
    setWindowTitle(" ");
    setWindowIcon(QIcon(":/image/logothin.png"));

    //QPalette palette;
    //palette.setColor(QPalette::Background, QColor(50, 50, 50));
    //setAutoFillBackground(true);
    //setPalette(palette);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(pTitleBar);
    pLayout->addStretch();
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(pLayout);

    setAttribute(Qt::WA_DeleteOnClose);
    ui->lab_password->setText(tr("please enter password"));
    ui->btn_ok->setText(tr("OK"));
    ui->btn_cancle->setText(tr("Cancle"));

}

SettingDialog::~SettingDialog()
{
    delete ui;
}
