#include <iostream>
#include <string>
using namespace std;
struct Product{
string name;
double price;
};
int main(){
Product p;
      initialize(p,"Chicken", 20);
      display(p);
      raisePrice(p,1.1);
      display(p);
return0;
}
