#include "map2d.h"
#include <QPainter>
#include <QHash>
#include <QPaintEvent>
#include "node2d.h"

Map2D::Map2D(QWidget *parent) :
    QGraphicsView(parent)
{
    style = TwoD;
    scene = new QGraphicsScene();
    factor=1;

    setScene(scene);
}
Map2D::~Map2D()
{}
void Map2D::createNode2D(uint x,uint y,uint x_scale,uint y_scale)
{
    int index=0;
    int x_num=(x/2)*x_scale;
    int y_num=(y/2)*y_scale;
    qDebug()<<x_num<<y_num<<x_scale<<y_scale<<0-x_num;
    for(int i=-x_num; i < x_num;i+=x_scale)
    {
        for(int j=-y_num;j < y_num;j+=y_scale)
        {

            QGraphicsItem *item = new Node2D(QString(":/Resource/glass.png"));
            if(style==TwoD)
                item->setPos(QPointF(i,j));
            else if(style==TowPFivwD)
                item->setPos(QPointF(x_scale,y_scale));
            else
                throw QString("Map2D: style error,not set style");
            index++;
            addNode(index,dynamic_cast<Node*>(item));
        }
    }
}
void Map2D::wheelEvent(QWheelEvent *e)
{
    if (e->modifiers() & Qt::ControlModifier) {
        if (e->delta() > 0)
            zoomIn(0.1);
        else
            zoomOut(-0.1);
        e->accept();
    } else {
        QGraphicsView::wheelEvent(e);
    }
}
void Map2D::zoomIn(const float &value)
{
    if(factor>=10)
    {
        qDebug()<<"zoomin";
        return ;
    }
    qDebug()<<matrix().dx()<<matrix().dy();
    factor +=value;
    QMatrix matrix;
    matrix.scale(factor, factor);
    setMatrix(matrix);
}
void Map2D::zoomOut(const float &value)
{
    if(factor<=0)
    {
        qDebug()<<"zoomout";
        return ;
    }
    factor +=value;
    QMatrix matrix;
    matrix.scale(factor, factor);
    setMatrix(matrix);
}
void Map2D::retoteLeft()
{}
void Map2D::retoteRight()
{}
void Map2D::addNode(const int &index,Node *node)
{
    hash_node.insert(index,node);
    this->scene->addItem(dynamic_cast<QGraphicsItem *>(node));
}
void Map2D::delNode(const int &index)
{
    delete hash_node.find(index).value();
    hash_node.remove(index);
}
void Map2D::setMap2DStyle(const Map2DStlye &s)
{
    style = s;
}
void Map2D::setXTileNum(const uint &n)
{
    x_tile_num = n;
}
void Map2D::setYTileNum(const uint &n)
{
    y_tile_num = n;
}
void Map2D::setTileSize(const QSize &size)
{
    tile_size = size;
}
Node *Map2D::indexOfNode(const uint &index)
{
    return hash_node.find(index).value();
}
void Map2D::setNodeSize(const QSize &size)
{
    node_size = size;
}
void Map2D::setupMatrix(const int &delt)
{
    if(rerote_factor>360 || rerote_factor<0)
        return ;
    QMatrix matrix;
    zoom_factor += delt;
    matrix.scale(zoom_factor*x(), zoom_factor*y());
    matrix.rotate(rerote_factor);
    setMatrix(matrix);
}
void Map2D::setBrush(QBrush *b)
{
    brush = *b;
}


Map2DTool::Map2DTool(Map2D *map)
{
    this->map = map;
}
Map2DTool::Map2DTool()
{
    map = new Map2D();
}
Map2DTool::~Map2DTool()
{}
void Map2DTool::editMap()
{}
void Map2DTool::saveMap()
{}
void Map2DTool::setMapBrush(QBrush *b)
{
    map->setBrush(b);
}
void Map2DTool::setObject(Map *object)
{
    map = dynamic_cast<Map2D *>(object);
}
