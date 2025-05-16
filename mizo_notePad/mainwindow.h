#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontComboBox>
#include <QSpinBox>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionColour_triggered();

private:
    Ui::MainWindow *ui;
    QFontComboBox *font_box;
    QSpinBox *fontSize_SB; // font size spin box
    QColorDialog *color_dialog;

    void init_widget();
    void setup_connections();
};
#endif // MAINWINDOW_H
