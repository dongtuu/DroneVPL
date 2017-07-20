#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "yuan.h"

/********************************************************************
* Class name: newview
* Description: provide a new view to do some mouse-events
********************************************************************/
class newscene:public QGraphicsScene
{
    Q_OBJECT
public:
    newscene();
    ~newscene();
    specialYuan* new_yuan;

protected:

    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // VIEW_H
