#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QTimer>

#define BASE_WIDTH  1920
#define BASE_HEIGHT  1080

#define LINE_WIDTH 312
#define LABEL_HORIZONTAL_OFFSET 45
#define LAB_LOGO_VERTICAL_OFFSET 250
#define LAB_USERNAME_VERTICAL_OFFSET 60
#define LAB_PASSWORD_VERTICAL_OFFSET 10

#define CCO_AUTOLOGIN_HORIZONTAL_OFFSET 30
#define CCO_PASSWORD_HORIZONTAL_OFFSET  140

#define CBO_USERNAME_HORIZONTAL_OFFSET  70
#define CBO_USERNAME_VERTICAL_OFFSET

#define CHECKBOX_VERTICAL_OFFSET    50

#define LEI_PASSWORD_HORIZONTAL_OFFSET  70

#define BTN_LOGIN_VERTICAL_OFFSET 60

#define BTN_DETAIL_HORIZONTAL_OFFSET   220
#define BTN_DETAIL_VERTICAL_OFFSET 70

#define BTN_SETTING_HORIZONTAL_OFFSET   160
#define BTN_SETTING_VERTICAL_OFFSET   70

#define BTN_SHUTDOWN_HORIZONTAL_OFFSET  60
#define BTN_SHUTDOWN_VERTICAL_OFFSET    70

#define LAB_TIME_HORIZONTAL_OFFSET  90
#define LAB_TIME_VERTICAL_OFFSET    30

#define FONT_SIZE   11
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
    QLabel * lab_time;
    QComboBox * cbo_userName;
    QLineEdit * lei_passWord;
    QCheckBox * cco_autoLogin;
    QCheckBox * cco_keepPassword;
    QPushButton * btn_login;
    QPushButton * btn_detail;
    QPushButton * btn_setting;
    QPushButton * btn_shutDown;
    QTimer * timer;
    Ui::Widget *ui;
    void AutoSize(QWidget * widget, int screenWidth, int screenHeight);
    void UIInit();
public slots:
    void slot_UpdateTime();
    void slot_BtnSettingClick();
};

#endif // WIDGET_H
