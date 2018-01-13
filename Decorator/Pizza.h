#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class AbstractPizza
{
public:
	virtual std::string GetDescription()  = 0;
	virtual void SetDescription(std::string PizzaName) = 0;
	virtual double CalculateCost() = 0;
};

class Pizza : public AbstractPizza
{
private:
	std::string _description;
public:
	Pizza(std::string PizzaName) { _description.assign(PizzaName); }
	Pizza(char * PizzaName) { _description.assign(PizzaName); }
	
	std::string GetDescription() override {return "Pizza";	}
	void SetDescription(std::string PizzaName) override  {_description.assign(PizzaName);	}
	double CalculateCost() override  { return 0.0; }
};

class PizzaDecorator : public AbstractPizza {
private:
	AbstractPizza *_pizza;
public:
	PizzaDecorator() {  }
	PizzaDecorator(int a) {  }
	PizzaDecorator(AbstractPizza *pizza) { _pizza = pizza; }

	std::string GetDescription() override {return  _pizza->GetDescription(); }
	void SetDescription(std::string PizzaName) override { _pizza->SetDescription(PizzaName); }
	double CalculateCost() override { return (_pizza->CalculateCost()); }
};

class SmallPizza : public PizzaDecorator {
public:
	SmallPizza(AbstractPizza *p) : PizzaDecorator(p) {}

	std::string GetDescription() override { return "Small Pizza"; }
	void SetDescription(std::string PizzaName) override { PizzaDecorator::SetDescription (PizzaName); }
	double CalculateCost() override { return (PizzaDecorator::CalculateCost() + 3.0); }
};



