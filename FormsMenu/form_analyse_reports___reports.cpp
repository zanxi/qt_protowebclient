#include "form_analyse_reports___reports.h"
#include "FormsMenu/ui_form_analyse_reports___reports.h"

#include "dataanimals.h"
#include "Debug/logger.h"

#include "utils/qcustomplot.h"
#include "utils/axistag.h"

#include "generatedbdata.h"
#include "worker.h"


Form_analyse_reports___reports::Form_analyse_reports___reports(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_analyse_reports___reports)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    setWindowTitle("Сухостойность");


    ui->tabWidget->setStyleSheet("QTabWidget"
                                 "{"
                                 "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabWidget:tab-bar"
                                                                                               "{"
                                                                                               "    alignment: center;"
                                                                                               "}"

                                                                                               "QTabBar:tab"
                                                                                               "{"
                                                                                               "   width: "+DataSystems::Instance().settings___tabwidget_width+";"
                                                                                               "   height: 30px;"
                                                                                               "}"

                                                                                               "QTabBar:selected"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"

                                                                                               "QTabBar:tab:!selected"
                                                                                               "{"
                                                                                               "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "}"


                                                                                               "QTabBar:tab:!selected:hover"
                                                                                               "{"
                                                                                               "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
                                                                                               "    color.rgb(255,255,255);"
                                                                                               "}"
                                                                                               ")");


    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:"+DataSystems::Instance().settings___color_header+";"
                                "padding: 4 20000 4 10;"
                                "}");
    ui->groupBox_3->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                  "padding: 4 20000 4 10;"
                                  "}");

    ui->groupBox_4->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:"+DataSystems::Instance().settings___color_header+";"
                                  "padding: 4 20000 4 10;"
                                  "}");



    ui->pushButton->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    ui->pushButton_2->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_3->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_4->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    ui->pushButton_down->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_up->setStyleSheet(
        "background-color:"+DataSystems::Instance().settings___color_header+";"
        "color: white;"
        "padding: 4 50 4 10;"
        );

    setupAdvancedAxesDemo();
    //plotRandom_();

    {
        QScopedPointer<DataBase> db_func(new DataBase());
        if(db_func->StatusOpen())
        {
           QString sql =  QString("SELECT * FROM  dataentry_robot  ORDER BY id ASC ").toLower();
           QSqlQuery* query = db_func->sql_exec2(sql);
           DataSystems::Instance().dataentry_robot_counter = query->size();
        }
    }

    mTimer=new QTimer(this);
    connect(mTimer, SIGNAL(timeout()),this, SLOT(plotRandom_()));
    mTimer->start(milliSeconds);

}

Form_analyse_reports___reports::~Form_analyse_reports___reports()
{
    delete ui;
}

void Form_analyse_reports___reports::on_pushButton_4_clicked()
{
    //this->close();
}


void Form_analyse_reports___reports::on_pushButton_clicked()
{

}

void Form_analyse_reports___reports::setupAdvancedAxesDemo()
{

    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    QPointer<QCPGraph> mGraph3;
    QPointer<QCPGraph> mGraph4;
    AxisTag *mTag1;
    AxisTag *mTag2;
    AxisTag *mTag3;

    //plot = nullptr;
    //mGraph1=nullptr;
    //mGraph2=nullptr;

    // configure plot to have two right axes:
    ui->widget->yAxis->setTickLabels(false);
    connect(ui->widget->yAxis2, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    ui->widget->yAxis2->setVisible(true);
    ui->widget->axisRect()->addAxis(QCPAxis::atRight);
    ui->widget->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags
    ui->widget->axisRect()->axis(QCPAxis::atRight, 1)->setPadding(30); // add some padding to have space for tags

    // create graphs:
    mGraph1 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph2 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 1));
    mGraph1->setPen(QPen(QColor(250, 120, 0)));
    mGraph2->setPen(QPen(QColor(0, 180, 60)));

    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());
    mTag2 = new AxisTag(mGraph2->valueAxis());
    mTag2->setPen(mGraph2->pen());

    return;

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("HH:mm:ss");
    dateTicker->setTickStepStrategy(QCPAxisTicker::TickStepStrategy::tssMeetTickCount);
    ui->widget->xAxis->setTicker(dateTicker);

    QDateTime from = QDateTime::currentDateTime().addMSecs(-3*1000*3600);
    QDateTime to = QDateTime::currentDateTime().addMSecs(1000*3600);

    ui->widget->xAxis->setRange(from.toSecsSinceEpoch(), to.toSecsSinceEpoch());

    return;

}

void Form_analyse_reports___reports::addPoint(double x, double y)
{
    cow_graph1_x.append(x);
    cow_graph1_y.append(y);
}

void Form_analyse_reports___reports::addPoint(double x, double y, double z)
{
    cow_graph1_x.append(x);
    cow_graph1_y.append(y);
    cow_graph2_y.append(z);
}

void Form_analyse_reports___reports::addPoint(double x, double y, double z, double w)
{
    cow_graph1_x.append(x);

    cow_graph1_y.append(y);
    cow_graph2_y.append(z);
    cow_graph3_y.append(w);
}

void Form_analyse_reports___reports::addPoint(double x, double y, double z, double w, double r)
{
    cow_graph1_x.append(x);

    cow_graph1_y.append(y);
    cow_graph2_y.append(z);
    cow_graph3_y.append(w);
    cow_graph4_y.append(r);
}

void Form_analyse_reports___reports::addPoint_x1_5(double x, double y, double z, double w)
{
    x0.append(x);
    y0.append(y);

    x1.append(x);
    y1.append(z);

    x2.append(x);
    y2.append(w);
}


void Form_analyse_reports___reports::clearData()
{
    //plot->clearGraphs();


    cow_graph1_x.clear();
    cow_graph1_y.clear();

    cow_graph2_x.clear();
    cow_graph2_y.clear();
}

void Form_analyse_reports___reports::plotRandom_()
{
    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    QPointer<QCPGraph> mGraph3;
    QPointer<QCPGraph> mGraph4;
    AxisTag *mTag1;
    AxisTag *mTag2;
    AxisTag *mTag3;
    AxisTag *mTag4;

    mGraph1 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph2 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 1));
    mGraph3 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 1));
    mGraph4 = ui->widget->addGraph(ui->widget->xAxis, ui->widget->axisRect()->axis(QCPAxis::atRight, 1));

    mGraph1->setPen(QPen(QColor(250, 120, 0)));
    mGraph2->setPen(QPen(QColor(0, 180, 60)));
    mGraph3->setPen(QPen(QColor(200, 180, 60)));
    mGraph4->setPen(QPen(QColor(200, 80, 60)));

    // create tags with newly introduced AxisTag class (see axistag.h/.cpp):
    mTag1 = new AxisTag(mGraph1->valueAxis());
    mTag1->setPen(mGraph1->pen());

    mTag2 = new AxisTag(mGraph2->valueAxis());
    mTag2->setPen(mGraph2->pen());

    mTag3 = new AxisTag(mGraph3->valueAxis());
    mTag3->setPen(mGraph3->pen());

    mTag4 = new AxisTag(mGraph4->valueAxis());
    mTag4->setPen(mGraph4->pen());


    //    double x = mGraph1->dataCount()*0.05;
    //    double y1 = 2*qCos(x)+3*qSin(x);
    //    double y2 = 2*qSin(x)+4*qCos(x);

    //ui->widget->legend->setVisible(true);

    //ui->widget->setValue(0);

    GetData_search("dataentry_robot", "");
    //ui->lineEdit->setText("num: "+QString::number(cow_graph1_x.count()));

    //mGraph1->addData(x, y1);
    mGraph1->addData(cow_graph1_x,cow_graph1_y);
    mGraph2->addData(cow_graph1_x,cow_graph2_y);
    mGraph3->addData(cow_graph1_x,cow_graph3_y);
    mGraph4->addData(cow_graph1_x,cow_graph4_y);
    //mGraph3->addData(cow_graph1_x,cow_graph3_y);
    //mGraph1->set;
    //mGraph2->addData(x, y2);

    // make key axis range scroll with the data:
    ui->widget->xAxis->rescale();
    mGraph1->rescaleValueAxis(false, true);
    mGraph2->rescaleValueAxis(false, true);
    mGraph3->rescaleValueAxis(false, true);
    mGraph4->rescaleValueAxis(false, true);
    //mGraph3->rescaleValueAxis(false, true);
    //ui->plot->xAxis->setRange(ui->plot->xAxis->range().upper, 100, Qt::AlignRight);

    // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
    double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
    double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    double graph3Value = mGraph3->dataMainValue(mGraph2->dataCount()-1);
    double graph4Value = mGraph3->dataMainValue(mGraph2->dataCount()-1);

    //double graph3Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph4Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph3Value = mGraph2->dataMainValue(mGraph3->dataCount()-1);

    mTag1->updatePosition(graph1Value);
    mTag2->updatePosition(graph2Value);
    mTag3->updatePosition(graph2Value);
    mTag4->updatePosition(graph2Value);

    mTag1->setText(QString::number(graph1Value, 'f', 2));
    mTag2->setText(QString::number(graph2Value, 'f', 2));
    mTag3->setText(QString::number(graph2Value, 'f', 2));
    mTag4->setText(QString::number(graph2Value, 'f', 2));

    ui->widget->replot();

    return;
}

void Form_analyse_reports___reports::GetData_search(QString tab, QString str2)
{
    //DataSystems::Instance().log+="id: "+id+;
    //logger::WriteLog(QString::number(this->id));

//    ui->textEdit->setText(DataSystems::Instance().log);
//    ui->textEdit_2->setText(
//        "coord_teat_lf min: "+QString::number(min1)+"\n" +
//        "coord_teat_lf max: "+QString::number(max1)+"\n" +
//        "coord_teat_lr min: "+QString::number(min2)+"\n" +
//        "coord_teat_lr max: "+QString::number(max2)+"\n"
//        );
    //ui->textEdit->;
    //ui->te

    //if(this->id<DataSystems::Instance().id_max)ui->tableWidget->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        //QString sql =  QString("SELECT * FROM "+tab+" WHERE (id>"+QString::number(this->id)+ " AND id<"+QString::number(this->id+100)+ ") ORDER BY id;").toLower();
        QString sql =  QString("SELECT * FROM "+tab+" WHERE (id>0"+QString::number(this->id)+") ORDER BY id;").toLower();
        //logger::WriteMsg("sql: "+sql.toStdString());
        QSqlQuery* query = db_func->sql_exec2(sql);

        //logger::WriteMsg(QString("reports id = " + QString::number(this->id)).toStdString()+": num: " + QString::number(query->size()).toStdString());
        //logger::WriteMsg(QString("reports id = " + QString::number(this->id) + "| dataentry_robot_counter: " + QString::number(DataSystems::Instance().dataentry_robot_counter)).toStdString());

//        this->id = query->value("id").toString().toInt();
//        if(this->id+100 < DataSystems::Instance().dataentry_robot_counter)
//        {
//           this->id=this->id + 100; //this->id = query->value("id").toString().toInt();
//        }
//        else
//        {
//           this->id = DataSystems::Instance().dataentry_robot_counter;
//        }


        if(query->size()<1)return;


//        if(ui->tableWidget->rowCount()>30)ui->tableWidget->clear();

//        QStringList NameColumns;
//        NameColumns<<"id"<<"robot_No"<<"coord_teat_lf"<<"coord_teat_lr"<<"coord_teat_rf"<<"coord_teat_rr"<<"paramtime1";
//        ui->tableWidget->setColumnCount( NameColumns.count() );
//        ui->tableWidget->setRowCount( 1 );
//        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("TableWidget"));
//        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
//        //ui->tableWidget->hideColumn(0);
//        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

//        ui->Plot->setValue(0);

        int i=0;
        while(query->next())
        {
            //tabwidget_insert_add_column(query,ui->tableWidget,"id",i,0);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param1",i,1);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param2",i,2);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param3",i,3);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param4",i,4);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey1",i,5);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey2",i,6);

//            tabwidget_insert_add_column(query,ui->tableWidget,"robot_no", i, 1);
//            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lf", i, 2);
//            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lr", i, 3);
//            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rf", i, 4);
//            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rr", i, 5);
//            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 6);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"param2", i, 7);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"param3", i, 8);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"param4", i, 9);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 10);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime2", i, 11);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime3", i, 12);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime4", i, 13);

            xi = query->value("id").toDouble();
            yi = query->value("coord_teat_lf").toDouble();
            zi = query->value("coord_teat_lr").toDouble();
            wi = query->value("coord_teat_rf").toDouble();
            ri = query->value("coord_teat_rr").toDouble();

            if(min1>yi)min1=yi;
            if(max1<yi)max1=yi;
            if(min2>zi)min2=zi;
            if(max2<zi)max2=zi;

            this->id = query->value("id").toString().toInt();

            if(this->id>DataSystems::Instance().id_max)
            {
                //genbigdata->status = false;
                //mTimer->stop();
            }
            //qDebug()<<"id: "<<query->value("id").toString();

            addPoint(xi, yi, wi, zi,ri);

            //addPoint_x1_5(xi, yi, zi, wi);
            //addPoint(xi, yi, zi, wi);


            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_lactation text",i,9);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_refusals",i,10);

            //ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
            //ui->Plot->setValue((int)(100*i*1.0/query->size()));
        }
    }

    /**/
}
