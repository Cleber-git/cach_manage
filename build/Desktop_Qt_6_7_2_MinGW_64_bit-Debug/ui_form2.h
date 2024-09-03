/********************************************************************************
** Form generated from reading UI file 'form2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM2_H
#define UI_FORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName("Form2");
        Form2->resize(579, 647);
        QFont font;
        font.setPointSize(22);
        Form2->setFont(font);
        Form2->setStyleSheet(QString::fromUtf8("background:transparent;"));
        tableWidget = new QTableWidget(Form2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(120, 120, 330, 441));
        tableWidget->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: #322886;"));
        label = new QLabel(Form2);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 30, 281, 71));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background: transparent ;\n"
"color: #322886 ;"));
        pushButton = new QPushButton(Form2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-30, 570, 101, 71));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 18px ;\n"
"background-color: #322886;\n"
"padding-left: 25px ;"));

        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QCoreApplication::translate("Form2", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form2", "Gerencie seus gastos", nullptr));
        pushButton->setText(QCoreApplication::translate("Form2", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM2_H
