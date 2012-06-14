#include "main.h"


tictactoe::tictactoe(){
	for(int i = 0; i < 9; i++){
		buttonHolder.push_back(new Gtk::Button);
	}
	
	for(int i = 0; i < 3; i++){
		boxes.push_back(new Gtk::HBox);
	}

	//Set up frames
	for(int i = 0; i < 3; i++){
		for(int x = 0; x < 3; x++){
			boxes[i]->add(*buttonHolder[i*3 + x]);
		}

		vertical.add(*boxes[i]);
	}

	
}


tictactoe::~tictactoe(){
	for(size_t i = 0; i < buttonHolder.size(); i++){
		delete buttonHolder[i];
	}

	for(size_t i = 0; i < boxes.size(); i++){
		delete boxes[i];
	}
}

int main(int argc, char * argv[]){

	Glib::RefPtr<Gtk::Application> app =  new Gtk::Application(argc, argv, "TicTacToe");
	tictactoe a;
	return app->run(a);
}
