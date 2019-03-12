#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:

    explicit login(QWidget *parent = 0);
   ~login();

private slots:
    void on_pushButton_clicked();

    void on_action_Exit_triggered();

    void on_pushButton_5_clicked();

    void on_action_About_triggered();

    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
