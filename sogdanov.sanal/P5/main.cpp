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
    void move(const point_t p) override;
    void scale(double k) override;
  private:
    double d_;
    point_t pos_;
  };
  struct Diamond: Shape {
    Diamond(double diagx, double diagy, point_t p);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(const point_t p) override;
    void scale(double k) override;
  private:
    double diagx_;
    double diagy_;
    point_t pos_;
  };
}
int main()
{}
sogdanov::Rectangle::Rectangle(double width, double height, point_t p):
  sogdanov::Shape(), width(width_), height(height_), p(pos_)
{}
double sogdanov::Rectangle::getArea() const
{
  return width_ * height_;
}
sogdanov::rectangle_t sogdanov::Rectangle::getFrameRect() const override
{
  return sogdanov::rectangle_t{width_, height_, pos_};
}
void sogdanov::Rectangle::move(const point_t p) override
{
  pos_ = p;
}
void sogdanov::Rectangle::move(double dx, double dy) override
{
  pos_.x += dx;
  pos_.y += dy;
}
void sogdanov::Rectangle::scale(double k) override
{
  width_ *= k;
  height_ *= k;
}
sogdanov::Xquare::Xquare(double d, point_t p):
  d_(d), pos_(p)
{}
double getArea() const override
{
  return (d_ * d_) / 2.0;
}
sogdanov::rectangle_t sogdanov::Xquare::getFrameRect() const override
{
  return sogdanov::rectangle_t{d_, d_, pos_};
}
void sogdanov::Xquare::move(double dx, double dy) override
{
  pos_.x += dx;
  pos_.y += dy;
}
void sogdanov::Xquare::move(point_t p) override
{
  pos_ = p;
}
void sogdanov::Xquare::scale(double k) override
{
  d_ *= k;
}
sogdanov::Diamond::Diamond(double diagx, double diagy, point_t p):
  diagx_(diagx), diagy_(diagy), pos_(p);
{}
double sogdanov::Diamond::getArea() const override
{
  return (diagx_ * diagy_) / 2.0;
}
sogdanov::rectangle_t sogdanov::Diamond::getFrameRect() const override
{
  return sogdanov::rectangle_t{diagx_, diagy_, pos_};
}
void sogdanov::Diamond::move(double dx, double dy) override
{
  pos_.x += dx;
  pos_.y += dy;
}
void sogdanov::Diamond::move(const point_t p) override
{
  pos_ = p;
}
void sogdanov::Diamond::scale(double k) override
{
  diagx *= k;
  diagy *= k;
}
