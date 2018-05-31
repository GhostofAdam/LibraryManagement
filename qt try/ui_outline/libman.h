#include "logindialog.h"
#include "mainwindow.h"
#include "registerdialogr.h"
#include <QObject>
#include "configure.h"
#include "db.h"

#pragma once

class MainWindow;
class LoginDialog;

namespace libman{
class Mainmsg: public QObject{

};


void toLogin();
void toRegister();
void toMainWindow();
}
