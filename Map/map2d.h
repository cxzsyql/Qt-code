#ifndef MAP2D_H
#define MAP2D_H

#include <QGraphicsView>
#include "node2d.h"
#include "map.h"


class Map2D;

enum Map2DStlye
{
    TwoD,TowPFivwD
};

class Map2DTool : public MapTool
{
public:
    Map2DTool(Map2D *);
    Map2DTool();
    virtual ~Map2DTool();
    void editMap();
    void saveMap();
    void setMapBrush(QBrush *);
    void setObject(Map *);
private:
    Map2D *map;
};

class Map2D : public QGraphicsView , public Map
{
    Q_OBJECT
public:
    explicit Map2D(QWidget *parent = 0);
    virtual ~Map2D();

    void setXTileNum(const uint &);
    void setYTileNum(const uint &);
    void setTileSize(const QSize &);
    Node *indexOfNode(const uint &);
    void createNode2D(uint x,uint y,uint x_scale,uint y_scale);
    void setMap2DStyle(const Map2DStlye &);
    void setNodeSize(const QSize &);
    void addNode(const int &,Node *);
    void delNode(const int &);
    void zoomIn(const float &);
    void zoomOut(const float &);
    void retoteLeft();
    void retoteRight();
    QGraphicsScene *scene;
    void setBrush(QBrush *);
private slots:
    void setupMatrix(const int &);

private:
    void wheelEvent(QWheelEvent *e);
    QHash<int,Node*> hash_cursor;
    uint x_tile_num;
    uint y_tile_num;
    QSize tile_size;
    QPainter painter;
    QPixmap render_pixmap;
    bool is_render;


    Map2DStlye style;
    QSize node_size;
    float factor;
    float zoom_factor;
    float rerote_factor;
    QBrush brush;
};

#endif // MAP2D_H
