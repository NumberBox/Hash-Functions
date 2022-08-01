#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool sum_1_ = false;
    bool sum_2_ = false;
    QWidget *bar;
    QWidget *bar_one;
    int M;
    int M2;

    QString word1;
    QString word2;


private slots:
    void on_pushButton_clicked();

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_11_textChanged(const QString &arg1);

    void on_lineEdit_16_textChanged(const QString &arg1);

    void on_lineEdit_13_textChanged(const QString &arg1);

    void on_lineEdit_20_textChanged(const QString &arg1);

    void on_lineEdit_18_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_lineEdit_8_textChanged(const QString &arg1);

    void on_lineEdit_27_textChanged(const QString &arg1);

    void on_lineEdit_24_textChanged(const QString &arg1);

    void on_lineEdit_21_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_lineEdit_29_textChanged(const QString &arg1);

    void on_lineEdit_34_textChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_10_textChanged(const QString &arg1);

    void on_lineEdit_31_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
