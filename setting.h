#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

private:
    Ui::Setting *ui;
    void UIInit();
public slots:
    void slot_CloseWindow();
};

#endif // SETTING_H
