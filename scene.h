#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "yuan.h"
#include "newnode.h"
#include "widgetmap.h"

//class DiagramWindow;
/********************************************************************
* Class name: newscene
* Description: provide a new scene to do some mouse-events
********************************************************************/
class newscene:public QGraphicsScene
{
    Q_OBJECT
public:
    newscene(WidgetMap* m);
    ~newscene();
    specialYuan* new_yuan;

    //void setnewCreationName();
    Node *selectedNode() const;
    NewNode *selectedNewNode() const;
    void addTranslationNode();
    void bringToFront();

    bool CreateTakeOff(QPointF point, int id);
    bool CreateLand(QPointF point, int id);
    bool CreateGo(QPointF point, int id);
    bool CreateTurn(QPointF point, int id);
    bool CreateHover(QPointF point, int id);
    bool CreateDelay(QPointF point, int id);
    bool CreateVarType(QPointF point, int id);
    bool CreateVarDef(QPointF point, int id);
    bool CreateCompute(QPointF point, int id);
    bool CreateIO(QPointF point, int id);
    bool CreateLogic(QPointF point, int id);
    /*
    bool CreateGoLeft(QPointF point, int id);
    bool CreateGoRight(QPointF point, int id);
    bool CreateGoUp(QPointF point, int id);
    bool CreateGoDown(QPointF point, int id);
    bool CreateForward(QPointF point, int id);
    bool CreateBackward(QPointF point, int id);
    bool CreateTurnLeft(QPointF point, int id);
    bool CreateTurnRight(QPointF point, int id);
*/

    int need_to_set;
    int selected_Index;

    int VarTypeNodeNum;  //计数varNode,命名每个varNode,下同
    int VarDefNodeNum;

    int LogicNodeNum;

    int takeoffNodeNum;
    int landonNodeNum;
    int GoNodeNum;  //6个方向的直线运动控件都包含在内
    int TurnNodeNum;    //左右两个方向的转向控件
    int HoverNodeNum;
    int DelayNodeNum;

    int CompputeNodeNum;

    int IONodeNum;

    int linkNodeNum;

    WidgetMap* wm;
signals:
    void itemInserted(int index);
private:
    void setZValue(int z);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* new_event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
};

#endif // SCENE_H
