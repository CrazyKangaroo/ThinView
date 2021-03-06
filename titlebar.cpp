#include "titlebar.h"
#include "ui_titlebar.h"
#include <QHBoxLayout>

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);

    UIInit();
    connect(pButtonClose, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::UIInit()
{
    setFixedHeight(30);

    pLabelIcon = new QLabel(this);
    pLabelTitle = new QLabel(this);
    pButtonClose = new QPushButton(this);

    pLabelIcon->setFixedSize(65, 15);
    pLabelIcon->setScaledContents(true);

    pLabelTitle->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    pButtonClose->setFixedSize(27, 22);
    pButtonClose->setFlat(true);

    QPalette palette;
    palette.setColor(QPalette::Background, QColor(50, 50, 50));
    setAutoFillBackground(true);
    setPalette(palette);

    QPalette fontPalette;
    fontPalette.setColor(QPalette::WindowText, Qt::white);
    pLabelTitle->setPalette(fontPalette);

    QHBoxLayout * pLayout = new QHBoxLayout(this);
    pLayout->addWidget(pLabelIcon);
    //pLayout->addSpacing(5);
    pLayout->addStretch();
    pLayout->addWidget(pLabelTitle);
    pLayout->addStretch();
    pLayout->addWidget(pButtonClose);
    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 0, 5, 0);
    setLayout(pLayout);
}

void TitleBar::onClicked()
{
    QPushButton * pButton = qobject_cast<QPushButton *>(sender());
    QWidget * pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == pButtonClose)
        {
            pWindow->close();
        }
    }
}

bool TitleBar::eventFilter(QObject *watched, QEvent *event)
{
    switch(event->type())
    {
        case QEvent::WindowTitleChange:
        {
            QWidget * pWidget = qobject_cast<QWidget *>(watched);
            if (pWidget)
            {
                pLabelTitle->setText(pWidget->windowTitle());
                return true;
            }
        }
        case QEvent::WindowIconChange:
        {
            QWidget * pWidget = qobject_cast<QWidget *>(watched);
            if (pWidget)
            {
                QIcon icon = pWidget->windowIcon();
                pLabelIcon->setPixmap(icon.pixmap(pLabelIcon->size()));
                return true;
            }
        }
    }

    return QWidget::eventFilter(watched, event);
}

void TitleBar::SetIconSize(int width, int height)
{
    pLabelIcon->setFixedSize(width, height);
}

void TitleBar::SetButtonSize(int width, int height)
{
    pButtonClose->setFixedSize(width, height);
}

void TitleBar::SetButtonIcon(QString filePath)
{
    pButtonClose->setIcon(QIcon(filePath));
    pButtonClose->setStyleSheet("QPushButton{border-image:url(" + filePath +");}"
                                "QPushButton:pressed{border-image:url(" + filePath + ");}");
}

void TitleBar::SetTitleBarWidth(int width, int height)
{
    this->resize(width, height);
}
