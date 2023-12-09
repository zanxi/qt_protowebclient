#include "formlibrary_1_9.h"
#include "ui_formlibrary_1_9.h"

#include "tabelwidget_module/datetimestyleditemdelegate.h"
#include "json/json_w.h"

#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>

#include "formlibrary_1_9_tab_series_dialog.h"
#include "formlibrary_1_9_tab_feed_types_dialog.h"
#include "dataanimals.h"

// 1. Навигатор: Ввод данных 2. Меню: Библиотеки


FormLibrary_1_9::FormLibrary_1_9(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormLibrary_1_9)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget_feed_types->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    ui->tableWidget_feed_types->setStyleSheet("QTabWidget"
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


    ui->tabWidget_library->setStyleSheet("QTabWidget"
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


    //1. Навигатор: Ввод данных 2. Меню: Библиотеки 3. Подменю: Производители
    create_series();

    // 1. Навигатор: Ввод данных     2. Меню: Библиотеки               3. Подменю: Типы корма
    create_feed_types();

    //QTimer::singleShot(100, this, SLOT(on_pushButton_tab_series_add_clicked()));
}



FormLibrary_1_9::~FormLibrary_1_9()
{
    delete ui;
}

void FormLibrary_1_9::create_series()
{
    ui->tableWidget->clear();
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    //QMap<QString, QString> allColumns = json_w::form_table("table_form_1_2_bf.json");
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_series.json");
    qDebug()<< " Чтение конфига ---------------- ";
    //qDebug()<< " ||| " << allTabs.count() << " ||| " ;
    //QString firstColumn = allColumns.keys().first();
    //QList<QString> tab = allTabs.value(firstTab);
    //qDebug()<< " ||| " << firstColumn << " ||| " ;
    QStringList NameColumns;
    int i=0;
    foreach (QString cols, allColumns)
    {
        //NameColumns.append(allColumns[key]);
        //ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(cols));
        qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        i++;
        NameColumns<<cols;
    }

    ui->tableWidget->setColumnCount( allColumns.count() );
    ui->tableWidget->setRowCount( 10 );

    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget->setHorizontalHeaderLabels( NameColumns );
    //ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    for(int i=0;i<allColumns.count();i++)ui->tableWidget->setColumnWidth(i, 150);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
    //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
    //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);
    ui->tableWidget->hideColumn(0);

    for(int i=0;i<3;i++)
    {
        //for(int j=0;j<allColumns.count();j++)
        {
            QLineEdit *lineEdit_sire_name = new QLineEdit();
            lineEdit_sire_name->installEventFilter(this);
            lineEdit_sire_name->setText("sire-"+QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,0,lineEdit_sire_name);

            QLineEdit *lineEdit_life_number = new QLineEdit();
            lineEdit_life_number->installEventFilter(this);
            lineEdit_life_number->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,1,lineEdit_life_number);

            QLineEdit *lineEdit_sire_code = new QLineEdit();
            lineEdit_sire_code->installEventFilter(this);
            lineEdit_sire_code->setText(QString::number(rand()%2222));
            ui->tableWidget->setCellWidget(i,2,lineEdit_sire_code);

            //            QComboBox *combobox_active = new QComboBox();
            //            combobox_active->installEventFilter(this);
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            ui->tableWidget->setCellWidget(i,3,combobox_active);

            QCheckBox *checkbox_active = new QCheckBox();
            checkbox_active->installEventFilter(this);
            checkbox_active->setCheckState(Qt::CheckState::Checked);
            ui->tableWidget->setCellWidget(i,3,checkbox_active);

            QPushButton *pushButton_search = new QPushButton();
            pushButton_search->installEventFilter(this);
            pushButton_search->setText("search");
            ui->tableWidget->setCellWidget(i,4,pushButton_search);

            QPushButton *pushButton_show_all = new QPushButton();
            pushButton_show_all->installEventFilter(this);
            pushButton_show_all->setText("show_all");
            ui->tableWidget->setCellWidget(i,5,pushButton_show_all);

            //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
            //ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(QDate().currentDate().toString()));
            //ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(QDate().currentDate().toString()));

        }
    }
}



void FormLibrary_1_9::on_pushButton_tab_series_add_clicked()
{

    formlibrary_1_9_tab_series_Dialog d_1_9_d(this);
    if(!(d_1_9_d.exec()==QDialog::Accepted)){
            //create();

        int i=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount( i+1 );

        QLineEdit *lineEdit_sire_name = new QLineEdit();
        lineEdit_sire_name->installEventFilter(this);
        lineEdit_sire_name->setText(DataSystems::Instance().dataentry_library_siries_sire_name);
        ui->tableWidget->setCellWidget(i,0,lineEdit_sire_name);

        QLineEdit *lineEdit_life_number = new QLineEdit();
        lineEdit_life_number->installEventFilter(this);
        lineEdit_life_number->setText(DataSystems::Instance().dataentry_library_siries_life_number);
        ui->tableWidget->setCellWidget(i,1,lineEdit_life_number);

        QLineEdit *lineEdit_sire_code = new QLineEdit();
        lineEdit_sire_code->installEventFilter(this);
        lineEdit_sire_code->setText(DataSystems::Instance().dataentry_library_siries_sire_code);
        ui->tableWidget->setCellWidget(i,2,lineEdit_sire_code);

        QCheckBox *checkbox_active = new QCheckBox();
        checkbox_active->installEventFilter(this);
        checkbox_active->setCheckState(Qt::CheckState::Checked);

        ui->tableWidget->setCellWidget(i,3,checkbox_active);

        QPushButton *pushButton_search = new QPushButton();
        pushButton_search->installEventFilter(this);
        pushButton_search->setText("search");
        ui->tableWidget->setCellWidget(i,4,pushButton_search);

        QPushButton *pushButton_show_all = new QPushButton();
        pushButton_show_all->installEventFilter(this);
        pushButton_show_all->setText("show_all");
        ui->tableWidget->setCellWidget(i,5,pushButton_show_all);
    }

    return;


}

void FormLibrary_1_9::create_feed_types()
{
    ui->tableWidget_feed_types->clear();
    auto datetimeDelegate = new DateTimeStyledItemDelegate(ui->tableWidget);

    //QMap<QString, QString> allColumns = json_w::form_table("table_form_1_2_bf.json");
    QList<QString> allColumns = json_w::form_table2("table_form_1_9_feed_types.json");
    qDebug()<< " Чтение конфига ---------------- ";
    //qDebug()<< " ||| " << allTabs.count() << " ||| " ;
    //QString firstColumn = allColumns.keys().first();
    //QList<QString> tab = allTabs.value(firstTab);
    //qDebug()<< " ||| " << firstColumn << " ||| " ;
    QStringList NameColumns;
    int i=0;
    foreach (QString cols, allColumns)
    {
        //NameColumns.append(allColumns[key]);
        //ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(cols));
        qDebug()<<i<<")"<<" name Columns: "<<cols<<"\n";
        i++;
        NameColumns<<cols;
    }

    ui->tableWidget_feed_types->setColumnCount( allColumns.count()+2 );
    ui->tableWidget_feed_types->setRowCount( 5 );
    for(int i=0;i<allColumns.count();i++)ui->tableWidget_feed_types->setColumnWidth(i, 150);
    ui->tableWidget_feed_types->setColumnWidth(allColumns.count(), 250);
    ui->tableWidget_feed_types->setColumnWidth(allColumns.count()+1, 250);

    ui->tableWidget_feed_types->setHorizontalHeaderItem(0, new QTableWidgetItem("Название"));
    ui->tableWidget_feed_types->setHorizontalHeaderLabels( NameColumns );
    ui->tableWidget_feed_types->horizontalHeader()->setStretchLastSection(true);

    //QStringList wordList;
    //wordList << "alpha" << "omega" << "omega2" << "omega3" <<"omicron" << "zeta";

    //ui->tableWidget->setItemDelegateForColumn(3,  datetimeDelegate);
    //ui->tableWidget->setItemDelegateForColumn(5,  datetimeDelegate);
    //ui->tableWidget->setItemDelegateForColumn(6,  datetimeDelegate);
    //ui->tableWidget_feed_types->hideColumn(0);

    for(int i=0;i<5;i++)
    {

            //QLineEdit *lineEdit_number_feed_types = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 0,  new QTableWidgetItem(QString::number(rand()%2222)));
            //QLineEdit *lineEdit_name = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 1,  new QTableWidgetItem("name" +QString::number(rand()%2222)));
            //QLineEdit *lineEdit_feed_types = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 2,  new QTableWidgetItem("name" +QString::number(rand()%2222)));
            //QLineEdit *lineEdit_dry_matter = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 3,  new QTableWidgetItem(QString::number(rand()%100)+"%"));

            //QLineEdit *lineEdit_remarks = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 4,  new QTableWidgetItem(QString::number(rand()%100)));

            QCheckBox *checkbox_active = new QCheckBox();
            checkbox_active->installEventFilter(this);
            checkbox_active->setCheckState(Qt::CheckState::Checked);
            ui->tableWidget_feed_types->setCellWidget(i,5,checkbox_active);

            QPushButton *pushButton_search = new QPushButton();
            pushButton_search->installEventFilter(this);
            pushButton_search->setText("Search");
            ui->tableWidget_feed_types->setCellWidget(i,6,pushButton_search);

            QPushButton *pushButton_show_all = new QPushButton();
            pushButton_show_all->installEventFilter(this);
            pushButton_show_all->setText("Show all");
            ui->tableWidget_feed_types->setCellWidget(i,7,pushButton_show_all);


            //QLineEdit *lineEdit_name = new QLineEdit();
//            ui->tableWidget->setItem( i, 0,  new QTableWidgetItem(QString::number(rand()%2222)));

//            QLineEdit *lineEdit_life_number = new QLineEdit();
//            lineEdit_life_number->installEventFilter(this);
//            lineEdit_life_number->setText(QString::number(rand()%2222));
//            ui->tableWidget->setCellWidget(i,1,lineEdit_life_number);

//            QLineEdit *lineEdit_sire_code = new QLineEdit();
//            lineEdit_sire_code->installEventFilter(this);
//            lineEdit_sire_code->setText(QString::number(rand()%2222));
//            ui->tableWidget->setCellWidget(i,2,lineEdit_sire_code);

            //            QComboBox *combobox_active = new QComboBox();
            //            combobox_active->installEventFilter(this);
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            combobox_active->addItem(QString::number(rand()%2222));
            //            ui->tableWidget->setCellWidget(i,3,combobox_active);

//            QCheckBox *checkbox_active = new QCheckBox();
//            checkbox_active->installEventFilter(this);
//            checkbox_active->setCheckState(Qt::CheckState::Checked);
//            ui->tableWidget->setCellWidget(i,3,checkbox_active);

//            QPushButton *pushButton_search = new QPushButton();
//            pushButton_search->installEventFilter(this);
//            pushButton_search->setText("search");
//            ui->tableWidget->setCellWidget(i,4,pushButton_search);


            //ui->tableWidget->setItem( i, 3,  new QTableWidgetItem(QDate().currentDate().toString()));
            //ui->tableWidget->setItem( i, 5,  new QTableWidgetItem(QDate().currentDate().toString()));
            //ui->tableWidget->setItem( i, 6,  new QTableWidgetItem(QDate().currentDate().toString()));

    }
}






void FormLibrary_1_9::on_pushButton_3_clicked()
{
    formlibrary_1_9_tab_feed_types_dialog d_1_9_d(this);
    if(!(d_1_9_d.exec()==QDialog::Accepted)){
            //create();

            int i=ui->tableWidget_feed_types->rowCount();
            ui->tableWidget_feed_types->setRowCount( i+1 );

            //QLineEdit *lineEdit_number_feed_types = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 0,  new QTableWidgetItem(DataSystems::Instance().dataentry_library_feed_types_number_feed_types));
            //QLineEdit *lineEdit_name = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 1,  new QTableWidgetItem(DataSystems::Instance().dataentry_library_feed_types_name));
            //QLineEdit *lineEdit_feed_types = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 2,  new QTableWidgetItem(DataSystems::Instance().dataentry_library_feed_types_type));
            //QLineEdit *lineEdit_dry_matter = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 3,  new QTableWidgetItem(DataSystems::Instance().dataentry_library_feed_types_dry_matter));

            //QLineEdit *lineEdit_remarks = new QLineEdit();
            ui->tableWidget_feed_types->setItem( i, 4,  new QTableWidgetItem(DataSystems::Instance().dataentry_library_feed_types_remark));

            QCheckBox *checkbox_active = new QCheckBox();
            checkbox_active->installEventFilter(this);
            checkbox_active->setCheckState(Qt::CheckState::Checked);
            ui->tableWidget_feed_types->setCellWidget(i,5,checkbox_active);

            QPushButton *pushButton_search = new QPushButton();
            pushButton_search->installEventFilter(this);
            pushButton_search->setText("Search");
            ui->tableWidget_feed_types->setCellWidget(i,6,pushButton_search);

            QPushButton *pushButton_show_all = new QPushButton();
            pushButton_show_all->installEventFilter(this);
            pushButton_show_all->setText("Show all");
            ui->tableWidget_feed_types->setCellWidget(i,7,pushButton_show_all);

    }

    QMessageBox::information(this,"Спасибо","Добавлены данные");
    this->close();

}

