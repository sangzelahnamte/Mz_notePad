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
    //ui->toolBar->setFixedHeight(50);
    font_box = new QFontComboBox(); // added to ui->toolBar parent
    fontSize_SB = new QSpinBox();
    ui->toolBar->addWidget(font_box);
    ui->toolBar->addWidget(fontSize_SB);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionBold);
    ui->toolBar->addAction(ui->actionItalix);
    ui->toolBar->addAction(ui->actionUnderline);
    ui->toolBar->addAction(ui->actionStrikeout);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionAlign_center);
    ui->toolBar->addAction(ui->actionAlign_Left);
    ui->toolBar->addAction(ui->actionAlign_right);
    ui->toolBar->addAction(ui->actionAlign_justify);
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

void MainWindow::on_actionBold_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.bold() ? font.setBold(false) : font.setBold(true);
    ui->textEdit->setCurrentFont(font);
}

void MainWindow::on_actionItalix_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.italic() ? font.setItalic(false) : font.setItalic(true);
    ui->textEdit->setCurrentFont(font);
}

void MainWindow::on_actionUnderline_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.underline() ? font.setUnderline(false) : font.setUnderline(true);
    ui->textEdit->setCurrentFont(font);
}

void MainWindow::on_actionStrikeout_triggered()
{
    QFont font = ui->textEdit->currentFont();
    font.strikeOut() ? font.setStrikeOut(false) : font.setStrikeOut(true);
    ui->textEdit->setCurrentFont(font);
}
// Align center
void MainWindow::on_actionAlign_center_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
// Align left
void MainWindow::on_actionAlign_Left_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}
// Align right
void MainWindow::on_actionAlign_right_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}
// Align justify
void MainWindow::on_actionAlign_justify_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}

