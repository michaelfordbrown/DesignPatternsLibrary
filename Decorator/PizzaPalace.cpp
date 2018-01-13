#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

// Component
class AbstractPizza
{
public:
	virtual std::string GetDescription() = 0;
	virtual double CalculateCost() = 0;
};

class Pizza : public AbstractPizza
{
public:
	Pizza() {  }

	std::string GetDescription() override { return "Pizza"; }
	double CalculateCost() override { return 0.0; }
};

// Decorator
class PizzaDecorator : public AbstractPizza {
private:
	AbstractPizza *_pizza;
public:
	PizzaDecorator(AbstractPizza *pizza) { _pizza = pizza; }

	std::string GetDescription() override { return  _pizza->GetDescription(); }
	double CalculateCost() override { return (_pizza->CalculateCost()); }
};

// Concrete Components
class SmallPizza : public PizzaDecorator {
public:
	SmallPizza(AbstractPizza *p) : PizzaDecorator(p) {}

	std::string GetDescription() override { return "Small Pizza"; }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 3.0); }
};

class MediumPizza : public PizzaDecorator {
public:
	MediumPizza(AbstractPizza *p) : PizzaDecorator(p) {}

	std::string GetDescription() override { return "Medium Pizza"; }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 3.0); }
};

class LargePizza : public PizzaDecorator {
public:
	LargePizza(AbstractPizza *pizza) : PizzaDecorator(pizza) {}

	std::string GetDescription() override { return "Large Pizza"; }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 3.0); }
};

// Concrete Decorators
class Cheese : public PizzaDecorator {
public:
	Cheese(AbstractPizza *pizza) : PizzaDecorator(pizza) {}

	std::string GetDescription() override { return (PizzaDecorator::GetDescription() +  " Cheese"); }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 1.0); }
};

class Mushrooms : public PizzaDecorator {
public:
	Mushrooms(AbstractPizza *pizza) : PizzaDecorator(pizza) {}

	std::string GetDescription() override { return (PizzaDecorator::GetDescription() + " Mushrooms"); }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 1.0); }
};

class Ham : public PizzaDecorator {
public:
	Ham(AbstractPizza *pizza) : PizzaDecorator(pizza) {}

	std::string GetDescription() override { return (PizzaDecorator::GetDescription() + " Ham"); }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 1.0); }
};

int main(int argc, char **argv)
{
	AbstractPizza *MiniPizza = new SmallPizza(new Pizza());
	AbstractPizza *NormalPizza = new MediumPizza(new Pizza());
	AbstractPizza *FamilyPizza = new LargePizza(new Pizza());
	std::cout << MiniPizza->GetDescription() << std::endl;
	std::cout << NormalPizza->GetDescription() << std::endl;
	std::cout << FamilyPizza->GetDescription() << std::endl;

	MiniPizza = new Cheese(MiniPizza);
	std::cout << MiniPizza->GetDescription() << std::endl;

	MiniPizza = new Mushrooms(MiniPizza);
	std::cout << MiniPizza->GetDescription() << std::endl;


	delete FamilyPizza;
	delete NormalPizza;
	delete MiniPizza;

	std::cin.get();
	return 0;
}


