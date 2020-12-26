#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QMouseEvent>

class Cell : public QPushButton{

private:
    QPushButton* cela;

public:
    /*noesvoid getCellInfo () {

    }*/

protected Q_SLOTS:
    void mouseLeftClick(QMouseEvent*);

signals:
    void leftClick();
};

#endif // CELL_H
