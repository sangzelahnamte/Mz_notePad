#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_widget();
    setup_connections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_widget()
{
    this->setCentralWidget(ui->textEdit);
    // Tool Box
    font_box = new QFontComboBox(); // added to ui->toolBar parent
    fontSize_SB = new QSpinBox();
    ui->toolBar->addWidget(font_box);
    ui->toolBar->addWidget(fontSize_SB);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionColour);
    color_dialog = new QColorDialog(this);
}

void MainWindow::on_actionColour_triggered()
{
    color_dialog->exec();
}

void MainWindow::setup_connections()
{
    // Undo Redo
    connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);
    // Cut copy paste select all
    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);
    connect(ui->actionSelect_All, &QAction::triggered, ui->textEdit, &QTextEdit::selectAll);
}













