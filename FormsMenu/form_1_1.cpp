#include "form_1_1.h"
#include "ui_form_1_1.h"

Form_1_1::Form_1_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_1_1)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::white);
    this->setPalette(pal);

    ui->groupBox_2->setStyleSheet("QGroupBox {"
                                  "background-color: white;"
                                  "}"
                                  "QGroupBox::title {"
                                  "color: white;"
                                  "background-color:#14B143;"
                                  "padding: 4 20000 4 10;"
                                  "}");

    m_qlist_model_country = new QStringListModel();
    m_qlist_model_culture = new QStringListModel();
    m_qlist_model_lang = new QStringListModel();

    QStringList list_country,  list_culture,  list_lang;
    list_country.append(QString("Россия "));
    list_country.append(QString("Германия "));
    list_country.append(QString("Голландия "));
    list_country.append(QString("Германия "));
    list_country.append(QString("Англия "));
    list_country.append(QString("Сша "));
    list_country.append(QString("Китай "));
    list_country.append(QString("Франция "));

    list_culture.append(QString("русская "));
    list_culture.append(QString("азиатская "));
    list_culture.append(QString("Голландия "));
    list_culture.append(QString("индо-европейская "));
    list_culture.append(QString("восточная "));
    list_culture.append(QString("западная "));
    list_culture.append(QString("буддизм "));
    list_culture.append(QString("атеизм "));

    list_lang.append(QString("русский "));
    list_lang.append(QString("немецкий "));
    list_lang.append(QString("голландский "));
    list_lang.append(QString("австрийский "));
    list_lang.append(QString("английский "));
    list_lang.append(QString("английский(Сша) "));
    list_lang.append(QString("китайский "));
    list_lang.append(QString("французский "));


    m_qlist_model_country->setStringList(list_country);
    m_qlist_model_culture->setStringList(list_culture);
    m_qlist_model_lang->setStringList(list_lang);

    //ui->comboBox->setModel(m_qlist_model);
    ui->comboBox_counrty->setModel(m_qlist_model_country);
    ui->comboBox_culture->setModel(m_qlist_model_culture);
    ui->comboBox_lang->setModel(m_qlist_model_lang);

    //ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked);

}

Form_1_1::~Form_1_1()
{
    delete ui;
}
