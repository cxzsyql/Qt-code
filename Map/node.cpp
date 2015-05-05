#include "node.h"


void Node::setNodeAttribute(const QString &attr_name,const QVariant &value)
{
    data.data.insert(attr_name,value);
}
void Node::setNodeAttribute(QMap<QString,QVariant> &map)
{
    for(QMap<QString,QVariant>::Iterator i = map.begin();i!=map.end();i++)
        data.data.insert(i.key(),i.value());
}
QVariant Node::getNodeAttribute(const QString &attr_name) const
{
    return data.data.find(attr_name).value();
}
