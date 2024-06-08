#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{

    ui->setupUi(this);
    this->setWindowTitle("Tabela Geral");

    C_db = new db_manage();
    db = C_db->getMDB();

/////////////////////////////////////////////////////////////////////////////////
    C_db->show_managerDivida(ui->tableWidget, db);

}


Form::~Form()
{
    delete ui;
    delete C_db;
}

void Form::on_pushButton_clicked()
{
    emit sendHideFromDivida();
    hide();
}

void Form::loadDbDivida(){


//    qDebug() << "Chamei loadDbDivida";

    C_db->show_managerDivida(ui->tableWidget, db);

}

