#include <QCoreApplication>

//https://stackoverflow.com/questions/61075951/minimal-example-on-how-to-read-write-and-print-qjson-code-with-qjsondocument

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QList>

#include "logger.h"


void readJsonFile(QString pathApp)
{
    //qDebug() << "Read Json File:";

    //qDebug()<<"******** //1. **********"<<"\n";
    //1. Open the QFile and write it to a byteArray and close the file
    QFile file;
    //file.setFileName("./tables/RFeedSettings.json");
    //qDebug()<<QDir::currentPath()+ "/tables/e.json"<<"\n";

    file.setFileName(pathApp);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "Json filef couldn't be opened/found";
        return;
    }



    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    //qDebug()<<"******* //2. ***********"<<"\n";

    //2. Format the content of the byteArray as QJsonDocument
    //and check on parse Errors
    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        return;
    }

    //qDebug()<<"******************"<<"\n";

    //3. Create a jsonObject and fill it with the byteArray content, formatted
    //and holding by the jsonDocument Class
    QJsonObject jsonObj;
    jsonObj = jsonDoc.object();

    qDebug()<<"******************"<<"\n";

    //4. Now picking the jsonValues and printing them out or do what ever you need
    QJsonValue jsonVal;
    QTextStream textStream(stdout);

//    jsonVal = jsonObj.value("FirstName");
//    textStream << jsonVal.toString() << endl;

//    jsonVal = jsonObj.value("MiddleName");
//    //null gets back to an empty fild - added the sting "null/empty" to make it visible
//    textStream << jsonVal.toVariant().toString() << "null/empty" << endl;

//    jsonVal = jsonObj.value("LastName");
//    textStream << jsonVal.toString() << endl;

//    //The number has to be converted to an int and than to a string to print it
//    jsonVal = jsonObj.value("Age");
//    textStream << QString::number(jsonVal.toInt()) << endl;

    //5. Now we need to fill the object of the object. To do that, we need
    //the Item Object and a jsonSubVal object for json without a loop
    QJsonObject jsonItemObj;
    QJsonValue jsonSubVal;

//    jsonVal = jsonObj.value(QString("Address"));
//    jsonItemObj = jsonVal.toObject();

//    jsonSubVal = jsonItemObj["Street"];
//    textStream << jsonSubVal.toString() << endl;

//    jsonSubVal = jsonItemObj["City"];
//    textStream << jsonSubVal.toString() << endl;

//    jsonSubVal = jsonItemObj["Country"];
//    textStream << jsonSubVal.toString() << endl;

    //6. now the Phone Numbers array with a loop


    qDebug()<<"******************"<<"\n";
    QJsonArray jsonArray;
    jsonArray = jsonObj["Phone numbers"].toArray();

    for(int i = 0; i < jsonArray.size(); i++)
        textStream << jsonArray[i].toString() << endl;

    //textStream << "or with foreach" << endl;

    //foreach(QJsonValue v, jsonArray) textStream << v.toString() << endl;

    //7. And finally the bool value:
    //jsonVal = jsonObj.value(QString("Valid"));
    //textStream << jsonVal.toVariant().toString() << endl;

    //textStream << "or as number, not a string: ";

    //textStream << (QString::number(jsonVal.toInt())) << endl;

    textStream << "\nThe whole file as printed in the file \n" <<
        jsonDoc.toJson(QJsonDocument::Indented);

}


QList<QString> readJsonFile2(QString pathApp)
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

    qDebug()<<"******************"<<"\n";

    //4. Now picking the jsonValues and printing them out or do what ever you need
    QJsonValue jsonVal;
    QTextStream textStream(stdout);

    //qDebug()<<"******************"<<"\n";
    QJsonArray jsonArray;
    jsonArray = jsonObj[pathApp].toArray();
    //jsonArray = jsonObj["Phone numbers"].toArray();
    logger::WriteMsg(QString(" ************** " + pathApp + " **********************").toStdString());

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

                //*writeStream<<"<field name = \""<<QString(value.toString())<<"\"""> </fieldmenu>"<<"\n";

                logger::WriteMsg(QString("Key = " + key + ", Value = " + value.toString()).toStdString());
            }
        }        
    }

    return vals;

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    /logger::ClearLog();


    QFile fileXml;
    //file.setFileName("./tables/RFeedSettings.json");
    //qDebug()<<QDir::currentPath()+ "/tables/e.json"<<"\n";

    //fileXml.setFileName(QDir::currentPath()+ "/tables/"+ "db_.xml");
    fileXml.setFileName(QDir::currentPath()+ "/db_.xml");
    if(!fileXml.open(QIODevice::ReadWrite)){
        qDebug() << "Json filef couldn't be opened/found";
        return 0;
    }

    QTextStream writeStream(&fileXml);
    writeStream<<"<db>"<<"\n";

    //writeStream<<"<fieldmenu = """<<<<""">";

    //QByteArray byteArray;
    //byteArray = file.readAll();
    //fileXm.close();


    QString pathApp = QDir::currentPath()+ "/tables/";
    qDebug()<<" Read Folder "<< (QDir::currentPath()+ "/tables/")<<"\n";
    QDir directory(pathApp);
    directory.setFilter(QDir::Files);
    QFileInfoList listfiles = directory.entryInfoList();
    for(QFileInfo qf: listfiles){
        //QDir::currentPath()+ "/tables/e.json";
        QString n = qf.fileName();
        QString nTab = n.remove(n.length()-5,n.length());
        //qDebug()<<qf.filePath()<<" | "<< nTab<<"\n";
        logger::WriteMsg(nTab.toStdString());

        writeStream<<"<fieldmenu name = \""<<nTab<<"\""">"<<"\n";
       // writeStream<<"<field name = \""<<nTab<<"\"""> </fieldmenu>"<<"\n";
        qDebug()<<"<fieldmenu name = \""<<nTab<<"\"""> </fieldmenu>"<<"\n";

        QList<QString> vals = readJsonFile2(nTab);
        foreach (auto vals, vals) {
            writeStream<<"<field name = \""<<vals<<"\"""> </field>"<<"\n";
        }

        writeStream<<"</fieldmenu>"<<"\n";
    }
    writeStream<<"</db>"<<"\n";

    fileXml.flush();
    fileXml.close();

    qDebug()<<" End Read folder "<<"\n";


    //readJsonFile(pathApp+"e.json");
    //readJsonFile(pathApp+"e.json");

    return a.exec();
}
