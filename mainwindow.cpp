#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include "mediaserver.h"
// #include "httpserver.h"

const QColor DISABLED = QColor::fromRgb(255, 138, 130);
const QColor ENABLED = QColor::fromRgb(178, 255, 130);
MediaServer* s;
// httpserver* http_server;

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

    s = new MediaServer;
    s->initSocket(7725);

    // http_server= new httpserver;

    this->ui->pushButton_2->setEnabled(false);
    this->ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->label->setText("Server is Offline.");
    this->ui->label->setStyleSheet("color: " + DISABLED.name());
    delete s;
    // delete http_server;

    this->ui->pushButton_2->setEnabled(true);
    this->ui->pushButton->setEnabled(false);
}
