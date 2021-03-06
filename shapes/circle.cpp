#include "circle.h"
#include "line.h"
#include <cmath>

Circle::Circle(Point center, int radius)
{
    this->center = center;
    this->radius = radius;
    _type = Mode::MODE_DRAW_CIRCLE;
    calcPoints();
}

void Circle::setRadius(int radius)
{
    this->radius = radius;
    refill();
    calcPoints();
}

void Circle::draw()
{
    for(auto p: points)
        p.draw();
    for(auto p: fillPoints)
        p.draw();
}

void Circle::drawControlPoints()
{
    center.drawCircle(255, 215, 0);
    auto p0 = center;
    auto p1 = Point(center.getX() + radius, center.getY());
    Line(p0, p1, true, BLUE).draw();
}

void Circle::plot(int dx, int dy)
{
    int d1[] = {1, -1, 1, -1, 1, -1, 1, -1};
    int d2[] = {1, 1, -1, -1, 1, 1, -1, -1};
    int i = 0;
    for(i = 0; i < 4; i++)
        points.push_back(Point(center.getX() + d1[i] * dx, center.getY() + d2[i] * dy));
    for(; i < 8; i++)
        points.push_back(Point(center.getX() + d1[i] * dy, center.getY() + d2[i] * dx));
}

void Circle::calcPoints()
{
    points.clear();
    auto x = 0;
    auto y = radius;
    auto p = 1 - radius;
    plot(x, y);
    while (x < y) {
        x++;
        if(p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        plot(x, y);
    }
}

bool Circle::selected(Point p)
{
    return abs(p - center - radius) <= 5;
}

void Circle::bound(BoundingBox & box)
{
    box.setLeft(center.getX() - radius);
    box.setRight(center.getX() + radius);
    box.setTop(center.getY() - radius);
    box.setBottom(center.getY() + radius);
}

Point Circle::getCenter()
{
    return this->center;
}

Point* Circle::onCircle(Point p)
{
    unsigned min = 0;
    for(size_t i = 1; i < points.size(); i++)
    {
        auto d1 = p - points[i];
        auto d2 = p - points[min];
        if(d1 < d2)
            min = i;
    }
    if(p == points[min])
        return &points[min];
    return nullptr;
}

void Circle::translate(int dx, int dy)
{
    center.translate(dx, dy);
    refill();
}

void Circle::update()
{
    calcPoints();
}

bool Circle::spectialPoint(Point p)
{
    return selected(p);
}

void Circle::scale(double s)
{
    radius *= s;
    refill();
}

void Circle::rotate(double)
{
    //do nothing
}

void Circle::fill(Color color)
{
    fColor.set(color.r, color.g, color.b);
    int cx = center.getX();
    int cy = center.getY();
    int rr = radius * radius;
    for(int y = cy; y <= cy + radius - 1; y++)
    {
        int dy = y - cy;
        int dx = sqrt(rr - dy * dy);
        int x1 = cx - dx;
        int x2 = cx + dx;
        for(int x = x1 + 1; x <= x2 - 1; x++)
        {
            auto p = Point(x, y);
            p.setColor(color);
            fillPoints.push_back(p);
            auto p1 = Point(x, 2 * cy - y);
            p1.setColor(color);
            fillPoints.push_back(p1);
        }
    }
}
