#include <iostream>
namespace sogdanov
{
  struct point_t {
    double x;
    double y;
  };
  struct rectangle_t {
    double wight;
    double height;
    point_t pos;
  };
  struct Shape {
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t p) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
  };
}
int main()
{}
