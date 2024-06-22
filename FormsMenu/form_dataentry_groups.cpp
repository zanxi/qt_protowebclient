#include "form_dataentry_groups.h"
#include "ui_form_dataentry_groups.h"

#include <QStringListModel>

#include "dataanimals.h"

form_dataentry_groups::form_dataentry_groups(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_dataentry_groups)
{
    ui->setupUi(this);

    ui->tabWidget_Groups->setStyleSheet("QTabWidget"
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


    QStringListModel *m_qlist_model = nullptr;
    m_qlist_model = new QStringListModel();
    QStringList list;
    list<<(QString("1)Буренки"));
    list<<(QString("3)Маруши"));
    list<<(QString("4)Зрелые"));
    list<<(QString("4)После родов"));

    m_qlist_model->setStringList(list);

    ui->listView->setModel(m_qlist_model);
    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);
    connect(ui->listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(SelectionChanged(QItemSelection)));
    ui->listView->update();


}

void form_dataentry_groups::SelectionChanged(const QItemSelection& selection)
{
    QModelIndex index = selection.indexes().first();
    QString listCheck = index.data(Qt::DisplayRole).toString();

    qDebug()<<listCheck;

    if (listCheck.contains("робот"))
    {
        if(ui->horizontalLayout->count()<1)
        {
            //form_dataentry_Robot *tr = new form_dataentry_Robot(this);
            //ui->horizontalLayout->addWidget(tr);
            return;
        }

        QLayoutItem *child = ui->horizontalLayout->takeAt(0);
        //while ((child = ui->verticalLayout_2->takeAt(0)) != 0)
        if(!child) {return;}
        QWidget* w = child->widget();
        delete child;
        if(!w) {return;}
        ui->horizontalLayout->removeWidget(w);
        delete w;

        //form_dataentry_Robot *tr = new form_dataentry_Robot(this);
        //ui->horizontalLayout->addWidget(tr);

        qDebug()<<"CHeck ListView"<<listCheck<<"; delete Widget";

    }

}

form_dataentry_groups::~form_dataentry_groups()
{
    delete ui;
}
