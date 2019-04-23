#include <Fl/Fl.H>
#include <Fl/Fl_Double_Window.H>
#include "fan.h"

class Tunnel_Window : public Fl_Double_Window
{
public:
    Tunnel_Window(int _w, int _h) : Fl_Double_Window(_w, _h, "Tunnel")
    {
       play_field = new Field(0, 0, _w, _h);
       end();
    }

    virtual void draw()
    {
        Fl_Double_Window::draw();
		
        play_field->update();
        play_field->draw();
    }

private:
    Field *play_field;  //pong playing field
};


//called to update each frame
void frame(void *window)
{
    ((Pong_Window*)window)->redraw();
    Fl::repeat_timeout(1.0f / 24, frame, window);
}


int main(int argc, char **argv)
{
    Pong_Window *window = new Pong_Window(640, 480);

    window->show(argc, argv);
    Fl::add_timeout(1.0f / 24, frame, window);
    Fl::run();
}
