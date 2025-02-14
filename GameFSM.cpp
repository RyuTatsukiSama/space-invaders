#include "GameFSM.h"
#include "GameState.h"

GameFSM::GameFSM()
{
	add(State::GAME, new GameState());
	current_state_ = states_[(int) State::GAME];
}

GameFSM::~GameFSM()
{
	for (int i = 0; i < (int) State::STATE_COUNT; ++i)
	{
		delete states_[i];
	}
}