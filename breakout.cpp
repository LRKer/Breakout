#include <Fl/Fl.H>
#include <Fl/Fl_Double_Window.H>
#include "breakfield.h"
class Breakout_Window : public Fl_Double_Window
{
public:
    Breakout_Window(int _w, int _h) : Fl_Double_Window(_w, _h, "Breakout")
    {
       play_breakfield = new Breakfield(0, 0, _w, _h);
       end();
    }

    virtual void draw()
    {
        Fl_Double_Window::draw();
		
        play_breakfield->update();
        play_breakfield->draw();
    }

private:
    Breakfield *play_breakfield;  //breakout playing field
};


//called to update each frame
void frame(void *window)
{
    ((Breakout_Window*)window)->redraw();
    Fl::repeat_timeout(1.0f / 24, frame, window);
}


int main(int argc, char **argv)
{
    Breakout_Window *window = new Breakout_Window(600, 500);

    window->show(argc, argv);
    Fl::add_timeout(1.0f / 24, frame, window);
    Fl::run();
}
