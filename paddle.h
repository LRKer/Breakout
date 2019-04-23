///////////////////////////////////////////////////////////////////////////
// File: paddle.h
// Purpose: Class definition of a representation of a paddle
///////////////////////////////////////////////////////////////////////////
#include <Fl/fl_draw.H>
#include "physical.h"
#ifndef PADDLE_H
#define PADDLE_H
class Paddle : public Physical_Object
{
public:
    /////////////////////////
    // Constructors / Destructors
    /////////////////////////
    Paddle();  
    Paddle(int _x, int _y, int _w, int _h, int _vx, int _vy, Fl_Color _color);
    Paddle(const Paddle &other);
    virtual ~Paddle();

    /////////////////////////
    // Accessors and mutators
    /////////////////////////
    virtual void color(Fl_Color _color);
    virtual Fl_Color color() const;

    /////////////////////////
    // Paddle Methods
    /////////////////////////
    // Draw the paddle during an FLTK draw context
    virtual void draw(int xoffset, int yoffset);

private:
    Fl_Color _color;  //color of the paddle
};
#endif
