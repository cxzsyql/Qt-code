#ifndef MAP_H
#define MAP_H

#include "map_global.h"
#include <QFile>
#include <QDomElement>
#include "node.h"


class MAPSHARED_EXPORT Map
{
public:
    Map();
    virtual ~Map();
    virtual void addNode(const int &,Node *);
    virtual void delNode(const int &);
    virtual Node *getNode(const int &);
    void delAllNode();
    virtual Map *createMap();
    virtual void saveMap();
    QHash<int,Node*> hash_node;
};

class MapTool
{
public :
    MapTool(){}
    virtual void editMap()=0;
    virtual void saveMap()=0;
    virtual void setObject(Map *)=0;
};







#endif // MAP_H
