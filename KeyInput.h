#pragma once

class IKeyMapper;

class KeyInput {
	IKeyMapper* keyMapper;
	int maxActionValue;
	int actionsThisFrame;

	KeyInput() {};
	KeyInput(const KeyInput&);
	KeyInput& operator=(const KeyInput&);
	static KeyInput instance;
public:
	bool initialize(IKeyMapper* keyMapper, int maxActionValue);
	bool shutdown();
	void update();
	int actionsHot(int actions) const;
	static KeyInput& getInstance();
};

#define input KeyInput::getInstance()
