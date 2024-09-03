#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_manage.h"
#include "form.h"
#include "cont_all.h"

#include <QFile>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->radioButton_2->setChecked(true);


    ct_a = new cont_all(this);
    ct_a->setHidden(true);
    form2 = new Form2(this);
    form = new Form(this);

    form2->hide();
    form->hide();

    connect(form2, SIGNAL(sendHide()), this, SLOT(showRefresh()));
    connect(form, SIGNAL(sendHideFromDivida()), this, SLOT(showRefresh()));






    ui->radioButton_2->setChecked(true);
//    cont_all *ct_a = new cont_all();

    // conecting sinais and slots

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)) ,this, SLOT(ChangeModeLabel(QString)) );
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(radio_change(bool)));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(radio_change1(bool)));

    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(set_Name_Column(bool)));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(set_Name_Column(bool)));




    this->setWindowTitle("Banc Manage");
    QString version = read_version();
    ui->label_5->setText(version);
    ui->lineEdit->hide();
    ui->label_6->hide();
    ui->label_5->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ct_a;
    delete form2;
    delete form;

}


void MainWindow::on_pushButton_clicked()
{



    qDebug()<<ui->lineEdit->text();

    QString preco = ui->valor->text();
    QString motivo = ui->motivo->text();
    QString divida = ui->lineEdit->text();



    if( !ui->motivo->text().isEmpty() && !ui->valor->text().isEmpty() && ui->lineEdit->isHidden() ){

        C_db.insert(preco, motivo);

    }else if( !ui->motivo->text().isEmpty() && !ui->valor->text().isEmpty() && !ui->lineEdit->isHidden() && !ui->lineEdit->text().isEmpty()){

        C_db.insertDivida(preco, motivo, divida);

    }
    ui->motivo->clear();
    ui->valor->clear();
    ui->lineEdit->clear();

    if (ui->comboBox->currentText() == "Show") {
        pushButton_2_clicked();

    }
    else if(ui->comboBox->currentText() == "Delete DataBase"){
        b_deleteDB_clicked();

    }
    else if(ui->comboBox->currentText() == "Sum"){
        if(name_column != ""){
            qDebug()<< "name: "<< name_column;
            ct_a->ChangeSum(name_column);
            cont_all_clicked();

        }
    }
    ui->valor->setFocus();
}

void MainWindow::ChangeModeLabel(QString name){
    qDebug()<< name;
    if(name != "Escolha" ){
        ui->valor->setEnabled(false);
        ui->motivo->setEnabled(false);
        return;
    }
    ui->valor->setEnabled(true);
    ui->motivo->setEnabled(true);

}





void MainWindow::b_deleteDB_clicked()
{
    db_manage C_db;
    QSqlDatabase db =  C_db.getMDB();
    QString path = C_db.getPath();
    if(ui->radioButton->isChecked()){
        C_db.Delete_db( path, db, "divida" );

    }else if(ui->radioButton_2->isChecked()){
        C_db.Delete_db( path, db, "gastos" );

    }
}

void MainWindow::cont_all_clicked()
{

    ct_a->show();
    moveForm(ct_a, 1500, 700);
}




QString MainWindow::read_version(){

    QFile f(qApp->applicationDirPath() + "/version");

    if(!f.open(QIODevice::ReadOnly)){
        qDebug() << "Erro ao tentar ler arquivo!";
        return "";
    }
    QTextStream read(&f);

    QString version = read.readAll();

    return version;
}

void MainWindow::radio_change(bool is_active){
    if(is_active){
            // get position of last widgets

            int posx_button = ui->pushButton->geometry().x();
            int height_button = ui->pushButton->geometry().height();
            int width_button = ui->pushButton->geometry().width();

            //////////////////////////////////////////////////////

            ui->pushButton->setGeometry(posx_button, 810, width_button, height_button);

            ui->label_6->setHidden(false);
            ui->lineEdit->setHidden(false);

        }
}

void MainWindow::radio_change1(bool is_active){
        if(is_active){
            ui->label_6->hide();
            ui->lineEdit->hide();
            ui->pushButton->setGeometry(830, 720, 281, 61);
        }
}


void MainWindow::pushButton_2_clicked()
{
        hideRefresh();
        if(ui->radioButton_2->isChecked()){
//            emit ShowDbGastos();
            form2->loadDbGasto();
            form2->show();

        }else if (ui->radioButton->isChecked()) {
            form->loadDbDivida();
            form->show();
            moveForm(form ,650, 200);
        }

}

void MainWindow::set_Name_Column( bool name ){

        if( ui->radioButton->isChecked() ){
            name_column ="dividas";
//            qDebug()<< "Nome da coluna: [ " <<  name_column << " ]";
            return;
        }
        name_column=  "gastos";
//        qDebug()<< "Nome da coluna: [ " <<  name_column << " ]";
}


void MainWindow::hideRefresh(){

        form2->move(650, 150);
        ui->comboBox->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEdit->hide();
        ui->motivo->hide();
        ui->valor->hide();
        ui->radioButton->hide();
        ui->radioButton_2->hide();
        ui->pushButton->hide();
}

void MainWindow::showRefresh( ){

        form2->hide();
        form->hide();
        ui->pushButton->move(830,720);
        ui->comboBox->show();
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        if(ui->radioButton->isChecked()){
            ui->label_6->show();
            ui->lineEdit->show();
            ui->pushButton->move(830,810);

        }
        ui->motivo->show();
        ui->valor->show();
        ui->radioButton->show();
        ui->radioButton_2->show();
        ui->pushButton->show();
}

void MainWindow::moveForm( QWidget *widget, int x, int y ){

        widget->move(x,y);

}

QString MainWindow::getNameColumn(){
        return name_column;
}










