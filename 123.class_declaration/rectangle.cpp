#include "rectangle.h"
    
    
using namespace std;


Rectangle::Rectangle(int width, int height) : width_(width), height_(height)
{
}

int Rectangle::GetArea() const {
    return width_ * height_;
}
int Rectangle::GetPerimeter() const {
    return 2 * (width_ + height_);
}
int Rectangle::GetWidth() const {
    return width_; 
}
int Rectangle::GetHeight() const {
    return height_;
}