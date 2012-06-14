GTK=`pkg-config --cflags --libs gtkmm-3.0`


all: main.cpp
	g++ -Wall main.cpp $(GTK)
