#include <iostream>
#include "ItemType.h"

ItemType::ItemType()
{
	int value=0; 
}
//public:  
/**
 * This method compares the item given to the item of this specific instance
 * If the item that is given is greater than the one of this instance then it will
 * return greater or less for less and equal if they are equal.
 * @param item the item being compared
 * @return an enum if its greater less or equal
 */	
/*ItemType::*/Comparison ItemType::compareTo(ItemType item)
{
	if (item.getValue() < value)
	{
		return GREATER;
	}
	else if (item.getValue() == value)
	{
		return EQUAL;	
	}
	else
	{ 
		return LESS;
	}
} // compareTo

/**
 * This method gets the value of the ItemType instance
 * @return the value of the ItemType
 */
int ItemType::getValue() const
{
	return value;
} // getValue

/**
 * This is how we put a value into an ItemType()
 * @param num the number that is going to be put into itemtype
 */	
void ItemType::initialize(int num)
{
	value = num;
} // initialize


//private:
