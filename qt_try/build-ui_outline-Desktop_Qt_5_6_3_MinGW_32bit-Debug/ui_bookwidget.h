/********************************************************************************
** Form generated from reading UI file 'bookwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKWIDGET_H
#define UI_BOOKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookWidget
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *textBrowser;
    QLabel *label_3;
    QLabel *_author;
    QGraphicsView *graphicsView;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *_more;
    QLabel *_book;
    QLabel *_isbn;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTextBrowser *textBrowser_2;
    QLabel *label_7;
    QTextEdit *textEdit;
    QPushButton *pushButton_4;
    QWidget *tab_2;
    QLabel *label_8;
    QLabel *label_9;
    QGraphicsView *graphicsView_2;
    QLabel *_book_2;
    QLabel *_author_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *_more_2;
    QLabel *label_12;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_3;
    QLabel *_isbn_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QTextBrowser *textBrowser_4;

    void setupUi(QWidget *BookWidget)
    {
        if (BookWidget->objectName().isEmpty())
            BookWidget->setObjectName(QStringLiteral("BookWidget"));
        BookWidget->resize(800, 640);
        listWidget = new QListWidget(BookWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 140, 256, 471));
        label = new QLabel(BookWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 72, 15));
        lineEdit = new QLineEdit(BookWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 70, 113, 21));
        comboBox = new QComboBox(BookWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(190, 70, 87, 22));
        tabWidget = new QTabWidget(BookWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(350, 10, 451, 641));
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 190, 431, 101));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(240, 50, 72, 15));
        _author = new QLabel(tab);
        _author->setObjectName(QStringLiteral("_author"));
        _author->setGeometry(QRect(300, 90, 72, 15));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 191, 141));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 90, 72, 15));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(240, 130, 72, 15));
        _more = new QLabel(tab);
        _more->setObjectName(QStringLiteral("_more"));
        _more->setGeometry(QRect(300, 130, 72, 15));
        _book = new QLabel(tab);
        _book->setObjectName(QStringLiteral("_book"));
        _book->setGeometry(QRect(300, 10, 72, 15));
        _isbn = new QLabel(tab);
        _isbn->setObjectName(QStringLiteral("_isbn"));
        _isbn->setGeometry(QRect(300, 50, 72, 15));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 300, 93, 28));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 10, 72, 15));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 160, 72, 15));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(130, 300, 93, 28));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 300, 93, 28));
        textBrowser_2 = new QTextBrowser(tab);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 360, 421, 151));
        textBrowser_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 340, 72, 15));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 536, 321, 41));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 540, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 160, 72, 15));
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 10, 72, 15));
        graphicsView_2 = new QGraphicsView(tab_2);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(10, 10, 191, 141));
        _book_2 = new QLabel(tab_2);
        _book_2->setObjectName(QStringLiteral("_book_2"));
        _book_2->setGeometry(QRect(300, 10, 72, 15));
        _author_2 = new QLabel(tab_2);
        _author_2->setObjectName(QStringLiteral("_author_2"));
        _author_2->setGeometry(QRect(300, 90, 72, 15));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(240, 90, 72, 15));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 130, 72, 15));
        _more_2 = new QLabel(tab_2);
        _more_2->setObjectName(QStringLiteral("_more_2"));
        _more_2->setGeometry(QRect(300, 130, 72, 15));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(240, 50, 72, 15));
        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 300, 93, 28));
        textBrowser_3 = new QTextBrowser(tab_2);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 190, 431, 101));
        _isbn_2 = new QLabel(tab_2);
        _isbn_2->setObjectName(QStringLiteral("_isbn_2"));
        _isbn_2->setGeometry(QRect(300, 50, 72, 15));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 530, 261, 51));
        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(130, 300, 93, 28));
        pushButton_8 = new QPushButton(tab_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(250, 300, 93, 28));
        textBrowser_4 = new QTextBrowser(tab_2);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(10, 360, 421, 151));
        textBrowser_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(BookWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BookWidget);
    } // setupUi

    void retranslateUi(QWidget *BookWidget)
    {
        BookWidget->setWindowTitle(QApplication::translate("BookWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("BookWidget", "\346\220\234\347\264\242", Q_NULLPTR));
        label_3->setText(QApplication::translate("BookWidget", "ISBN", Q_NULLPTR));
        _author->setText(QApplication::translate("BookWidget", "\344\275\234\350\200\205", Q_NULLPTR));
        label_4->setText(QApplication::translate("BookWidget", "\344\275\234\350\200\205", Q_NULLPTR));
        label_5->setText(QApplication::translate("BookWidget", "more", Q_NULLPTR));
        _more->setText(QApplication::translate("BookWidget", "more", Q_NULLPTR));
        _book->setText(QApplication::translate("BookWidget", "TextLabel", Q_NULLPTR));
        _isbn->setText(QApplication::translate("BookWidget", "TextLabel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("BookWidget", "\351\242\204\347\272\246", Q_NULLPTR));
        label_2->setText(QApplication::translate("BookWidget", "\344\271\246\345\220\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("BookWidget", "\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("BookWidget", "\347\273\255\345\200\237", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("BookWidget", "\351\242\204\350\247\210", Q_NULLPTR));
        label_7->setText(QApplication::translate("BookWidget", "\350\257\204\350\256\272", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("BookWidget", " \345\217\221\351\200\201", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("BookWidget", "Tab 1", Q_NULLPTR));
        label_8->setText(QApplication::translate("BookWidget", " \344\275\215\347\275\256", Q_NULLPTR));
        label_9->setText(QApplication::translate("BookWidget", "\344\271\246\345\220\215", Q_NULLPTR));
        _book_2->setText(QApplication::translate("BookWidget", "TextLabel", Q_NULLPTR));
        _author_2->setText(QApplication::translate("BookWidget", "\344\275\234\350\200\205", Q_NULLPTR));
        label_10->setText(QApplication::translate("BookWidget", "\344\275\234\350\200\205", Q_NULLPTR));
        label_11->setText(QApplication::translate("BookWidget", "more", Q_NULLPTR));
        _more_2->setText(QApplication::translate("BookWidget", "more", Q_NULLPTR));
        label_12->setText(QApplication::translate("BookWidget", "ISBN", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("BookWidget", "\344\277\256\346\224\271", Q_NULLPTR));
        _isbn_2->setText(QApplication::translate("BookWidget", "TextLabel", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("BookWidget", "  \345\242\236\345\212\240 \346\226\260\344\271\246", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("BookWidget", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("BookWidget", "\345\200\237\351\230\205 \350\256\260\345\275\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("BookWidget", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BookWidget: public Ui_BookWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKWIDGET_H
