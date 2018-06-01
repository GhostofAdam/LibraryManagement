/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *AccountEdit;
    QLineEdit *PasswordEdit;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *RegisterButton;
    QPushButton *LoginButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(400, 300);
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 72, 51));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 30, 72, 15));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(140, 70, 121, 20));
        AccountEdit = new QLineEdit(LoginDialog);
        AccountEdit->setObjectName(QStringLiteral("AccountEdit"));
        AccountEdit->setGeometry(QRect(120, 110, 171, 21));
        PasswordEdit = new QLineEdit(LoginDialog);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(120, 170, 171, 21));
        PasswordEdit->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(LoginDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 72, 15));
        label_5 = new QLabel(LoginDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 170, 72, 15));
        RegisterButton = new QPushButton(LoginDialog);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        RegisterButton->setGeometry(QRect(80, 240, 93, 28));
        LoginButton = new QPushButton(LoginDialog);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        LoginButton->setGeometry(QRect(180, 240, 93, 28));
        CancelButton = new QPushButton(LoginDialog);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(290, 240, 93, 28));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("LoginDialog", "LOGO", Q_NULLPTR));
        label_2->setText(QApplication::translate("LoginDialog", "HEADLINE", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225\347\231\273\345\207\272\347\263\273\347\273\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("LoginDialog", "\350\264\246\345\217\267", Q_NULLPTR));
        label_5->setText(QApplication::translate("LoginDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        RegisterButton->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("LoginDialog", "\347\231\273\345\275\225", Q_NULLPTR));
        CancelButton->setText(QApplication::translate("LoginDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
