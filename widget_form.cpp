#include "widget_form.h"
#include "ui_widget_form.h"

#include <QMessageBox>
#include <QDebug>
#include "debug/logger.h"

Widget_Form::Widget_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Form)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    bool flag = initDatabase();
    qDebug()<<"status Database: "<<flag<<"\n";
    logger::WriteMsg("status Database: "+QString::number(flag).toStdString()+"\n");
    populatedDataItem();
    connect(ui->pushButton_del,SIGNAL(clicked(bool)),this,SLOT(remove()));
    connect(ui->pushButton_add,SIGNAL(clicked(bool)),this,SLOT(addnew()));
    connect(ui->pushButton_submit,SIGNAL(clicked(bool)),this,SLOT(save()));
}

Widget_Form::~Widget_Form()
{
    closeDatabase();
    delete model;
    delete ui;
}

void Widget_Form::populatedDataItem()
{
    model = new QSqlTableModel(0,db);
    model->setTable("books");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ISBN"));
    model->setHeaderData(1, Qt::Horizontal, tr("Title"));
    model->setHeaderData(2, Qt::Horizontal, tr("Edition"));
    model->setHeaderData(3, Qt::Horizontal, tr("Publisher"));
    //model->setHeaderData(4, Qt::Horizontal, tr("Copyright"));
    //model->setHeaderData(5, Qt::Horizontal, tr("Price"));
    //model->setHeaderData(6, Qt::Horizontal, tr("Authors"));

    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);

}

bool Widget_Form::initDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.124.135");
    db.setDatabaseName("tinzao");
    db.setUserName("postgres");
    db.setPassword("000");
    db.setPort(5432);

    return db.open();
}

void Widget_Form::closeDatabase()
{
    db.close();
}

void Widget_Form::addnew()
{
    int row = 0;
    model->insertRows(row,1);
    model->setData(model->index(row,0),ui->lineEdit_edIsbn->text());
    model->setData(model->index(row,1),ui->lineEdit_edTitle->text());
    model->setData(model->index(row,2),ui->lineEdit_edEdition->text());
    model->setData(model->index(row,3),ui->lineEdit_edPublisher->text());

}

void Widget_Form::remove(){
    int row = ui->tableView->currentIndex().row();
    if(QMessageBox::question(0,"Delete","Record no."+QString::number(row+1)+
                              " will be deleted. Are you sure?",
                              QMessageBox::No,QMessageBox::Yes)==QMessageBox::Yes){
        model->removeRow(row);
    }
}

void Widget_Form::save()
{
    bool flag = model->submit();
    if(flag == false)
    {
        QMessageBox::critical(0,"Failed","cannot save changes.");
        logger::WriteMsg("cannot save changes.");
    }
    else{
        QMessageBox::information(0,"success", "changes saved successfully");
        logger::WriteMsg("changes saved successfully");
    }

}

