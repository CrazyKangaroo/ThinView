#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
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
    //pLayout->setSpacing(0);
    pLayout->setContentsMargins(0, 0, 0, 0);
    pLayout->addLayout(ui->gridLayout);
    setLayout(pLayout);

    ui->btn_ok->setText(tr("OK"));
    ui->btn_cancle->setText(tr("Cancle"));

    connect(ui->btn_ok, SIGNAL(clicked(bool)), this, SLOT(onBtnOKClick()));
    connect(ui->btn_cancle, SIGNAL(clicked(bool)), this, SLOT(onBtnCancleClick()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::SetInfo(QString info)
{
    ui->label->setText(info);
}

void Dialog::onBtnOKClick()
{
    this->accept();
}

void Dialog::onBtnCancleClick()
{
    this->reject();
}
