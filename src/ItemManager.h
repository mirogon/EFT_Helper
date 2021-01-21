#pragma once
#include "Item.h"

class ItemManager
{
public:

	ItemManager(const std::string& xmlFile);

	void AddItem(const Item& pItem);
	std::vector<Item> GetItems();

	void PrintItems_CLI();

private:

	void LoadItemsFromXmlFile(const std::string& filename);

	std::vector<Item> items;

};

