#include <iostream>
#include <iomanip>

using namespace std;

/**
   A simulated cash register that tracks the item count and
   the total amount due.
*/
class CashRegister
{
public:
   /**
      Constructs a cash register with no sale.
   */
   CashRegister(double rate);
   /**
      Clears this cash register.
   */
   void clear();
   /**
      Adds an item to this cash register.
      @param price the price of the added item
   */
   void add_item(double price);

   /*
    * Adds a taxable item to this cash register.
    * @param price the price of the added item
    */
   void add_taxable_item(double price);

   /*
    * Gets the tax of all the items in the current sale.
    */
   double get_total_tax() const;

   /**
      Gets the price of all items in the current sale.
      @return the total amount
   */
   double get_total() const;
   /**
      Gets the number of items in the current sale.
      @return the item count
   */
   int get_count() const;
private:
   int item_count;
   double total_price;
   double tax_rate;
   double total_tax;
};

CashRegister::CashRegister(double rate)
{
   total_tax = 0;
   tax_rate = rate;
   item_count = 0;
   total_price = 0;
}

void CashRegister::clear()
{
   total_tax = 0;
   item_count = 0;
   total_price = 0;
}

void CashRegister::add_item(double price)
{
   item_count++;
   total_price = total_price + price;
}

double CashRegister::get_total() const
{
   return total_price; 
}

void CashRegister::add_taxable_item(double price) {
    item_count++;
    total_tax += tax_rate * price;
    total_price = total_price + price + total_tax;

}

double CashRegister::get_total_tax() const {
    return total_tax;
}

int CashRegister::get_count() const
{
   return item_count; 
}

/**
   Displays the item count and total price of a cash register.
   @param reg the cash register to display
*/
void display(CashRegister reg)
{
   cout << "Item " << reg.get_count() << ": $"
      << fixed << setprecision(2) << reg.get_total() << " Tax: $" << reg.get_total_tax() << endl;
}

int main()
{
   double rate;
   cout << "Input tax rate: -> ";
   cin >> rate;
   CashRegister register1(rate);
   register1.clear();
   register1.add_item(1.95);
   display(register1);
   register1.add_item(0.95);
   display(register1);
   register1.add_item(2.50);
   display(register1);
   register1.add_taxable_item(5.99);
   display(register1);
   return 0;
}
