#ifndef __GAMECONTROLLER__
#define __GAMECONTROLLER__
#include <string>
#include <vector>
#include "Player.h"
class GameController
{
public:
	
	GameController();
	~GameController();


	bool ManageInput(const std::vector<std::string>& inputs);
private:
	Player *_player;
	

};
#endif
