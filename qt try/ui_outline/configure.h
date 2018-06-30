#ifndef CONSTANT_H
#define CONSTANT_H
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QListWidget>
#include <QStackedWidget>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>

#define ADMINISTRATOR_NUM 0
#define USER_NUM 1

#define LOGINCHECK_SUCCESS_ADMINISTRATOR 3
#define LOGINCHECK_NOQUEST 1
#define LOGINCHECK_UNMATCH 2
#define LOGINCHECK_SUCCESS_READER 0

#define READER_DISABLE  0
#define BORROW_SUCCEED  1
#define SUBSCRIBE_SUCCEED    2
#define FAIL false
#define SUCCESS true

#define USER_TABLE 0
#define BUG qDebug() << "THERE'S A BUG!"
#endif // CONSTANT_H
