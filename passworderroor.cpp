#include "passworderroor.h"
#include "ui_passworderroor.h"

PasswordErroor::PasswordErroor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordErroor)
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
    ui->label->move(this->width() / 2, this->height() / 2);
}

PasswordErroor::~PasswordErroor()
{
    delete ui;
}
