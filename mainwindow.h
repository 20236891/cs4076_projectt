#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ZorkUL.h"
#include <iostream>
#include <string>
using namespace std;
#include<QPushButton>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
//QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    ZorkUL temp;




private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void toggleResponseViews();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:

    QPushButton *push_button1;
        QPushButton *push_button2;
        QPushButton *push_button3;
        QPushButton *push_button4;
        QPushButton *push_button5;
        QPushButton *push_button6;
        QPushButton *push_button7;
        QPushButton *push_button8;
        QPushButton *push_button9;


};
#endif // MAINWINDOW_H
