#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "companyemployees.h"

#define DRIVER "QSQLITE"
#define DATABASE QStringLiteral("./database.db3")
#define HOST QString()
#define USERNAME QString()
#define PASSWORD QString()

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    CompanyEmployees db;
    Nut::Row<User> user;

private slots:
    void init();
    void createUser();
    void deleteUser(QString name);


    void on_pushButton_connect_clicked();

    void on_pushButton_create_clicked();

    void on_pushButton_3_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
