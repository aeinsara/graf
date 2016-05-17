#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
      void paintEvent(QPaintEvent *);


private slots:
       // void checkInput(const QString &text);

       void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void writefile();
};

#endif // MAINWINDOW_H
