#ifndef NODE_H
#define NODE_H


#include <QtCore>

struct NodeData
{
public:
    QMap<QString,QVariant> data;
};


class Node
{
public:
    Node(){}
    virtual~Node(){}
    virtual void setNodeAttribute(const QString &,const QVariant &);
    virtual void setNodeAttribute( QMap<QString,QVariant> &);
    virtual QVariant getNodeAttribute(const QString &) const;
    NodeData data;
};

#endif // NODE_H
