#include "formlibrary_1_9_tab_feed_types_dialog.h"
#include "ui_formlibrary_1_9_tab_feed_types_dialog.h"

#include "dataanimals.h"

// диалог ввода
// 1. Навигатор: Ввод данных     2. Меню: Библиотеки               3. Подменю: Типы корма


formlibrary_1_9_tab_feed_types_dialog::formlibrary_1_9_tab_feed_types_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::formlibrary_1_9_tab_feed_types_dialog)
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

    ui->pushButton_feed_types_save->setStyleSheet(
        "background-color:#14B143;"
        "color: white;"
        "padding: 4 50 4 10;"
        );
    ui->pushButton_feed_types_close->setStyleSheet(
        "background-color:#14B143;"
        "color: white;"
        "padding: 4 50 4 10;"
        );

}

formlibrary_1_9_tab_feed_types_dialog::~formlibrary_1_9_tab_feed_types_dialog()
{
    delete ui;
}

void formlibrary_1_9_tab_feed_types_dialog::on_pushButton_save_clicked()
{

}


void formlibrary_1_9_tab_feed_types_dialog::on_pushButton_feed_types_close_clicked()
{
    this->close();
}


void formlibrary_1_9_tab_feed_types_dialog::on_pushButton_feed_types_save_clicked()
{
    DataSystems::Instance().dataentry_library_feed_types_number_feed_types = (ui->lineEdit_number_feed_types->text());
    DataSystems::Instance().dataentry_library_feed_types_dry_matter = (ui->lineEdit_dry_matter->text());
    DataSystems::Instance().dataentry_library_feed_types_name = (ui->lineEdit_name->text());
    DataSystems::Instance().dataentry_library_feed_types_type = (ui->comboBox_type->currentText());
    //DataSystems::Instance().dataentry_library_feed_types_active = (ui->radioButton->se);

    QMessageBox::information(this,"Спасибо","Сохранеы данные по типам кормов");
    this->close();
}

