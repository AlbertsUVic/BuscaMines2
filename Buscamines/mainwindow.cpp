#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QMargins>
#include <QLayout>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //console.log(minefield);
    cont=0;
    pols=false;
    Q_INIT_RESOURCE(resource);
    setFocusPolicy(Qt::ClickFocus);

    ui->setupUi(this);

    QTimer *time=new QTimer(this);
    connect(this, SIGNAL(leftclick()), this, SLOT(True()));
    connect(time, SIGNAL(timeout()), this, SLOT(Contador()));
    time->start(1000);

    CrearMatriu();
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

void MainWindow:: Contador(){
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
        cela->pressed();
        emit leftclick();
    }
}


void MainWindow::CrearMatriu(){
    QGridLayout* layout = new QGridLayout(ui->taulell);
    Cell* cela;
    layout->setContentsMargins(5,0,5,0);
    layout->setSpacing(3);
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            Cell minefield[i][j];
            cela->setMinimumSize(20,30);
            layout->addWidget(cela, i, j);

        }
    }
}

