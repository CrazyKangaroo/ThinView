#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>

#define LINE_WIDTH 312
#define LABEL_HORIZONTAL_OFFSET 45
#define LAB_LOGO_VERTICAL_OFFSET 250
#define LAB_USERNAME_VERTICAL_OFFSET 60
#define LAB_PASSWORD_VERTICAL_OFFSET 10

#define CCO_AUTOLOGIN_HORIZONTAL_OFFSET 30
#define CCO_PASSWORD_HORIZONTAL_OFFSET  140
#define CHECKBOX_VERTICAL_OFFSET    50

#define LAB_AUTOLOGIN_HORIZONTAL_OFFSET 20
#define LAB_KEEPPASSWORD_HORIZONTAL_OFFSET 20

#define BTN_LOGIN_VERTICAL_OFFSET 60

#define BTN_DETAIL_HORIZONTAL_OFFSET   220
#define BTN_DETAIL_VERTICAL_OFFSET 70

#define BTN_SETTING_HORIZONTAL_OFFSET   160

#define BTN_SHUTDOWN_HORIZONTAL_OFFSET  60
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
    QLineEdit * lei_passWord;
    QCheckBox * cco_autoLogin;
    QCheckBox * cco_keepPassword;
    QLabel * lab_autoLogin;
    QLabel * lab_keepPassword;
    QPushButton * btn_login;
    QPushButton * btn_detail;
    QPushButton * btn_setting;
    QPushButton * btn_shutDown;
    Ui::Widget *ui;
};

#endif // WIDGET_H
