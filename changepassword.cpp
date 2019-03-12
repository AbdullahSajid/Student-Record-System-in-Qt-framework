#include "changepassword.h"
#include "ui_changepassword.h"
#include <QMessageBox>
#include "loginform.h"
#include <stdio.h>
#include <QErrorMessage>
#include <exception>
#include "sqlite3.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
}

ChangePassword::~ChangePassword()
{
    delete ui;
}

void ChangePassword::on_pushButton_clicked()
{
    try
        {
        bool m,n=false;
        sqlite3 * connection = nullptr;

           int result = sqlite3_open("C:\\Users\\Mehar Abdullah\\Sqlite\\login.db", &connection);

           if (SQLITE_OK != result)
           {
              throw sqlite3_errmsg(connection);
              printf("%s\n", sqlite3_errmsg(connection));
              sqlite3_close(connection);

           }

           sqlite3_stmt * query = nullptr;

//           result = sqlite3_prepare_v2(connection, "create table Users(username text primary key Not Null,password text Not Null)", -1, &query, nullptr);

//          if (SQLITE_OK != result)
//          {
//               throw sqlite3_errmsg(connection);
//              printf("%s\n", sqlite3_errmsg(connection));
//              sqlite3_close(connection);

//           }
//           sqlite3_step(query);
//           sqlite3_finalize(query);
      QString username = ui->username_textField->text();
      QByteArray a = username.toUtf8();
      const char* c = a.constData();
      QString password = ui->oldPassword_Field->text();
      QByteArray b = password.toUtf8();
      const char* d = b.constData();
      QString newpassword = ui->newPassword_Field->text();
      QByteArray p = newpassword.toUtf8();
     // const char* k = p.constData();
//       result = sqlite3_prepare_v2(connection, "Insert into Users(username,password) Values(?,?)", -1, &query, nullptr);
    //  sqlite3_bind_text(query,1,a,-1,SQLITE_STATIC);
     // sqlite3_bind_text(query,2,b,-1,SQLITE_STATIC);
        if(username.isEmpty()==true||password.isEmpty()==true||newpassword.isEmpty()==true) {
             throw "Any field should not be empty";

        }
//      if (SQLITE_OK != result)
//         {
//               throw sqlite3_errmsg(connection);
//              printf("%s\n", sqlite3_errmsg(connection));
//              sqlite3_close(connection);

//         }
//          sqlite3_step(query);
//          sqlite3_finalize(query);
           result = sqlite3_prepare_v2(connection, "Select * from Users", -1, &query, nullptr);
           while (SQLITE_ROW == sqlite3_step(query))
           {
               //printf("%s\n%s\n",sqlite3_column_text(query, 0),sqlite3_column_text(query, 1));
             const char* e =(const char*)sqlite3_column_text(query, 0);
             const char* f = (const char*)sqlite3_column_text(query, 1);
             if(strcmp(c,e)==0)
          {
               m=true;
               if(strcmp(d,f)==0){
                   n=true;
                   break;
               }
          }
           }
if(m==true&&n==true){

             sqlite3_finalize(query);
             result = sqlite3_prepare_v2(connection, "Update Users set password = ?1 where username = ?2 ", -1, &query, nullptr);
              sqlite3_bind_text(query,1,p,-1,SQLITE_STATIC);
              sqlite3_bind_text(query,2,a,-1,SQLITE_STATIC);
              if (SQLITE_OK != result)
                      {
                        throw sqlite3_errmsg(connection);
                        printf("%s\n", sqlite3_errmsg(connection));
                        sqlite3_close(connection);

                      }
              else{
                  if (QMessageBox::Yes == QMessageBox(QMessageBox::Question, "Confirm Change", "Would you like to change password", QMessageBox::Yes|QMessageBox::No).exec())
                  {
                  sqlite3_step(query);
                  }
              }

             sqlite3_finalize(query);
             sqlite3_close(connection);

           loginForm *lf = new loginForm();
            lf->show();
            this->close();
 }
          else{
           sqlite3_finalize(query);
           sqlite3_close(connection);
           throw "Invalid username and password";
}
        }
        catch (const char* e)
        {
            QErrorMessage msg(this);
            msg.showMessage(e);
            msg.exec();
        }

}

void ChangePassword::on_pushButton_2_clicked()
{
    loginForm *lf = new loginForm();
     lf->show();
     this->close();
}
