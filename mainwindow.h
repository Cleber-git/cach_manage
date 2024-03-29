#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QLineEdit>

#include "cont_all.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString name_column;

    QString read_version();
signals:
    void send(QString name);
public slots:

    void ChangeModeLabel(QString name);
    void pushButton_2_clicked();

    void b_deleteDB_clicked();

    void cont_all_clicked();
    void get_Name_Column(bool name);

private slots:

    void on_pushButton_clicked();


    void radio_change(bool);

    void radio_change1(bool);


private:
    Ui::MainWindow *ui;
    QString divida;

    cont_all * ct_a= new cont_all();

};
#endif // MAINWINDOW_H
