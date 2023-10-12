#include "ShoeStore.h"
#include "ShoeStorage.h"
#include "PairOfShoes.h"

ShoeStore::ShoeStore(double disc) {
	discount = disc;
	shelves = new ShoeStorage();
}

void ShoeStore::setDiscountPercent(double newPercent) {
	discount = newPercent;
}

double ShoeStore::getDiscountPercent() {
	return discount;
}

void ShoeStore::addShoes(char* name, double price, int pairs) {
	PairOfShoes* shoeTemplate = new PairOfShoes(name, price);
	for (int i = 0; i < pairs; i++) {
		shelves->addPairOfShoes(*shoeTemplate);
	}
}

double ShoeStore::averageShoePrice() {
	return shelves->averageShoePrice() * discount;
}

double ShoeStore::getShoePrice(char* name) {
	return shelves->getPrice(name) * discount;
}

void ShoeStore::removeOnePair(char* name) {
	shelves->removePairOfShoes(name);
}

