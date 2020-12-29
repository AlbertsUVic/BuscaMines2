#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addMines();
    void crearMatriu();
    void checkMines();
    void addNumbers(int, int);

public slots:
    void contador();
    void True();


private:
    Ui::MainWindow *ui;
    bool pols;
    int cont;

    Cell* minefield[9][9];
};

#endif // MAINWINDOW_H
