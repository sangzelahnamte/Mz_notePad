#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_widget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_widget()
{
    this->setCentralWidget(ui->textEdit);
    font_box = new QFontComboBox(); // added to ui->toolBar parent
    fontSize_SB = new QSpinBox();
    ui->toolBar->addWidget(font_box);
    ui->toolBar->addWidget(fontSize_SB);
}
