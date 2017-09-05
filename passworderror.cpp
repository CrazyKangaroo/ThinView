#include "passworderror.h"
#include "ui_passworderror.h"
#include "titlebar.h"
#include <QVBoxLayout>
#include <QDebug>

PasswordError::PasswordError(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordError)
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

    ui->label->setText(tr("Password error!"));
    //ui->label->move(this->width() / 2 - ui->label->width() / 2, (this->height() - pTitleBar->height())/ 2);
}

PasswordError::~PasswordError()
{
    delete ui;
}
