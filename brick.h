///////////////////////////////////////////////////////////////////////////
// File: Brick.h
// Purpose: Class definition of a representation of a Brick
///////////////////////////////////////////////////////////////////////////
#ifndef Brick_H
#define Brick_H
#include <Fl/fl_draw.H>
#include "physical.h"

class Brick : public Physical_Object
{
public:
    /////////////////////////
    // Constructors / Destructors
    /////////////////////////
    Brick();  
    Brick(int _x, int _y, int _w, int _h, int _vx, int _vy, Fl_Color _color);
    Brick(const Brick &other);
    virtual ~Brick();

    /////////////////////////
    // Accessors and mutators
    /////////////////////////
    virtual void color(Fl_Color _color);
    virtual Fl_Color color() const;

    /////////////////////////
    // Brick Methods
    /////////////////////////
    // Draw the Brick during an FLTK draw context
    virtual void draw(int xoffset, int yoffset);
    virtual void present(bool _present);
    virtual bool present();

private:
    Fl_Color _color;  //color of the Brick
    bool _present;
};
#endif
