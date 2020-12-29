#ifndef CELL_H
#define CELL_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include <QString>

class Cell : public QPushButton{
    Q_OBJECT

private:
    int x;
    int y;
    int numero; //atribut per al numero o -1 per una bomba

public:
    Cell(int x, int y, int numero){this->x=x; this->y=y; this->numero=numero; setText(QString("%1").arg(numero));};

    void setNumber(int num) {
        numero=num;
        setText(QString("%1").arg(numero));
    }

    int getNumber () {
        return numero;
    }

protected Q_SLOTS:
    void mouseLeftClick(QMouseEvent*);

signals:
    void leftclick();

};
#endif // CELL_H
