#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFile>
#include <QMainWindow>
#include "addressbook.h"
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clearButton_clicked();

    void on_saveButton_clicked();

    void on_deleteButton_clicked();

    void on_changeButton_clicked();

    void on_addButton_clicked();

    void acceptChangesSlot();
private:
    Ui::MainWindow *ui;

    AddressBook book;
    QFile *contactsFile;
    QWidget *changeWidget;

    QLineEdit *nameLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QPushButton *acceptChanges;
    QPushButton *decline;
};

#endif // MAINWINDOW_H
