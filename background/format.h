#ifndef FORMAT_H
#define FORMAT_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QTextStream>

#include "widgetwrap.h"
#include "scene.h"
#include "diagramwindow.h"

typedef WidgetWrap widget ;

/***************************************************
 * Class name: format
 * Base class: QObject
 * Description: This class is designed for
 *    save digraph, which is not in topological
 *    sequence. It also compile the topological
 *    widgets into python code that will be carried
 *    out by drones.
****************************************************/


class format
{
public:
    //~format(){;}
    //format(){set_scene(view->scene);}
    format(QMap<QString,WidgetWrap>& m);
    bool save_frame_file(QString filename);    //保存框图文件
    bool save_pyfile(QString filename);     //保存py可执行文件
    bool read_frame_file(QString filename);
    QMap<QString, widget> get_map(){return Map;}
    bool set_scene(newscene* s){scene = s;return true;}


private:
    //WidgetMap wm;
    QMap<QString, widget> Map;
    //SSmap用于保存需要接受变量的控件的名字和对应的变量
    //因为每一个前置控件都知道其后置控件需要什么参数并定义该参数，但是后置控件需要事先与参数绑定才能在转化时找到它
    QMap<QString,QString> SSmap;
    newscene* scene;

    //控件转化成代码块。参数1是要写入的目标文件名，2是要被转化的控件的指针
    void widget_convert_to_py(QMap<QString, widget>::iterator& iter, QTextStream& stream);

    //控件转化成xml格式代码。参数1是指向要转化的控件的迭代器，2是xml文件的写入流
    void widget_convert_to_xml(QMap<QString, widget>::iterator& iter, QXmlStreamWriter& stream);

    //读取xml文件并生成控件的需要，实现与scene中代码类似的create函数。num表示VarDef是VarType的第几个节点
    //bool CreateVarDef(QPoint point, int id, QString data_type, int num);
signals:

public slots:
};

#endif // FORMAT_H
