#ifndef SLASHSCREENFORM_H
#define SLASHSCREENFORM_H

#include <QWidget>

namespace Ui {
class slashScreenForm;
}

class slashScreenForm : public QWidget
{
    Q_OBJECT

public:
    explicit slashScreenForm(QWidget *parent = 0);
    ~slashScreenForm();

private:
    Ui::slashScreenForm *ui;
};

#endif // SLASHSCREENFORM_H
