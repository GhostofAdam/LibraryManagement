/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *label;
    QLineEdit *account;
    QLineEdit *password;
    QLineEdit *passwordaffirm;
    QLineEdit *schoolID;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *sex;
    QLineEdit *department;
    QLabel *label_7;
    QLineEdit *major;
    QLabel *label_8;
    QLineEdit *name;
    QLabel *label_9;
    QPushButton *ok;
    QPushButton *pushButton_2;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(480, 514);
        label = new QLabel(RegisterDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 72, 15));
        account = new QLineEdit(RegisterDialog);
        account->setObjectName(QStringLiteral("account"));
        account->setGeometry(QRect(130, 70, 113, 21));
        password = new QLineEdit(RegisterDialog);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(130, 130, 113, 21));
        password->setEchoMode(QLineEdit::Password);
        passwordaffirm = new QLineEdit(RegisterDialog);
        passwordaffirm->setObjectName(QStringLiteral("passwordaffirm"));
        passwordaffirm->setGeometry(QRect(130, 190, 113, 21));
        passwordaffirm->setEchoMode(QLineEdit::Password);
        schoolID = new QLineEdit(RegisterDialog);
        schoolID->setObjectName(QStringLiteral("schoolID"));
        schoolID->setGeometry(QRect(130, 310, 113, 21));
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 72, 15));
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 72, 15));
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 190, 72, 15));
        label_5 = new QLabel(RegisterDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 250, 72, 15));
        label_6 = new QLabel(RegisterDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 310, 72, 15));
        sex = new QComboBox(RegisterDialog);
        sex->setObjectName(QStringLiteral("sex"));
        sex->setGeometry(QRect(130, 250, 111, 22));
        department = new QLineEdit(RegisterDialog);
        department->setObjectName(QStringLiteral("department"));
        department->setGeometry(QRect(130, 370, 113, 21));
        label_7 = new QLabel(RegisterDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 370, 72, 15));
        major = new QLineEdit(RegisterDialog);
        major->setObjectName(QStringLiteral("major"));
        major->setGeometry(QRect(130, 420, 113, 21));
        label_8 = new QLabel(RegisterDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 420, 72, 15));
        name = new QLineEdit(RegisterDialog);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(130, 470, 113, 21));
        label_9 = new QLabel(RegisterDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 470, 72, 15));
        ok = new QPushButton(RegisterDialog);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(330, 210, 93, 28));
        pushButton_2 = new QPushButton(RegisterDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 250, 93, 28));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterDialog", "*\350\264\246\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterDialog", "*\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterDialog", "*\345\257\206\347\240\201\347\241\256\350\256\244", Q_NULLPTR));
        label_5->setText(QApplication::translate("RegisterDialog", "\346\200\247\345\210\253", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterDialog", "*\345\255\246\345\217\267", Q_NULLPTR));
        sex->clear();
        sex->insertItems(0, QStringList()
         << QApplication::translate("RegisterDialog", "\346\234\252\347\237\245", Q_NULLPTR)
         << QApplication::translate("RegisterDialog", "\347\224\267", Q_NULLPTR)
         << QApplication::translate("RegisterDialog", "\345\245\263", Q_NULLPTR)
        );
        department->setText(QString());
        label_7->setText(QApplication::translate("RegisterDialog", "\351\231\242\347\263\273", Q_NULLPTR));
        label_8->setText(QApplication::translate("RegisterDialog", "\344\270\223\344\270\232", Q_NULLPTR));
        name->setText(QString());
        label_9->setText(QApplication::translate("RegisterDialog", "\345\247\223\345\220\215", Q_NULLPTR));
        ok->setText(QApplication::translate("RegisterDialog", "\346\217\220\344\272\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("RegisterDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
