#include <iostream>
#include <vector>
#include "model.h"
#include <random>
#include <time.h>
using namespace std;

vector<Product> allProducts = {
    Product(1, "Shahi Paneer", 250),
    Product(3, "Biryan", 180),
    Product(2, "Lassi", 50),
    Product(5, "Aloo Parantha", 20),
    Product(4, "Gulab jamun", 10),
    Product(1, "Chicken Curry", 280),
};
Product *chooseProduct()
{
    string productList;
    cout << "Available Products " << endl;
    for (auto product : allProducts)
    {
        productList.append(product.getDisplayName());
    }
    cout << productList << endl;
    cout << "-------------------" << endl;
    string choice;
    cin >> choice;
    for (int i = 0; i < allProducts.size(); i++)
    {
        if (allProducts[i].getShortName() == choice)
        {
            return &allProducts[i];
        }
    }
    cout << "Product not found" << endl;
    return NULL;
}
bool checkout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }
    int total = cart.getTotal();
    cout << "Pay in Cash" << endl;
    int paid;
    char ans;

    cout << "Sir do you want to participate in lucky discount withdraw costing Rs 20 (y)es or (n)o" << endl;
    cin >> ans;
    if (ans == 'y')
    {
        cout << "Extra Rs 20 will be added to ur bill " << endl;
        srand((unsigned)time(NULL));
        float discount = ((float)rand() / RAND_MAX) * 100;
        cout<<"Congrats you earned a discount of "<<discount<<'%'<<endl;
        int final=total*(100-discount)/100 +20;
        cout<<"Your total bill is Rs : "<<final<<endl;
        cin >> paid;
        if (paid >= final)
        {
            cout << "change : " << paid - final << endl;
            cout << "Successfull checkout";
            return true;
        }
         else
    {
        cout << "not enough cash";
        return false;
    }
    }
    else
    {
        cin >> paid;
        if (paid >= total)
        {
            cout << "change : " << paid - total << endl;
            cout << "Successfull checkout";
            return true;

        }
    else
    {
        cout << "not enough cash";
        return false;
    }

        
    }
   
}

int main()
{
    char action;
    Cart cart;
    cout << "Welcome to Ayush ka dhaba" << '\n';
    while (true)
    {
        cout << "Select an action - (a)dd item, (r)emove, (v)iew cart, (c)heckout" << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Added to the cart " << product->getDisplayName() << endl;
                cart.addProduct(*product);
            }
        }
        else if (action == 'r')
        {
            Product *product = chooseProduct();
            if (product != NULL)
            {
                cout << "Removed from the cart " << product->getDisplayName() << endl;
                cart.delProduct(*product);
            }
        }

        else if (action == 'v')
        {

            cout << "--------------------------------------------" << endl;
            cout << cart.viewCart();
            cout << "--------------------------------------------" << endl;
        }
        else
        {
            cart.viewCart();
            if (checkout(cart))
            {
                break;
            }
        }
    }
    return 0;
}
