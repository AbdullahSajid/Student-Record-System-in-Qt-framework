#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
