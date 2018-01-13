#pragma once
#include "PizzaDecorator.h"
class Cheese :
	public PizzaDecorator
{
public:
	Cheese();
	~Cheese();

	Cheese(Pizza pizza) 
	{
		SetDescription("Cheese");
	}

	std::string GetDescription() override { return (_pizza.GetDescription() + GetDescription()); }

	double CalculateCost() override { return (_pizza.CalculateCost() + 1.25); }
};

