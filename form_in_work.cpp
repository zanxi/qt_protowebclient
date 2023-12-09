#include "form_in_work.h"
#include "ui_form_in_work.h"
#include <QFont>
#include "./utils/imageview.h"
#include "dataanimals.h"

Form_in_work::Form_in_work(QByteArray ba, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_in_work)
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

    //ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    QPalette sample_palette;


    sample_palette.setColor(QPalette::Window, Qt::white);
    sample_palette.setColor(QPalette::WindowText, Qt::blue);

    //ui->label->setAutoFillBackground(true);
    //ui->label->setPalette(sample_palette);
    //ui->label->setText("What ever text");

    //ui->label->setStyleSheet("QLabel {color: #0000FF; background: #9ACD32;}; QFont{size:25}");


    ImageView *imageView = new ImageView(this);    
    imageView->setDisplayStyle(imageView->STYLE::contain);//
    QPixmap p;
    if(p.loadFromData(ba,"JPG"))
    {
        // do something with pixmap
    }
    imageView->setLoadingPixmap(p);
    ui->verticalLayout->addWidget(imageView);    
}

Form_in_work::Form_in_work(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_in_work)
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

    //ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    QPalette sample_palette;

    sample_palette.setColor(QPalette::Window, Qt::white);
    sample_palette.setColor(QPalette::WindowText, Qt::blue);

    //ui->label->setAutoFillBackground(true);
    //ui->label->setPalette(sample_palette);
    //ui->label->setText("What ever text");

    //ui->label->setStyleSheet("QLabel {color: #0000FF; background: #9ACD32;}; QFont{size:25}");

    ImageView *imageView = new ImageView(this);
    //imageView->setGeometry(50,50,200,200);
    //imageView->setGeometry(qRect);
    imageView->setDisplayStyle(imageView->STYLE::contain);//
    imageView->setLoadingPixmap(QPixmap(":/images/vim_logo.png"));
    //imageView->setFailedPixmap(QPixmap(":/images/image_error_page.png"));
    //imageView->setUrl("http://img.bss.csdn.net/201708102057303085.jpg");

    ui->verticalLayout->addWidget(imageView);

    //ui->label->setFont(QFont("10"));
}

Form_in_work::~Form_in_work()
{
    delete ui;
}
