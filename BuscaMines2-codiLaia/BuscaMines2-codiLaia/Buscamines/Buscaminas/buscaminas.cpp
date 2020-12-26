#include "buscaminas.h"
#include "ui_buscaminas.h"
#include "cell.h"

#include <QLayout>
#include <QDebug>
#include <QMouseEvent>
#include <QTimer>

Buscaminas::Buscaminas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Buscaminas)
{
    Q_INIT_RESOURCE(resource);
    setFocusPolicy(Qt::ClickFocus);

    ui->setupUi(this);

    QTimer *time=new QTimer(this);
    //connect(this, SIGNAL(leftClick()), this, SLOT(True()));
    connect(time, SIGNAL(timeout()), this, SLOT(Contador()));
    time->start(1000);

    crearMatriu();
}

Buscaminas::~Buscaminas()
{
    delete ui;
}

void Buscaminas::crearMatriu() {
    QGridLayout* layout = new QGridLayout(ui->frame_tauler);
    layout->setContentsMargins(5,0,5,0);
    layout->setSpacing(3);
    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            QPushButton* cela = new QPushButton();
            cela->setMinimumSize(20,30);
            layout->addWidget(cela, i, j);
        }
    }
}

/*void Cell::mouseLeftClick(QMouseEvent* e){
    if (e->button()==Qt::LeftButton){
        //cela->pressed();
        qInfo("Puta");
        emit leftClick();
    }
}*/

void Buscaminas::True(){
    if (pols==true){
        pols=false;
    }
    else{
        pols=true;
    }
}
void Buscaminas:: Contador(){
    if(pols==true){
        ui->compt_temps->display(cont);
        cont++;
        if(cont>999){
            cont=0;
            //afegir missatge GAME OVER
        }
    }

}

