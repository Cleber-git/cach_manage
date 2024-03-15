#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db_manage.h"
#include "form.h"
#include "form2.h"
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
    ct_a->show();
    ct_a->setHidden(true);

//    ui->radioButton_2->setChecked(true);
//    cont_all *ct_a = new cont_all();

    // conecting sinais and slots

    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString)) ,this, SLOT(ChangeModeLabel(QString)) );
    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(radio_change(bool)));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(radio_change1(bool)));

    connect(ui->radioButton, SIGNAL(clicked(bool)), this, SLOT(get_Name_Column(bool)));
    connect(ui->radioButton_2, SIGNAL(clicked(bool)), this, SLOT(get_Name_Column(bool)));

    connect(this, SIGNAL(send(QString)), ct_a, SLOT(ChangeSum(QString)));


    this->setWindowTitle("Banc Manage");
    QString version = read_version();
    ui->label_5->setText(version);
    ui->lineEdit->hide();
    ui->label_6->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    db_manage C_db;


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
    else if(ui->comboBox->currentText() == "Delete DataBase" ){
        b_deleteDB_clicked();
    }
    else if(ui->comboBox->currentText() == "Sum"){
        if(name_column!= 0){
            qDebug()<< "name: "<< name_column;

            emit send(name_column);
            cont_all_clicked();
        }
    }
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
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");

    QString path;
    path =  qApp->applicationDirPath() ;
    path +=  "/cach.db";
    if(ui->radioButton->isChecked()){
        C_db.Delete_db( path, db, "divida" );

    }else if(ui->radioButton_2->isChecked()){
        C_db.Delete_db( path, db, "gastos" );

    }
}

void MainWindow::cont_all_clicked()
{


    ct_a->setHidden(false);
    setHidden(true);
}




QString MainWindow::read_version(){

    QFile f(qApp->applicationDirPath() + "/version.txt");

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
//            int posy_button = ui->pushButton->geometry().y();
            int height_button = ui->pushButton->geometry().height();
            int width_button = ui->pushButton->geometry().width();

            //////////////////////////////////////////////////////

            ui->pushButton->setGeometry(posx_button, 480, width_button, height_button);

            ui->label_6->setHidden(false);
            ui->lineEdit->setHidden(false);

        }
}

void MainWindow::radio_change1(bool is_active){
        if(is_active){
            ui->label_6->hide();
            ui->lineEdit->hide();
            ui->pushButton->setGeometry(130, 430, 150, 51);
        }
}


void MainWindow::pushButton_2_clicked()
{
        hide();
        if(ui->radioButton_2->isChecked()){
            Form2 *form2 = new Form2();
            form2->show();
        }else if (ui->radioButton->isChecked()) {
            Form *form = new Form();
            form->show();

        }

}

void MainWindow::get_Name_Column(bool name){
        if(ui->radioButton->isChecked()){
           name_column ="dividas";
            return;
        }
        name_column=  "gastos";
}
