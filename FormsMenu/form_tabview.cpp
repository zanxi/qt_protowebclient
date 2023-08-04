#include "form_tabview.h"
#include "ui_form_tabview.h"
#include "connectiondialog.h"

Form_tabview::Form_tabview(QString user,QString pwd, QString host, QString db_name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_tabview)
{
    this->user = user;
    this->pwd = pwd;
    this->host = host;
    this->db_name = db_name;


    ui->setupUi(this);
    setFixedSize(650,350); // фиксированный размер гл. окна

   //ConnectionDialog dialog(this);

    db = new DataBase();                        //  объект, который будет использоваться для подключения и дальнейшей работы с БД
    db->connectToDataBase();                //  подключаемся/создаем бд

    for (int i = 0; i < 10; i++) {
         QVariantList data;
         data.append(i+1);                                      //     ЗАПОЛНЯЕМ СТРОКАМИ qual_table
         data.append(i+10);
         db->inserIntoTable("", QList<QString>{""},data);             //  каждый раз вызываем inserIntoTable()  с передачей массива данных
    }


    //this->setupSQLTableModel( TABLE2,   QStringList() << "columns"  );         // передаем имя таблицы main_table, и массив заголовков (который заполняем прямо здесь)

    tableView = new QTableView(this);
    this->setupTableView();                       //  инициализируем ВИД  (QTableView)

    QPushButton *btnInsert = new QPushButton("Добавить", this);
    QPushButton *btnDelete = new QPushButton("Удалить",this);
    QPushButton *btnUpdate = new QPushButton("Редактировать",this);

    QHBoxLayout *hlayot = new QHBoxLayout();     // горизонтальный слой с кнопками
    QVBoxLayout *vlayot = new QVBoxLayout();         // таблица + слой с кнопками

    hlayot->addWidget(btnInsert);
    hlayot->addWidget(btnDelete);          // горизонтальный слой кнопок
    hlayot->addWidget(btnUpdate);
    hlayot->addSpacing(300);

    vlayot->addLayout(hlayot);                    //  вертикальный слой,  кнопки + таблица
    vlayot->addWidget(tableView);

    QWidget *placeholderWidget = new QWidget;        //  стандартный приём, добавляем главный слой на простой виджет, и этот виджет делаем центральным. Т.к.  setCentralWidget принимает лишь виджет.
    placeholderWidget->setLayout(vlayot);
    //setCentralWidget(placeholderWidget);


    connect(btnInsert, SIGNAL(clicked()), this, SLOT(onAddButtonClickedSlot()));
    connect(btnUpdate, SIGNAL(clicked()), this, SLOT(onEditButtonClickedSlot()));                //  при нажатии на кнопки
    connect(tableView, SIGNAL(doubleClicked(const QModelIndex)), this, SLOT(onEditButtonClickedSlot()));
    connect(btnDelete, SIGNAL(clicked()), this, SLOT(deleteRowSlot()));
    //connect(dialog.buttonSave, SIGNAL(clicked()), this, SLOT(onSaveButtonClickedSlot()));

}


void Form_tabview::setupSQLTableModel(QString tableName,   QStringList headers)          //    метод  настройки  QSqlTableModel ,   принимает имя таблицы и заголовки
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);                       //  этот встроенный метод QSqlTableModel задает имя таблицы,  ведь QSqlTableModel работает только с одной таблицей.

    for(int i = 0;  i < model->columnCount();  i++){            //  Устанавливаем названия столбцов из принятого массива
        model->setHeaderData( i,  Qt::Horizontal,  headers[i]);
    }
    model->setSort(0, Qt::AscendingOrder);                    // Устанавливаем сортировку по возрастанию данных по нулевой колонке
}



void Form_tabview::setupTableView()               //  метод настройки TableView
{
   tableView->setModel(model);                         // Устанавливаем модель  QSqlTableModel  на TableView

   tableView->setSelectionBehavior(QAbstractItemView::SelectRows);          // Разрешаем выделение строк
   tableView->setSelectionMode(QAbstractItemView::SingleSelection);          // Устанавливаем режим выделения лишь одной строки в таблице
   tableView->resizeColumnsToContents();                         // Устанавливаем размер колонок по содержимому

   tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
   tableView->horizontalHeader()->setStretchLastSection(true);                //  последний столбец растягивается на все оставшееся пространство

    model->select();                                 // делаем выборку данных из main_table и обновляемся, что-бы видеть изменения.
    tableView->setFixedSize(650,300);
}


void Form_tabview::onEditButtonClickedSlot()
{
    if(tableView->currentIndex().isValid()) {                   //  проверка выделено ли что-нибудь.
      forEdit = true;
      dialog.buttonSave->setText("Сохранить");

      QString str1 = model->index(tableView->currentIndex().row(), 0, QModelIndex()).data().toString();                 //  получаем текст элементов
      QString str2 = model->index(tableView->currentIndex().row(), 1, QModelIndex()).data().toString();
      QString str3 = model->index(tableView->currentIndex().row(), 2, QModelIndex()).data().toString();

      dialog.show();                                                           //  открываем окно для редактирования.
      dialog.lineedit1->setText(str1);
      dialog.lineedit2->setText(str2);
      dialog.lineedit3->setText(str3);                         //   поля редактирования изначально будут заполнены текущими данными.
    }
}

void Form_tabview::onAddButtonClickedSlot()
{
    forEdit = false;
    dialog.buttonSave->setText("Добавить строку");
    dialog.show();                                                                    //  открываем окно для добавления.
    dialog.lineedit1->clear();
    dialog.lineedit2->clear();
    dialog.lineedit3->clear();
}

void Form_tabview::onSaveButtonClickedSlot()
{
    //if(forEdit) { updateRow("", QList<QString>(){""}); }                                       //  вызовет либо изменение либо добавление строки, в зависимости от ситуации.
    //else insertRow();
}


void Form_tabview::insertRow(QString table)
{
    QSqlQuery query;

    query.prepare( "INSERT INTO " + table + " ( i, r, t ) "
                                           "VALUES  (?,?,?)");
    query.addBindValue(dialog.lineedit1->text().toInt());
    query.addBindValue(dialog.lineedit2->text());
    query.addBindValue(dialog.lineedit3->text());

    if(!query.exec()){
         QMessageBox::critical(0, "Не удалось добавить строку", query.lastError().text());
    }
    else {
    model->select();          //  обновляем модель, что-бы увидеть изменения
    dialog.close();
    QMessageBox::information(0, "Ок", "Данные успешно добавлены в базу");
    }
}

void Form_tabview::updateRow(QString table, QList<QString> columns)
{
    QModelIndex ind = model->index(tableView->currentIndex().row(), 0, QModelIndex());          //  получаем индекс первого элемента выделенной строки (он уникальный, поэтому будем по нему искать)
    QString str = ind.data().toString();


    QSqlQuery query;

    QString update="UPDATE " + table + " SET "+columns[0]+" = ? ";
    for(int i=1; i<columns.count();i++)
    {
       update+=", "+columns[i]+" = ? ";
    }

        query.prepare(update);
        //query.prepare( "UPDATE " + table + " SET i = ?, r = ?, t = ?  WHERE i = " +str+";");

        for(int i=0; i<columns.count();i++)
         query.addBindValue(columns[i]);


    if(!query.exec()){
        QMessageBox::critical(0, "Не удалось изменить строку", query.lastError().text());
    }
    else {
    model->select();                   //  обновляем модель, что-бы увидеть изменения
    dialog.close();
    QMessageBox::information(0, "Ок", "Данные успешно изменены");
    }
}


void Form_tabview::deleteRowSlot(int i){

   QModelIndex ind = model->index(tableView->currentIndex().row(), 0, QModelIndex());          //  получаем индекс первого элемента выделенной строки (он уникальный, поэтому будем по нему искать)
   QString str = ind.data().toString();

    QSqlQuery query;
   if(!query.exec( "DELETE FROM " + table + " WHERE i = " +str+";"))                      //  удаляем строку по уникальному индексу
    {
        QMessageBox::critical(0, "Не удалось удалить строку", query.lastError().text());
    }
    model->select();          //  обновляем модель, что-бы увидеть изменения
}

Form_tabview::~Form_tabview()
{
    delete ui;
}


