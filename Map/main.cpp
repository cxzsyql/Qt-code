#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QGridLayout>
#include "node2d.h"
#include "map2d.h"

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);
    a.setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);

    QWidget w;
    QGridLayout *layout = new QGridLayout;
    w.setLayout(layout);

    Q_INIT_RESOURCE(resources);
    Map2D map;
    map.resize(640,480);

    Map2DTool tool;
    tool.setObject(&map);
    tool.setMapBrush(new QBrush());

    map.createNode2D(100,100,11,11);

    map.setRenderHint(QPainter::Antialiasing, false);
    map.setDragMode(QGraphicsView::RubberBandDrag);
    map.setOptimizationFlags(QGraphicsView::DontSavePainterState);
    map.setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    map.setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

    layout->addWidget(&map);
    w.show();

    return a.exec();
}
