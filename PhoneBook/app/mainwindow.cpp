#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    contactsFile = new QFile("/home/fnick/Repos/ModernProgramming/PhoneBook/app/res/contacts.csv");
    if (!contactsFile->open(QIODevice::ReadOnly)) {
        qDebug() << contactsFile->errorString();
        qDebug() << contactsFile->error();
    } else {
        QStringList wordList;
        while (!contactsFile->atEnd()) {
            QByteArray line = contactsFile->readLine();
            QList<QByteArray> fields = line.split(',');
            for (int idx = 0; idx < fields.size(); idx += 2) {
                QString record = QString("ФИО: %1\tТел: %2").arg(QString(fields[idx])).arg(QString(fields[idx + 1]).trimmed());
                book.insert(fields[idx].toStdString(), fields[idx + 1].toStdString());
                ui->contactList->addItem(record);
            }
        }
        contactsFile->close();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clearButton_clicked()
{
    ui->contactList->clear();
    book.clear();
}

void MainWindow::on_saveButton_clicked()
{
    if (!contactsFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << contactsFile->errorString();
        qDebug() << contactsFile->error();
    } else {
        for (int idx = 0; idx < ui->contactList->count(); ++idx) {
            QListWidgetItem *item = ui->contactList->item(idx);
            QStringList fields = item->text().split('\t');
            contactsFile->write(QString("%1,%2\n").arg(fields[0].mid(5)).arg(fields[1].mid(5)).toUtf8());
        }
        contactsFile->close();
    }
}

void MainWindow::on_deleteButton_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->contactList->selectedItems();
    for (int idx = 0; idx < selectedItems.size(); ++idx) {
        QStringList fields = selectedItems[idx]->text().split('\t');
        book.remove(fields[0].toStdString());
        ui->contactList->removeItemWidget(selectedItems[idx]);
        delete selectedItems[idx];
    }
}

void MainWindow::on_changeButton_clicked()
{
    QString name = ui->nameField->text();
    QString phoneNumber = ui->nameField->text();
    if (!(name.isEmpty() || phoneNumber.isEmpty())) {
        book.change(name.toStdString(), phoneNumber.toStdString());
        QList<QListWidgetItem *> items = ui->contactList->findItems(QString("ФИО: %1").arg(name), Qt::MatchStartsWith);
        if (!items.empty()) {
            items[0]->setText(QString("ФИО: %1\tТел: %2").arg(name).arg(phoneNumber));
            items.removeFirst();

            for (auto item: items) {
                ui->contactList->removeItemWidget(item);
                delete item;
            }
        }
        ui->nameField->clear();
        ui->numberField->clear();
    }
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameField->text();
    QString phoneNumber = ui->numberField->text();
    if (!(name.isEmpty() || phoneNumber.isEmpty())) {
        book.insert(name.toStdString(), phoneNumber.toStdString());
        ui->contactList->addItem(QString("ФИО: %1\tТел: %2").arg(name).arg(phoneNumber));
        ui->nameField->clear();
        ui->numberField->clear();
    }
}
