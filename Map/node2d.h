#ifndef NODE2D_H
#define NODE2D_H

#include "map.h"
#include <QtCore>
#include <QGraphicsItem>
#include <QBrush>

struct Node2DData
{
    uint xscale;
    uint yscale;
    uint xmargin;
    uint ymargin;
    uint x_index;
    uint y_index;
};



class Node2D : public QGraphicsItem, public Node
{
public:
    Node2D();
    Node2D(const QString &filename);
    ~Node2D();
    void setSize(const uint &x,const uint &y);
    void loadPicture(const QString &);
    void setIndex(const uint &,const uint &);
    QPainterPath shape() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setBrush(QBrush *);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    QRectF boundingRect() const;

    Node2DData p_data;
    QString filename;
    QBrush *brush;
};

#endif // NODE2D_H
