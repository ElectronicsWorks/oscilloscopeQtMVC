#ifndef CGRIDMANAGER_H
#define CGRIDMANAGER_H
#include "DataManage/CVaoVboManager.h"
#include "CGrid.h"
#include <QGLWidget>
#include <QOpenGLFunctions_4_3_Core>

#include <map>

using std::map;
class CGridManager : public QObject, public QOpenGLFunctions_4_3_Core
{
    Q_OBJECT
public:
    explicit CGridManager(CVaoVboManager* _vaovboManager, QGLWidget* _widget);
    ~CGridManager();
    void createNewLineForNewIndex(u_short _imgIndex);
    void setCurIndex(u_short _index);
    void setRotation(u_short _index, QMatrix4x4 _rotation);
    void setMove(u_short _index, QMatrix4x4 _move);
    void setZoom(float _scale);
    void setDrawType(CGrid::DRAWTYPE _drawtype);
    void setCordi(vector2f _x, vector2f _y, vector2f _z);
    void draw();

    void adjustGridNumer(u_short _imgIndex, vector2f _xrange, vector2f _yrange, vector2f _zrange, CGrid::RangeChange _xRanChange, CGrid::RangeChange _yRanChange, CGrid::RangeChange _zRanChange);
private:
    void initial();
    u_short                    m_curIndex = 0;
    CVaoVboManager*              m_vaovboManager;
    QGLWidget*                  m_glwidget;
    map<u_short, CGrid*>         m_grids;
};

#endif // CGRIDMANAGER_H