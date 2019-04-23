#include "field.h"
#include <time.h>
#include <FL/Fl_Text_Display.H>
#include <string>
using namespace std;
/////////////////////////
// Constructor
/////////////////////////
Field::Field(int _x, int _y, int _w, int _h) : Fl_Widget(_x,_y,_w,_h)
{
   reset_ball();
   score_p=3;

   //Run the game
   unpause();
}

/////////////////////////
// Methods
/////////////////////////

//pause and unpaused
void 
Field::pause()
{
    _paused = true;
}

void 
Field::unpause()
{
    _paused = false;
}

//check if it is paused
bool 
Field::is_paused() const
{
    return _paused;
}


//Advance to the next frame
void 
Field::update()
{
    if(is_paused()) {
        return;
    }
        //try the move, check for paddle collisions
    Ball trial = _ball;
    trial.move();
	if(trial.collides(_player)){	
		if(_ball.x()> _player.x()+_player.h()*2/3){
			_ball.vx(-_ball.vx()+2);
			_ball.vy(_ball.vy()+1);
		}
		else if (_ball.x()< _player.x()+_player.h()*1/3){
			_ball.vx(-_ball.vx()+2);
			_ball.vy(_ball.vy()-1);
		}
		else{
			_ball.vx(-_ball.vx()+2);
		}
		
		
		if(_player.vy()<0 and _ball.vy()>0)
		{
			_ball.vy(_ball.vy()+1);
		}
		if(_player.vy()>0 and _ball.vy()<0)
		{
			_ball.vy(_ball.vy()-1);
		}
		if(_player.vy()>0 and _ball.vy()>0)
		{
			_ball.vy(_ball.vy()-1);
		}
		if(_player.vy()<0 and _ball.vy()<0)
		{
			_ball.vy(_ball.vy()+1);
		}
		
	}
	
    //check for ball collisions
    if(_ball.vx() > 0 and _ball.x() + _ball.vx() + _ball.size() >= w()) {
        _ball.vx(-_ball.vx()-1);
    } else if(_ball.x() + _ball.vx() <= 0) {
        _ball.vx(-_ball.vx()+1);
    }
    if(_ball.vy() > 0 and _ball.y() + _ball.vy() + _ball.size() >= h()) {
        reset_ball();
        score_p--; //bounce
    } else if(_ball.y() + _ball.vy() <= 0) {
        _ball.vy(-_ball.vy()+1); //bounce
    }
    _ball.move();
        //the computer is a dirty cheat!  Improve upon this!
    _player.move();
}

//Draw the widget
void 
Field::draw()
{
    fl_color(FL_BLACK);
    fl_rectf(x(), y(), w(), h());
 
    _ball.draw(x(), y());
    _player.draw(x(), y());
    
    fl_font(FL_SCREEN_BOLD,18);
    fl_color(FL_RED);
	char temp[10];
	itoa(this->pscore(),temp,10);
	string ps=temp;
	char temp2[10];
	string total="SCORE: "+ps;
	char* final=new char [total.length()+1];
	strcpy(final,total.c_str());
    fl_draw(final,20,20);
    //draw text

	
}


//Event handler
int
Field::handle(int event)
{
    switch(event) {
	case FL_FOCUS:
    case FL_UNFOCUS:
        return 1;
        break;
    case FL_RELEASE:
        if(is_paused()) {
            unpause();
        } else {
            pause();
        }
        return 1;
        break;
    case FL_KEYBOARD:
        switch(Fl::event_key()) {
        case FL_Left:
            _player.vx(-10);
            break;
        case FL_Right:
            _player.vx(10);
            break;
        }
        return 1;
        break;
    case FL_KEYUP:
        switch(Fl::event_key()) {
        case FL_Right:
        case FL_Left:
            _player.vx(0);
            break;
        }
        return 1;
        break;    
    }

    return Fl_Widget::handle(event);
}

//reset the ball
void 
Field::reset_ball()
{
   //position the ball
   _ball.size((int)(w() * .02 + 1));
   _ball.x(w()/2 - _ball.size()/2);
   _ball.y(h()/2 - _ball.size()/2);
   do{
   _ball.vx(rand()%11-5);
	 _ball.vy(-5);
  //   _ball.vy(rand()%11-5);
	} while(_ball.vy()< 1);
      //position the paddles
   _player.h(_ball.size());
   _player.w(w()/5);
   _player.x(w()/2-_player.w()/2);
   _player.y(h()-_player.h()-5);
}
int
Field::pscore()
{
	return score_p;
}
