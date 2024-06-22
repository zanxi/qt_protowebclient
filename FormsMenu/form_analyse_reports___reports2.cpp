#include "form_analyse_reports___reports.h"
#include "FormsMenu/ui_form_analyse_reports___reports.h"

#include "dataanimals.h"

Form_analyse_reports___reports::Form_analyse_reports___reports(QWidget *parent) :
    QFrame(parent),
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


    ui->groupBox_plot->setStyleSheet("QGroupBox {"
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

    //plot = new QCustomPlot(ui->groupBox_plot);
    //ui->verticalLayout_plot->addWidget(plot);
    //plot->setObjectName(QString::fromUtf8("plot"));
    //setupAdvancedAxesDemo(plot);
    //TimeOperation(plot);

    //GetData_FirstId("0", "dataentry_robot", "");

    //mTimer=new QTimer(this);
    //connect(mTimer, SIGNAL(timeout()),this, SLOT(plotRandom_()));

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

/*
void Form_analyse_reports___reports::setupAdvancedAxesDemo(QCustomPlot *customPlot)
{

    //plot = nullptr;
    //mGraph1=nullptr;
    //mGraph2=nullptr;

    // configure plot to have two right axes:
    customPlot->yAxis->setTickLabels(false);
    connect(customPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis, SLOT(setRange(QCPRange))); // left axis only mirrors inner right axis
    customPlot->yAxis2->setVisible(true);
    customPlot->axisRect()->addAxis(QCPAxis::atRight);
    customPlot->axisRect()->axis(QCPAxis::atRight, 0)->setPadding(30); // add some padding to have space for tags
    customPlot->axisRect()->axis(QCPAxis::atRight, 1)->setPadding(30); // add some padding to have space for tags

    // create graphs:
    mGraph1 = customPlot->addGraph(customPlot->xAxis, customPlot->axisRect()->axis(QCPAxis::atRight, 0));
    mGraph2 = customPlot->addGraph(customPlot->xAxis, customPlot->axisRect()->axis(QCPAxis::atRight, 1));
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
    customPlot->xAxis->setTicker(dateTicker);

    QDateTime from = QDateTime::currentDateTime().addMSecs(-3*1000*3600);
    QDateTime to = QDateTime::currentDateTime().addMSecs(1000*3600);

    customPlot->xAxis->setRange(from.toSecsSinceEpoch(), to.toSecsSinceEpoch());

    return;

}

void Form_analyse_reports___reports::GetData()
{

}

bool Form_analyse_reports___reports::fromStringValue(const QString &inStr, QDateTime &value) {
    QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss[Z|[+|-]HH:mm]";
    //QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";
    auto dateTime = QDateTime::fromString(inStr, DateTimeFormat);
    auto dateTime2 = QDateTime::fromString(inStr, "yyyy-MM-ddTHH:mm:ss[Z|[+|-]HH:mm]");
    if (dateTime.isValid()) {
        value.setDate(dateTime.date());
        value.setTime(dateTime2.time());
    }
}


void Form_analyse_reports___reports::tabwidget_insert_add_column(QSqlQuery *query, QTableWidget *tab, QString nameColumnX,  int numRow, int numColumn)
{
    //QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss[Z|[+|-]HH:mm]";
    QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";
    //QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";

    if(nameColumnX.contains("timey2"))
    {
        //uint t_ = query->value("timey2").toDouble();
        t_ = query->value("timey2").toDouble();
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
        logger::WriteMsg("date: "+a.toString().toStdString());
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
        QDateTime time2 = QDateTime::fromString(t_, Qt::ISODateWithMs).currentDateTimeUtc().toLocalTime();
        xi = time2.toTime_t();
        QString time = time2.toString("yyyy-MM-dd hh:mm:ss.zzzZ");
        QTableWidgetItem *item = new QTableWidgetItem(time);
        item->setTextAlignment(Qt::AlignHCenter);
        tab->setItem( numRow, numColumn,  item);
    }

    else
    {
        QTableWidgetItem *item = new QTableWidgetItem(query->value(nameColumnX).toString());
        item->setTextAlignment(Qt::AlignLeft);
        tab->setItem( numRow, numColumn,  item);
    }
    //ui->comboBox->addItem(query->value(nameColumn).toString());
    //xi = query->value(nameColumnX).toDouble();
    //yi = query->value(nameColumnY).toDouble();
}


void Form_analyse_reports___reports::GetData_search(QString id)
{
    //DataSystems::Instance().log+="id: "+id+;
    logger::WriteLog(QString::number(this->id));
    ui->textEdit->setText(DataSystems::Instance().log);
    //ui->textEdit->;
    //ui->te

    if(this->id<DataSystems::Instance().id_max)ui->tableWidget->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "bigdata";
        //QString sql =  QString("SELECT * FROM public."+tab+" WHERE animal_No LIKE '%"+str+"%' OR Robot_No LIKE '%"+str+"%' ORDER BY id;").toLower();
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE id> "+id+" ORDER BY id;").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        QStringList NameColumns;
        NameColumns<<"id"<<"x"<<"y"<<"z"<<"w"<<"time1"<<"time2";
        ui->tableWidget->setColumnCount( NameColumns.count() );
        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("TableWidget"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->hideColumn(0);
        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 100);

        int i=0;
        while(query->next())
        {
            tabwidget_insert_add_column(query,ui->tableWidget,"id",i,0);
            tabwidget_insert_add_column(query,ui->tableWidget,"param1",i,1);
            tabwidget_insert_add_column(query,ui->tableWidget,"param2",i,2);
            tabwidget_insert_add_column(query,ui->tableWidget,"param3",i,3);
            tabwidget_insert_add_column(query,ui->tableWidget,"param4",i,4);
            tabwidget_insert_add_column(query,ui->tableWidget,"timey1",i,5);
            tabwidget_insert_add_column(query,ui->tableWidget,"timey2",i,6);
            xi = query->value("param1").toDouble();
            yi = query->value("param2").toDouble();
            zi = query->value("param3").toDouble();
            wi = query->value("param4").toDouble();


            this->id = query->value("id").toString().toInt();
            if(this->id>DataSystems::Instance().id_max)
            {
                //genbigdata->status = false;
                //mTimer->stop();
            }
            //qDebug()<<"id: "<<query->value("id").toString();
            addPoint(xi, yi, wi);
            addPoint_x1_5(xi, yi, zi, wi);
            //addPoint(xi, yi, zi, wi);


            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_lactation text",i,9);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_refusals",i,10);

            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }

}

void Form_analyse_reports___reports::GetData_search(QString id, QString tab, QString str2)
{
    //DataSystems::Instance().log+="id: "+id+;
    logger::WriteLog(QString::number(this->id));

    ui->textEdit->setText(DataSystems::Instance().log);
    ui->textEdit_2->setText(
        "coord_teat_lf min: "+QString::number(min1)+"\n" +
        "coord_teat_lf max: "+QString::number(max1)+"\n" +
        "coord_teat_lr min: "+QString::number(min2)+"\n" +
        "coord_teat_lr max: "+QString::number(max2)+"\n"
        );
    //ui->textEdit->;
    //ui->te

    //if(this->id<DataSystems::Instance().id_max)ui->tableWidget->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString sql =  QString("SELECT * FROM public."+tab+" WHERE id> "+id+" ORDER BY id;").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        if(ui->tableWidget->rowCount()>30)ui->tableWidget->clear();

        QStringList NameColumns;
        NameColumns<<"id"<<"robot_No"<<"coord_teat_lf"<<"coord_teat_lr"<<"coord_teat_rf"<<"coord_teat_rr"<<"paramtime1";
        ui->tableWidget->setColumnCount( NameColumns.count() );
        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("TableWidget"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->hideColumn(0);
        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        ui->Plot->setValue(0);

        int i=0;
        while(query->next())
        {
            tabwidget_insert_add_column(query,ui->tableWidget,"id",i,0);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param1",i,1);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param2",i,2);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param3",i,3);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param4",i,4);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey1",i,5);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey2",i,6);

            tabwidget_insert_add_column(query,ui->tableWidget,"robot_no", i, 1);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lf", i, 2);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lr", i, 3);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rf", i, 4);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rr", i, 5);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 6);
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
            //wi = query->value("coord_teat_rf").toDouble();

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
            addPoint(xi, wi, zi);
            //addPoint_x1_5(xi, yi, zi, wi);
            //addPoint(xi, yi, zi, wi);


            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_lactation text",i,9);
            //            tabwidget_insert_add_column(query,ui->tableWidget,"average_refusals",i,10);

            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
            ui->Plot->setValue((int)(100*i*1.0/query->size()));
        }
    }

}

void Form_analyse_reports___reports::TimeOperation()
{
}

// SELECT * FROM public.dataentry_robot ORDER BY id ASC LIMIT 1

void Form_analyse_reports___reports::GetData_FirstId(QString id, QString tab, QString str2)
{

    if(ui->tableWidget->rowCount()>30)ui->tableWidget->clear();

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString sql = "SELECT * FROM public.dataentry_robot ORDER BY id ASC LIMIT 1";
        QSqlQuery* query = db_func->sql_exec2(sql);
        if(query->size()<1)return;

        QStringList NameColumns;
        NameColumns<<"id"<<"robot_No"<<"coord_teat_lf"<<"coord_teat_lr"<<"coord_teat_rf"<<"coord_teat_rr"<<"paramtime1";
        ui->tableWidget->setColumnCount( NameColumns.count() );
        ui->tableWidget->setRowCount( 1 );
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("TableWidget"));
        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
        //ui->tableWidget->hideColumn(0);
        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        int i=0;
        while(query->next())
        {
            tabwidget_insert_add_column(query,ui->tableWidget,"id",i,0);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param1",i,1);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param2",i,2);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param3",i,3);
            //tabwidget_insert_add_column(query,ui->tableWidget,"param4",i,4);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey1",i,5);
            //tabwidget_insert_add_column(query,ui->tableWidget,"timey2",i,6);

            tabwidget_insert_add_column(query,ui->tableWidget,"robot_no", i, 1);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lf", i, 2);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_lr", i, 3);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rf", i, 4);
            tabwidget_insert_add_column(query,ui->tableWidget,"coord_teat_rr", i, 5);
            tabwidget_insert_add_column(query,ui->tableWidget,"paramtime1", i, 6);
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

            min1=yi;
            max1=yi;
            min2=zi;
            max2=zi;


            ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }

    ui->textEdit->setText(DataSystems::Instance().log);
    ui->textEdit_2->setText(
        "coord_teat_lf min: "+QString::number(min1)+"\n" +
        "coord_teat_lf max: "+QString::number(max1)+"\n" +
        "coord_teat_lr min: "+QString::number(min2)+"\n" +
        "coord_teat_lr max: "+QString::number(max2)+"\n"
        );

}

void Form_analyse_reports___reports::TimeOperation(QCustomPlot *customPlot)
{

    QString const DateTimeFormat = "yyyy-MM-ddTHH:mm:ss.zzzZ";

    QDateTime UTC(QDateTime::currentDateTimeUtc());
    QDateTime local(UTC.toLocalTime());

    //local.da;
    //qDebug() << "UTC time is:" << UTC;
    //qDebug() << "Local time is:" << local;
    //qDebug() << "No difference between times:" << UTC.secsTo(local);

    logger::WriteLog("UTC time is:" + UTC.toString());
    logger::WriteLog("Local time is:" + local.toString(DateTimeFormat));
    logger::WriteLog("year:" + QString::number(local.date().year()));
    logger::WriteLog("month:" + QString::number(local.date().month()));
    logger::WriteLog("days:" + QString::number(local.date().day()));
    logger::WriteLog("hours:" + QString::number(local.time().hour()));
    logger::WriteLog("minutes:" + QString::number(local.time().minute()));
    logger::WriteLog("seconds:" + QString::number(local.time().second()));
    logger::WriteLog("No difference between times:" + QString::number(UTC.secsTo(local)));

    ui->textEdit->setText(DataSystems::Instance().log);

    //QDateTime local2(QDateTime::currentDateTime());
    //QDateTime UTC2(local.toTimeSpec(QTimeZone::));
    //logger::WriteLog("Local time is:" + local.toString());
    //logger::WriteLog("UTC time is:" + UTC.toString());
    //logger::WriteLog("No difference between times represented:" + local.secsTo(UTC));


    //*****************************************

    // set locale to english, so we get english month names:
    customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    // seconds of current time, we'll use it as starting point in time for data:
    double now = QDateTime::currentDateTime().toTime_t();
    srand(8); // set the random seed, so we always get the same random data
    // create multiple graphs:
    for (int gi=0; gi<5; ++gi)
    {
        customPlot->addGraph();
        QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
        customPlot->graph()->setLineStyle(QCPGraph::lsLine);
        customPlot->graph()->setPen(QPen(color.lighter(200)));
        //customPlot->graph()->setBrush(QBrush(color));
        // generate random walk data:
        QVector<QCPGraphData> timeData(250);
        for (int i=0; i<250; ++i)
        {
            QCPGraphData qcpGP;
            qcpGP.key = now + 24*3600*i;
            timeData[i].key = now + 24*3600*i;
            if (i == 0)
            {
               qcpGP.value = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
            }
            else
            {
               qcpGP.value = qFabs(timeData[i-1].value)*(1+0.02/4.0*(4-gi)) + (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
            }
            timeData.append(qcpGP);
        }

        customPlot->graph()->data()->set(timeData);
    }
    // configure bottom axis to show date instead of number:
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    customPlot->xAxis->setTicker(dateTicker);
    // configure left axis text labels:
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10, "a bit\nlow");
    textTicker->addTick(50, "quite\nhigh");
    customPlot->yAxis->setTicker(textTicker);
    // set a more compact font size for bottom and left axis tick labels:
    customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
    customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
    // set axis labels:
    customPlot->xAxis->setLabel("Date");
    customPlot->yAxis->setLabel("Random wobbly lines value");
    // make top and right axes visible but without ticks and labels:
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setTickLabels(false);
    // set axis ranges to show all data:
    customPlot->xAxis->setRange(now, now+24*3600*249);
    customPlot->yAxis->setRange(0, 60);
    // show legend with slightly transparent background brush:
    customPlot->legend->setVisible(true);
    customPlot->legend->setBrush(QColor(255, 255, 255, 150));

     // ***************************************

    return;

    customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    customPlot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    customPlot->legend->setFont(legendFont);
    customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    // setup for graph 0: key axis left, value axis bottom
    // will contain left maxwell-like function
    customPlot->addGraph(customPlot->yAxis, customPlot->xAxis);
    customPlot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    customPlot->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    customPlot->graph(0)->setName("Left maxwell function");

    // setup for graph 1: key axis bottom, value axis left (those are the default axes)
    // will contain bottom maxwell-like function with error bars
    customPlot->addGraph();
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
    customPlot->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    customPlot->graph(1)->setName("Bottom maxwell function");
    QCPErrorBars *errorBars = new QCPErrorBars(customPlot->xAxis, customPlot->yAxis);
    errorBars->removeFromLegend();
    errorBars->setDataPlottable(customPlot->graph(1));

    // setup for graph 2: key axis top, value axis right
    // will contain high frequency sine with low frequency beating:
    customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
    customPlot->graph(2)->setPen(QPen(Qt::blue));
    customPlot->graph(2)->setName("High frequency sine");

    // setup for graph 3: same axes as graph 2
    // will contain low frequency beating envelope of graph 2
    customPlot->addGraph(customPlot->xAxis2, customPlot->yAxis2);
    QPen blueDotPen;
    blueDotPen.setColor(QColor(30, 40, 255, 150));
    blueDotPen.setStyle(Qt::DotLine);
    blueDotPen.setWidthF(4);
    customPlot->graph(3)->setPen(blueDotPen);
    customPlot->graph(3)->setName("Sine envelope");

    // setup for graph 4: key axis right, value axis top
    // will contain parabolically distributed data points with some random perturbance
    customPlot->addGraph(customPlot->yAxis2, customPlot->xAxis2);
    customPlot->graph(4)->setPen(QColor(50, 50, 50, 255));
    customPlot->graph(4)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(4)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    customPlot->graph(4)->setName("Some random data around\na quadratic function");

    // generate data, just playing with numbers, not much to learn here:


    for (int i=0; i<25; ++i) // data for graph 0
    {
        double x = 3*i/25.0;
        x0.append(x);
        y0.append(qExp(-x*x*0.8)*(x*x+x));
    }
    for (int i=0; i<15; ++i) // data for graph 1
    {
        double x = 3*i/15.0;
        x1.append(x);
        y1.append(qExp(-x*x)*(x*x)*2.6);
        y1err.append(qExp(-x*x)*(x*x)*2.6*0.25);
    }
    for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
    {
        double x = i/250.0*3*M_PI;
        double x2_ = i/250.0*100-50;

        x2.append(x);
        x3.append(x);
        x4.append(x2_);
        y2.append(qSin(x2_*12)*qCos(x2_)*10);
        y3.append(qCos(x3[i])*10);
        y4.append(0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI);
    }

    // pass data points to graphs:
    customPlot->graph(0)->setData(x0, y0);
    customPlot->graph(1)->setData(x1, y1);
    errorBars->setData(y1err);
    customPlot->graph(2)->setData(x2, y2);
    customPlot->graph(3)->setData(x3, y3);
    customPlot->graph(4)->setData(x4, y4);
    // activate top and right axes, which are invisible by default:
    customPlot->xAxis2->setVisible(true);
    customPlot->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    //customPlot->xAxis->setRange(0, 2.7);
    customPlot->yAxis->setRange(0, 2.6);
    customPlot->xAxis2->setRange(0, 3.0*M_PI);
    customPlot->yAxis2->setRange(-70, 35);
    // set pi ticks on top axis:
    customPlot->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
    // add title layout element:
    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(customPlot, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
    // set labels:
    customPlot->xAxis->setLabel("Bottom axis with outward ticks");
    customPlot->yAxis->setLabel("Left axis label");

    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    customPlot->xAxis->setTicker(dateTicker);

    customPlot->xAxis2->setLabel("Top axis label");
    customPlot->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:
    customPlot->xAxis->setTickLength(0, 5);
    customPlot->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:
    customPlot->yAxis2->setTickLength(3, 3);
    customPlot->yAxis2->setSubTickLength(1, 1);

    plot->replot();

}


void Form_analyse_reports___reports::plotRandom2()
{
    //QCustomPlot *customPlot = plot;
    plot->clearPlottables();
    plot->clearGraphs();
    plot->clearItems();
    plot->clearFocus();
    plot->clearMask();

    plot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    plot->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    plot->legend->setFont(legendFont);
    plot->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    // setup for graph 0: key axis left, value axis bottom
    // will contain left maxwell-like function
    plot->addGraph(plot->yAxis, plot->xAxis);
    plot->graph(0)->setPen(QPen(QColor(255, 100, 0)));
    plot->graph(0)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // fill with texture of specified image
    plot->graph(0)->setLineStyle(QCPGraph::lsLine);
    plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 5));
    plot->graph(0)->setName("Left maxwell function");

    // setup for graph 1: key axis bottom, value axis left (those are the default axes)
    // will contain bottom maxwell-like function with error bars
    plot->addGraph();
    plot->graph(1)->setPen(QPen(Qt::red));
    plot->graph(1)->setBrush(QBrush(QPixmap("./balboa.jpg"))); // same fill as we used for graph 0
    //plot->graph(1)->setLineStyle(QCPGraph::lsStepCenter);
    plot->graph(1)->setLineStyle(QCPGraph::lsLine);
    plot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::red, Qt::white, 7));
    plot->graph(1)->setName("Bottom maxwell function");
    QCPErrorBars *errorBars = new QCPErrorBars(plot->xAxis, plot->yAxis);
    errorBars->removeFromLegend();
    errorBars->setDataPlottable(plot->graph(1));

    // setup for graph 2: key axis top, value axis right
    // will contain high frequency sine with low frequency beating:
    plot->addGraph(plot->xAxis, plot->yAxis);
    //plot->addGraph(plot->xAxis2, plot->yAxis2);
    plot->graph(2)->setPen(QPen(Qt::blue));
    plot->graph(2)->setName("High frequency sine");

    // setup for graph 3: same axes as graph 2
    // will contain low frequency beating envelope of graph 2

    // generate data, just playing with numbers, not much to learn here:
    qDebug()<<"Read Data";

    GetData_search(QString::number(this->id));
    ui->lineEdit->setText("num: "+QString::number(y1.count()));
    //qDebug()<<" --- "<<y0.size()<<" --- size y1: "<<y1.size()<<" --- size y2: "<<y2.size()<<" --- size y3: "<<y3.size()<<" --- size y4: "<<y4.size();

    qDebug()<<"Read Data END ---------";


//    for (int i=0; i<25; ++i) // data for graph 0
//    {
//        x0.append(3*i/25.0);
//        y0.append(qExp(-x0[i]*x0[i]*0.8)*(x0[i]*x0[i]+x0[i]));
//    }
//    for (int i=0; i<15; ++i) // data for graph 1
//    {
//        x1.append(3*i/15.0);
//        y1.append(qExp(-x1[i]*x1[i])*(x1[i]*x1[i])*2.6);
//        y1err.append(y1[i]*0.25);
//    }
//    for (int i=0; i<250; ++i) // data for graphs 2, 3 and 4
//    {
//        x2.append(i/250.0*3*M_PI);
//        x3.append(x2[i]);
//        x4.append(i/250.0*100-50);
//        y2.append(qSin(x2[i]*12)*qCos(x2[i])*10);
//        y3.append(qCos(x3[i])*10);
//        y4.append(0.01*x4[i]*x4[i] + 1.5*(rand()/(double)RAND_MAX-0.5) + 1.5*M_PI);
//    }



    // pass data points to graphs:
    plot->graph(0)->setData(x0, y0);
    plot->graph(1)->setData(x1, y1);
    errorBars->setData(y1err);
    plot->graph(2)->setData(x2, y2);
    // activate top and right axes, which are invisible by default:
    plot->xAxis2->setVisible(true);
    plot->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    //plot->xAxis->setRange(0, 2.7);
    //plot->yAxis->setRange(0, 2.6);
    //plot->xAxis2->setRange(0, 3.0*M_PI);
    //plot->yAxis2->setRange(-70, 35);
    // set pi ticks on top axis:
    plot->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
    // add title layout element:
    //plot->plotLayout()->insertRow(0);
    //plot->plotLayout()->addElement(0, 0, new QCPTextElement(plot, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
    // set labels:
    plot->xAxis->setLabel("Bottom axis with outward ticks");
    plot->yAxis->setLabel("Left axis label");

    //QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    //dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
    //plot->xAxis->setTicker(dateTicker);

    plot->xAxis2->setLabel("Top axis label");
    plot->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:

    //plot->xAxis->setTickLength(0, 5);
    //plot->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:

    //plot->yAxis2->setTickLength(3, 3);
    //plot->yAxis2->setSubTickLength(1, 1);

    plot->replot();    //clearData();

    //ui->textEdit->setText("xi="+QString::number(xi)+"; yi="+QString::number(yi)+"\n num pixels: ["+QString::number(mGraph1->dataCount())+"]");
    return;
}

void Form_analyse_reports___reports::plotRandom()
{

    //    double x = mGraph1->dataCount()*0.05;
    //    double y1 = 2*qCos(x)+3*qSin(x);
    //    double y2 = 2*qSin(x)+4*qCos(x);

    for (int i=1; i<30; ++i)
    {
        //xi=xi+0.002;
        //yi=5*cos(5*xi)-4*cos(xi)-3*sin(2*xi)+2*sin(4*xi);
        //addPoint(xi, yi);
    }

    GetData_search(QString::number(this->id));
    ui->lineEdit->setText("num: "+QString::number(cow_graph1_x.count()));

    //mGraph1->addData(x, y1);
    mGraph1->addData(cow_graph1_x,cow_graph1_y);
    mGraph2->addData(cow_graph1_x,cow_graph2_y);
    //mGraph3->addData(cow_graph1_x,cow_graph3_y);
    //mGraph1->set;
    //mGraph2->addData(x, y2);

    // make key axis range scroll with the data:
    plot->xAxis->rescale();
    mGraph1->rescaleValueAxis(false, true);
    mGraph2->rescaleValueAxis(false, true);
    //mGraph3->rescaleValueAxis(false, true);
    //ui->plot->xAxis->setRange(ui->plot->xAxis->range().upper, 100, Qt::AlignRight);

    // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
    double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
    double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph3Value = mGraph2->dataMainValue(mGraph3->dataCount()-1);
    mTag1->updatePosition(graph1Value);
    mTag2->updatePosition(graph2Value);
    mTag1->setText(QString::number(graph1Value, 'f', 2));
    mTag2->setText(QString::number(graph2Value, 'f', 2));
    //mTag3->setText(QString::number(graph3Value, 'f', 2));

    plot->replot();
    //clearData();


    //ui->textEdit->setText("xi="+QString::number(xi)+"; yi="+QString::number(yi)+"\n num pixels: ["+QString::number(mGraph1->dataCount())+"]");
    return;
}

void Form_analyse_reports___reports::plotRandom_()
{

    //    double x = mGraph1->dataCount()*0.05;
    //    double y1 = 2*qCos(x)+3*qSin(x);
    //    double y2 = 2*qSin(x)+4*qCos(x);

    for (int i=1; i<30; ++i)
    {
        //xi=xi+0.002;
        //yi=5*cos(5*xi)-4*cos(xi)-3*sin(2*xi)+2*sin(4*xi);
        //addPoint(xi, yi);
    }
    plot->legend->setVisible(true);

    ui->Plot->setValue(0);

    GetData_search(QString::number(this->id), "dataentry_robot", "");
    ui->lineEdit->setText("num: "+QString::number(cow_graph1_x.count()));

    //mGraph1->addData(x, y1);
    mGraph1->addData(cow_graph1_x,cow_graph1_y);
    mGraph2->addData(cow_graph1_x,cow_graph2_y);
    //mGraph3->addData(cow_graph1_x,cow_graph3_y);
    //mGraph1->set;
    //mGraph2->addData(x, y2);

    // make key axis range scroll with the data:
    plot->xAxis->rescale();
    mGraph1->rescaleValueAxis(false, true);
    mGraph2->rescaleValueAxis(false, true);
    //mGraph3->rescaleValueAxis(false, true);
    //ui->plot->xAxis->setRange(ui->plot->xAxis->range().upper, 100, Qt::AlignRight);

    // update the vertical axis tag positions and texts to match the rightmost data point of the graphs:
    double graph1Value = mGraph1->dataMainValue(mGraph1->dataCount()-1);
    double graph2Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph3Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph4Value = mGraph2->dataMainValue(mGraph2->dataCount()-1);
    //double graph3Value = mGraph2->dataMainValue(mGraph3->dataCount()-1);
    mTag1->updatePosition(graph1Value);
    mTag2->updatePosition(graph2Value);
    mTag1->setText(QString::number(graph1Value, 'f', 2));
    mTag2->setText(QString::number(graph2Value, 'f', 2));
    //mTag3->setText(QString::number(graph3Value, 'f', 2));

    plot->replot();
    //clearData();


    //ui->textEdit->setText("xi="+QString::number(xi)+"; yi="+QString::number(yi)+"\n num pixels: ["+QString::number(mGraph1->dataCount())+"]");
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
    //cow_graph3_y.append(w);
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




void Form_analyse_reports___reports::createTableWidget()
{
    return;
//    ui->tableWidget->setColumnCount( 3 );
//    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Динамическое изменение"));

//    QStringList NameColumns;
//    NameColumns<<"x"<<"f(x)"<<"f(z)";
//    int i=0;

//    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
//    ui->tableWidget->setRowCount( 1 );

//    for(int i=0;i<2;i++)ui->tableWidget->setColumnWidth(i, 150);

//    for(int i=0;i<1;i++)
//    {
//        // X
//        ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(QString::number(rand()%22)));
//        // Y
//        ui->tableWidget->setItem( i, 1,  new QTableWidgetItem(QString::number(rand()%33)));
//        // Z
//        ui->tableWidget->setItem( i, 2,  new QTableWidgetItem(QString::number(rand()%33)));
//    }


}


void Form_analyse_reports___reports::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(true);
    //setupAdvancedAxesDemo(plot);
    clearData();
    mTimer->start(milliSeconds);
}


void Form_analyse_reports___reports::on_pushButton_2_clicked()
{
    //mTimer->start(milliSeconds);
    //plot->clearGraphs();
    //plot->clearPlottables();
    //plot->clearItems();
    //setupAdvancedAxesDemo(plot);
    mTimer->stop();

    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);

    //clearData();
    //mGraph1.clear();
    //mGraph2.clear();
    //plotRandom_();
}


void Form_analyse_reports___reports::on_pushButton_close_clicked()
{
    this->close();
}

/**/

