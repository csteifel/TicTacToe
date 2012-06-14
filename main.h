#include <gtkmm.h>
#include <vector>

class tictactoe : public Gtk::Window {
	public:
		tictactoe();
		virtual ~tictactoe();
	private:

		int turn, numOff, winner;
		void buttonPressed(Gtk::Button*);
		std::vector<Gtk::Button *> buttonHolder;
		std::vector<Gtk::HBox *> boxes;
		Gtk::VBox vertical;
		Gtk::Label label;
};
