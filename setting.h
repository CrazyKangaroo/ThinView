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
    QLabel * pLab_note;
    QLabel * pLab_serverAddr;
    QLabel * pLab_port;
    QLineEdit * pLei_serverAddr;
    QLineEdit * pLei_port;
    QCheckBox * pCco_autoReslotion;
    QCheckBox * pCco_manualReslotion;
    QPushButton * pBtn_save;
};

#endif // SETTING_H
