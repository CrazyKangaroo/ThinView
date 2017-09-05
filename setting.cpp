#include "setting.h"
#include "ui_setting.h"
#include "customtabstyle.h"
#include "titlebar.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    TitleBar * pTitleBar = new TitleBar(this);
    pTitleBar->SetButtonSize(10, 8);
    pTitleBar->SetTitleBarWidth(800, 600);
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

    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
}

Setting::~Setting()
{
    delete ui;
}
