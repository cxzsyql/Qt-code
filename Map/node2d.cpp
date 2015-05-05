#include "node2d.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>

Node2D::Node2D()
{
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}
Node2D::Node2D(const QString &filename)
{
    this->filename = filename;
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}
Node2D::~Node2D()
{}
void Node2D::setSize(const uint &x,const uint &y)
{
    p_data.xscale=x;
    p_data.yscale=y;
}
void Node2D::setBrush(QBrush *b)
{
    brush = b;
}
void Node2D::loadPicture(const QString &filename)
{
    this->filename = filename;
}
void Node2D::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    Q_UNUSED(widget);
    QColor color(125,125,125);

    painter->drawRect(QRectF(0,0,10,10));

    if (option->state & QStyle::State_MouseOver)
    {
        color = color.light(80);
        brush->setColor(color);
    }
    else
        brush->setColor(color);
    if(option->state & QStyle::State_Selected)
        brush->setTexture(QPixmap(filename));
    painter->fillRect(QRectF(0,0,10,10),*brush);
}
void Node2D::setIndex(const uint &x_index,const uint &y_index)
{
    p_data.x_index = x_index;
    p_data.y_index = y_index;
}
QRectF Node2D::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}
QPainterPath Node2D::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 50, 50);
    return path;
}
void Node2D::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void Node2D::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void Node2D::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
