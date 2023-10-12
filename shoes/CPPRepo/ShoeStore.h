#pragma once
#include "PairOfShoes.h"
#include "ShoeStorage.h"
class ShoeStore
{
private:
	ShoeStorage* shelves;
	double discount;

public:
	ShoeStore(double discount = 0.0);
	void setDiscountPercent(double newDiscount);
	double getDiscountPercent();
	void addShoes(char* name, double price, int pairs=1);
	double averageShoePrice();
	double getShoePrice(char* name);
	void removeOnePair(char* name);
};

