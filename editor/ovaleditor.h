#ifndef OVALEDITOR_H
#define OVALEDITOR_H

#include "editor.h"
#include "shapes/oval.h"

class OvalEditor: public Editor
{
    BoundingBox *box;
    Oval *oval;
    enum class EditMode
    {
        NONE,
        MOVE,
        //编辑各个位置的点
        TOP_LEFT,
        TOP_RIGHT,
        BOTTOM_LEFT,
        BOTTOM_RIGHT,
        TOP,
        LEFT,
        RIGHT,
        BOTTOM,
        EDIT_RADIUS
    }editMode;
    Point *pold;

public:
    OvalEditor();
    void setEdit(IShape *shape, BoundingBox *box) override;
    void mousePressEvent(QMouseEvent *)override;
    void mouseMoveEvent(QMouseEvent *)override;
    void mouseReleaseEvent(QMouseEvent * )override;
};

#endif // OVALEDITOR_H
