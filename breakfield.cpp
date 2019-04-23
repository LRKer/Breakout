#include "breakfield.h"
#include <time.h>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <cmath>
#include <time.h>
using namespace std;
/////////////////////////
// Constructor
/////////////////////////
Breakfield::Breakfield(int _x, int _y, int _w, int _h) : Fl_Widget(_x,_y,_w,_h)
{
   reset_ball();
   score_p=3;
	int spacerx=0;
	int spacery=0;
   vector<Brick*> row;
	for(int i=0;i<11;i++){
		bricks.push_back(row);
		for(int j=0;j<8;j++){
			bricks[i].push_back(new Brick(0,0,50,15,0,0,FL_BLUE));
			bricks[i][j]->x(x()+60+spacerx);
			bricks[i][j]->y(y()+60+spacery);
			bricks[i][j]->present(false);
		spacerx+=60;
		}
		spacerx=0;
		spacery+=30;
	}
   //Run the game
   level=0;
   started=0;
   unpause();
}

/////////////////////////
// Methods
/////////////////////////

//pause and unpaused
void
Breakfield::reset_field()
{
	started=1;
   reset_ball();
   score_p=3;
		if(level==1){
		for(int i=0;i<11;i++){
			for(int j=0;j<8;j++){
				if(i==3){bricks[i][j]->present(true);}
				if(i==4 && j>0 && j<7){bricks[i][j]->present(true);}
				if(i==5 && j>1 && j<6){bricks[i][j]->present(true);}
				if(i==6 && j>2 && j<5){bricks[i][j]->present(true);}
				if(i==7 && j>3 && j<4){bricks[i][j]->present(true);}
			}
		}
	}
	if(level==2){
		for(int i=0;i<11;i+=2){
			for(int j=0;j<8;j+=2){
				bricks[i][j]->present(true);
			}
		}
	}
	if(level==3){
		for(int i=0;i<11;i++){
			for(int j=0;j<8;j++){
				if(i>3 && i<7)bricks[i][j]->present(true);
				if(j>2 && j<5)bricks[i][j]->present(true);
			}
		}
	}
	if(level==0){bricks[10][7]->present(true);}
	if(level>=4){
		srand(time(NULL));
		for(int i=0;i<11;i++){
			for(int j=0;j<8;j++){
				if(rand()%2==0){
					bricks[i][j]->present(true);
				}
			}
		}
	}
					

   //Run the game
}
void 
Breakfield::pause()
{
    _paused = true;
}

void 
Breakfield::unpause()
{
    _paused = false;
}

//check if it is paused
bool 
Breakfield::is_paused() const
{
    return _paused;
}



//Advance to the next frame
void 
Breakfield::update()
{
    if(is_paused()) {
        return;
    }
        //try the move, check for paddle collisions
    Ball trial = _ball;
        if(locked){
		_ball.x(_player.x()+_player.w()/2-_ball.size()/2);
		_ball.y(_player.y()-_ball.size());
	}
	else{
    trial.movex();
    for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			if(bricks[i][j]->present()){
				if(trial.collides(*bricks[i][j])){
					_ball.vx(-_ball.vx());
					bricks[i][j]->present(false);
				}
			}
		}
	}
    trial.movey();
    for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			if(bricks[i][j]->present()){
				if(trial.collides(*bricks[i][j])){
					_ball.vy(-_ball.vy());
					bricks[i][j]->present(false);
				}
			}
		}
	}
//fix this !!!!!!!!!!!!!!!!!
	if(trial.collides(_player)){
		
		if(_ball.x()> _player.x()+_player.w()*2/3){
			if(abs(_ball.vy())<9){
				_ball.vy(-_ball.vy()-1);
			}
			else{
				_ball.vy(-_ball.vy());
			}
			if(_ball.vx()<8){
				_ball.vx(_ball.vx()+1);
			}
		}
		else if (_ball.x()< _player.x()+_player.w()*1/3){
			if(abs(_ball.vy())<9){
				_ball.vy(-_ball.vy()-1);
			}
			else{
				_ball.vy(-_ball.vy());
			}
			if(_ball.vx()>-8){
				_ball.vx(_ball.vx()-1);
			}
		}
		else{
			if(abs(_ball.vy())<9){
				_ball.vy(-_ball.vy()-1);
			}
			else{
				_ball.vy(-_ball.vy());
			}
		}
		if(_player.vx()<0 and _ball.vx()>0)
		{
			if(_ball.vx()<8){
				_ball.vx(_ball.vx()+2);
			}
		}
		if(_player.vx()>0 and _ball.vx()<0)
		{
			if(_ball.vx()>-8){
				_ball.vx(_ball.vx()-2);
			}
		}
		if(_player.vx()>0 and _ball.vx()>0)
		{
			if(_ball.vx()>-8){
				_ball.vx(_ball.vx()-2);
			}
		}
		if(_player.vx()<0 and _ball.vx()<0)
		{
			if(_ball.vx()<8){
				_ball.vx(_ball.vx()+2);
			}
		}
		
	}
	int count=0;
    for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			if(bricks[i][j]->present()){
				count++;
			}
		}
	}
	if(count==0&&started==1){level++;}
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
    _ball.movex();
    _ball.movey();
    _player.movex();
    
}

//Draw the widget
void 
Breakfield::draw()
{

    fl_color(FL_BLACK);
    fl_rectf(x(), y(), w(), h());
 	for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			if(bricks[i][j]->present()){
				bricks[i][j]->draw(x(),y());
			}
		}
	}

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
    int count=0;
    for(int i=0;i<11;i++){
		for(int j=0;j<8;j++){
			if(bricks[i][j]->present()){
				count++;
			}
		}
	}
	if(started==0){
	fl_font(FL_SCREEN_BOLD,30);
	fl_color(FL_GREEN);
	fl_draw("Press Down to Start", 50, 50);
	}
	else if(count==0 && started==1){
		pause();
		fl_font(FL_SCREEN_BOLD,30);
		fl_color(FL_GREEN);
		fl_draw("Victory!", 50, 50);
	}
	
    else if(score_p==0 && started==1){
		pause();
		fl_font(FL_SCREEN_BOLD,30);
		fl_color(FL_GREEN);
		fl_draw("Game Over", 50, 50);
	}
	

	
}


//Event handler
int
Breakfield::handle(int event)
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
            _player.vx(-12);
            break;
        case FL_Right:
            _player.vx(12);
            break;
        case FL_Up:
			break;
        }
        return 1;
        break;
    case FL_KEYUP:
        switch(Fl::event_key()) {
        case FL_Down:
			reset_field();
			unpause();
        case FL_Right:
        case FL_Left:
            _player.vx(0);
            break;
        case FL_Up:
			if(locked){
			locked=false;
			_ball.vx(_player.vx());
			_ball.vy(-5);
			}
			break;
        }
        return 1;
        break;    
    }

    return Fl_Widget::handle(event);
}

//reset the ball
void 
Breakfield::reset_ball()
{
	locked=true;
   //position the ball
   _player.h(_ball.size());
   _player.w(w()/5);
   
   _player.x(w()/2-_player.w()/2);
   _player.y(h()-_player.h()-5);
   _ball.size((int)(w() * .02 + 1));
   _ball.x(_player.x()+_player.w()/2-_ball.size()/2);
   _ball.y(_player.y() - _ball.size());
   _ball.vx(0);
	 _ball.vy(0);
  //   _ball.vy(rand()%11-5);
      //position the paddles
}
int
Breakfield::pscore()
{
	return score_p;
}
