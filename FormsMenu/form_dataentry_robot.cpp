#include "form_dataentry_robot.h"
#include "ui_form_dataentry_robot.h"

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"
#include "FormsMenu/cell_check_and_edit.h"
#include "FormsMenu/form_dataentry_robot_dialog.h"
#include "form_in_work.h"

#include "FormsMenu/form_dataentry_dataentry___milk_separationoff_add.h"


#include "dataanimals.h"
#include "Debug/logger.h"

#include <QMessageBox>

form_dataentry_Robot::form_dataentry_Robot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_Robot)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");
    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                      "padding: 4 20000 4 10;"
                                                                                      "}");

    ui->pushButton_view_param->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->pushButton_add->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_select->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    ui->pushButton_delete->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );

    mTimer=new QTimer(this);    
    connect(mTimer, SIGNAL(timeout()),this, SLOT(GetData()));
    mTimer->start(1000);

}

form_dataentry_Robot::~form_dataentry_Robot()
{
    delete ui;
}


void form_dataentry_Robot::addRandom()
{
    for(int i=0;i<3;i++)
    {
        DataSystems::Instance().robot_coord_teat_lf = QString::number(rand()%1000/37.0);
        DataSystems::Instance().robot_coord_teat_lr = QString::number(rand()%1000/37.0);
        DataSystems::Instance().robot_coord_teat_rf = QString::number(rand()%1000/37.0);
        DataSystems::Instance().robot_coord_teat_rr = QString::number(rand()%1000/37.0);

        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {
            QString tab = "dataentry_robot";
            db_func->insert_add(tab, "coord_teat_lf", DataSystems::Instance().robot_coord_teat_lf);
            db_func->insert_add(tab, "coord_teat_lr", DataSystems::Instance().robot_coord_teat_lr);
            db_func->insert_add(tab, "coord_teat_rf", DataSystems::Instance().robot_coord_teat_rf);
            QString sql_insert = db_func->insert_add(tab, "coord_teat_rr", DataSystems::Instance().robot_coord_teat_rr);

            //"----------" + "')";
            db_func->sql_exec(sql_insert, "add dry off");
        }
    }
}

void form_dataentry_Robot::GetData()
{
    GetData_search(searchText);
    return;    
    /**/
}

void form_dataentry_Robot::GetData(QString str)
{
    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        //QString tab = "dataentry_robot";
        //QString sql =  QString("SELECT * FROM public."+tab+" WHERE coord_teat_lf LIKE '%"+str+"%' OR  ORDER BY id;").toLower();
        QString sql =  QString("SELECT * FROM public.dataentry_robot WHERE id =  " + str +";").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        int i=0;
        while(query->next())
        {
            QVariant val;
            val = query->value("robot_no"); DataSystems::Instance().robot_robot_no =  (!val.isNull())?val.toString():" ";
            val = query->value("coord_teat_lf"); DataSystems::Instance().robot_coord_teat_lf =  (!val.isNull())?val.toString():" ";
            val = query->value("coord_teat_lr"); DataSystems::Instance().robot_coord_teat_lr =  (!val.isNull())?val.toString():" ";
            val = query->value("coord_teat_rf"); DataSystems::Instance().robot_coord_teat_rf =  (!val.isNull())?val.toString():" ";
            val = query->value("coord_teat_rr"); DataSystems::Instance().robot_coord_teat_rr =  (!val.isNull())?val.toString():" ";
            val = query->value("param1"); DataSystems::Instance().robot_param1 =  (!val.isNull())?val.toString():" ";
            val = query->value("param2"); DataSystems::Instance().robot_param2 =  (!val.isNull())?val.toString():" ";
            break;
        }
    }
    /**/
}

void form_dataentry_Robot::GetData_search2(QString str)
{
    if(ui->tableWidget->rowCount()>30)ui->tableWidget->clear();
    ui->comboBox_id->clear();

    //logger::WriteMsg(" GetData_search:  ---------- robot record: " + QString::number(355.0/113.0).toStdString());

    //ui->tableWidget->dele;

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_robot";
        //QString sql =  QString("SELECT * FROM public."+tab+" WHERE coord_teat_lf LIKE '%"+str+"%' OR coord_teat_lr LIKE '%"+str+"%' OR coord_teat_rf LIKE '%"+str+"%' or  coord_teat_rr LIKE '%"+str+"%'  ORDER BY id;").toLower();
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE id>0  ORDER BY id;").toLower();
        qDebug()<<"sql: "<<sql;

        //logger::WriteMsg(" GetData_search: read:  ---------- robot record: " + QString::number(355.0/113.0).toStdString());

        //QString tab = "dataentry_robot";
        //QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        QStringList NameColumn;
        int i=0;
        NameColumn<<"id"<<"Robot N"<<"РєРѕРѕСЂРґРёРЅР°С‚С‹ Р»РµРІРѕРіРѕ РЅРёР¶РЅРµРіРѕ СЃРѕСЃРєР°"<<"РєРѕРѕСЂРґРёРЅР°С‚С‹ Р»РµРІРѕРіРѕ РІРµСЂС…РЅРµРіРѕ СЃРѕСЃРєР°"<<"РєРѕРѕСЂРґРёРЅР°С‚С‹ РїСЂР°РІРѕРіРѕ РЅРёР¶РЅРµРіРѕ СЃРѕСЃРєР°"<<"РєРѕРѕСЂРґРёРЅР°С‚С‹ РїСЂР°РІРѕРіРѕ РІРµСЂС…РЅРµРіРѕ СЃРѕСЃРєР°"<<"param1"<<"param2"<<"param3"<<"param4"<<"paramtime1"<<"paramРµtime2"<<"paramtime3"<<"paramtime4";

        ui->tableWidget->setColumnCount( NameColumn.count()+1 );

        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("РџР°СЂР°РјРµС‚СЂС‹ СЂРѕР±РѕС‚Р°"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumn );





        for(int i=0;i<NameColumn.count();i++)ui->tableWidget->setColumnWidth(i, 250);

        i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);

            //logger::WriteMsg("robot record: " + QString::number(i).toStdString());

            tabwidget_insert_add_column(query,ui->tableWidget,"id", i, 0);
            ui->comboBox_id->addItem(query->value("id").toString());
            tabwidget_insert_add_column(query,ui->tableWidget,"robot_no", i, 1);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lf", i, 2);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lr", i, 3);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rf", i, 4);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rr", i, 5);
            tabwidget_insert_add_column(query,ui->tableWidget,"param1", i, 6);
            tabwidget_insert_add_column(query,ui->tableWidget,"param2", i, 7);
            tabwidget_insert_add_column(query,ui->tableWidget,"param3", i, 8);
            tabwidget_insert_add_column(query,ui->tableWidget,"param4", i, 9);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 10);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime2", i, 11);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime3", i, 12);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime4", i, 13);
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }

    /**/
}




void form_dataentry_Robot::GetData_search(QString str)
{
    if(ui->tableWidget->rowCount()>30)ui->tableWidget->clear();
    ui->comboBox_id->clear();

    //ui->tableWidget->dele;

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_robot";
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE coord_teat_lf LIKE '%"+str+"%' OR coord_teat_lr LIKE '%"+str+"%' OR coord_teat_rf LIKE '%"+str+"%' or  coord_teat_rr LIKE '%"+str+"%'  ORDER BY id;").toLower();
        sql =  QString("SELECT * FROM public."+tab+" WHERE id>0  ORDER BY id;").toLower();
        qDebug()<<"sql: "<<sql;

        //QString tab = "dataentry_robot";
        //QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        QStringList NameColumn;
        int i=0;
        NameColumn<<"id"<<"Robot N"<<"paramfile1"<<"paramfile2"<<"координаты левого нижнего соска"<<"координаты левого верхнего соска"<<"координаты правого нижнего соска"<<"координаты правого верхнего соска"<<"param1"<<"param2"<<"param3"<<"param4"<<"paramtime1"<<"paramеtime2"<<"paramtime3"<<"paramtime4";

        ui->tableWidget->setColumnCount( NameColumn.count()+1 );

        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumn );



        for(int i=0;i<NameColumn.count();i++)ui->tableWidget->setColumnWidth(i, 250);

        i=0;
        while(query->next())
        {
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);

            //logger::WriteMsg("robot record: " + QString::number(i).toStdString());

            tabwidget_insert_add_column(query,ui->tableWidget,"id", i, 0);
            ui->comboBox_id->addItem(query->value("id").toString());
            tabwidget_insert_add_column(query,ui->tableWidget,"robot_no", i, 1);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramfile1", i, 2);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramfile2", i, 3);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lf", i, 4);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lr", i, 5);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rf", i, 6);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rr", i, 7);
            tabwidget_insert_add_column(query,ui->tableWidget,"param1", i, 8);
            tabwidget_insert_add_column(query,ui->tableWidget,"param2", i, 9);
            tabwidget_insert_add_column(query,ui->tableWidget,"param3", i, 10);
            tabwidget_insert_add_column(query,ui->tableWidget,"param4", i, 11);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 12);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime2", i, 13);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime3", i, 14);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime4", i, 15);
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }

    /**/
}

/*
void form_dataentry_Robot::tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumn, int numRow, int numColumn)
{
    QTableWidgetItem *item = new QTableWidgetItem(query->value(nameColumn).toString());
    item->setTextAlignment(Qt::AlignHCenter);
    tab->setItem( numRow, numColumn,  item);
}
/**/

void form_dataentry_Robot::tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumnX,  int numRow, int numColumn)
{
    //QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss[Z|[+|-]HH:mm]";
    QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";
    //QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";

    if(nameColumnX.contains("timey2"))
    {
        //uint t_ = query->value("timey2").toDouble();
        double t_ = query->value("timey2").toDouble();
        QTime a(0,0,0);
        a = a.addSecs(int(t_));
        QString time = a.toString();

        QTableWidgetItem *item = new QTableWidgetItem(time);
        item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);

    }
    else if(nameColumnX.contains("timey1"))
    {

        QString t_ = query->value("timey1").toString();
        QDateTime a;
        //a.fromString(t_,"yyyy-MM-ddTHH:mm:ss.zzzZ");
        //a.fromString(t_,"yyyy-MM-dd HH:mm:ss.zzzZ");
        //a.fromString(t_,("yyyy-MM-dd hh:mm:ss.ms"));
        //a.fromString(t_,DateTimeFormat);
        //a.fromString(t_, Qt::ISODate);
        QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs);
        //fromStringValue(t_,a);
        //logger::WriteMsg("date: "+a.toString().toStdString());
        //a.fromString(t_, Qt::ISODateWithMs);
        QString time = time2.toString("yyyy-MM-dd hh:mm:ss.zzzZ");

        //fromStringValue(t_,a);

        QTableWidgetItem *item = new QTableWidgetItem(time);
        //QTableWidgetItem *item = new QTableWidgetItem(t_);
        item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);

    }
    else if(nameColumnX.contains("paramtime1"))
    {

        QString t_ = query->value("paramtime1").toString();
        QDateTime a;
        //QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs).currentDateTimeUtc().toLocalTime();
        QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs);
        double xi = time2.toTime_t();
        QString time = time2.toString("yyyy-MM-dd hh:mm:ss.zzzZ");
        QTableWidgetItem *item = new QTableWidgetItem(time);
        //QTableWidgetItem *item = new QTableWidgetItem(t_);
        item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);
    }

    else if(nameColumnX.toLower().contains("paramfile1"))
    {
        //return;
        QByteArray ba = QByteArray::fromBase64(query->value("paramfile1").toByteArray());

        if(ba == nullptr)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString("[binary data]"));
            item->setTextAlignment(Qt::AlignHCenter);
            tab->setItem( numRow, numColumn,  item);
            return;
        }
        return;
        QPixmap p;
        if(p.loadFromData(ba,"PNG"))
        {
            // do something with pixmap
        }

        Form_in_work *fiw = new Form_in_work(ba);
        tab->setCellWidget(numRow, numColumn,  fiw);
    }
    else if(nameColumnX.toLower().contains("paramfile2"))
    {
        //return;
        QByteArray ba = QByteArray::fromBase64(query->value("paramfile2").toByteArray());

        if(ba == nullptr)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString("[binary data]"));
            item->setTextAlignment(Qt::AlignHCenter);
            tab->setItem( numRow, numColumn,  item);
            return;
        }
        return;
        QPixmap p;
        if(p.loadFromData(ba,"JPG"))
        {
            // do something with pixmap
        }

        Form_in_work *fiw = new Form_in_work(ba);
        tab->setCellWidget(numRow, numColumn,  fiw);
    }

    else
    {
        if(nameColumnX.toLower().contains("file"))
        {
            return;
        }

        QTableWidgetItem *item = new QTableWidgetItem(query->value(nameColumnX).toString());
        item->setTextAlignment(Qt::AlignLeft);
        tab->setItem( numRow, numColumn,  item);
    }
    //ui->comboBox->addItem(query->value(nameColumn).toString());
    //xi = query->value(nameColumnX).toDouble();
    //yi = query->value(nameColumnY).toDouble();
}




void form_dataentry_Robot::on_comboBox_id_activated(int index)
{
    mTimer->stop();
    //DataSystems::Instance().clear_otel();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkId = ui->comboBox_id->currentText();
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = ui->tableWidget->item(i,0);
        qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
        if (NULL != item) {
            val = item->text();
            qDebug()<<"check: "<<checkId<<"; "<<"i: "<<i<<"; "<<val;
            if(checkId.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)ui->tableWidget->item(selectRowOld,0)->setBackground( Qt::white);
                ui->tableWidget->item(selectRow,0)->setBackground( Qt::gray);
                selectRowOld=selectRow;
                break;
            }
        }
    }
    //mTimer->start(1000);

}




void form_dataentry_Robot::on_pushButton_add_clicked()
{

}


void form_dataentry_Robot::on_pushButton_select_clicked()
{

}


void form_dataentry_Robot::on_pushButton_delete_clicked()
{
    if(QMessageBox::question(0, "Не удалять: Уверены?", "Удалить все записи: Уверены?",
                                  QMessageBox::Yes,QMessageBox::No)==QMessageBox::No)
    {
        QMessageBox::information(this,"Отмена","Записи не удалены");
        return;

    }
    else{

        QScopedPointer<DataBase> db_func(new DataBase());
        //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
        if(db_func->StatusOpen())
        {
            QString sql2=QString("TRUNCATE TABLE dataentry_robot;");
            db_func->sql_exec(sql2, "delete Robot");
        }

        QMessageBox::information(this,"Успешно","Записи удалены");
    }

    GetData();
}




void form_dataentry_Robot::on_comboBox_id_textActivated(const QString &arg1)
{
    //mTimer->stop();

}


void form_dataentry_Robot::on_lineEdit_textEdited(const QString &arg1)
{

}

void form_dataentry_Robot::on_lineEdit_textChanged(const QString &arg1)
{
    searchText = arg1;
}






void form_dataentry_Robot::on_comboBox_id_editTextChanged(const QString &arg1)
{
    //mTimer->stop();
}


void form_dataentry_Robot::on_pushButton_view_param_clicked()
{
    //mTimer->stop();
    QString msg = "host: " + DataSystems::Instance().db_host + " | " +
                  "db name: " + DataSystems::Instance().db_name + " | " +
                  "port: " + QString::number(DataSystems::Instance().db_port) + " | " +
                  "login: " + DataSystems::Instance().db_login + " | " +
                  "passowrd: " + DataSystems::Instance().db_password + " | ";
    logger::WriteMsg("Login Dialog Plotter: "+msg.toStdString());


//    form_dataentry_dataentry___milk_separationoff_add tf(this);
//    if(!(tf.exec()==QDialog::Accepted))
//    {
//        //QMessageBox::information(this,"Спасибо","Сухостойность");
//    }

    //return;

    form_dataentry_robot_Dialog tf2(this);
    if(!(tf2.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }

            msg = "host: " + DataSystems::Instance().db_host + " | " +
                  "db name: " + DataSystems::Instance().db_name + " | " +
                  "port: " + QString::number(DataSystems::Instance().db_port) + " | " +
                  "login: " + DataSystems::Instance().db_login + " | " +
                  "passowrd: " + DataSystems::Instance().db_password + " | ";

    logger::WriteMsg("Exit Dialog Plotter: "+msg.toStdString());

    //mTimer->start(1000);

}

