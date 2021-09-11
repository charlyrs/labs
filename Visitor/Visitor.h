
#ifndef ITERATOR_VISITOR_H
#define ITERATOR_VISITOR_H

class Vector;

class Circle;

class Square;

class Visitor {
public:
    virtual void visit(const Vector &vector) = 0;

    virtual void visit(const Circle &circle) = 0;

    virtual void visit(const Square &square) = 0;
};

class Shape {
public:
    virtual void accept(const Visitor &v) = 0;
};

class Vector : Shape {
    double x;
    double y;
public:
    Vector(double x_coordinate, double y_coordinate) {
        x = x_coordinate;
        y = y_coordinate;
    }
};

class Circle : Shape {
    double x_center;
    double y_center;
    double radius;

    Circle(double x_center_coordinate, double y_center_coordinate, double radius) {
        x_center = x_center_coordinate;
        y_center = y_center_coordinate;
        this->radius = radius;
    }
};

class Square : Shape {
    double x_bottom_left;
    double y_bottom_left;
    double x_top_right;
    double y_top_right;

    Square(double x_bottom_left, double y_bottom_left, double x_top_right, double y_top_right) {
        this->x_bottom_left = x_bottom_left;
        this->y_bottom_left = y_bottom_left;
        this->x_top_right = x_top_right;
        this->y_top_right = y_top_right;
    }
};

#endif //ITERATOR_VISITOR_H
