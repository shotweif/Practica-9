#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Configuracion; }
QT_END_NAMESPACE

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    Configuracion(QWidget *parent = nullptr);
    ~Configuracion();
    void Save_File();
    void Open_File();


private slots:
    void on_pButton_Guardar_clicked();
    void on_pButton_Abrir_clicked();

private:
    Ui::Configuracion *ui;
};
#endif // CONFIGURACION_H
