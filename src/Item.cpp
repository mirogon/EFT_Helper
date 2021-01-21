#include "Item.h"

Item::Item()
{
	itemType = ItemType::NONE;
	name = "unnamed";
	neededForHideout = 0;
	neededForQuests = 0;
	weight = 0;

}

ItemType Item::ItemTypeFromString(const std::string& s)
{
	ItemType t = ItemType::NONE;
	if (s == "Food")
	{
		t = ItemType::FOOD;
	}

	return t;
}

std::string Item::ItemTypeToString(ItemType t)
{
	std::string s;
	switch (t)
	{
		case ItemType::FOOD: s = "FOOD"; break;
		default: s = "NONE";
	}
		
	return s;
}
