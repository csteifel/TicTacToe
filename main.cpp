#include "main.h"


tictactoe::tictactoe(){
	for(int i = 0; i < 9; i++){
		buttonHolder.push_back(new Gtk::Button());
	}
	
	for(int i = 0; i < 3; i++){
		boxes.push_back(new Gtk::HBox);
	}

	//Set up frames
	for(int i = 0; i < 3; i++){
		for(int x = 0; x < 3; x++){
			boxes[i]->add(*buttonHolder[i*3 + x]);
			buttonHolder[i*3 + x]->set_size_request(100, 40);

			buttonHolder[i*3 + x]->signal_clicked().connect(sigc::bind<Gtk::Button*>(sigc::mem_fun(*this, &tictactoe::buttonPressed), buttonHolder[i*3 + x]));

			buttonHolder[i*3 + x]->show();
		}
		boxes[i]->show();
		vertical.add(*boxes[i]);
	}

	this->turn = 0;
	this->numOff = 0;
	this->winner = 0;


	this->add(vertical);

	label.set_label("X's turn");
	vertical.add(label);
	label.show();
	vertical.show();
}

void tictactoe::buttonPressed(Gtk::Button * button){
	if(winner == 1)
		return;
	if(turn == 0){
		button->set_label("X");
		button->set_sensitive(false);
		label.set_label("O's turn");
		turn = 1;
	}else{
		turn = 0;
		button->set_label("O");
		button->set_sensitive(false);
		label.set_label("X's turn");
	}

	//Check Diagonals
	if(buttonHolder[0]->get_label() != "" && buttonHolder[0]->get_label() == buttonHolder[4]->get_label() && buttonHolder[4]->get_label() == buttonHolder[8]->get_label()){
		label.set_label(buttonHolder[0]->get_label() + " wins");	
			winner = 1;
	}

	if(buttonHolder[2]->get_label() != "" && buttonHolder[2]->get_label() == buttonHolder[4]->get_label() && buttonHolder[6]->get_label() == buttonHolder[8]->get_label()){
		label.set_label(buttonHolder[2]->get_label() + " wins");	
			winner = 1;
	}


	//Check horizontals and verticals
	for(int i = 0; i < 3; i++){
		if(buttonHolder[i*3]->get_label() != "" && buttonHolder[i*3 + 0]->get_label() == buttonHolder[i*3 + 1]->get_label() && buttonHolder[i*3 + 1]->get_label() == buttonHolder[i*3 + 2]->get_label() ){
			label.set_label(buttonHolder[i*3 + 0]->get_label() + " wins");
			winner = 1;
		}

		if(buttonHolder[i]->get_label() != "" && buttonHolder[i]->get_label() == buttonHolder[i + 3]->get_label() && buttonHolder[i+ 3]->get_label() == buttonHolder[i+ 6]->get_label()){
			label.set_label(buttonHolder[i]->get_label() + " wins");
			winner = 1;
		}
	}

	numOff ++;

	if(numOff == 9){
		label.set_label("No one wins");
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

	Glib::RefPtr<Gtk::Application> app =  Gtk::Application::create(argc, argv, "Tic.Tac.Toe");
	tictactoe a;
	return app->run(a);
}
