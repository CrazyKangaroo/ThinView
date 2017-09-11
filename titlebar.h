#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    void SetIconSize(int width, int height);
    void SetButtonSize(int width, int height);
    void SetButtonIcon(QString filePath);
    void SetTitleBarWidth(int width, int height);
    ~TitleBar();
protected:
    virtual bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::TitleBar *ui;
    QLabel * pLabelIcon;
    QLabel * pLabelTitle;
    QPushButton * pButtonClose;
    void UIInit();
private slots:
    void onClicked();
};

#endif // TITLEBAR_H
