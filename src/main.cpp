#include "ItemManager.h"

int main()
{

	if (!std::filesystem::exists("EFTItems.xml"))
	{
		pugi::xml_document doc;
		doc.save_file("EFTItems.xml");
	}
	ItemManager m{ "EFTItems.xml" };
	
	Item ak;
	ak.name = "AK";
	ak.itemType = ItemType::NONE;
	ak.neededForHideout = 0;
	ak.neededForQuests = 5;
	ak.weight = 55;
	m.AddItem(ak);

	m.PrintItems_CLI();

	system("pause");
	return 0;
}