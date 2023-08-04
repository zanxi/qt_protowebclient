#include "form_in_work.h"
#include "ui_form_in_work.h"
#include <QFont>

Form_in_work::Form_in_work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_in_work)
{
    ui->setupUi(this);

    ui->groupBox->setStyleSheet("QGroupBox {"
                                "background-color: white;"
                                "}"
                                "QGroupBox::title {"
                                "color: white;"
                                "background-color:#14B143;"
                                "padding: 4 20000 4 10;"
                                "}");

    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    QPalette sample_palette;


    sample_palette.setColor(QPalette::Window, Qt::white);
    sample_palette.setColor(QPalette::WindowText, Qt::blue);

    ui->label->setAutoFillBackground(true);
    ui->label->setPalette(sample_palette);
    ui->label->setText("What ever text");

    ui->label->setStyleSheet("QLabel {color: #0000FF; background: #9ACD32;};"
                             "QFont{size:25}");
    //ui->label->setFont(QFont("10"));
}

Form_in_work::~Form_in_work()
{
    delete ui;
}
