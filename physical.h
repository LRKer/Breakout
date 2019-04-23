///////////////////////////////////////////////////////////////////////////
// File: physical.h
// Purpose: Class definition of a physical object
///////////////////////////////////////////////////////////////////////////
#include <Fl/fl_draw.H>
#ifndef PHYSICAL_H
#define PHYSICAL_H
class Physical_Object
{
public:
    /////////////////////////
    // Constructors
    /////////////////////////
    Physical_Object(int _x, int _y, int _w, int _h, int _vx, int _vy);
    Physical_Object(const Physical_Object &other);


    /////////////////////////
    // Accessor and Mutators
    /////////////////////////
    virtual void x(int _x);
    virtual int x() const;

    virtual void y(int _y);
    virtual int y() const;

    virtual void w(int _w);
    virtual int w() const;

    virtual void h(int _h);
    virtual int h() const;

    virtual void vx(int _vx);
    virtual int vx() const;

    virtual void vy(int _vy);
    virtual int vy() const;

    /////////////////////////
    // Physical Methods
    /////////////////////////
    // Update the object for the next frame
    virtual void movex();
    virtual void movey();

    // Draw the object during an FLTK draw context (Pure Virtual)
    virtual void draw(int xoffset, int yoffset)=0;

    // Check for collisions with another physical object
    virtual bool collides(const Physical_Object &other);

private:
    int _x;  //x coordinate of the physical object
    int _y;  //y coordinate of the physical object
    int _w;  //width of the physical object
    int _h; //height of the physical object
    int _vx; //x velocity
    int _vy; //y velocity
};

#endif
