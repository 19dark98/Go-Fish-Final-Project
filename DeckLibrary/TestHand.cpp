#include "TestHand.h"

void TestHand::TestPropertiesEmpty()
{
	//test hasSuit
	{
		Hand h;
		Card c(1, 1);
		std::cout << h.hasSuit(1) << endl << h.hasFace(1) << endl<<h.hasCard(1,1)<<endl<<h.hasCard(c)<<endl;
		int i1 = -1;
		int i2 = -1;
		cout << h.hasCard(1, 1, i1) << endl << i1 << endl << h.hasCard(c, i2) <<endl<< i2<<endl;
		
	}
}