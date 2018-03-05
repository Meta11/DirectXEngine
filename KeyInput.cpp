#include <Windows.h>
#include "KeyInput.h"
#include "IKeyMapper.h"

KeyInput KeyInput::instance;

bool KeyInput::initialize(IKeyMapper* keyMapper, int maxActionValue)
{
	if (keyMapper == nullptr || maxActionValue < 0)
		return false;
	this->keyMapper = keyMapper;
	this->maxActionValue = maxActionValue;
	return true;
}

bool KeyInput::shutdown()
{
	return true;
}

void KeyInput::update()
{
	actionsThisFrame = 0;
	int possibleAction = 1;
	while (possibleAction != maxActionValue)
	{
		int key = keyMapper->getKeyFor(possibleAction);
		if (GetAsyncKeyState(key))
			actionsThisFrame |= possibleAction;
		possibleAction <<= 1;
	}
}

int KeyInput::actionsHot(int actions) const
{
	return (actionsThisFrame & actions) == actions;
}

KeyInput& KeyInput::getInstance()
{
	return instance;
}