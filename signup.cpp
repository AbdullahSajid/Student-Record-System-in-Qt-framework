#include "signup.h"
#include "ui_signup.h"
#include "loginform.h"
#include <QMessageBox>
#include "loginform.h"
#include <stdio.h>
#include <QErrorMessage>
#include <exception>
#include "sqlite3.h"

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_pushButton_clicked()
{
    try
    {
        bool m,n = false;
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
        QString password = ui->password_textField->text();
        QByteArray b = password.toUtf8();
        const char* d = b.constData();
        // QString email = ui->email_textfield->text();
        // QByteArray p = newpassword.toUtf8();
        // const char* k = p.constData();
//         result = sqlite3_prepare_v2(connection, "Insert into Users(username,password) Values(?,?)", -1, &query, nullptr);
//         sqlite3_bind_text(query,1,a,-1,SQLITE_STATIC);
//         sqlite3_bind_text(query,2,b,-1,SQLITE_STATIC);
        if(username.isEmpty()==true||password.isEmpty()==true) {
            sqlite3_close(connection);
            throw "Username and Password must not be empty";

        }
//              if (SQLITE_OK != result)
//                 {
//                      throw sqlite3_errmsg(connection);
//                      printf("%s\n", sqlite3_errmsg(connection));
//                      sqlite3_close(connection);

//                 }
//                 sqlite3_step(query);
//                 sqlite3_finalize(query);
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
        if(m==false&&n==false){

            sqlite3_finalize(query);
            result = sqlite3_prepare_v2(connection, "Insert into Users(username,password) Values(?,?)", -1, &query, nullptr);
            sqlite3_bind_text(query,1,a,-1,SQLITE_STATIC);
            sqlite3_bind_text(query,2,b,-1,SQLITE_STATIC);
            if (SQLITE_OK != result)
            {

                sqlite3_close(connection);
                throw sqlite3_errmsg(connection);
            }
            else{
                sqlite3_step(query);
                sqlite3_finalize(query);
                sqlite3_close(connection);
                loginForm *lg = new loginForm();
                lg->show();
                this->close();
            }

         }
        else{
            sqlite3_finalize(query);
            sqlite3_close(connection);
            throw "Username or Password combination already exists";
        }
    }
    catch (const char* e)
    {
        QErrorMessage msg(this);
        msg.showMessage(e);
        msg.exec();
    }

}
