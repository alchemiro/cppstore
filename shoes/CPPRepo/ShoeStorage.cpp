#include "ShoeStorage.h"
#include "PairOfShoes.h"

ShoeStorage::ShoeStorage(int size) {
	chainLength = size;
	shoes = new PairOfShoes * [size];
	for (int i = 0; i < size; i++) {
		shoes[i] = nullptr;
	}
}

ShoeStorage::~ShoeStorage() {
	for (int i = 0; i < chainLength; i++) {
		delete shoes[i];
	}
	delete[] shoes;
}

ShoeStorage::ShoeStorage(ShoeStorage& shoePile) {
	chainLength = shoePile.chainLength;
	shoes = new PairOfShoes * [chainLength];
	for (int i = 0; i < chainLength; i++) {
		shoes[i] = shoePile.shoes[i] != nullptr ? new PairOfShoes(*(shoePile.shoes[i])) : nullptr;
	}
}

ShoeStorage& ShoeStorage::operator=(ShoeStorage& shoePile) {
	if (this != &shoePile) {
		this ->~ShoeStorage();
		chainLength = shoePile.chainLength;
		shoes = new PairOfShoes * [chainLength];
		for (int i = 0; i < chainLength; i++) {
			shoes[i] = shoePile.shoes[i] != nullptr ? new PairOfShoes(*(shoePile.shoes[i])) : nullptr;
		}
	}
	return *this;
}

void ShoeStorage::addPairOfShoes(PairOfShoes shoe) {
	PairOfShoes* shoeToInsert = new PairOfShoes(shoe.getName(), shoe.getPrice());

	for (int i = 0; i < chainLength; i++) {
		if (shoes[i] == nullptr) {
			shoes[i] = shoeToInsert;
			return;
		}
	}
	
	PairOfShoes** tempShoes = new PairOfShoes * [chainLength * 2];
	for (int i = 0; i < chainLength*2; i++) {
		tempShoes[i] = nullptr;
	}
	for (int i = 0; i < chainLength; i++) {
		tempShoes[i] = shoes[i];
	}
	tempShoes[chainLength] = shoeToInsert;
	this->~ShoeStorage();
	shoes = tempShoes;
	chainLength *= 2;
}

void ShoeStorage::removePairOfShoes(char* name) {
	for (int i = 0; i < chainLength; i++) {
		if (strcmp(name, shoes[i]->getName())) {
			shoes[i] = nullptr;
			return;
		}
	}
}

double ShoeStorage::getPrice(char* name) {
	for (int i = 0; i < chainLength; i++) {
		if (shoes[i] != nullptr) {
			if (strcmp(shoes[i]->getName(), name) == 0) {
				return shoes[i]->getPrice();
			}
		}
	}
	return 0.0;
}

double ShoeStorage::averageShoePrice() {
	int actualShoes = 0;
	double average = 0.0;
	for (int i = 0; i < chainLength; i++) {
		if (shoes[i] != nullptr) {
			actualShoes++;
			average += shoes[i]->getPrice();
		}
	}
	return actualShoes == 0 ? 0.0 : average / actualShoes;
}