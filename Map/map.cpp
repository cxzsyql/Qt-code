#include "map.h"

Map::Map()
{
}

Map::~Map()
{   
}
void Map::addNode(const int &index,Node *n)
{
    hash_node.insert(index,n);
}
void Map::delNode(const int &index)
{
    delete hash_node.find(index).value();
}
Map *Map::createMap()
{
    return new Map();
}
void Map::saveMap()
{}

Node *Map::getNode(const int &index)
{
    return hash_node.find(index).value();
}
void Map::delAllNode()
{
    for(QHash<int,Node*>::Iterator i = hash_node.begin();i!=hash_node.end();i++)
        delete i.value();
    hash_node.clear();
}


