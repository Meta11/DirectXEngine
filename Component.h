#pragma once
#include "Entity.h"

class Component {
	friend class Entity;
	Entity* parent;

public:
	Entity* getParent() const { return this->parent; }
	virtual bool initialize() { return true; }
	virtual bool shutdown() { return true; }
	virtual void update() {}
};
