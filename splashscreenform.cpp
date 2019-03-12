#include "splashscreenform.h"
#include "ui_splashscreenform.h"
#include "login.h"

splashScreenForm::splashScreenForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::splashScreenForm)
{
    ui->setupUi(this);
}

splashScreenForm::~splashScreenForm()
{
    delete ui;
}

void splashScreenForm::on_pushButton_clicked()
{
        login *menu = new login();
        menu->show();
        this->close();
}
