#ifndef TABLE_FORM_1_2_OTEL_H
#define TABLE_FORM_1_2_OTEL_H

#include <QWidget>

namespace Ui {
class table_form_1_2_otel;
}

class table_form_1_2_otel : public QWidget
{
    Q_OBJECT

public:
    explicit table_form_1_2_otel(QWidget *parent = nullptr);
    ~table_form_1_2_otel();

private:
    Ui::table_form_1_2_otel *ui;
};

#endif // TABLE_FORM_1_2_OTEL_H
