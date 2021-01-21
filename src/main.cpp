#include "ItemManager.h"

int main()
{

	if (!std::filesystem::exists("EFTItems.xml"))
	{
		pugi::xml_document doc;
		doc.save_file("EFTItems.xml");
	}
	ItemManager m{ "EFTItems.xml" };
	
	m.PrintItems_CLI();

	system("pause");
	return 0;
}