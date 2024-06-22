#include "form_analyse_reports___x_link.h"
#include "ui_form_analyse_reports___x_link.h"

#include <QCheckBox>
#include "dataanimals.h"

// Инструкция%20по%20Т4С%20№5%20X-LINK%20и%20робот.pdf
//5.1 Показать Доклады на X-Link
//    Существует возможность настройки показа отчетов T4C на X-Link:
//    1. Навигация: Анализ/Доклады (Analysis/Reports)
//                            2. Меню: Доклады (Reports)
//                                          3. Открыть отчет, который должен быть показан на X-Link

form_analyse_reports___X_Link::form_analyse_reports___X_Link(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_analyse_reports___X_Link)
    , actSaveExcel(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel "), this)
    , actSaveExcelXML(QIcon(":/Resource/Images/xls.png"), PBSTR("Excel (XML)"), this)
    , actSaveWordXML(QIcon(":/Resource/Images/word.png"), PBSTR("Word (XML)"), this)
    , actSavePDF(QIcon(":/Resource/Images/pdf.png"), PBSTR("PDF "), this)
    , actSaveCSV(QIcon(":/Resource/Images/csv.png"), PBSTR("Text (CSV)"), this)
    , actSaveXML(QIcon(":/Resource/Images/xml.png"), PBSTR("XML "), this)
    , actSaveHTML(QIcon(":/Resource/Images/htm.png"), PBSTR("HTML "), this)
{
    ui->setupUi(this);

    //***************** Установка белого цвета приложения и размеров ****************************//
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);
    //setGeometry(QRect(200, 100, 1600, 800));
    //***************** End Установка белого цвета приложения и размеров ****************************//


    create_table_view();

    ThisStyle(DataSystems::Instance().settings___color_header);


}

form_analyse_reports___X_Link::~form_analyse_reports___X_Link()
{
    delete ui;
}

void form_analyse_reports___X_Link::GetData()
{
    //ui->tableWidget->clear();


    //logger::WriteLog("GetData()");
    //ui->textEdit->setText(DataSystems::Instance().log);

    QScopedPointer<DataBase> db_func(new DataBase());
    if(db_func->StatusOpen())
    {
        QString tab = "analyse_reports___x_link";
        QString sql =  QString("SELECT * FROM public."+tab+" ORDER BY id ASC ").toLower();
        QSqlQuery* query = db_func->sql_exec2(sql);
        qDebug()<<"koll-vo records: "<<query->size()<<" | "<<sql;
        if(query->size()<1)return;

        //        QStringList NameColumns;
        //        int i=0;
        //        foreach (QString cols, allColumns)
        //        {
        //            qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        //            i++;
        //            NameColumns<<cols;
        //        }

        //        ui->tableWidget->setColumnCount( allColumns.count() );


        //        ui->tableWidget->setRowCount( 1 );
        //        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Параметры робота"));
        //        ui->tableWidget->setHorizontalHeaderLabels( NameColumns );

        QList<QString> columns = {
            "check",
            "cow_number",
            "robot_No",
            "group_No",
            "LF_condition",
            "LF_colour_code",
            "LR_condition",
            "LR_colour_code",
            "RF_condition",
            "RF_colour_code",
            "RR_condition,",
            "RR_colour_code",
            "day_pregnance",
            "lactation_day",
            "lactation_No",
            "quad_dev",
            "dev_day"
        };

        //        for(int i=0;i<NameColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

        //logger::WriteLog("READING ... GetData()");
        //ui->textEdit->setText(DataSystems::Instance().log);

        _table_model.setColumnCount(COL_COUNT);
        _table_model.setRowCount(query->size());
        //for(int row = 0; row < ROW_COUNT;row++)
        int i=0;
        while(query->next())
        {
            for(int j = 0; j < COL_COUNT; j++)
            {
                _table_model.setData(_table_model.index(i,j),
                                     query->value(columns[j]).toString(),
                                     Qt::EditRole);
            }
            //_table_model.appendRow();
            i++;
        }

        i=0;
        //while(query->next())
        {

            for(int j=0;j<columns.count();j++)
            {
                //QTableWidgetItem *item = new QTableWidgetItem(query->value(columns[j]).toString());
                //item->setTextAlignment(Qt::AlignHCenter);
                //  ui->tableWidget->setItem( i, j,  item);
                qDebug()<<"j: "<<j;
            }
            //ui->tableWidget->insertRow( ui->tableWidget->rowCount() );
            i++;
        }
    }
    else
    {
        //logger::WriteLog("ERROR READING ... GetData() ????????????????????? ");
        //ui->textEdit->setText(DataSystems::Instance().log);
    }
}


void form_analyse_reports___X_Link::create_table_view()
{

    GetData();

    _table_view = new zf::TableView;
    _table_view->setAutoResizeRowsHeight(false);
    _table_view->setSortingEnabled(true);
    _table_view->setModel(&_table_model);

    configureHeader2(_table_view->horizontalRootHeaderItem());

    QString text = "";

    ui->verticalLayout_tableview->addWidget(_table_view);

    //ui->tblInventory->model()->data(ui->tblInventory->model()->index(0,2)).toString()
    for(int i=0; i<_table_view->model()->rowCount();i++)
    {
        //qDebug()<<i<<",2)"<<_table_view->model()->data(_table_view->model()->index(i,2)).toString();
        text += QString::number(i)+",2)"+_table_view->model()->data(_table_view->model()->index(i,2)).toString() + "    -----   ";
        text += QString::number(i)+",3)"+_table_view->model()->data(_table_view->model()->index(i,3)).toString() + "\n";
    }

    createPopupMenu_();
    connect(_table_view, SIGNAL(onCreatePopupMenu(QMenu *)), SLOT(onCreateFooterMenu(QMenu *)));

    connect(&actSaveExcel, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveExcel);
    connect(&actSaveExcelXML, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveExcelXML);
    connect(&actSaveWordXML, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveWordXML);
    connect(&actSavePDF, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSavePDF);
    connect(&actSaveCSV, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveCSV);
    connect(&actSaveXML, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveXML);
    connect(&actSaveHTML, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSaveHTML);

    connect(&actSendToPrinter, &QAction::triggered, this, &form_analyse_reports___X_Link::onActSendToPrinter);

    connect(_table_view->horizontalHeader(), SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(showCustomContextMenu(const QPoint&)));

    //ui->textEdit->setText(text);
}



void form_analyse_reports___X_Link::configureHeader2(zf::HeaderItem *parent)
{
    {
        QString h_name = QString("Check");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }

    {
        QString h_name = QString("Номер коровы");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }

    {
        QString h_name = QString("Номер робота");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }
    {
        QString h_name = QString("Номер группы");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append(" ");
    }
    {
        QString h_name = QString("LF");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Условие");
        item->append("Цветовой код");
    }
    {
        QString h_name = QString("RF");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Условие");
        item->append("Цветовой код");
    }
    {
        QString h_name = QString("RF");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Условие");
        item->append("Цветовой код");
    }
    {
        QString h_name = QString("RR");
        zf::HeaderItem *item =  parent->append(h_name);
        item->append("Условие");
        item->append("Цветовой код");
    }
    {
        QString h_name = QString("Дни беременности");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Дни лактации");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("Номер лактации");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("qqq");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
    {
        QString h_name = QString("qqr");
        zf::HeaderItem *item =  parent->append(h_name);
        //item->append("");
    }
}

void form_analyse_reports___X_Link::ThisStyle(QString color_h)
{


    QList<QPushButton*> allButton = findChildren<QPushButton*>();
    for(int i=0;i<allButton.size();i++)
    {
        allButton[i]->setStyleSheet(
            "background-color:"+color_h+";"
                                            "color: white;"
                                            "padding: 4 50 4 10;");
    }

    QList<QGroupBox*> allGroup = findChildren<QGroupBox*>();
    for(int i=0;i<allGroup.size();i++)
    {
        allGroup[i]->setStyleSheet(
            "QGroupBox {"
            "background-color: white;"
            "}"
            "QGroupBox::title {"
            "color: white;"
            "background-color:"+color_h+";"
                        "padding: 4 20000 4 10;"
                        "}"
            );
    }

//    _table_view->setStyleSheet("QTableView"
//                               "{"
//                               "   background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"

//                                                                                             "QTabWidget:tab-bar"
//                                                                                             "{"
//                                                                                             "    alignment: center;"
//                                                                                             "}"

//                                                                                             "QTabBar:tab"
//                                                                                             "{"
//                                                                                             "   width: "+DataSystems::Instance().settings___tabwidget_width+";"
//                                                                                      "   height: 30px;"
//                                                                                      "}"

//                                                                                      "QTabBar:selected"
//                                                                                      "{"
//                                                                                      "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"

//                                                                                             "QTabBar:tab:!selected"
//                                                                                             "{"
//                                                                                             "    color.rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "}"


//                                                                                             "QTabBar:tab:!selected:hover"
//                                                                                             "{"
//                                                                                             "    background-color:rgb"+DataSystems::Instance().settings___color_header___decimal+";"
//                                                                                             "    color.rgb(255,255,255);"
//                                                                                             "}"
//                                                                                             ")");


}


void form_analyse_reports___X_Link::showCustomContextMenu(const QPoint &p)
{
    QPoint mP = mapToGlobal(p);

    //int iCol = _table_view->horizontalHeader()->logicalIndexAt(p),
    //  iSort = _table_view->horizontalHeader()->sortIndicatorSection();

    //actSortAsc.setChecked(iCol == iSort && _table_view->horizontalHeader()->sortIndicatorOrder() == Qt::AscendingOrder);
    //actSortDesc.setChecked(iCol == iSort && _table_view->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);

    popupMenu.popup(mP);
}

void form_analyse_reports___X_Link::onActSaveExcelXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewExcelXMLExporter e(_table_view, &f, this);
        e.execute();
        f.close();
    }
}

void form_analyse_reports___X_Link::onActSaveWordXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewWordXMLExporter e(_table_view, &f, this);
        e.execute();
        f.close();
    }
}

void form_analyse_reports___X_Link::onActSaveCSV()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewCSVExporter e(_table_view, &f, this);
        e.execute();
        f.close();
    }
}

void form_analyse_reports___X_Link::onActSaveHTML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewHTMLExporter e(_table_view, &f, this);
        e.execute();
        f.close();
    }
}

void form_analyse_reports___X_Link::onActSaveExcel()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        PBSTableViewXLSXExporter e(_table_view, sName, this);
        e.execute();
    }
}

void form_analyse_reports___X_Link::onActSaveXML()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        QFile f(sName);
        f.open(QIODevice::ReadWrite);
        PBSTableViewXMLExporter e(_table_view, &f, this);
        e.execute();
        f.close();
    }
}

void form_analyse_reports___X_Link::onActSavePDF()
{
    QString sName = PBSFileUtil::getSaveFileName(this, PBSTR("Введите имя сохраняемого фала"));
    if(!sName.isEmpty())
    {
        PBSTableViewPDFExporter e(_table_view, sName, this);
        e.execute();
    }
}

void form_analyse_reports___X_Link::onActSendToPrinter()
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

void form_analyse_reports___X_Link::print(QPrinter *prn)
{
    QPainter painter;

    painter.begin(prn);

    PBSTablePrinter p(&painter, _table_view, this);
    p.setPrinter(prn);

    p.setHeadersFont(_table_view->horizontalHeader()->font());
    p.setContentFont(font());

    p.execute();
}



void form_analyse_reports___X_Link::onCreateFooterMenu(QMenu *m)
{
    emit onCreatePopupMenu(FooterMenu, m);
}

void form_analyse_reports___X_Link::createPopupMenu_()
{
    popupMenu.clear();
    popupMenu.addAction(&actSortAsc);
    popupMenu.addAction(&actSortDesc);
    popupMenu.addSeparator();
    popupMenu.addAction(&actFooter);
    popupMenu.addAction(&actFilter);
    popupMenu.addSeparator();
    popupMenu.addAction(&actSendToPrinter);
    popupMenu.addSeparator();
    popupMenu.addAction(&actStretchColumn);
    popupMenu.addAction(&actStretchColumnAll);
    popupMenu.addAction(&actStretch);

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



