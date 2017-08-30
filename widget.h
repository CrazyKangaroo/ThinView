#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>

#define LINE_WIDTH 312
#define LABEL_HORIZONTAL_OFFSET 45
#define LAB_LOGO_VERTICAL_OFFSET 250
#define LAB_USERNAME_VERTICAL_OFFSET 60
#define LAB_PASSWORD_VERTICAL_OFFSET 10

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
    QLabel * lab_logo;
    QLabel * lab_userName;
    QLabel * lab_passWord;
    QComboBox * cbo_userName;
    QLineEdit * lei_password;
    Ui::Widget *ui;
};

#endif // WIDGET_H
