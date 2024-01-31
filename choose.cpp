#include "choose.h"
#include "ui_choose.h"
#include "form.h"
#include "form2.h"

choose::choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
}

choose::~choose()
{
    delete ui;
}

void choose::on_pushButton_clicked()
{
    hide();
    Form2 *form2 = new Form2();

    form2->show();
}


void choose::on_pushButton_2_clicked()
{
    hide();
    Form *form = new Form();

    form->show();
}

