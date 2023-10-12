#pragma once
#include <iostream>
#include "PairOfShoes.h"
class ShoeStorage
{
private:
	int chainLength;
	PairOfShoes** shoes;
public:
	ShoeStorage(int size=4);
	~ShoeStorage();
	ShoeStorage(ShoeStorage& shoePile);
	ShoeStorage& operator = (ShoeStorage& shoePile);
	void addPairOfShoes(PairOfShoes shoe);
	void removePairOfShoes(char* name);
	double getPrice(char* name);
	double averageShoePrice();
};