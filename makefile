OBJS = fixPictures_main.o dirWalker.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall $(DEBUG)
BOOST_LIBS = -lboost_system -lboost_filesystem -lboost_regex -lboost_program_options

program : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(BOOST_LIBS) -o program

fixPictures_main.o : fixPictures_main.cpp dirWalker.hpp
	$(CC) $(CFLAGS) fixPictures_main.cpp

dirWalker.o : dirWalker.hpp dirWalker.cpp
	$(CC) $(CFLAGS) dirWalker.cpp

clean:
	\rm *.o *~ program

tar:
	tar cfv fixPics.tar fixPictures_main.cpp dirWalker.cpp dirWalker.hpp

