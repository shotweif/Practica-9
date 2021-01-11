#include "dialogconfirm.h"
#include "ui_dialogconfirm.h"

DialogConfirm::DialogConfirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfirm)
{
    ui->setupUi(this);

    //resize();
    QPushButton *ptr = ui->pushButton;
    QObject::connect(ptr,SIGNAL(clicked()),this,SLOT(close()));
}

DialogConfirm::~DialogConfirm()
{
    delete ui;
}
