#include "json_w.h"

json_w::json_w()
{

}

QList<QString> json_w::readJsonFile_all_tables(QString pathApp)
{
    QList<QString> vals;
    //qDebug() << "Read Json File:";

    //qDebug()<<"******** //1. **********"<<"\n";
    //1. Open the QFile and write it to a byteArray and close the file
    QFile file;
    //file.setFileName("./tables/RFeedSettings.json");
    //qDebug()<<QDir::currentPath()+ "/tables/e.json"<<"\n";

    file.setFileName(QDir::currentPath()+ "/tables/" + pathApp+".json");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Json filef couldn't be opened/found";
        return vals;
    }



    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return vals;
    }

    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    //qDebug()<<"******************"<<"\n";

    //4. Now picking the jsonValues and printing them out or do what ever you need
    QJsonValue jsonVal;
    QTextStream textStream(stdout);

    //qDebug()<<"******************"<<"\n";
    QJsonArray jsonArray;
    jsonArray = jsonObj[pathApp].toArray();
    //jsonArray = jsonObj["Phone numbers"].toArray();
    //logger::WriteMsg(QString(" ************** " + pathApp + " **********************").toStdString());

    foreach(const QJsonValue & value, jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            foreach(const QString& key, obj.keys()) {
                QJsonValue value = obj.value(key);
                //qDebug() << "Key = " << key << ", Value = " << value.toString();
                //vals.append(value.toString());
                vals.append(key);
            }
        }
    }
    return vals;
}

QMap<QString, QList<QString>> json_w::all_tables()
{

    QMap<QString, QList<QString>> temp_all_tables;

    QString pathApp = QDir::currentPath()+ "/tables/";
    qDebug()<<" Read Folder "<< (QDir::currentPath()+ "/tables/")<<"\n";
    QDir directory(pathApp);
    directory.setFilter(QDir::Files);
    QFileInfoList listfiles = directory.entryInfoList();
    for(QFileInfo qf: listfiles){
        //QDir::currentPath()+ "/tables/e.json";
        QString n = qf.fileName();
        QString nTab = n.remove(n.length()-5,n.length());        
        QList<QString> vals = readJsonFile_all_tables(nTab);
        temp_all_tables[nTab] = vals;        

    }
    return temp_all_tables;

}

QMap<QString, QString> json_w::form_table(QString table_form_file)
{

    QMap<QString, QString> temp_form_table;

    QString pathApp = QDir::currentPath()+ "/setting_forms/"+table_form_file;

    qDebug()<<" Read json file:  "<< (QDir::currentPath()+ "/setting_forms/"+table_form_file)<<"\n";
    QFileInfo qf(pathApp);
    if(!qf.exists())
    {
        //qDebug()<<" Read json file:  "<< (QDir::currentPath()+ "/setting_forms/"+table_form_file)<<"\n";
        return temp_form_table;

    }
        QString n = qf.fileName();
        QString nTab = n.remove(n.length()-5,n.length());
        //qDebug()<<qf.filePath()<<" | "<< nTab<<"\n";
        temp_form_table = readJsonFile_form_table(nTab);


    return temp_form_table;

}

QList<QString> json_w::form_table2(QString table_form_file)
{

    QList<QString> temp_form_table;

    QString pathApp = QDir::currentPath()+ "/setting_forms/"+table_form_file;

    qDebug()<<" Read json file:  "<< (QDir::currentPath()+ "/setting_forms/"+table_form_file)<<"\n";
    QFileInfo qf(pathApp);
    if(!qf.exists())
    {
        //qDebug()<<" Read json file:  "<< (QDir::currentPath()+ "/setting_forms/"+table_form_file)<<"\n";
        return temp_form_table;

    }
    QString n = qf.fileName();
    QString nTab = n.remove(n.length()-5,n.length());
    //qDebug()<<qf.filePath()<<" | "<< nTab<<"\n";
    temp_form_table = readJsonFile_form_table2(nTab);


    return temp_form_table;

}



QMap<QString, QString> json_w::readJsonFile_form_table(QString pathApp)
{
    QMap<QString, QString> temp;

    QFile file;
    //file.setFileName("./tables/RFeedSettings.json");
    //qDebug()<<QDir::currentPath()+ "/tables/e.json"<<"\n";

    file.setFileName(QDir::currentPath()+ "/setting_forms/" + pathApp+".json");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Json filef couldn't be opened/found";
        return temp;
    }



    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return temp;
    }

    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    //qDebug()<<"******************"<<"\n";

    //4. Now picking the jsonValues and printing them out or do what ever you need
    QJsonValue jsonVal;
    QTextStream textStream(stdout);

    //qDebug()<<"******************"<<"\n";
    QJsonArray jsonArray;
    jsonArray = jsonObj[pathApp].toArray();
    //jsonArray = jsonObj["Phone numbers"].toArray();
    //logger::WriteMsg(QString(" ************** " + pathApp + " **********************").toStdString());

    foreach(const QJsonValue & value, jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            foreach(const QString& key, obj.keys()) {
                QJsonValue value = obj.value(key);
                qDebug() << "Key = " << key << ", Value = " << value.toString();
                //vals.append(value.toString());
                temp[key]=value.toString();
            }
        }
    }


    return temp;
}


QList<QString> json_w::readJsonFile_form_table2(QString pathApp)
{
    QList<QString> temp;

    QFile file;
    //file.setFileName("./tables/RFeedSettings.json");
    //qDebug()<<QDir::currentPath()+ "/tables/e.json"<<"\n";

    file.setFileName(QDir::currentPath()+ "/setting_forms/" + pathApp+".json");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Json filef couldn't be opened/found";
        return temp;
    }



    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return temp;
    }

    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    //qDebug()<<"******************"<<"\n";

    //4. Now picking the jsonValues and printing them out or do what ever you need
    QJsonValue jsonVal;
    QTextStream textStream(stdout);

    //qDebug()<<"******************"<<"\n";
    QJsonArray jsonArray;
    jsonArray = jsonObj[pathApp].toArray();
    //jsonArray = jsonObj["Phone numbers"].toArray();
    //logger::WriteMsg(QString(" ************** " + pathApp + " **********************").toStdString());

    int i=0;
    foreach(const QJsonValue & value, jsonArray)
    {
        if (value.isObject())
        {
            QJsonObject obj = value.toObject();
            foreach(const QString& key, obj.keys()) {
                QJsonValue value = obj.value(key);
                qDebug() << "Key = " << key << ", Value = " << value.toString();
                //vals.append(value.toString());
                //temp.append(value.toString());
                temp.append(key);
                qDebug()<<i<<")"<<" name Columns: "<<key<<"|"<<value.toString()<<"\n";
                i++;
            }
        }
    }


    return temp;
}
