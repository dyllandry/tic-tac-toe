#ifndef PICKED_TILE_INPUT_EVENT_H
#define PICKED_TILE_INPUT_EVENT_H

#include "event.hpp"

using DescriptorType = const char*;

enum PickedTile
{
	topLeft,
	topCenter,
	topRight,
	centerLeft,
	center,
	centerRight,
	bottomLeft,
	bottomCenter,
	bottomRight
};

class PickedTileInputEvent : public Event
{
private:
	PickedTile _pickedTile;
public:
	PickedTileInputEvent(PickedTile pickedTile) : _pickedTile(pickedTile) {}
	PickedTile pickedTile() const { return _pickedTile; }
	static constexpr DescriptorType descriptor {"PickedTileInputEvent"};
	virtual DescriptorType type() const { return descriptor; }
};

#endif // PICKED_TILE_INPUT_EVENT_H
