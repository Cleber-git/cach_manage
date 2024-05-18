#include "form2.h"
#include "ui_form2.h"
#include "mainwindow.h"
#include "db_manage.h"
#include <QDebug>


Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
    this->setWindowTitle("Tabela Geral");

    C_db = new db_manage();
    db = C_db->getMDB();

    loadDbGasto();

}

Form2::~Form2()
{
    delete ui;
    delete C_db;
}

void Form2::on_pushButton_clicked()
{
    emit sendHide();
}

void Form2::loadDbGasto(){
    C_db->show_manager(ui->tableWidget, db);

}
