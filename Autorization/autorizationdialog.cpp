#include "autorizationdialog.h"
#include "ui_autorizationdialog.h"

#include "Debug/logger.h"
#include "dataanimals.h"
#include <QSharedPointer>
#include <QFile>
#include <QDateTime>



AutorizationDialog::AutorizationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutorizationDialog)
{
    ui->setupUi(this);

    //***************** Установка белого цвета приложения и размеров ****************************//
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    setGeometry(QRect(600, 300, 400, 200));
    //***************** End Установка белого цвета приложения и размеров ****************************//

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                                                                    "padding: 4 20000 4 10;"
                                                                                    "}");

   // *****************************************************************************************************

    //this->setToolTip("Введите данные авторизации: ip: ");

   // *****************************************************************************************************



    GetAutorization();

    ui->comboBox_db->addItem("Server(PostgreSQL)");
    ui->comboBox_db->addItem("Local(SQLite)");
    //DataSystems::Instance().db_check_create = (ui->checkBox->checkState()==::Qt::CheckState::Checked)?true:false;
    ui->checkBox->setCheckState(DataSystems::Instance().db_check_create?(Qt::CheckState::Checked):Qt::CheckState::Unchecked);
    (DataSystems::Instance().db_check==DB_check::PGSQL)?ui->comboBox_db->setCurrentIndex(0):ui->comboBox_db->setCurrentIndex(1);
    //(DataSystems::Instance().db_check==DB_check::PGSQL)?ui->comboBox_db->setCurrentIndex(0):
        ui->comboBox_db->setCurrentIndex(0); // по умолчанию postgresql

    if(ui->comboBox_db->currentText().toLower().contains("postgre"))
    {
            ui->lineEdit_password->setEnabled(true);
            ui->lineEdit_login->setEnabled(true);
            ui->lineEdit_name_db->setEnabled(true);
            ui->lineEdit_Port->setEnabled(true);
            ui->lineEdit_host->setEnabled(true);

        ui->lineEdit_host->setText(DataSystems::Instance().db_host);
        ui->lineEdit_name_db->setText(DataSystems::Instance().db_name);
        ui->lineEdit_Port->setText(QString::number(DataSystems::Instance().db_port));
        ui->lineEdit_login->setText(DataSystems::Instance().db_login);
        ui->lineEdit_password->setText(DataSystems::Instance().db_password);
        DataSystems::Instance().db_check =  DB_check::PGSQL;        
    }
    if(ui->comboBox_db->currentText().toLower().contains(QString("sqlite").toLower()))
    {
        ui->lineEdit_host->setText("");
        //DataSystems::Instance().db_name = DataSystems::Instance().db_sqlite_file;
        ui->lineEdit_name_db->setText(DataSystems::Instance().db_sqlite_file);
        DataSystems::Instance().db_name = DataSystems::Instance().db_sqlite_file;
        //ui->lineEdit_Port->setText("");
        //ui->lineEdit_login->setText("");
        //ui->lineEdit_password->setText("");
        DataSystems::Instance().db_check =  DB_check::SQLITE;

        ui->lineEdit_password->setEnabled(false);
        ui->lineEdit_login->setEnabled(false);
        ui->lineEdit_Port->setEnabled(false);
        ui->lineEdit_host->setEnabled(false);
        ui->lineEdit_name_db->setEnabled(false);

        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);

    }


    if(ui->lineEdit_login->text().toLower()!="postgres")
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
    }



    setWindowTitle("Форма авториазции в систем ""ЦИФРОВАЯ ФЕРМА:""");

}

AutorizationDialog::~AutorizationDialog()
{
    delete ui;
}

void AutorizationDialog::GetAutorization()
{
    //return;
    logger::WriteMsg("<<< " + DataSystems::Instance().db_sqlite_file_autorization.toStdString() + " >>>");

    QFile f_sqlite(DataSystems::Instance().db_sqlite_file_autorization);    
    if (!f_sqlite.exists())
    {
        qDebug()<<"Not exists sqlite file autorization: ";
        return;
    }
    qDebug()<<"!!!!!!!! Exists sqlite file autorization: ";
    f_sqlite.close();
    {
        QScopedPointer<DataBase> db_func_sqlite_autorization(new DataBase("sqlite"));
        //QSqlDatabase db2=QSqlDatabase::database(DataSystems::Instance().conn_name);
        if(db_func_sqlite_autorization->StatusOpenSQLite())
        {
            logger::WriteMsg("Read data user autorization ");
                     /*
                      *
                      *
                      // CREATE TABLE [LocalSettings] ([id] INTEGER PRIMARY KEY NOT NULL, [ParameterName] NVARCHAR(32) UNIQUE,  [ParameterValue] NVARCHAR(512) )

                        db_func_sqlite_autorization->sql_exec("CREATE TABLE IF NOT EXISTS  autorization_local_data"
                                          "(ID INTEGER PRIMARY KEY   AUTOINCREMENT, "
                                          "hostname text,"
                                          "db_name text,"
                                          "port text,"
                                          "login_ text,"
                                          "password_ text,"
                                          "date_ text,"
                                          "param text"
                                          ")");

                        /**/

            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("hostname"));
               query->next();
               DataSystems::Instance().db_host = query->value(1).toString();
               //qDebug()<<" ------ host: "<<DataSystems::Instance().db_host;
               qDebug()<<" ------ host: "<<query->value(1).toString()<<" ------ host: "<<query->value(0).toString()<<" ------ host: "<<query->value(2).toString();
            }
            //return;
            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("db_name"));
               query->next();
               DataSystems::Instance().db_name = query->value(1).toString();
               qDebug()<<" ------ host: "<<DataSystems::Instance().db_name;
            }
            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("db_port"));
               query->next();
               DataSystems::Instance().db_port = query->value(1).toInt();
               qDebug()<<" ------ host: "<<DataSystems::Instance().db_port;
            }
            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("db_login"));
               query->next();
               DataSystems::Instance().db_login = query->value(1).toString();

            }
            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("db_password"));
               query->next();
               DataSystems::Instance().db_password = query->value(1).toString();
            }
            {
               QSqlQuery* query = db_func_sqlite_autorization->sql_exec2(db_func_sqlite_autorization->GetParameter("date_work"));
               query->next();
               DataSystems::Instance().db_date_work = query->value(1).toString();
            }


            QDateTime dt1 = QDateTime::currentDateTime();
            QString date_ = dt1.toString("yyyy-MM-dd hh:mm:ss.ms");

            qDebug()<<" | "<<DataSystems::Instance().db_sqlite_file_autorization<<" | "<<date_<<" - num autorization - "<<
                        "|"<<
                        DataSystems::Instance().db_host<<"|"<<
                        DataSystems::Instance().db_name<<"|"<<
                        DataSystems::Instance().db_port<<"|"<<
                        DataSystems::Instance().db_login<<"|"<<
                        DataSystems::Instance().db_password<<"|"<<
                        DataSystems::Instance().db_date_work;

        }

    }

}

void AutorizationDialog::on_pushButton_exit_clicked()
{
    DataSystems::Instance().exit_application=true;    
    this->close();
}


void AutorizationDialog::on_pushButton_logon_clicked()
{        
    if(ui->comboBox_db->currentText().toLower().contains("postgre"))
    {
        DataSystems::Instance().db_host = ui->lineEdit_host->text();
        DataSystems::Instance().db_name = ui->lineEdit_name_db->text();
        DataSystems::Instance().db_port = ui->lineEdit_Port->text().toInt();
        DataSystems::Instance().db_login = ui->lineEdit_login->text();
        DataSystems::Instance().db_password = ui->lineEdit_password->text();
        DataSystems::Instance().db_check =  DB_check::PGSQL;
    }
    else if(ui->comboBox_db->currentText().toLower().contains(QString("sqlite").toLower()))
    {
        //DataSystems::Instance().db_host = "";
        DataSystems::Instance().db_name = ui->lineEdit_name_db->text();
        //DataSystems::Instance().db_login = "";
        //DataSystems::Instance().db_password = "";
        DataSystems::Instance().db_check =  DB_check::SQLITE;
    }

    DataSystems::Instance().exit_application=false;
    this->close();
}


void AutorizationDialog::on_comboBox_db_activated(int index)
{
    ui->comboBox_db->setCurrentIndex(index);
    if(ui->comboBox_db->currentText().toLower().contains("postgre"))
    {
        ui->lineEdit_password->setEnabled(true);
        ui->lineEdit_login->setEnabled(true);
        ui->lineEdit_Port->setEnabled(true);
        ui->lineEdit_host->setEnabled(true);

        ui->lineEdit_host->setText(DataSystems::Instance().db_host);
        ui->lineEdit_name_db->setText(DataSystems::Instance().db_name);
        ui->lineEdit_login->setText(DataSystems::Instance().db_login);
        ui->lineEdit_password->setText(DataSystems::Instance().db_password);
        DataSystems::Instance().db_check =  DB_check::PGSQL;
    }
    else if(ui->comboBox_db->currentText().toLower().contains(QString("sqlite").toLower()))
    {
        ui->lineEdit_password->setEnabled(false);
        ui->lineEdit_login->setEnabled(false);
        ui->lineEdit_Port->setEnabled(false);
        ui->lineEdit_host->setEnabled(false);

        //ui->lineEdit_host->setText("");
        //DataSystems::Instance().db_name = DataSystems::Instance().db_sqlite_file;
        ui->lineEdit_name_db->setText(DataSystems::Instance().db_sqlite_file);
        //ui->lineEdit_login->setText("");
        //ui->lineEdit_password->setText("");
        DataSystems::Instance().db_check =  DB_check::SQLITE;        
    }
}


void AutorizationDialog::on_checkBox_stateChanged(int arg1)
{
    //ui->checkBox->setCheckState(DataSystems::Instance().db_check_create?(Qt::CheckState::Checked):Qt::CheckState::Unchecked);
    //qDebug()<<"state create db: "<<ui->checkBox->checkState();

    DataSystems::Instance().db_check_create=ui->checkBox->checkState()==Qt::CheckState::Checked?true:false;
}


void AutorizationDialog::on_lineEdit_login_textChanged(const QString &arg1)
{
    //if(!arg1.toLower().contains("postgres"))
    if(!(arg1 =="postgres"))
    {
        ui->checkBox->setEnabled(false);
        ui->checkBox->setCheckState(Qt::CheckState::Unchecked);
    }
    else
    {
        ui->checkBox->setEnabled(true);

    }

}

