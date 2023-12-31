#ifndef JSON_W_H
#define JSON_W_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QFile>
#include <QDir>
#include <QMap>
#include <QDebug>
#include <QList>



class json_w
{
public:
    json_w();

    static QList<QString> readJsonFile_all_tables(QString pathApp);
    static QMap<QString, QList<QString>> all_tables();
    static QMap<QString, QString> form_table(QString table_form_file);
    static QList<QString> form_table2(QString table_form_file);

    static QMap<QString, QString> readJsonFile_form_table(QString pathApp);
    static QList<QString> readJsonFile_form_table2(QString pathApp);
    //static QMap<QString, QList<QString>> all_tables();

};

#endif // JSON_W_H
