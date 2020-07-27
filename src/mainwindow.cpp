#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "query.h"
#include "tableset.h"
#include "tablemodel.h"
//#include "databasemodel.h"

#include "user.h"

#include <QMessageBox>

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
    auto count = db.saveChanges();

    if (count)
        QMessageBox::information(this, "Create user", "User created successfully");
}

void MainWindow::deleteUser(QString name)
{
    auto userToDelete = db.users()
            ->query()
            ->setWhere(User::usernameField() == name)
            ->remove();
    db.saveChanges();

    if (userToDelete)
        QMessageBox::information(this, "Create user", "User deleted successfully");
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<User*>();
    qRegisterMetaType<CompanyEmployees*>();
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

void MainWindow::on_pushButton_3_clicked()
{
    deleteUser("admin");
}
