#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "query.h"
#include "tableset.h"
#include "tablemodel.h"
//#include "databasemodel.h"

#include "user.h"

void MainWindow::init()
{
    db.setDriver(DRIVER);
    db.setHostName(HOST);
    db.setDatabaseName(DATABASE);
    db.setUserName(USERNAME);
    db.setPassword(PASSWORD);
    bool ok = db.open();
    if (ok) {
        qDebug() << "Connected!";
    }
}

void MainWindow::createUser()
{
    user = Nut::create<User>();
    user->setUsername("admin");
    user->setPassword("123456");
    db.users()->append(user);
    db.saveChanges();
}

void MainWindow::deleteUser(QString name)
{
//    auto userToDelete = db.users()
//            ->query()
//            ->setWhere(User::username() == name)
//            .remove();
//    db.saveChanges();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connect_clicked()
{
    init();
}

void MainWindow::on_pushButton_create_clicked()
{
    createUser();
}
