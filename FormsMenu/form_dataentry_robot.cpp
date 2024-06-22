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

#include "utils/dialog_viewphoto.h"
#include <QMessageBox>

#include "tabelwidget_module2/CustomDelegateView.h"
#include "tabelwidget_module2/customdelegate.h"

#include "zf_itemview/zf_table_view.h"
#include "zf_itemview/zf_tree_view.h"

#include <QDebug>
#include <QMessageBox>
#include <QkeyEvent>
#include <QList>

#include <QPrintPreviewDialog>


#include "Src/pbs/pbsfileutil.h"
#include "Src/pbs/pbstools.h"
#include "Src/pbsmodelexporter.h"
#include "src/pbstableprinter.h"






form_dataentry_Robot::form_dataentry_Robot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_Robot)
    , actSaveExcel(PBSTR("Excel "), this)
    , actSaveExcelXML(PBSTR("Excel (XML)"), this)
    , actSaveWordXML(PBSTR("Word (XML)"), this)
    , actSavePDF(PBSTR("PDF "), this)
    , actSaveCSV(PBSTR("Text (CSV)"), this)
    , actSaveXML(PBSTR("XML "), this)
    , actSaveHTML(PBSTR("HTML "), this)
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


    create_table_view();


}

void form_dataentry_Robot::createButton() {
    logger::WriteMsg("void form_dataentry_Robot::createButton()");
    //logger::WriteMsg("createButton() " + QString::number(index));
    logger::WriteMsg("createButton() ");
    CustomDelegate *delegate = new CustomDelegate(12,this);
    ui->tableView->setItemDelegateForColumn(12,delegate);

    connect(
        delegate,
        &CustomDelegate::signalClicked,
        [this](QModelIndex index)
        {
            int result = QMessageBox::warning(this,"Warnings", "delete?", QMessageBox::Yes, QMessageBox::No);
            if(result == QMessageBox::Yes) this->onBtnClicked(index);
        }
        );

//    connect(delegate, &CustomDelegate::signalClicked, ui->tableView, [this](QModelIndex index) {
//        int result = QMessageBox::warning(this, "Предупреждение!", "Подтвердите удаление", QMessageBox::Yes, QMessageBox::No);
//        if(result == QMessageBox::Yes);
//            //this->onBtnClicked(index);
//    });
}

void form_dataentry_Robot::onBtnClicked(QModelIndex index)
{
    //model->deleted(index.row());
}


form_dataentry_Robot::~form_dataentry_Robot()
{
    delete ui;
}

void form_dataentry_Robot::PhotoView_Dialog()
{
    //OutputLog(QString::number(row));

    //DataSystems::Instance().savePath = QApplication::applicationDirPath();

    QString fileNamePicture = DataSystems::Instance().robot_paramfilephoto1; //ui->comboBox->currentText();
    //OutputLog(fileNamePicture);

    //fileNamePicture = "https://demotivatorium.ru/sstorage/3/2014/09/13001529222202/demotivatorium_ru_a_chto_eto_vi_tut_delaete_a_58272.jpg";
    Dialog_ViewPhoto dvf(fileNamePicture, this);

    if(!(dvf.exec()==QDialog::Accepted))
    {
        //QMessageBox::information(this,"Спасибо","Сухостойность");
    }

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
            db_func->sql_exec(sql_insert, "add robot");
        }
    }
}

void form_dataentry_Robot::GetData()
{
    logger::WriteMsg("robot record getdata: ");// + QString::number(i).toStdString());
    GetData_search(searchText);
    return;    
    /**/
}

void form_dataentry_Robot::on_tableWidget_cellEntered2(int row, int column)
{
//    if(column !=2 && column!=3)return;
//    //OutputLog(QString::number(row) + "|" + QString::number(column));
//    QString id = "";
//    QTableWidgetItem *item = tableWidget->item(row,0);
//    if (NULL != item) {
//        id = item->text();
//        DataSystems::Instance().robot_id = id;
//        //OutputLog(id);
//        GetDataImage(id);
//        if(DataSystems::Instance().robot_paramfile1==nullptr)
//        {
//            //OutputLog(QString("Empty photo") + "|" + QString::number(row) + "|" + QString::number(column));
//            return;
//        }

//        PhotoView_Dialog();
//    }
    return;
}

void form_dataentry_Robot::OutputLog(QString f)
{

}

void form_dataentry_Robot::GetDataImage(QString id)
{
    /*

    //tableWidget->row()

    //tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
    for(int i=0;i<tableWidget->columnCount();i++)tableWidget->setColumnWidth(i, 250);

    tableWidget->update();

    QString str = "vz";

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public.dataentry_robot WHERE id =  '" + id +"';").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        int i=0;
        while(query->next())
        {
            QString val_out="";
            {
                QVariant val = query->value("paramfile1");
                DataSystems::Instance().robot_paramfile1 = (!val.isNull())?val.toByteArray():nullptr;
                if(DataSystems::Instance().robot_paramfile1!=nullptr)
                {
                    OutputLog("Empty photo");
                    DataSystems::Instance().robot_paramfilephoto1 = DataSystems::Instance().savePath+"/" + QString::fromStdString(logger::CreateLogName2())+ "_" + fileName+".jpg";
                    QFileInfo file(DataSystems::Instance().robot_paramfilephoto1);
                    if(file.exists()){
                        QMessageBox::critical(this, tr("Пожалуйста, обрати внимание:") ,tr("В текущем пути уже есть файл с таким именем, пожалуйста, выберите новый путь, чтобы сохранить файл!"), QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0 );
                    }else{
                        newFile = new QFile(DataSystems::Instance().robot_paramfilephoto1);
                        newFile->open(QFile::WriteOnly);
                        newFile->write(DataSystems::Instance().robot_paramfile1);
                        newFile->flush();
                        newFile->close();
                    //            fileExits = true;
                }
                }
            }
            {
                QVariant val = query->value("param1");
                DataSystems::Instance().robot_param1 = (!val.isNull())?val.toString():" ";
            }
            {
                QVariant val = query->value("paramtime1");
                DataSystems::Instance().robot_paramtime1 = (!val.isNull())?val.toString():" ";
            }
            {
                //QVariant val = query->value("id");
                //val_out+=QString("id") + " = "  +((!val.isNull())?val.toString():" ");
            }
            i++;
            //break;
        }
    }
    else{
        OutputLog("No connection db <<<VIM>>>");
    }
    /**/

}


void form_dataentry_Robot::GetData(const QString &str)
{
    //return;
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


void form_dataentry_Robot::GetData_search(const QString &str)
{
    /*
    //if(tableWidget->rowCount()>0)tableWidget->clear();
    tableWidget->clear();
    ui->comboBox_id->clear();

    //tableWidget->dele;

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "dataentry_robot";
        QString sql = QString("SELECT * FROM public."+tab+" WHERE id>0  ORDER BY id;").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query!=nullptr)
        {
        //if(query->size()<1)return;

        auto datetimeDelegate = new DateTimeStyledItemDelegate(tableWidget);
        QStringList NameColumn;
        int i=0;
        NameColumn<<"id"<<"Robot N"<<"paramfile1"<<"paramfile2"<<"координаты левого нижнего соска"<<"координаты левого верхнего соска"<<"координаты правого нижнего соска"<<"координаты правого верхнего соска"<<"param1"<<"param2"<<"param3"<<"param4"<<"paramtime1"<<"paramеtime2"<<"paramtime3"<<"paramtime4";
        tableWidget->setColumnCount( NameColumn.count() );
        tableWidget->setRowCount( query->size() );
        tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
        tableWidget->setHorizontalHeaderLabels( NameColumn );

        for(int i=0;i<NameColumn.count();i++)tableWidget->setColumnWidth(i, 250);

        i=0;
        while(query->next())
        {
            //tableWidget->insertRow( tableWidget->rowCount() );
            QCheckBox *checkbox = new QCheckBox();
            checkbox->installEventFilter(this);
            checkbox->setText("");
            checkbox->setCheckState((rand()%20==4)?Qt::CheckState::Checked:Qt::CheckState::Unchecked);

            //logger::WriteMsg("robot record: " + QString::number(i).toStdString());

            tabwidget_insert_add_column(query,tableWidget,"id", i, 0);
            ui->comboBox_id->addItem(query->value("id").toString());
            tabwidget_insert_add_column(query,tableWidget,"robot_no", i, 1);
            tabwidget_insert_add_column(query,tableWidget,"paramfile1", i, 2);
            tabwidget_insert_add_column(query,tableWidget,"paramfile2", i, 3);
            tabwidget_insert_add_column(query,tableWidget,"coord_teat_lf", i, 4);
            tabwidget_insert_add_column(query,tableWidget,"coord_teat_lr", i, 5);
            tabwidget_insert_add_column(query,tableWidget,"coord_teat_rf", i, 6);
            tabwidget_insert_add_column(query,tableWidget,"coord_teat_rr", i, 7);
            tabwidget_insert_add_column(query,tableWidget,"param1", i, 8);
            tabwidget_insert_add_column(query,tableWidget,"param2", i, 9);
            tabwidget_insert_add_column(query,tableWidget,"param3", i, 10);
            tabwidget_insert_add_column(query,tableWidget,"param4", i, 11);
            tabwidget_insert_add_column(query,tableWidget,"paramtime1", i, 12);
            tabwidget_insert_add_column(query,tableWidget,"paramtime2", i, 13);
            tabwidget_insert_add_column(query,tableWidget,"paramtime3", i, 14);
            tabwidget_insert_add_column(query,tableWidget,"paramtime4", i, 15);

            i++;
        }
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

void form_dataentry_Robot::tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, const QString &nameColumnX,  int numRow, int numColumn)
{    
    QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";

    //return;
    logger::WriteMsg(QString("robot vars: " + nameColumnX).toStdString());


    if(nameColumnX.contains("coord"))
    {
        logger::WriteMsg(QString("robot vars: " + nameColumnX).toStdString());
        QVariant val = query->value(nameColumnX);
        double var =  (!val.isNull())?val.toDouble():0;

        QTableWidgetItem *item = new QTableWidgetItem(((!val.isNull())?val.toString():""));
        item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);

        QTime a(0,0,0);
        a = a.addSecs(int(var));
        QString time = a.toString();        

    }    
    else if(nameColumnX.contains("paramtime"))
    {

        QVariant val = query->value(nameColumnX);
        QString t_ = (!val.isNull())?val.toString():"";
        if(t_== "")
        {
            QTableWidgetItem *item = new QTableWidgetItem(t_);
            item->setTextAlignment(Qt::AlignHCenter);
            tab->setItem( numRow, numColumn,  item);
        }
        else
        {
            QDateTime a;
            //QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs).currentDateTimeUtc().toLocalTime();
            QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs);
            double xi = time2.toTime_t();
            QString time = time2.toString("yyyy-MM-dd hh:mm:ss.zzzZ");
            QTableWidgetItem *item = new QTableWidgetItem(time);
            item->setTextAlignment(Qt::AlignHCenter);
            tab->setItem( numRow, numColumn,  item);
        }
    }

    else if(nameColumnX.toLower().contains("paramfile"))
    {
        //return;
        QByteArray ba = query->value(nameColumnX).toByteArray();

        if(ba == nullptr)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString("[empty binary data]"));
            item->setTextAlignment(Qt::AlignHCenter);
            tab->setItem( numRow, numColumn,  item);
            return;
        }
        else
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString("[photo binary data]"));
                item->setTextAlignment(Qt::AlignHCenter);
                tab->setItem( numRow, numColumn,  item);
                return;
            }
        return;        
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
}




void form_dataentry_Robot::on_comboBox_id_activated(int index)
{
    /*
    mTimer->stop();
    //DataSystems::Instance().clear_otel();

    int i=0;
    selectRow=-1;
    //qDebug()<<"check: "<<ui->comboBox->currentText();
    //QString check = ui->comboBox->currentData(index).toString();
    checkId = ui->comboBox_id->currentText();
    for(i=0;i<tableWidget->rowCount();i++)
    {
        QString val;
        QTableWidgetItem *item = tableWidget->item(i,0);
        qDebug()<<"--- break: "<<"i: "<<i<<"; "<<val;
        if (NULL != item) {
            val = item->text();
            qDebug()<<"check: "<<checkId<<"; "<<"i: "<<i<<"; "<<val;
            if(checkId.contains(val))
            {
                selectRow = i;
                if(selectRowOld!=-1)tableWidget->item(selectRowOld,0)->setBackground( Qt::white);
                tableWidget->item(selectRow,0)->setBackground( Qt::gray);
                selectRowOld=selectRow;
                break;
            }
        }
    }
    //mTimer->start(1000);

    /**/

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


void form_dataentry_Robot::create_table_view()
{
//    //    _table_model.setColumnCount(COL_COUNT);
//    //    _table_model.setRowCount(ROW_COUNT);
//    //    for(int row = 0; row < ROW_COUNT;row++)
//    //    {
//    //       for(int col = 0; col < COL_COUNT; col++)
//    //        {
//    //            _table_model.setData(_table_model.index(row,col),
//    //                         QString::number(row)+QString("|")+QString::number(col),
//    //                                Qt::EditRole);
//    //        }
//    //    }



//    //logger::WriteLog("GetData()");
//    //ui->textEdit->setText(DataSystems::Instance().log);

//    GetData();

//    ui->tableView = new zf::TableView;
//    ui->tableView->setAutoResizeRowsHeight(false);
//    ui->tableView->setSortingEnabled(true);
//    ui->tableView->setModel(&_table_model);

//    configureHeader2(ui->tableView->horizontalRootHeaderItem());

//    QString text = "";


    fileName = "";  //имя файла

    //tableWidget = new ExtendQTableWidget(this);
    //ui->verticalLayout->addWidget(tableWidget);
    //connect(tableWidget, SIGNAL(cellEntered(int,int)), this, SLOT(on_tableWidget_cellEntered2(int,int)));
    //mTimer=new QTimer(this);
    //connect(mTimer, SIGNAL(timeout()),this, SLOT(GetData()));
    //mTimer->start(1000);

    //AsyncSql::DatabaseConnection::setDefaultDatabaseName(QApplication::applicationDirPath()+"/"+ "example.db");
    AsyncSql::DatabaseConnection::setDefaultDriver(AsyncSql::DatabaseConnection::QPSQL);
    AsyncSql::DatabaseConnection::setDefaultHostName(DataSystems::Instance().db_host);
    AsyncSql::DatabaseConnection::setDefaultDatabaseName(DataSystems::Instance().db_name);
    AsyncSql::DatabaseConnection::setDefaultPort(DataSystems::Instance().db_port);
    AsyncSql::DatabaseConnection::setDefaultUserName(DataSystems::Instance().db_login);
    AsyncSql::DatabaseConnection::setDefaultPassword(DataSystems::Instance().db_password);
    TableName = "dataentry_robot";
    //OptionsDialog::setTableName("per_test");

    model = new AsyncSql::AsyncSqlTableModel(this);

    model->setTable(TableName);
    //model->setTable(OptionsDialog::getTableName());
    //ui->tableView->verticalHeader()->hide();                                                //Скрытие вертикального заголовка таблицы
    ui->tableView->setModel(model);
    model->select();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    //connect(model, SIGNAL(AsyncSql::AsyncSqlTableModel::dataUpdated()), this, SLOT(createButton()));
    //createButton();
    //GetData();

    createPopupMenu_();
    connect(ui->tableView, SIGNAL(onCreatePopupMenu(QMenu *)), SLOT(onCreateFooterMenu(QMenu *)));    
    connect(&actSaveExcel, &QAction::triggered, this, &form_dataentry_Robot::onActSaveExcel);
    connect(&actSaveExcelXML, &QAction::triggered, this, &form_dataentry_Robot::onActSaveExcelXML);
    connect(&actSaveWordXML, &QAction::triggered, this, &form_dataentry_Robot::onActSaveWordXML);
    connect(&actSavePDF, &QAction::triggered, this, &form_dataentry_Robot::onActSavePDF);
    connect(&actSaveCSV, &QAction::triggered, this, &form_dataentry_Robot::onActSaveCSV);
    connect(&actSaveXML, &QAction::triggered, this, &form_dataentry_Robot::onActSaveXML);
    connect(&actSaveHTML, &QAction::triggered, this, &form_dataentry_Robot::onActSaveHTML);
    connect(&actSendToPrinter, &QAction::triggered, this, &form_dataentry_Robot::onActSendToPrinter);

    //connect(ui->tableView->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));
    connect(ui->tableView->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));

    //ui->textEdit->setText(text);
}

void form_dataentry_Robot::createPopupMenu_()
{
    popupMenu.clear();
    //popupMenu.addAction(&actSortAsc);
    //popupMenu.addAction(&actSortDesc);
    //popupMenu.addSeparator();
    //popupMenu.addAction(&actFooter);
    //popupMenu.addAction(&actFilter);
    //popupMenu.addSeparator();
    //popupMenu.addAction(&actSendToPrinter);
    //popupMenu.addSeparator();
    //popupMenu.addAction(&actStretchColumn);
    //popupMenu.addAction(&actStretchColumnAll);
    //popupMenu.addAction(&actStretch);

    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    popupMenu.addSeparator();
    //QMenu *saveAsMenu = popupMenu.addMenu(QIcon(":/Resource/Images/save.png"), ("Преобразовать в  ..."));
    QMenu *saveAsMenu = popupMenu.addMenu(PBSTR("Transpose -> (EXCEL)Преобразовать в  ..."));
    saveAsMenu->addAction(&actSaveExcel);
    saveAsMenu->addAction(&actSaveExcelXML);
    saveAsMenu->addAction(&actSaveWordXML);
    //saveAsMenu->addSeparator();
    saveAsMenu->addAction(&actSavePDF);
    saveAsMenu->addAction(&actSaveCSV);
    saveAsMenu->addAction(&actSaveXML);
    saveAsMenu->addAction(&actSaveHTML);

    //popupMenu.addSeparator();
    //popupMenu.addAction(&actSaveLayout);

    emit onCreatePopupMenu(HeaderMenu, &popupMenu);
}


void form_dataentry_Robot::showCustomContextMenu(const QPoint &p)
{

    logger::WriteMsg("showCustomContextMenu");

    QPoint mP = mapToGlobal(p);
    //mP.setY(mP.y()-50);

    //int iCol = ui->tableView->horizontalHeader()->logicalIndexAt(p),
    // iSort = ui->tableView->horizontalHeader()->sortIndicatorSection();

    //actSortAsc.setChecked(iCol == iSort && ui->tableView->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder);
    //actSortDesc.setChecked(iCol == iSort && ui->tableView->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);

    popupMenu.popup(mP);
}

void form_dataentry_Robot::onActSaveExcelXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewExcelXMLExporter e(ui->tableView, &f, this);
        e.execute();
        f.close();
    }
}

void form_dataentry_Robot::onActSaveWordXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewWordXMLExporter e(ui->tableView, &f, this);
        e.execute();
        f.close();
    }
}

void form_dataentry_Robot::onActSaveCSV()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewCSVExporter e(ui->tableView, &f, this);
        e.execute();
        f.close();
    }
}

void form_dataentry_Robot::onActSaveHTML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewHTMLExporter e(ui->tableView, &f, this);
        e.execute();
        f.close();
    }
}

void form_dataentry_Robot::onActSaveExcel()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        PBSTableViewXLSXExporter e(ui->tableView, sName, this);
        e.execute();
    }
}

void form_dataentry_Robot::onActSaveXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewXMLExporter e(ui->tableView, &f, this);
        e.execute();
        f.close();
    }
}

void form_dataentry_Robot::onActSavePDF()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        PBSTableViewPDFExporter e(ui->tableView, sName, this);
        e.execute();
    }
}

void form_dataentry_Robot::onActSendToPrinter()
{
    QPrinter printer(QPrinter::ScreenResolution);
    printer.setPaperSize(QPrinter::A4);
    printer.setFullPage(false);

    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins(0, 0, 0, 0, QPrinter::Unit::Millimeter);
    printer.setResolution(96); // QApplication::screens().at(0)->logicalDotsPerInch());

    QPrintPreviewDialog d(&printer, reinterpret_cast<QWidget*>(parent()));
    d.setWindowFlags(Qt::Window | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    connect(&d, SIGNAL(paintRequested(QPrinter *)), this, SLOT(print(QPrinter *)));

    d.exec();
}

void form_dataentry_Robot::print(QPrinter *prn)
{
    QPainter painter;

    painter.begin(prn);

    PBSTablePrinter p(&painter, ui->tableView, this);
    p.setPrinter(prn);

    p.setHeadersFont(ui->tableView->horizontalHeader()->font());
    p.setContentFont(font());

    p.execute();
}



void form_dataentry_Robot::onCreateFooterMenu(QMenu *m)
{
    emit onCreatePopupMenu(FooterMenu, m);
}

