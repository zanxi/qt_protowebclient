#include "modelbuilder.h"

#include <QDebug>
#include "debug/logger.h"

ModelBuilder::ModelBuilder(QString file_path)
{
    tree_model = new QStandardItemModel();
    GetXmlData(file_path);

}

ModelBuilder::~ModelBuilder(){
    delete tree_model;
}

QStandardItemModel *ModelBuilder::GetTreeModel(){
    return tree_model;
}

void ModelBuilder::GetXmlData(QString xml_file_path){
    QFile xml_file(xml_file_path);

    bool ret = xml_file.open(QFile::ReadOnly | QFile::Text);

    //QString str = QString(xml_file.readAll());
    //logger::WriteMsg(str.toStdString());
    //qDebug()<<str;


//    if (ret) {
//        qDebug()<<"file <"<<xml_file_path<<"> not exists"<<"\n";
//        logger::WriteMsg("file "+xml_file_path.toStdString()+" not exists"+"\n");
//        //return;
//    }

    //QString str = QString(xml_file.readAll());
    //qDebug()<<str;


    QDomDocument dom_document;
    dom_document.setContent(&xml_file);
    xml_file.close();

    QDomElement top_element = dom_document.documentElement();
    if(top_element.isNull())
    {
        logger::WriteMsg("xml isNULL");
        return;
    }
    QDomNodeList node_list = top_element.childNodes();
    if(node_list.isEmpty()) return;
    QHash<QString, QDomNode> hash;

    for(int i=0; i<node_list.length();i++)
    {
        QString id = node_list.at(i).toElement().attribute("id");
        if(!id.isNull()&&!id.isEmpty())
        {
            hash.insert(id, node_list.at(i));
        }
    }

    QDomNode dom_node = top_element.firstChild();

    while(!dom_node.isNull())
    {
        QDomElement dom_element = dom_node.toElement();
        if(dom_element.attribute("id") == QString(""))
        {
            GetElementData(nullptr, dom_element, hash);
        }
        dom_node = dom_node.nextSibling();
    }
}

void ModelBuilder::GetElementData(
    QStandardItem *treeItem,
    QDomNode &dom_node,
    QHash<QString, QDomNode> &hash,
    bool from_hash)
{
    QDomElement element = dom_node.toElement();
    QString name = element.attribute("name");
    QString id = element.attribute("id");
    QDomNode child = dom_node.firstChild();
    QDomNode node = hash[id];

    //logger::WriteMsg("GetElementData(tree): --- "+name.toStdString());

    if(!name.isEmpty()){
        QStandardItem *item = SetChild(treeItem,
                                       name.isEmpty()?id:name);
        qDebug()<<"tree: "<<(name.isEmpty()?id:name);
        while(!child.isNull())
        {
            GetElementData(item,child,hash);
            child = child.nextSibling();
        }

        if(!id.isEmpty()&&!node.isNull()&&!from_hash)
        {
            GetElementData(item,node,hash,true);            
        }
    }
    else if(!id.isEmpty())
    {
        while(!child.isNull())
        {
            GetElementData(treeItem,child,hash);            
            child = child.nextSibling();

        }

        if(child.isNull()&&name.isEmpty())
        {
            if(!node.isNull()&&!from_hash)
            {
                GetElementData(treeItem,node,hash,true);
                return;
            }

            if(!from_hash)
            {
                SetChild(treeItem,name.isEmpty()?id:name);
            }

        }
    }
    else
    {

    }
}

QStandardItem *ModelBuilder::SetChild(QStandardItem *parent, QString name, QString icon_picture)
{
    if(parent == nullptr)
    {
        parent  = new QStandardItem(name);
        //parent->setIcon(QIcon(":/images/logo"));
        //parent->setIcon(QIcon(":/menu/icon.png"));
        parent->setIcon(QIcon(icon_picture));
        //parent->setFlags(Qt::ItemFlags::enum_type::ItemIsEditable);
        //parent->setEditable(false); //Qt::ItemFlags::enum_type::ItemIsEditable);
        logger::WriteMsg("GetElementData(tree): --- "+name.toStdString());
        if(name.contains("Начало"))
        {
           parent->setIcon(QIcon(":/menu/icon.png"));
        }
        else if(name.contains("Ввод данных"))
        {
           parent->setIcon(QIcon(":/images/1.png"));

        }
        else if(name.contains("Анализ/доклады"))
        {
           parent->setIcon(QIcon(":/images/2.png"));
        }
        else if(name.contains("Конфигурация"))
        {
           parent->setIcon(QIcon(":/images/3.png"));

        }
        else if(name.contains("Обслуживание"))
        {
           parent->setIcon(QIcon(":/images/4.png"));
        }
        else if(name.contains("Электронное обучение"))
        {
           parent->setIcon(QIcon(":/images/5.png"));
        }



        if(tree_model->rowCount()==0)
        {            
            tree_model->setItem(0,0,parent);
            tree_model->setHeaderData(0, Qt::Horizontal," ");
        }
        else
        {
            tree_model->setItem(tree_model->rowCount(),0,parent);
        }
        return parent;

    }
    QStandardItem* child = new QStandardItem(name);
    parent->setChild(parent->rowCount(),0,child);
    return child;

}
