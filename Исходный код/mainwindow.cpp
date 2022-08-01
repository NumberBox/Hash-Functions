#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTabWidget>
#include <QTabBar>
#include <QDebug>
#include <QTextCodec>
#include <ctime>
#include <QFile>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file("files/Sourse.html");
        if((!file.exists())||(!file.open(QIODevice::ReadOnly))){
            QMessageBox::warning(this,"Warning", "Отсутствует файл Sourse.html \nДальнейшее использование невозможно");
        }
        else{
              QString str = file.readAll();
              qDebug()<<str;
              ui->textEdit_2->setHtml(str);
              file.close();
        }
     QFile file2("files/first_division.html");
        if((!file2.exists())||(!file2.open(QIODevice::ReadOnly))){
                QMessageBox::warning(this,"Warning", "Отсутствует файл first_division.html \nДальнейшее использование невозможно");
        }
        else{
                  QString str = file2.readAll();
                  qDebug()<<str;
                  ui->textEdit->setHtml(str);
                  file.close();
        }
        QFile file3("files/second_multiplication.html");
           if((!file3.exists())||(!file3.open(QIODevice::ReadOnly))){
                   QMessageBox::warning(this,"Warning", "Отсутствует файл second_multiplication.html \nДальнейшее использование невозможно");
           }
           else{
                     QString str = file3.readAll();
                     qDebug()<<str;
                     ui->textEdit_3->setHtml(str);
                     file.close();
           }
           QFile file4("files/third_square.html");
              if((!file4.exists())||(!file4.open(QIODevice::ReadOnly))){
                      QMessageBox::warning(this,"Warning", "Отсутствует файл third_square.html \nДальнейшее использование невозможно");
              }
              else{
                        QString str = file4.readAll();
                        qDebug()<<str;
                        ui->textEdit_4->setHtml(str);
                        file.close();
              }
              QFile file5("files/fourth_addition.html");
                 if((!file5.exists())||(!file5.open(QIODevice::ReadOnly))){
                         QMessageBox::warning(this,"Warning", "Отсутствует файл fourth_addition.html \nДальнейшее использование невозможно");
                 }
                 else{
                           QString str = file5.readAll();
                           qDebug()<<str;
                           ui->textEdit_5->setHtml(str);
                           file.close();
                 }

                 QFile file6("files/Finish.html");
                    if((!file6.exists())||(!file6.open(QIODevice::ReadOnly))){
                            QMessageBox::warning(this,"Warning", "Отсутствует файл Finish.html \nДальнейшее использование невозможно");
                    }
                    else{
                              QString str = file6.readAll();
                              qDebug()<<str;
                              ui->textEdit_6->setHtml(str);
                              file.close();
                    }




    QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));

    int a = 0;
    ui->tabWidget->tabBar()->setDocumentMode(true);
    ui->tabWidget->tabBar()->setExpanding(true);

    ui->tabWidget->setTabEnabled(2, false);
    ui->tabWidget->setTabEnabled(3, false);
    ui->tabWidget->setTabEnabled(4, false);
    ui->tabWidget->tabBar()->hide();
    bar = ui->tab_6;
    bar_one = ui->tab_5;
    ui->tabWidget->removeTab(5);
    srand( time( 0 ) );
    M = 10 + rand() % 16;
    QString str = QString::number(fmod(1684,M));
    if(str.size()==1){
       ui->lineEdit_5->setText("0"+str);
    }else{
        ui->lineEdit_5->setText(str);
    }
    double b;
    double c = modf(0.66*M, &b);
    M2 = b;
    qDebug()<<M;
    qDebug()<<M2;


    srand( time( 0 ) );
    int ran = 1 + rand() % 5;
    if (ran == 1){
        word1 = "Компьютер";
        word2 = "Программа";
    }
    if (ran == 2){
        word1 = "Телевизор";
        word2 = "Провод";
    }
    if (ran == 3){
        word1 = "Часовщик";
        word2 = "Стрелка";
    }
    if (ran == 4){
        word1 = "Город";
        word2 = "Море";
    }
    if (ran == 5){
        word1 = "Телефон";
        word2 = "Обруч";
    }

    QString str2 = ui->textEdit_5->toHtml();
    int g = str2.indexOf("LINK_ONE_");
    str2.remove(g,9);
    qDebug()<<g;
    str2 = str2.insert(g,word1);
    ui->textEdit_5->setHtml(str2);

    g = str2.indexOf("LINK_TWO_");
    str2.remove(g,9);
    qDebug()<<g;
    str2 = str2.insert(g,word2);
    ui->textEdit_5->setHtml(str2);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->tabBar()->show();
    ui->tabWidget->removeTab(5);
    ui->tabWidget->removeTab(0);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)//деление
{
    ui->lineEdit_3->setText("");
    int summ = 0;
    for (int i = 0;i<arg1.size();i++) {
        QString symvol = arg1.at(i);
        summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
        //ui->lineEdit_3->setText(ui->lineEdit_3->text()+QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10));
    }
    ui->lineEdit_3->setText(QString::number(summ));
    if(arg1.size()==0){
       ui->lineEdit_3->setText("");
    }
}




void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)//деление
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    if(ok){
     QString str = QString::number(fmod(hex,M));
     if(str.size()==1){
        ui->lineEdit_5->setText("0"+str);
     }else{
         ui->lineEdit_5->setText(str);
     }

    }
    else{
       ui->lineEdit_5->setText("");
    }
}

void MainWindow::on_pushButton_2_clicked()//деление
{
  if(ui->lineEdit->text().toInt() == M){
      ui->tabWidget->setCurrentIndex(1);
      ui->tabWidget->setTabEnabled(1, true);
      ui->lineEdit->setStyleSheet("QLineEdit{"
                              "background-color: rgb(205, 255, 217);"
                              "border: 1px solid #000000;"
                              "}");

  }
  else{
      ui->lineEdit->setStyleSheet("QLineEdit{"
                              "background-color: rgb(255, 215, 223);"
                              "border: 1px solid #000000;"
                              "}");
  }
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)//умножение
{
    ui->lineEdit_7->setText("");
    int summ = 0;
    for (int i = 0;i<arg1.size();i++) {
        QString symvol = arg1.at(i);
        summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
        ui->lineEdit_7->setText(QString::number(summ));
        //ui->lineEdit_7->setText(ui->lineEdit_7->text()+QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10));
    }
    if(arg1.size()==0){
       ui->lineEdit_7->setText("");
    }
}

void MainWindow::on_lineEdit_11_textChanged(const QString &arg1)//умножение
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    if(ok){
       double A = ui->lineEdit_15->text().toDouble();
       ui->lineEdit_12->setText(QString::number(A*hex));
    }
    else{
       ui->lineEdit_12->setText("");
    }
}

void MainWindow::on_lineEdit_16_textChanged(const QString &arg1)//умножение
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    double i;
    if(ok){
        double a = modf(hex, &i);
        ui->lineEdit_17->setText(QString::number(a));
    }
    else{
       ui->lineEdit_17->setText("");
    }
}

void MainWindow::on_lineEdit_13_textChanged(const QString &arg1)//умножение
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    bool ok2;
    double hex2 = ui->lineEdit_20->text().toDouble(&ok);
    if(ok&&ok2){
        ui->lineEdit_14->setText(QString::number(hex*hex2));
    }else{
        ui->lineEdit_14->setText("");
     }
}

void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)//умножение
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    bool ok2;
    double hex2 = ui->lineEdit_13->text().toDouble(&ok);
    if(ok&&ok2){
        ui->lineEdit_14->setText(QString::number(hex*hex2));
    }else{
        ui->lineEdit_14->setText("");
     }
}

void MainWindow::on_lineEdit_18_textChanged(const QString &arg1)//умножение
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    double i;
    if(ok){
        double a = modf(hex, &i);
        ui->lineEdit_19->setText(QString::number(i));
    }
    else{
       ui->lineEdit_19->setText("");
    }
}

void MainWindow::on_pushButton_3_clicked()//умножение
{
    if(ui->lineEdit_10->text().toInt() == M2){
        ui->tabWidget->setCurrentIndex(2);
        ui->tabWidget->setTabEnabled(2, true);

        ui->lineEdit_10->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(205, 255, 217);"
                                  "border: 1px solid #000000;"
                                  "}");

      }
      else{
          ui->lineEdit_10->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(255, 215, 223);"
                                  "border: 1px solid #000000;"
                                  "}");
      }
}

void MainWindow::on_lineEdit_8_textChanged(const QString &arg1)//середины квадрата
{
    ui->lineEdit_9->setText("");
    int summ = 0;
    for (int i = 0;i<arg1.size();i++) {
        QString symvol = arg1.at(i);
        summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
        ui->lineEdit_9->setText(QString::number(summ));
        //ui->lineEdit_7->setText(ui->lineEdit_7->text()+QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10));
    }
    if(arg1.size()==0){
       ui->lineEdit_9->setText("");
    }
}

void MainWindow::on_lineEdit_27_textChanged(const QString &arg1)//середины квадрата
{
    QString str = arg1;
    bool ok;
    double hex = str.toDouble(&ok);
    if(ok){
        ui->lineEdit_28->setText(QString::number(hex*hex,'f',0));
    }
    else{
       ui->lineEdit_28->setText("");
    }
}



void MainWindow::on_lineEdit_24_textChanged(const QString &arg1)//середины квадрата
{
    QString str = arg1;
    bool ok;
    int hex = str.toInt(&ok);
    if(ok){
        hex>>=ui->lineEdit_25->text().toInt();
        ui->lineEdit_26->setText(QString::number(hex));
    }
    else{
       ui->lineEdit_26->setText("");
    }
}

void MainWindow::on_lineEdit_21_textChanged(const QString &arg1)//середины квадрата
{
    QString str = arg1;
    bool ok;
    int hex = str.toInt(&ok);
    if(ok){
        int a = ui->lineEdit_22->text().toInt();
        ui->lineEdit_23->setText(QString::number(fmod(hex,pow(2,a))));
    }
    else{
       ui->lineEdit_23->setText("");
    }
}

void MainWindow::on_pushButton_4_clicked()//середины квадрата
{
    if(ui->lineEdit_31->text() == "438"){
        ui->tabWidget->setCurrentIndex(3);
        ui->tabWidget->setTabEnabled(3, true);

        ui->lineEdit_31->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(205, 255, 217);"
                                  "border: 1px solid #000000;"
                                  "}");

      }
      else{
          ui->lineEdit_31->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(255, 215, 223);"
                                  "border: 1px solid #000000;"
                                  "}");
      }
}


void MainWindow::on_lineEdit_29_textChanged(const QString &arg1)//сложения
{

    ui->lineEdit_30->setText("");
    int summ = 0;
    for (int i = 0;i<arg1.size();i++) {
        QString symvol = arg1.at(i);
        summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    }
    ui->lineEdit_30->setText(QString::number(summ%123));
    if(arg1.size()==0){
       ui->lineEdit_30->setText("");
    }
}

void MainWindow::on_lineEdit_34_textChanged(const QString &arg1)//сложения
{
    ui->lineEdit_35->setText("");
    if(arg1.size()==0){
       ui->lineEdit_35->setText("");
       return;
    }
    int summ = 0;
    QString symvol = arg1.at(0);
    summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    symvol = arg1.at(arg1.size()-1);
    summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    ui->lineEdit_35->setText(QString::number(summ%123));
    if(arg1.size()==0){
       ui->lineEdit_35->setText("");
    }
}

QString sum_2(QString str){//сложения
    int summ = 0;
    for (int i = 0;i<str.size();i++) {
        QString symvol = str.at(i);
        summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    }
    return QString::number(summ%123);
    if(str.size()==0){
       return "";
    }
}
QString sum_3(QString str){//сложения
    if(str.size()==0){
       return "";
    }
    int summ = 0;
    QString symvol = str.at(0);
    summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    symvol = str.at(str.size()-1);
    summ+=QString::number(symvol.toLocal8Bit().toHex().toInt(0, 16), 10).toInt();
    return QString::number(summ%123);

}
void MainWindow::on_pushButton_6_clicked()//сложения
{
    if(sum_2(ui->lineEdit_41->text()) == sum_2(word1) && ui->lineEdit_41->text() != word1){
        //ui->tabWidget->setCurrentIndex(1);
        sum_1_ = true;
        ui->lineEdit_41->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(205, 255, 217);"
                                  "border: 1px solid #000000;"
                                  "}");

      }
      else{
          ui->lineEdit_41->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(255, 215, 223);"
                                  "border: 1px solid #000000;"
                                  "}");
      }
    if (sum_2_ && sum_1_){

        qDebug()<<"Завершено";
        ui->tabWidget->addTab(bar,"");
        ui->tabWidget->setCurrentIndex(4);
        ui->tabWidget->tabBar()->hide();
    }
}

void MainWindow::on_pushButton_5_clicked()//сложения
{
    if(sum_3(ui->lineEdit_40->text()) == sum_3(word2) && ui->lineEdit_40->text() != word2){
        //ui->tabWidget->setCurrentIndex(1);
        sum_2_ = true;
        ui->lineEdit_40->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(205, 255, 217);"
                                  "border: 1px solid #000000;"
                                  "}");

      }
      else{
          ui->lineEdit_40->setStyleSheet("QLineEdit{"
                                  "background-color: rgb(255, 215, 223);"
                                  "border: 1px solid #000000;"
                                  "}");
      }

        if (sum_2_ && sum_1_){
            ui->tabWidget->addTab(bar,"");
            ui->tabWidget->setCurrentIndex(4);
            ui->tabWidget->tabBar()->hide();
            qDebug()<<"Завершено";
        }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    ui->lineEdit->setStyleSheet("QLineEdit{"
                            "background-color: rgb(255, 255, 255);"
                            "border: 1px solid #000000;"
                            "}");
}

void MainWindow::on_lineEdit_10_textChanged(const QString &arg1)
{
    ui->lineEdit_10->setStyleSheet("QLineEdit{"
                            "background-color: rgb(255, 255, 255);"
                            "border: 1px solid #000000;"
                            "}");
}

void MainWindow::on_lineEdit_31_textChanged(const QString &arg1)
{
    ui->lineEdit_31->setStyleSheet("QLineEdit{"
                            "background-color: rgb(255, 255, 255);"
                            "border: 1px solid #000000;"
                            "}");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tabWidget->insertTab(0,bar_one,"");
    ui->tabWidget->setCurrentIndex(0);
    sum_1_ = false;
    sum_2_ = false;
    ui->lineEdit_40->setText("");
     ui->lineEdit_41->setText("");
    ui->lineEdit_40->setStyleSheet("QLineEdit{"
                            "background-color: rgb(255, 255, 255);"
                            "border: 1px solid #000000;"
                            "}");
    ui->lineEdit_41->setStyleSheet("QLineEdit{"
                            "background-color: rgb(255, 255, 255);"
                            "border: 1px solid #000000;"
                            "}");
}
