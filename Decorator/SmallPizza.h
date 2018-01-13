#pragma once
#include "Pizza.h"

class SmallPizza :Pizza
{
public:
	SmallPizza();
	~SmallPizza();
	
	std::string GetDescription() override { return std::string("Small Pizza"); }
	void SetDescription(std::string PizzaName) override 	{ _description = PizzaName;	}
	double CalculateCost() override 	{return 3.0;}
};

