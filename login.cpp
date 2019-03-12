#include "login.h"
#include "ui_login.h"
#include "aboutbox.h"
#include "loginform.h"
#include "insertform.h"


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}


void login::on_pushButton_clicked()
{

  InsertForm *i = new InsertForm();
  i->show();
  this->close();

}

void login::on_action_Exit_triggered()
{
    QApplication::quit();
}

void login::on_pushButton_5_clicked()
{

    QApplication::quit();
}

void login::on_action_About_triggered()
{
    AboutBox about_box;
    about_box.show();
    about_box.exec();
}

void login::on_commandLinkButton_clicked()
{
    loginForm *im = new loginForm();
    im->show();
    this->close();
}

void login::on_pushButton_2_clicked()
{
    InsertForm *j = new InsertForm();
    j->show();
    this->close();
}

void login::on_pushButton_3_clicked()
{
    InsertForm *k = new InsertForm();
    k->show();
    this->close();
}

void login::on_pushButton_4_clicked()
{
     AboutBox m;
     m.show();
     m.exec();
}
