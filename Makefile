CXXFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`
TARGETS=breakout

all: $(TARGETS)
breakout: ball.o breakfield.o paddle.o physical.o brick.o breakout.o
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
clean:
	rm -f *.o $(TARGETS)
