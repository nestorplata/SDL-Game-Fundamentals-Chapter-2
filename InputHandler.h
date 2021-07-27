#pragma once

#include "SDL.h"
#include"Game.h"
#include"Vector2D.h"

#include <vector>
#include<iostream>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public: 
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();

	void initialiseJoysticks();

	bool joysticksInitialised() { return m_bJoysticksInitialised; }
	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}
	bool getMouseButtonStates(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}

	int xvalue(int joy, int stick);
	int yvalue(int joy, int stick);

	bool isKeyDown(SDL_Scancode key);

	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	//private functions to handle different event types
	
	//handle keyboard events
	void onKeyDown();
	void onKeyUp();

	//handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	//handle joysticks events
	void onJoystckAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);
private:
	InputHandler();
	~InputHandler() {};

	static InputHandler* s_pInstance;

	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<std::vector<bool>> m_buttonStates;
	std::vector<bool> m_mouseButtonStates;

	bool m_bJoysticksInitialised;
	//bool mouseused;
	const int m_joystickDeadZone = 10000;

	Vector2D* m_mousePosition;
	const Uint8* m_keystates;
};

typedef InputHandler TheInputHandler;