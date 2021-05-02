#include <iostream>

using namespace std;


class Product
{
  private:
    string code;
    string name;
  public:
    void setCode(string c) {code = c;}
    string getCode() {return code;}
    void scanner()
    {
        cout << "Input the info for the product.\n";
        cout << "Code: ";
        getline(cin, code);
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cin.sync(); cin.clear();
    }

    
    void printer()
    {
        cout << "Name: "
             << name
             << "\nCode: "
             << code << endl;
    }
};

class Packed: public Product
{
  public:
    double unitPrice;
  private:
    double getPrice() {return unitPrice;}
    void setPrice(double p) {unitPrice = p;}
    void scanner()
    {
        Product::scanner();
        cout << "unit price: "; cin >> unitPrice;
    }

    void printer()
    {
        Product::printer();
        cout << "Unit price: " << unitPrice << endl;
    }

};

class Unpacked: public Product
{
  public:
    double weight;
    double kiloPrice;  
  private:
    void setWeight(double w) {weight = w;}
    double getWeight() {return weight;}

    void scanner()
    {
        Product::scanner();
        cout << "Weight: "; cin >> weight;
        cout << "kilo price: "; cin >> kiloPrice; 
    }


    void printer()
    {
        Product::printer();
        cout << "Weight: " << weight;
        cout << "Kilo price: " << kiloPrice << endl;
    }
};