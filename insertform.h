#ifndef INSERTFORM_H
#define INSERTFORM_H

#include <QWidget>

namespace Ui {
class InsertForm;
}

class InsertForm : public QWidget
{
    Q_OBJECT

public:
    explicit InsertForm(QWidget *parent = 0);
    ~InsertForm();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::InsertForm *ui;
};

#endif // INSERTFORM_H
