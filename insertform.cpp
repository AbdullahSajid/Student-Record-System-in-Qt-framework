#include "insertform.h"
#include "ui_insertform.h"
#include "login.h"
#include "List.h"
#include <exception>
#include <QErrorMessage>
#include <QMessageBox>

List wt;
InsertForm::InsertForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertForm)
{
    ui->setupUi(this);
}

InsertForm::~InsertForm()
{
    delete ui;
}

void InsertForm::on_commandLinkButton_clicked()
{
    login *e = new login();
    e->show();
    this->close();
}

void InsertForm::on_pushButton_clicked()
{
    try{

        QString a = ui->rollNoField->text();
        bool ok;
        int m = a.toInt(&ok);
        if(!ok){
            throw "Roll No. must be an integer";
        }
        if(m<=0||m>5000){
            throw "Roll No. must be between 0 to 5000";
        }
        QString b = ui->studentNameField->text();
        string s = b.toStdString();
        QString c = ui->fatherNameField->text();
        string t = c.toStdString();
        QString d = ui->departmentNameField->text();
        string k = d.toStdString();
        QString e = ui->semesterField->text();
        string w= e.toStdString();
        QString f = ui->gradeField->text();
        string x = f.toStdString();
        QString g = ui->dateField->text();
        string v = g.toStdString();
        if(a.isEmpty()==true||b.isEmpty()||c.isEmpty()==true||d.isEmpty()==true||e.isEmpty()==true||f.isEmpty()==true||g.isEmpty()==true){
            throw "Any Field must not be empty";
        }
        float z = f.toFloat(&ok);
        if(!ok){
            throw "Grade must be of type float";
        }
        if(z>4.0||z<0.0){
            throw "Grade(CGPA) must be less than 4 and greater than 0";
        }
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Confirm Insertion", "Do you want to insert record", QMessageBox::Yes|QMessageBox::No).exec())
        {
         wt.InsertNode(m,s,t,k,w,x,v);
        }
        ui->rollNoField->clear();
        ui->studentNameField->clear();
        ui->fatherNameField->clear();
        ui->semesterField->clear();
        ui->gradeField->clear();
        ui->departmentNameField->clear();
    }
    catch (const char* e)
    {
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}

void InsertForm::on_pushButton_3_clicked()
{
    try{

        QString a = ui->rollNoField->text();
        bool ok;
        int m = a.toInt(&ok);
        if(!ok){
            throw "Roll No. must be an integer";
        }


        if(a.isEmpty()==true){
            throw "Any Field must not be empty";
        }
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Confirm Deletion", "Do you want to delete record against this Student Id", QMessageBox::Yes|QMessageBox::No).exec())
        {
         wt.DeleteNode(m);
        }
        ui->rollNoField->clear();
        ui->studentNameField->clear();
        ui->fatherNameField->clear();
        ui->semesterField->clear();
        ui->gradeField->clear();
        ui->departmentNameField->clear();
    }
    catch (const char* e)
    {
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}

void InsertForm::on_pushButton_2_clicked()
{
    try{

        QString a = ui->rollNoField->text();
        bool ok;
        int m = a.toInt(&ok);
        if(!ok){
            throw "Roll No. must be an integer";
        }
        QString b = ui->studentNameField->text();
        string s = b.toStdString();
        QString c = ui->fatherNameField->text();
        string t = c.toStdString();
        QString d = ui->departmentNameField->text();
        string k = d.toStdString();
        QString e = ui->semesterField->text();
        string w= e.toStdString();
        QString f = ui->gradeField->text();
        string x = f.toStdString();
        QString g = ui->dateField->text();
        string v = g.toStdString();
        if(a.isEmpty()==true){
            throw "Any Field must not be empty";
        }


        if(f.isEmpty()!=true){
            float z = f.toFloat(&ok);
            if(!ok){
                throw "Grade must be of type float";
            }
            if(z>4||z<0)
            throw "Grade(CGPA) must be less than 4 and greater than 0";
        }

        if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Confirm Updation", "Do you want to update record", QMessageBox::Yes|QMessageBox::No).exec())
        {
         wt.UpdateNode(m,s,t,k,w,x,v);
        }
        ui->rollNoField->clear();
        ui->studentNameField->clear();
        ui->fatherNameField->clear();
        ui->semesterField->clear();
        ui->gradeField->clear();
        ui->departmentNameField->clear();
    }
    catch (const char* e)
    {
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}

void InsertForm::on_pushButton_5_clicked()
{
    try{
    wt.PrintList();
    }
    catch(const char* e){
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}

void InsertForm::on_pushButton_6_clicked()
{
    try{
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Confirm Sorting", "Do you want to sort according to Student Id", QMessageBox::Yes|QMessageBox::No).exec())
        {
          wt.AscendingSort();
        }
        ui->rollNoField->clear();
        ui->studentNameField->clear();
        ui->fatherNameField->clear();
        ui->semesterField->clear();
        ui->gradeField->clear();
        ui->departmentNameField->clear();


    }
    catch(const char* e){
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}

void InsertForm::on_pushButton_4_clicked()
{
    try{
        QString a = ui->rollNoField->text();
        bool ok;
        int m = a.toInt(&ok);
        if(!ok){
            throw "Roll No. must be an integer";
        }
        if(a.isEmpty()==true){
            throw "Any Field must not be empty";
        }
        wt.searchElement(m);
        ui->rollNoField->clear();
        ui->studentNameField->clear();
        ui->fatherNameField->clear();
        ui->semesterField->clear();
        ui->gradeField->clear();
        ui->departmentNameField->clear();
    }
    catch(const char* e){
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }
}
