// Decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SmallPizza.h"
#include "Cheese.h"


int main()
{
	Pizza *smallPizza = new Pizza(new SmallPizza());


	std::cout << smallPizza.GetDescription() << std::endl;
	std::cout <<   smallPizza.CalculateCost() << std::endl;

	getchar();

    return 0;
}

