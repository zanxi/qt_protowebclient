#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <QString>
#include <QtXml>
#include <QStandardItemModel>

struct StringPair{
    QString name;
    QString value;

};


class ModelBuilder
{
public:
    ModelBuilder(QString file_path);
    ~ModelBuilder();

    QStandardItemModel* GetTreeModel();
    //void SetTabInfo();

private:
    void GetXmlData(QString xml_file_path);
    void GetElementData(
        QStandardItem *treeItem,
        QDomNode &dom_node,
        QHash<QString, QDomNode> &hash,
        bool from_hash = false);
    QStandardItem *SetChild(QStandardItem *parent,
                            QString name);
    QStandardItemModel *tree_model;
};

#endif // MODELBUILDER_H
