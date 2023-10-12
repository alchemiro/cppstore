#include <iostream>
#include "PairOfShoes.h"
#include "ShoeStorage.h"
using namespace std;

int main()
{

    char name[10] = "nike";
    PairOfShoes* shoe = new PairOfShoes(name, 400);
    ShoeStorage* shelf = new ShoeStorage();
    cout << *shoe->getName() << endl;
    cout << shoe->getPrice() << endl;
    shoe->setPrice(300);
    cout << shoe->getPrice() << endl;

    shelf->addPairOfShoes(*shoe);
    cout << shelf->getPrice(name);
    
    cout << "Hello World!\n";
}
