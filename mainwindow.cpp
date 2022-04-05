#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    temp.createRooms();
    temp.createPlayer();

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setFontPointSize(16);

    QString style = "QMainWindow {background-color: green;}";
    this->setStyleSheet(style);

    ui->textEdit->insertPlainText(QString::fromStdString(temp.printWelcome()));


    if(temp.getCurrentRoom()->getDescription() != "nine") {

    ui->lineEdit->hide();
    ui->pushButton_9->hide();

  }

else{
   ui->lineEdit->show();
   ui->pushButton_9->show();
        }

   ui->textEdit_2->setPlainText(QString::number(temp.me.getHealth()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete push_button1;
    delete push_button2;
    delete  push_button3;
    delete push_button4;
    delete push_button5;
    delete push_button6;
    delete push_button7;
    delete push_button8;
    delete push_button9;



}

void MainWindow::toggleResponseViews(){

    if(temp.getCurrentRoom()->getDescription() != "nine") {
        ui->lineEdit->hide();
        ui->pushButton_9->hide();
    }
    else{
        ui->lineEdit->show();
        ui->pushButton_9->show();
    }

}


void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString::fromStdString(temp.map()));
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());


}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();


    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("north")));

    toggleResponseViews();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("east")));
    toggleResponseViews();

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("west")));
    toggleResponseViews();

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("south")));
    toggleResponseViews();

}

void MainWindow::on_pushButton_9_clicked()
{
    QString ans = ui->lineEdit->text();

    if (ans == "towel"){

        ui->textEdit->insertPlainText("Correct");
        temp.me.setHasAnswered(1);

    }

    else{

        ui->textEdit->insertPlainText("Incorrect");


        ui->textEdit->insertPlainText(QString::fromStdString(temp.quitFucntion()));
        ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());

        ui->pushButton_8->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);


    }
    toggleResponseViews();

}

void MainWindow::on_pushButton_7_clicked()

{

    if(temp.me.getHasAnswered() == 1 && temp.me.checkItemExistence<char>("key") == 0){


     QString text = ui->lineEdit_2->text();
     temp.setText(text);
     string text1 = temp.getText().toStdString();
     string take = "take";
     Command* itemTake = new Command(take,text1);
     ui->textEdit->insertPlainText(QString::fromStdString(temp.processCommand(*itemTake)));
     ui->textEdit_3->clear();
     ui->textEdit_3->insertPlainText("Inventory: ");
     ui->textEdit_3->insertPlainText(QString::fromStdString(temp.Inventory));
     ui->lineEdit_2->clear();
     ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
}
    else{
        ui->textEdit->insertPlainText("Go answer the riddle before taking the key");

    }

}

void MainWindow::on_pushButton_8_clicked()
{

    if(temp.getCurrentRoom()->getDescription() == "five" && temp.me.getHasAnswered() == 1 && temp.me.checkItemExistence<char>("key") == 1){

        ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
        ui->textEdit_2->setPlainText(QString::number(temp.getPlayerHealth()));

        ui->textEdit->insertPlainText(QString::fromStdString(temp.quitFucntion()));
        ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());

        ui->pushButton_8->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
    }
    else{

        ui->textEdit->insertPlainText("\nNo You cannot fight the Lion unless you have answered the riddle and take the key");

    }
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->clear();

    ui->textEdit->insertPlainText(QString::fromStdString(temp.quitFucntion()));
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());

    ui->pushButton_8->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);






}
