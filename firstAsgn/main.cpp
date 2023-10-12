/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class PairOfShoes
{
public:
    string name;
    int price;
    string GetName()
    {
        return name;
    }
    int GetPrice()
    {
        return price;
    }
    void SetPrice(int value)
    {
        price = value;
    }
    PairOfShoes(string shoeName, int shoePrice)
    {
        name = shoeName;
        price = shoePrice;
    }
    PairOfShoes()
    {
        name = NULL;
        price = NULL;
    }
};

class ShoeStorage
{
public:
    int storageSize;
    PairOfShoes *shoeChain;
    ShoeStorage(int chainSize = 4)
    {
        storageSize = chainSize;
        shoeChain = new PairOfShoes[chainSize];
    }
    void AddPairOfShoes(PairOfShoes pair)
    {
        bool notAdded = true;
        int chainLength = 0;
        for (int i = 0; shoeChain[i] != '\0' && notAdded; i++)
        {
            chainLength++;
            if (shoeChain[i] == NULL)
            {
                shoeChain[i] = pair.GetName();
                shoeChain[i + 1] = pair.GetPrice();
                notAdded = false;
            }
        }
        if (notAdded)
        {
            shoeChain = new PairOfShoes[chainLength * 2];
            shoeChain[chainLength] = pair.GetName();
            shoeChain[chainLength + 1] = pair.GetPrice();
        }
    }
};

int main()
{
    cout << "Hello World";
    PairOfShoes pair = new PairOfShoes("Nike", 100);
    ShoeStorage store = new ShoeStorage();
    store.AddPairOfShoes(pair);

    return 0;
}
