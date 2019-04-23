//////////////////////////////////////////////////////////////////////////
// Implementation of the pong paddle
///////////////////////////////////////////////////////////////////////////
#include "paddle.h"

/////////////////////////
// Constructors / Destructors
/////////////////////////
Paddle::Paddle() : Paddle(0, 0, 100, 30, 0, 0, FL_RED)
{
    //nothing to do
}


Paddle::Paddle(int _x, int _y, int _w, int _h, int _vx, int _vy, Fl_Color _color) : Physical_Object(_x,_y,_w,_h,_vx,_vy)
{
    color(_color);
}


Paddle::Paddle(const Paddle &other) : Physical_Object(other)
{
    color(other.color());
}


Paddle::~Paddle()
{
    //nothing to do
}

/////////////////////////
// Accessors and mutators
/////////////////////////
void 
Paddle::color(Fl_Color _color)
{
    this->_color = _color;
}

Fl_Color 
Paddle::color() const
{
    return _color;
}

/////////////////////////
// Paddle Methods
/////////////////////////
// Draw the paddle during an FLTK draw context
void 
Paddle::draw(int xoffset, int yoffset)
{
    //draw the circle
    fl_color(_color);
    fl_rectf(xoffset+x(), yoffset+y(), w(), h());
}
