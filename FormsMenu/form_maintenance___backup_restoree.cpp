#include "form_maintenance___backup_restoree.h"
#include "ui_form_maintenance___backup_restoree.h"

#include "dataanimals.h"
#include "FormsMenu/form_maintenance___backup_restoree_dialog.h"
#include "csv/csvfile.h"

#include <QCheckBox>
#include <QProcess>

Form_maintenance___backup_restoree::Form_maintenance___backup_restoree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_maintenance___backup_restoree)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(600, 100, 900, 700));

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


    ui->pushButton_new->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );
    ui->pushButton_submit->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                "color: white;"
                                                                                "padding: 4 50 4 10;"
        );



    ui->tableWidget->setColumnWidth(0, this->width()/3);
    ui->tableWidget->setColumnWidth(1, this->width()/3);
    ui->tableWidget->setColumnWidth(2, this->width()/3);
    ui->tableWidget->setColumnWidth(3, this->width()/3);

    GetData();


}

void Form_maintenance___backup_restoree::GetData()
{
    QString folder = DataSystems::Instance().savePath + "/";
    //folder = "d:/img2/";
    int j=0;
    std::vector<std::string> vec = csvfile::ReadFiles(folder.toStdString().c_str());
    for(int k=0; k<vec.size();k++)
    {
        if(QString::fromStdString(vec[k]).toLower().contains("backup")&&
           QString::fromStdString(vec[k]).toLower().contains(".sql"))
        {
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );

            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState(Qt::CheckState::Unchecked); //(rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(j,0,checkbox);

            ui->tableWidget->setItem( j, 1,  new QTableWidgetItem( QString::fromStdString(vec[k]) ));
            qDebug()<<"backup["<<j<<"]: "<<QString::fromStdString(vec[k]);
            j++;
        }
    }

    return;

    ui->tableWidget->clear();
    //ui->comboBox_number->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString sql =  (QString("SELECT * FROM public.")+QString("tab")+(" ORDER BY id ASC ")).toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        //auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

        //QStringList NameColumns;
        //NameColumns<<" "<<"Номер животного"<<"Номер Робота"<<"Номер лактации"<<"Дни лактации"<<"От даты"<<"До даты"<<"Активная машрутизация";

        //ui->tableWidget->setColumnCount( NameColumns.count() );

        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Сухостойность"));
        //ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

        //for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        int i=0;
        while(query->next())
        {
            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);
            ui->tableWidget->setCellWidget(i,0,checkbox);

            ui->tableWidget->setItem( i, 1,  new QTableWidgetItem( query->value("animal_No").toString() ));
            //ui->comboBox_number->addItem(query->value("animal_No").toString());

            ui->tableWidget->setItem( i, 2,  new QTableWidgetItem( query->value("Robot_No").toString() ));
            ui->tableWidget->setItem( i, 3,  new QTableWidgetItem( query->value("lactation_No").toString() ));
            ui->tableWidget->setItem( i, 4,  new QTableWidgetItem( query->value("lactation_days").toString() ));
            ui->tableWidget->setItem( i, 5,  new QTableWidgetItem( query->value("area").toString() ));
            ui->tableWidget->setItem( i, 6,  new QTableWidgetItem( query->value("from_date").toString() ));
            ui->tableWidget->setItem( i, 7,  new QTableWidgetItem( query->value("till_date").toString() ));
            ui->tableWidget->setItem( i, 8,  new QTableWidgetItem( query->value("from_till_time").toString() ));
            ui->tableWidget->setItem( i, 9,  new QTableWidgetItem( query->value("active_routing").toString() ));


            //ui->tableWidget->;
            i++;
        }
    }


    /**/

}

void Form_maintenance___backup_restoree::Db_backup(QString dump_sql)
{

  //process.startCommand("gedit /home/oDx/Documents/a.txt");

    //cout<<"\n * Program to demonstrate the usage of linux commands in qt * \n";

    QProcess process;
    QString Command;    //Contains the command to be executed
    QStringList args;   //Contains arguments of the command

    //psql -h 127.0.0.1 -p 5433  -U postgres -d vim5  -f b_home.sql
    Command = "psql ";
    args<<"-l "<<"-h "<<DataSystems::Instance().db_host<<QString(" -p ")<<QString::number(DataSystems::Instance().db_port)<<" -U "<<DataSystems::Instance().db_login<<" -d "<<DataSystems::Instance().db_name<<"  -f "<<dump_sql;

    process.start(Command,args,QIODevice::ReadOnly); //Starts execution of command
    process.waitForFinished();                       //Waits for execution to complete

    QString StdOut      =   process.readAllStandardOutput();  //Reads standard output
    QString StdError    =   process.readAllStandardError();   //Reads standard error

    cout<<"\n Printing the standard output..........\n";
    cout<<endl<<StdOut.toStdString();
    cout<<"\n Printing the standard error..........\n";
    cout<<endl<<StdError.toStdString();

}

void Form_maintenance___backup_restoree::Db_restore(QString dump_sql)
{

  //process.startCommand("gedit /home/oDx/Documents/a.txt");
  //pg_dump --dbname=postgresql://postgres:000@localhost:5433/vim3 > c:\db_backup_name3.sql

  QProcess process;
  QString Command;    //Contains the command to be executed
  QStringList args;   //Contains arguments of the command

  //psql -h 127.0.0.1 -p 5433  -U postgres -d vim5  -f b_home.sql
  Command = "pg_dump ";
  args<<" --dbname="<<
      DataSystems::Instance().db_login<<
      ":"<<
      DataSystems::Instance().db_password<<
      "@"<<
      DataSystems::Instance().db_host<<
      ":"<<
      QString::number(DataSystems::Instance().db_port) <<
      "/"<<
      DataSystems::Instance().db_name <<
      " > "<<
      DataSystems::Instance().savePath + dump_sql;

  process.start(Command,args,QIODevice::ReadOnly); //Starts execution of command
  process.waitForFinished();                       //Waits for execution to complete

  QString StdOut      =   process.readAllStandardOutput();  //Reads standard output
  QString StdError    =   process.readAllStandardError();   //Reads standard error

  cout<<"\n Printing the standard output..........\n";
  cout<<endl<<StdOut.toStdString();
  cout<<"\n Printing the standard error..........\n";
  cout<<endl<<StdError.toStdString();
}

void Form_maintenance___backup_restoree::GetData(const QString &str)
{


    QScopedPointer<DataBase> db_func(new DataBase());
    //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
    if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public.tab WHERE animal_No =  '" + str +"';").toLower();
        //logger::WriteLog("SELECT vars: ----- " + sql);

        QSqlQuery* query = db_func->sql_exec2(sql);

        if(query->size()<1)return;
        //logger::WriteMsg("чтение завершено: кол-во записей: "+ query->size());

        int i=0;
        while(query->next())
        {
            QVariant val;

            val = query->value("animal_No"); DataSystems::Instance().routing_animal_No =  (!val.isNull())?val.toString():" ";
            val = query->value("Robot_No"); DataSystems::Instance().routing_Robot_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_No"); DataSystems::Instance().routing_lactation_number =  (!val.isNull())?val.toString():" ";
            val = query->value("lactation_days"); DataSystems::Instance().routing_lactation_days =  (!val.isNull())?val.toString():" ";
            val = query->value("area"); DataSystems::Instance().routing_area =  (!val.isNull())?val.toString():" ";
            val = query->value("from_date"); DataSystems::Instance().routing_from_date =  (!val.isNull())?val.toString():" ";
            val = query->value("till_date"); DataSystems::Instance().routing_till_date =  (!val.isNull())?val.toString():" ";
            val = query->value("from_till_time"); DataSystems::Instance().routing_from_till_time =  (!val.isNull())?val.toString():" ";
            val = query->value("active_routing"); DataSystems::Instance().routing_active_routing =  (!val.isNull())?val.toString():" ";
            /**/

            break;
        }
    }

    /**/

}



Form_maintenance___backup_restoree::~Form_maintenance___backup_restoree()
{
    delete ui;
}

void Form_maintenance___backup_restoree::on_pushButton_new_clicked()
{

}


void Form_maintenance___backup_restoree::on_pushButton_submit_clicked()
{
    {
        form_maintenance___backup_restoree_Dialog tf(this);
        if(!(tf.exec()==QDialog::Accepted))
        {
            //QMessageBox::information(this,"Спасибо","Сухостойность");
        }

    }


}

