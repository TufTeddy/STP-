#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    contactsFile = new QFile(QCoreApplication::applicationDirPath() + "/contacts.csv");
    if (!contactsFile->open(QIODevice::ReadOnly)) {
        qDebug() << contactsFile->errorString();
        qDebug() << contactsFile->error();
    } else {
        QStringList wordList;
        while (!contactsFile->atEnd()) {
            QByteArray line = contactsFile->readLine();

            bool trig = false;
            for (int i = 0; i < line.length(); i++)
            {
                if ( (line[i] == ',') && (trig) )
                {
                    line.remove(i, 1);
                }
                else if ((line[i] == ',') && (!trig))
                {
                    trig = true;
                }
            }
            QList<QByteArray> fields = line.split(',');
            for (int idx = 0; idx < fields.size(); idx += 2) {
                QString record = QString("‘»Œ: %1\t“ÂÎ: %2").arg(QString(fields[idx])).arg(QString(fields[idx + 1]).trimmed());
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
/*
void MainWindow::on_changeButton_clicked()
{
    QString name = ui->nameField->text();
    QString phoneNumber = ui->nameField->text();
    if (!(name.isEmpty() || phoneNumber.isEmpty())) {
        book.change(name.toStdString(), phoneNumber.toStdString());
        QList<QListWidgetItem *> items = ui->contactList->findItems(QString("–§–ò–û: %1").arg(name), Qt::MatchStartsWith);
        if (!items.empty()) {
            items[0]->setText(QString("–§–ò–û: %1\t–¢–µ–ª: %2").arg(name).arg(phoneNumber));
            items.removeFirst();

            for (auto item: items) {
                ui->contactList->removeItemWidget(item);
                delete item;
            }
        }
        ui->nameField->clear();
        ui->numberField->clear();
    }
}*/

void MainWindow::on_changeButton_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->contactList->selectedItems();
    for (int idx = 0; idx < selectedItems.size(); ++idx) {
        QStringList fields = selectedItems[idx]->text().split('\t');
        QString name = fields[0];
        QString phoneNumber = fields[1];
        name.remove(0, 4);
        phoneNumber.remove(0, 4);


        nameLineEdit = new QLineEdit(name);
        phoneNumberLineEdit = new QLineEdit(phoneNumber);
        acceptChanges = new QPushButton("»ÁÏÂÌËÚ¸");
        decline = new QPushButton("ŒÚÏÂÌ‡");

        changeWidget = new QWidget();
        QVBoxLayout *vertLayout = new QVBoxLayout();
        QHBoxLayout *nameLayout = new QHBoxLayout();
        QHBoxLayout *phoneNumberLayout = new QHBoxLayout();
        nameLayout->addWidget(new QLabel("‘»Œ:"));
        nameLayout->addWidget(nameLineEdit);
        phoneNumberLayout->addWidget(new QLabel("“ÂÎÂÙÓÌÌ˚È ÌÓÏÂ:"));
        phoneNumberLayout->addWidget(phoneNumberLineEdit);
        vertLayout->addLayout(nameLayout);
        vertLayout->addLayout(phoneNumberLayout);
        vertLayout->addWidget(acceptChanges);
        vertLayout->addWidget(decline);

        connect(acceptChanges, &QPushButton::clicked, this, &MainWindow::acceptChangesSlot);
        connect(decline, &QPushButton::clicked, changeWidget, &QWidget::close);

        changeWidget->show();
    }
}

void MainWindow::on_addButton_clicked()
{
    QString name = ui->nameField->text();
    QString phoneNumber = ui->numberField->text();

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ',') name.remove(i, 1);
    }
    for (int i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] == ',') phoneNumber.remove(i, 1);
    }

    if (!(name.isEmpty() || phoneNumber.isEmpty())) {
        book.insert(name.toStdString(), phoneNumber.toStdString());
        ui->contactList->addItem(QString("‘»Œ: %1\t“ÂÎ: %2").arg(name).arg(phoneNumber));
        ui->nameField->clear();
        ui->numberField->clear();
    }
}

void MainWindow::acceptChangesSlot()
{
    QString name = nameLineEdit->text();
    QString phoneNumber = phoneNumberLineEdit->text();

    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == ',') name.remove(i, 1);
    }
    for (int i = 0; i < phoneNumber.length(); i++)
    {
        if (phoneNumber[i] == ',') phoneNumber.remove(i, 1);
    }


    changeWidget->setLayout(vertLayout);
    book.remove(fields[0].toStdString());
    ui->contactList->removeItemWidget(selectedItems[idx]);
    delete selectedItems[idx];
        
    book.insert(name.toStdString(), phoneNumber.toStdString());
    ui->contactList->addItem(QString("‘»Œ: %1\“ÂÎ: %2").arg(name).arg(phoneNumber));
}

