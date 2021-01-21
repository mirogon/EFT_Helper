#include "ItemManager.h"

ItemManager::ItemManager(const std::string& xmlFile)
{
	items = std::vector<Item>();

	LoadItemsFromXmlFile(xmlFile);
}

void ItemManager::AddItem(const Item& pItem)
{
	items.push_back(pItem);
}

std::vector<Item> ItemManager::GetItems()
{
	return items;
}

void ItemManager::PrintItems_CLI()
{
	std::cout << "Items:" << std::endl;
	for (int i = 0; i < items.size(); ++i)
	{
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << "ItemType: " << Item::ItemTypeToString(items[i].itemType) << std::endl;
		std::cout << "Name: "<<items[i].name << std::endl;
		std::cout << "Needed for Hideout: " << items[i].neededForHideout << std::endl;
		std::cout << "Needed for Quests: " << items[i].neededForQuests << std::endl;
		std::cout << "Weight: " << items[i].weight << std::endl;
		std::cout << "--------------------" << std::endl;
	}
}

void ItemManager::LoadItemsFromXmlFile(const std::string& filename)
{
	pugi::xml_document xmlDoc;
	pugi::xml_parse_result parseRes = xmlDoc.load_file(filename.c_str());
	std::cout << filename << ": " << std::endl;
	for (pugi::xml_node node = xmlDoc.first_child(); node; node = node.next_sibling())
	{
		std::cout << node.name() << ":" << node.text().as_string()<<std::endl;
		for (pugi::xml_node child = node.first_child(); child; child = child.next_sibling())
		{
			items.push_back(Item());
			std::cout <<"	"<< child.name() << ":" << child.text().as_string()<<std::endl;
			for (pugi::xml_node subChild = child.first_child(); subChild; subChild = subChild.next_sibling())
			{
				std::string name = subChild.name();
				if (name == "ItemType")
				{
				items.back().itemType = Item::ItemTypeFromString(subChild.text().as_string());
				}
				else if (name == "Name")
				{
					items.back().name = subChild.text().as_string();
				}
				else if (name == "NeededForHideout")
				{
					items.back().neededForHideout = subChild.text().as_int();
				}
				else if (name == "NeededForQuests")
				{
					items.back().neededForQuests = subChild.text().as_int();
				}
				else if (name == "Weight")
				{
					items.back().weight = subChild.text().as_float();
				}
				std::cout <<"		"<< subChild.name() << ":" << subChild.text().as_string()<<std::endl;
			}
		}
		
		
		std::cout << std::endl;
	}

}
