
#include "physical.h"
/////////////////////////
// Constructors
/////////////////////////
Physical_Object::Physical_Object(int _x, int _y, 
                                 int _w, int _h, 
                                 int _vx, int _vy)
{
   //set all the fields using mutators
   x(_x);
   y(_y);
   w(_w);
   h(_h);
   vx(_vx);
   vy(_vy);
}

Physical_Object::Physical_Object(const Physical_Object &other)
{
   //set all the fields using mutators
   x(other.x());
   y(other.y());
   w(other.w());
   h(other.h());
   vx(other.vx());
   vy(other.vy());
}
/////////////////////////
// Accessor and Mutators
/////////////////////////
void
Physical_Object::x(int _x)
{
    this->_x=_x;
}



int
Physical_Object::x() const 
{
    return this->_x;
}



void
Physical_Object::y(int _y)
{
    this->_y=_y;
}



int
Physical_Object::y() const 
{
    return this->_y;
}



void
Physical_Object::w(int _w)
{
    this->_w=_w;
}



int
Physical_Object::w() const 
{
    return this->_w;
}



void
Physical_Object::h(int _h)
{
    this->_h=_h;
}



int
Physical_Object::h() const 
{
    return this->_h;
}



void
Physical_Object::vx(int _vx)
{
    this->_vx=_vx;
}



int
Physical_Object::vx() const 
{
    return this->_vx;
}



void
Physical_Object::vy(int _vy)
{
    this->_vy=_vy;
}



int
Physical_Object::vy() const 
{
    return this->_vy;
}

/////////////////////////
// Physical Methods
/////////////////////////

// Update the object for the next frame
void 
Physical_Object::movex()
{
    //move the object by vx and vy
    x(x()+vx());
}
void
Physical_Object::movey()
{
	y(y()+vy());
}
// Check for collisions with another physical object
bool 
Physical_Object::collides(const Physical_Object &other)
{
    //behold the glories of axis aligned bounding box collision
    //detection!
    return x() < other.x() + other.w()&&
           x() + w() > other.x() &&
           y() < other.y() + other.h() &&
           y() + h() > other.y();
}
