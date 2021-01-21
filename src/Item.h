#pragma once
#include "Global.h"

enum class ItemType
{
	NONE=0,
	FOOD=1
};

class Item
{

public:
	Item();

	static ItemType ItemTypeFromString(const std::string& s);
	static std::string ItemTypeToString(ItemType t);

	ItemType itemType;
	std::string name;
	unsigned int neededForHideout;
	unsigned int neededForQuests;
	float weight;
};

