///////////////////////////////////////////////////////////////////////////
// File: ball.h
// Purpose: Class definition of a representation of a ball
///////////////////////////////////////////////////////////////////////////
#include <Fl/fl_draw.H>
#include "physical.h"
#ifndef BALL_H
#define BALL_H

class Ball : public Physical_Object
{
public:
    /////////////////////////
    // Constructors / Destructors
    /////////////////////////
    Ball();  
    Ball(int _x, int _y, int _size, int _vx, int _vy, Fl_Color _color);
    Ball(const Ball &other);
    virtual ~Ball();

    /////////////////////////
    // Accessors and mutators
    /////////////////////////
	virtual void size(int _size);
	virtual int size() const;
    virtual void color(Fl_Color _color);
    virtual Fl_Color color() const;

    /////////////////////////
    // Ball Methods
    /////////////////////////

    // Draw the ball during an FLTK draw context
    virtual void draw(int xoffset, int yoffset);

private:
    int _size;  //size of the ball
    Fl_Color _color;  //color of the ball
};
#endif
