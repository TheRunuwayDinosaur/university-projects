#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <words_analize.h>
#include <QMessageBox>
#include <numbers_analize.h>
#include <work_with_numbers.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_analize_clicked();

private:
    Ui::MainWindow *ui;
    words_analize *first_step;
    numbers_analize *second_step;
    work_with_numbers *third_step;
};
#endif // MAINWINDOW_H
