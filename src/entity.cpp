#include "component.hpp"
#include "entity.hpp"
#include <assert.h>
#include <iostream>

Entity::Entity() {
	std::cout << "new Entity (id: " << _id << ")\n";
	_id = makeId();
}

Entity::~Entity()
{
	std::cout << "destroy Entity (id: " << _id << ")\n";
	for (auto component : _components) delete component.second;
	_components.clear();
}

Entity::Id Entity::id() { return _id; }

Entity::Id Entity::makeId()
{
	static Id nextId{0};
	return nextId++;
}

