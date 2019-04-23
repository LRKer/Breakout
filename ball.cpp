///////////////////////////////////////////////////////////////////////////
// Implementation of the pong ball
///////////////////////////////////////////////////////////////////////////

#include "ball.h"
/////////////////////////
// Constructors / Destructors
/////////////////////////
Ball::Ball() : Ball(0, 0, 10, 0, 0, FL_RED)
{
    //nothing to do
}


Ball::Ball(int _x, int _y, int _size, int _vx, int _vy, Fl_Color _color) : Physical_Object(_x,_y,_size,_size,_vx,_vy)
{
	size(_size);
    color(_color);
}


Ball::Ball(const Ball &other) : Physical_Object(other)
{
    size(other.size());

    color(other.color());
}


Ball::~Ball()
{
    //nothing to do
}

/////////////////////////
// Accessors and mutators
/////////////////////////
void 
Ball::size(int _size)
{
    this->_size = _size;
}


int 
Ball::size() const
{
    return _size;
}

void 
Ball::color(Fl_Color _color)
{
    this->_color = _color;
}

Fl_Color 
Ball::color() const
{
    return _color;
}

/////////////////////////
// Ball Methods
/////////////////////////


// Draw the ball during an FLTK draw context
void 
Ball::draw(int xoffset, int yoffset)
{
    //draw the circle
    fl_color(_color);
    fl_pie(xoffset + x(), yoffset + y(), size(), size(), 0, 360);
}
