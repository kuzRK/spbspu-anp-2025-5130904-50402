#include <iostream>
namespace sogdanov
{
  struct point_t {
    double x;
    double y;
  };
  struct rectangle_t {
    double widht;
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
  struct Rectangle: Shape {
    Rectangle(double widht, double height, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t p) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    double width_;
    double height;
    poin_t pos_;
  };
  struct Xquare: Shape {
    Xquare(double d, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t p) override;
    void scale(double k) override;
  private:
    double d_;
    point_t pos_;
  };
  struct Diamond: Shape {
    Diamond(double dx, double dy, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t p) override;
    void scale(double k) override;
  private:
    double dx_;
    double dy_;
    point_t pos_;
  };
}
int main()
{}
