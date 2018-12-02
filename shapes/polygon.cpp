#include "polygon.h"

Poly::Poly(Point start, Point next)
{
    vertexs.push_back(start);
    vertexs.push_back(next);
    calcPoints();
}

void Poly::addVertex(Point p)
{
    if(!close())
        vertexs.push_back(p);
    calcPoints();
}

void Poly::setLastVertex(Point p)
{
    vertexs[vertexs.size() - 1] = p;
    calcPoints();
}

bool Poly::close()
{
    if(vertexs[vertexs.size() - 1] == vertexs[0] and vertexs.size() >= 3)
    {
        vertexs[vertexs.size() - 1] = vertexs[0];
        return true;
    }
    return false;
}

void Poly::calcPoints()
{
    points.clear();
    for(size_t i = 0; i < vertexs.size() - 1; i++)
    {
        auto v = Line(vertexs[i], vertexs[i+1]).getPoints();
        points.insert(points.end(), v.begin(), v.end());
    }
}

void Poly::draw()
{
    for(auto p: points)
        p.draw();
}

void Poly::bound(BoundingBox & box)
{
    auto minx = 10000;
    auto miny = 10000;
    auto maxx = 0;
    auto maxy = 0;
    for(auto p: vertexs)
    {
        minx = min(minx, p.getX());
        maxx = max(maxx, p.getX());
        miny = min(miny, p.getY());
        maxy = max(maxy, p.getY());
    }
    box.setLeft(minx);
    box.setRight(maxx);
    box.setTop(miny);
    box.setBottom(maxy);
}
