#include "stdafx.h"
#include "GameController.h"
#include "Definitions.h"
#include <iostream>
GameController::GameController()
{
	vector<string> d;
	d.push_back("Hola");
	ManageInput(d);


}


GameController::~GameController()
{
}

bool GameController::ManageInput(const std::vector<std::string>& inputs)
{
	bool r = false;
	
	bool recognizedAction = true;
	if (inputs.size() > 0) {
		std::string action = inputs.at(0);
		std::size_t size = 1;
		if (action.compare("Take") == 0 && inputs.size()>1) {
			_player->TakeItem(inputs.at(1).c_str());
		}
		else if (action.compare("u") == 0 || action.compare("up") == 0) {
			_player->EnterRoom(Direction::UP);
		}
		else if (action.compare("l") == 0 || action.compare("left") == 0) {
			_player->EnterRoom(Direction::LEFT);

		}
		else if (action.compare("r") == 0 || action.compare("right") == 0) {
			_player->EnterRoom(Direction::RIGHT);
		}
		else if (action.compare("d") == 0 || action.compare("down") == 0) {
			_player->EnterRoom(Direction::DOWN);
		}
		else if (action.compare("Use") == 0 && inputs.size()>1) {
			_player->UseItem(inputs.at(1).c_str());
		}
		else if (action == "exit") {

		}
		else
			recognizedAction = false;

	}
	else {
		recognizedAction = false;
	}
	if (!recognizedAction) {
		cout << "Not recognized action" << endl;
	}

	return r;


}


