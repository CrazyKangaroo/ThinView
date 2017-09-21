#include "dialogtimer.h"
#include "ui_dialogtimer.h"

DialogTimer::DialogTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTimer)
{
    ui->setupUi(this);

    //this->setAttribute(Qt::WA_DeleteOnClose);
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
}

DialogTimer::~DialogTimer()
{
    delete ui;
}

void DialogTimer::SetInfo(QString info, unsigned int time)
{
    this->info = info;
    ui->label->setText(info + " " + QString::number(time));
}

void DialogTimer::SetTimer(unsigned int time)
{
    if (time < 0)
    {
        return;
    }

    this->time = time;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_TimeOut()));
    timer->start(1000);
}

void DialogTimer::slot_TimeOut()
{
    //qDebug()<<time;
    if (time > 0)
    {
        time--;
        ui->label->setText(info + " " + QString::number(time));
    }
    else
    {
        timer->stop();
    }
}
