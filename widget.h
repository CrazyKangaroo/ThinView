#ifndef WIDGET_H
#define WIDGET_H

#define LINE_WIDTH 312
#define LABEL_HORIZONTAL_OFFSET 45
#define LAB_LOGO_VERTICAL_OFFSET 250
#define LAB_USERNAME_VERTICAL_OFFSET 55
#define LAB_PASSWORD_VERTICAL_OFFSET 15

#include <QWidget>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel * Lab_Logo;
    QLabel * Lab_userName;
    QLabel * Lab_passWord;
    Ui::Widget *ui;
};

#endif // WIDGET_H
