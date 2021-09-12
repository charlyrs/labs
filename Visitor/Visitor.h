

#ifndef ITERATOR_VISITOR_H
#define ITERATOR_VISITOR_H
#include <iostream>
class Vector;

class Circle;

class Square;

class Visitor {
public:
    virtual void visit(Vector &vector) = 0;

    virtual void visit(Circle &circle) = 0;

    virtual void visit(Square &square) = 0;
};

class Shape {
public:
    virtual void accept(Visitor &v) = 0;
    virtual void to_console() = 0;
};

class Vector : Shape {
public:
    double x;
    double y;

    Vector(double x_coordinate, double y_coordinate) {
        x = x_coordinate;
        y = y_coordinate;
    }
    void accept(Visitor &v) override {
        v.visit(*this);
    }
    void to_console() override {
        std::cout << "Vector (" << x << " ," << y << ')';
    }
};

class Circle : Shape {
public:
    double x_center;
    double y_center;
    double radius;

    Circle(double x_center_coordinate, double y_center_coordinate, double radius) {
        x_center = x_center_coordinate;
        y_center = y_center_coordinate;
        this->radius = radius;
    }
    void accept(Visitor &v) override {
        v.visit(*this);
    }
    void to_console() override{
        std::cout << "Circle center (" << x_center << " ," << y_center << "); Radius " << radius;
    }
};

class Square : Shape {
public:
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
    void accept(Visitor &v) override {
        v.visit(*this);
    }
    void to_console() override {
        std::cout << "Square: bottom left corner (" << x_bottom_left << " ," << y_bottom_left
        << "); top right corner (" << x_top_right << " ," << y_top_right << ')';
    }
};

class ParallelMover : public Visitor {
    double move_by_x;
    double move_by_y;
public:
    ParallelMover(double move_by_x, double move_by_y){
        this->move_by_y = move_by_y;
        this->move_by_x = move_by_x;
    }
    void visit(Vector &vector) override {
        vector.x += move_by_x;
        vector.y += move_by_y;
    }
    void visit(Circle &circle) override {
        circle.x_center += move_by_x;
        circle.y_center += move_by_y;
    }
    void visit(Square &square) override {
        square.x_top_right += move_by_x;
        square.x_bottom_left += move_by_x;
        square.y_top_right += move_by_y;
        square.y_bottom_left += move_by_y;
    }
};
class Resizer : public Visitor {
public:
    double value;
    Resizer(double value_to_resize){
        value = value_to_resize;
    }
    void visit(Vector &vector) override {
        vector.x *= value;
        vector.y *= value;
    }
    void visit(Circle &circle) override {
        circle.radius *= value;
    }
    void visit(Square &square) override {
        if(square.x_top_right < 0 || square.y_top_right < 0){
            square.x_bottom_left *= value;
            square.y_bottom_left *= value;
        } else{
            square.x_top_right *= value;
            square.y_top_right *= value;
        }
    }

};
enum Axis{
    Ox = 1, Oy
};
class Mirrorer : public Visitor{
    Axis axis;
public:
    Mirrorer(Axis axis){
        this->axis = axis;
    }
    void visit(Vector &vector) override {
        switch (axis) {
            case 1:{
                vector.y = -vector.y;
                break;
            }
            case 2:{
                vector.x = -vector.x;
            }
        }
    }
    void visit(Circle &circle) override {
        switch (axis) {
            case 1:{
                circle.y_center = -circle.y_center;
                break;
            }
            case 2:{
                circle.x_center = -circle.x_center;
            }
        }
    }
    void visit(Square &square) override {
        switch (axis) {
            case 1:{
                square.y_top_right = -square.y_top_right;
                square.y_bottom_left = -square.y_bottom_left;
                break;
            }
            case 2:{
                square.x_top_right = -square.x_top_right;
                square.x_bottom_left = -square.x_bottom_left;
            }
        }
    }
};

#endif //ITERATOR_VISITOR_H
