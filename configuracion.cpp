#include "configuracion.h"
#include "ui_configuracion.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include "dialogconfirm.h"
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonObject>
#include <QByteArray>
#include <QMessageBox>
#include <QSplitter>

Configuracion::Configuracion(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Configuracion)
{
    ui->setupUi(this);

    resize(360, 290);
    setWindowIcon(QIcon(
    "C:/Users/Kenneth D/OneDrive - Universidad Politecnica Salesiana/UPS Proyect - Programacion/P8-Configuracio-LISOFT/Resourse/icono.png"));

}

Configuracion::~Configuracion()
{
    delete ui;
}

void Configuracion::Save_File()
{
    DialogConfirm *dialogo_confirm = new DialogConfirm(this);
    QString direcion = ui->lineE_Direccion->text();
    int puerto = ui->sBox_Puerto->value();
    bool caja1 = ui->cBox1->isChecked();
    bool caja2 = ui->cBox2->isChecked();
    bool caja3 = ui->cBox3->isChecked();
    bool caja4 = ui->cBox4->isChecked();

    QString temporal = QDir::home().absolutePath() + "/New_Fil";

    QString fileName = QFileDialog::getSaveFileName(this,tr("Save File"),
                                                    temporal, "Archivo de Configuracion (*.cfg)");

    QFile archivo(fileName);
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream out(&archivo);
            out << "Diteccion: " << direcion << "\n";
            out << "Puerto: " << puerto << "\n";
            out << "Caja 1: " << caja1 << "\n";
            out << "Caja 2: " << caja2 << "\n";
            out << "Caja 3: " << caja3 << "\n";
            out << "Caja 4: " << caja4 << "\n";
            qDebug() << "Archivo almacenado en:" << fileName;
            dialogo_confirm->show();
        }else {
            QMessageBox::critical(this, tr("Error"),tr("No guardo el archivo"));
        }
    archivo.close();
        /*
    QString Saver = "Archivo de Configuracion (*.cfg)";
    DialogConfirm *dialogo_confirm = new DialogConfirm(this);
    QString json_filter = "JSON(*.cfg)";
    QString file_name = QFileDialog::getSaveFileName(this,tr("Save File"),"/",Saver);

    if(!file_name.isEmpty()){
        QString Dato1 = ui->lineE_Direccion->text();
        const int Dato2 = ui->sBox_Puerto->value();
        const bool Dato3 = ui->cBox1->checkState();
        const bool Dato4 = ui->cBox2->checkState();
        const bool Dato5 = ui->cBox3->checkState();
        const bool Dato6 = ui->cBox4->checkState();

        QJsonDocument doc;
        QJsonObject obj;
        obj["Dato1"] = Dato1;
        obj["Dato2"] = Dato2;
        obj["Dato3"] = Dato3;
        obj["Dato4"] = Dato4;
        obj["Dato5"] = Dato5;
        obj["Dato6"] = Dato6;

        doc.setObject(obj);
        QByteArray data_json = doc.toJson();
        QFile output(file_name);

        if(output.open(QFile::WriteOnly | QFile::Text)){
            output.write(data_json);
            output.close();
            dialogo_confirm->show();

        }else{
            QMessageBox::critical(this, tr("Error"),tr("No guardo el archivo"));
        }
    }*/

}

void Configuracion::Open_File()
{
    QString Saver = QDir::home().absolutePath();
    QString file_name = QFileDialog::getOpenFileName(this,("Save File"),
                                                    Saver, "Archivo de Configuracion (*.cfg)");

    QFile File(file_name);
    if(!File.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this, tr("Error"),tr("El documento no fue abierto o no se pudo leer"));
        return;
    }

    QStringList documet;
    QTextStream in(&File);
    while (!in.atEnd()) {
        QString Linea = in.readLine();
        documet << Linea;
    }
    QStringList div = documet[0].split("Diteccion: ");
    QStringList div1 = documet[1].split("Puerto: ");
    QStringList div2 = documet[2].split("Caja 1: ");
    QStringList div3 = documet[3].split("Caja 2: ");
    QStringList div4 = documet[4].split("Caja 3: ");
    QStringList div5 = documet[5].split("Caja 4: ");

    ui->lineE_Direccion->setText(div[1]);
    ui->sBox_Puerto->setValue(div1[1].toInt());
    ui->cBox1->setChecked(div2[1].toInt());
    ui->cBox2->setChecked(div3[1].toInt());
    ui->cBox3->setChecked(div4[1].toInt());
    ui->cBox4->setChecked(div5[1].toInt());
    QMessageBox::information(this, tr("Mensaje"),tr("Documento leido correctamente"));
    /*
    QString Saver = "Archivo de Configuracion (*.cfg)";
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"),"/",Saver);

    if(file_name.isEmpty()){}else{
        QJsonDocument doc;
        QJsonObject obj;
        QByteArray data_json;
        QFile input(file_name);

        if(input.open(QIODevice::ReadOnly | QIODevice::Text)){


            data_json = input.readAll();
            doc = doc.fromJson(data_json);
            obj = doc.object();
            qDebug() << data_json;

            QString Dato1 = obj["Dato1"].toString();
            const int Dato2 = obj["Dato2"].toInt();

            const bool Dato3 = obj["Dato3"].toInt();
            const bool Dato4 = obj["Dato4"].toInt();
            const bool Dato5 = obj["Dato5"].toInt();
            const bool Dato6 = obj["Dato6"].toInt();

            ui->lineE_Direccion->setText(Dato1);
            ui->sBox_Puerto->setValue(Dato2);

            ui->cBox1->setChecked(Dato3);
            ui->cBox2->setChecked(Dato4);
            ui->cBox3->setChecked(Dato5);
            ui->cBox4->setChecked(Dato6);

            QMessageBox::information(this, tr("Mensaje"),tr("Documento leido correctamente"));

        }else{
            QMessageBox::critical(this, tr("Error"),input.errorString());
        }
    }*/
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void Configuracion::on_pButton_Guardar_clicked()
{
    Save_File();
}

void Configuracion::on_pButton_Abrir_clicked()
{
    Open_File();
}
