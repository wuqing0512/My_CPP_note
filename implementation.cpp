#include <iostream>
#include "oop2_note.cpp"

void Point::init(int ix, int iy) {  // :: resolver
    x = ix; y = iy;
}

void Point::move(int dx, int dy) {
    x += dy; y += dy;
}

void Point::print() const{  // 也需要加上const
    std::cout << x << ' ' << y << std::endl;
}