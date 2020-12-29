#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cell.h"

#include <QGridLayout>
#include <QMargins>
#include <QLayout>
#include <QMouseEvent>
#include <QDebug>
#include <time.h>
#include <stdlib.h>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    cont=0;
    pols=false;

    setFocusPolicy(Qt::ClickFocus);

    ui->setupUi(this);

    QTimer* time=new QTimer(this);
    connect(this, SIGNAL(leftclick()), this, SLOT(True()));
    connect(time, SIGNAL(timeout()), this, SLOT(contador()));
    time->start(1000);

    crearMatriu();
    addMines();
    for (int posX = 0; posX < 9; posX++) {
        for (int posY = 0; posY < 9; posY++) {
            addNumbers(posX, posY);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::True(){
    if (pols==true){
        pols=false;
    }
    else{
        pols=true;
    }
}

void MainWindow:: contador(){
    if(pols==true){
        ui->Temps->display(cont);
        cont++;
        if(cont>999){
            cont=0;
            //afegir missatge GAME OVER
        }
    }

}
void Cell::mouseLeftClick(QMouseEvent* e){
    if (e->button()==Qt::LeftButton){
        //minefield[i][j]->pressed();
        qInfo() << "Pressed";
        emit leftclick();
    }
}


void MainWindow::crearMatriu(){
    QGridLayout* layout = new QGridLayout(ui->taulell);
    layout->setContentsMargins(5,0,5,0);
    layout->setSpacing(3);
    int num = 0;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            minefield[i][j] = new Cell (i,j,num);
            minefield[i][j]->setMinimumSize(20,30);

            layout->addWidget(minefield[i][j], i, j);
        }
    }
}

void MainWindow::addMines(){
    int bombs = 10;
    srand(time(NULL));
    ui->Temps->display(bombs);
    while (bombs>0) {
        int i = rand()%9;
        int j = rand()%9;
        if (minefield[i][j]->getNumber()==0) {
            minefield[i][j]->setNumber(-1);
            bombs--;
        }
    }
}

void MainWindow::addNumbers(int posX, int posY) {
    int number = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (posX + i >= 0 && posX + i < 8 && posY + j >= 0 && posY + j < 8) {
                if (minefield[posX+i][posY+j]->getNumber() == -1) {
                    ++number;
                } else if (minefield[posX][posY]->getNumber() != -1) {
                    minefield[posX][posY]->setNumber(number);
                }
            }
        }
    }

}

void MainWindow::checkMines() {

}


