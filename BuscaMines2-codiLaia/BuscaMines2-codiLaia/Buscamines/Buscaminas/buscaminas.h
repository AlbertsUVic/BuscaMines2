#ifndef BUSCAMINAS_H
#define BUSCAMINAS_H

#include <QMainWindow>
#include "cell.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Buscaminas; }
QT_END_NAMESPACE

class Buscaminas : public QMainWindow
{
    Q_OBJECT

public:
    Buscaminas(QWidget *parent = nullptr);
    ~Buscaminas();

public slots:
    void Contador();
    void True();
    void crearMatriu();

private:
    Ui::Buscaminas *ui;
    bool pols = false;
    int cont = 0;

    Cell minefield[9][9];
};
#endif // BUSCAMINAS_H
