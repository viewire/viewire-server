#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include "server.h"

const QColor DISABLED = QColor::fromRgb(255, 138, 130);
const QColor ENABLED = QColor::fromRgb(178, 255, 130);
Server* s;

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


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->label->setText("Server is Online.");
    this->ui->label->setStyleSheet("color: " + ENABLED.name());

    s = new Server;
    s->initSocket(7725);

    this->ui->pushButton_2->setEnabled(false);
    this->ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->label->setText("Server is Offline.");
    this->ui->label->setStyleSheet("color: " + DISABLED.name());
    delete s;

    this->ui->pushButton_2->setEnabled(true);
    this->ui->pushButton->setEnabled(false);
}
