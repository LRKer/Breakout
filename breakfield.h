///////////////////////////////////////////////////////////////////////////
// File: breakfield.h 
// Purpose: A definition of a breakout play field class
///////////////////////////////////////////////////////////////////////////
#include <Fl/Fl.H>
#include <Fl/Fl_Widget.H>
#include "ball.h"
#include "paddle.h"
#include <vector>
#include "brick.h"
#include <FL/Fl_Text_Display.H>
#ifndef BREAKFIELD_H
#define BREAKFIELD_H
class Breakfield : public Fl_Widget
{
public:
    /////////////////////////
    // Constructor
    /////////////////////////
    Breakfield(int _x, int _y, int _w, int _h);

    /////////////////////////
    // Methods
    /////////////////////////

    //pause and unpaused
    virtual void pause();
    virtual void unpause();

    //check if it is paused
    virtual bool is_paused() const;

    //Advance to the next frame
    virtual void update();

    //Draw the widget
    virtual void draw();

    //Event handler
    virtual int handle(int event);

    //reset the ball
    virtual void reset_ball();
    virtual int pscore();
    virtual void reset_field();

private:
    Ball _ball;
    bool locked;
    bool _paused;
    Paddle _player;
    std::vector<std::vector <Brick*> > bricks;
    int score_p;
    int level=0;
    int started=0;
};
#endif
