#pragma once

#include"GameState.h"

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const { return s_playID; }

private:
	static const std::string s_playID;
};