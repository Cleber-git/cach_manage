#include "dialog.h"
#include "ui_dialog.h"
#include "cont_all.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    emit sendModeSum("gastos");
    cont_all* ct_a = new cont_all();
    ct_a->show();
    hide();
}


void Dialog::on_pushButton_2_clicked()
{
    emit sendModeSum("divida");
    cont_all* ct_a = new cont_all();
    ct_a->show();
    hide();
}

