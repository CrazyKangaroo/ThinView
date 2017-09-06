#include "setting.h"
#include "ui_setting.h"
#include "customtab.h"
#include "titlebar.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    TitleBar * pTitleBar = new TitleBar(this);
    pTitleBar->SetButtonSize(14, 12);
    pTitleBar->SetTitleBarWidth(500, 600);
    pTitleBar->SetIconSize(113, 26);
    pTitleBar->SetButtonIcon(":/image/close_set.png");
    installEventFilter(pTitleBar);
    setWindowTitle(tr("Configuration"));
    setWindowIcon(QIcon(":/image/logo.png"));
    CustomTab * pCustomTab = new CustomTab(this);

    QVBoxLayout * pLayout = new QVBoxLayout();
    pLayout->addWidget(pTitleBar);
    //pLayout->addStretch();
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->addWidget(pCustomTab);
    setLayout(pLayout);
}

Setting::~Setting()
{
    delete ui;
}
