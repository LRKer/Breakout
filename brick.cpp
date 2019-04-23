//////////////////////////////////////////////////////////////////////////
// Implementation of the pong Brick
///////////////////////////////////////////////////////////////////////////
#include "brick.h"

/////////////////////////
// Constructors / Destructors
/////////////////////////
Brick::Brick() : Brick(0, 0, 100, 30, 0, 0, FL_BLUE)
{
    //nothing to do
}


Brick::Brick(int _x, int _y, int _w, int _h, int _vx, int _vy, Fl_Color _color) : Physical_Object(_x,_y,_w,_h,_vx,_vy)
{
    color(_color);
    _present=true;
}


Brick::Brick(const Brick &other) : Physical_Object(other)
{
    color(other.color());
}


Brick::~Brick()
{
    //nothing to do
}

/////////////////////////
// Accessors and mutators
/////////////////////////
void 
Brick::color(Fl_Color _color)
{
    this->_color = _color;
}

Fl_Color 
Brick::color() const
{
    return _color;
}

/////////////////////////
// Brick Methods
/////////////////////////
// Draw the Brick during an FLTK draw context
/*void
Brick::draw()
{
	fl_color(_color);
	fl_rectf(0,0,0,0);
}*/
void 
Brick::draw(int xoffset, int yoffset)
{
    //draw the circle
    fl_color(_color);
    fl_rectf(xoffset+x(), yoffset+y(), w(), h());
}
void 
Brick::present(bool _present)
{
    this->_present = _present;
}


bool 
Brick::present()
{
    return this->_present;
}
