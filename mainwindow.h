#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QList>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();
    void signalAndSlots();

    void calReslut();
private:
    Ui::MainWindow *ui;
    QMap<QString,QMap<QString,double>> m_mapUnit;
};

#endif // MAINWINDOW_H
