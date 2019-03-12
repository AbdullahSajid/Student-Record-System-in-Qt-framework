#ifndef SPLASHSCREENFORM_H
#define SPLASHSCREENFORM_H

#include <QWidget>

namespace Ui {
class splashScreenForm;
}

class splashScreenForm : public QWidget
{
    Q_OBJECT

public:
    explicit splashScreenForm(QWidget *parent = 0);
    ~splashScreenForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::splashScreenForm *ui;
};

#endif // SPLASHSCREENFORM_H
