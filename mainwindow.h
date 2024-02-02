#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString read_version();
    QString getDivida();
    bool getDivida_IsHiden();
public slots:

    void ChangeModeLabel(QString name);


private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_b_deleteDB_clicked();

    void on_cont_all_clicked();

    void radio_change(bool);

    void radio_change1(bool);


private:
    Ui::MainWindow *ui;
    QString divida;
    QString Where_I_came_from;

};
#endif // MAINWINDOW_H
