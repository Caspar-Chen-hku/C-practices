//supermarket.cpp
//This program analyzes the data in a supermarket

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Product{
 int pid;
 double unitPrice;
 string category;
 string name;
};

struct Transaction{
 int tid;
 string datetime;
 string place;
};

struct TransactionDetail{
 int tid;
 int pid;
 int quantity;
};

 struct Database{
  Product products[];
  int noOfProducts;
  Transaction transactions[];
  int noOfTransactions;
  TransactionDetail tran_details[];
  int noOfTran_details;
};

void loadProducts(Database &d, string fileName);
//void queryA(Database d);
//void loadTransactions(Database &d, string fileName);
//void queryB(Database d); 
//void loadTran_details(Database &d, string fileName);
//void queryC(Database d);
//void queryD(Database d, string searchName);
//string to_lowercase(string s);
//void queryE(Database d, string place, int YYYY);
//void queryF
//void queryG

int main()
{
  Database d;
  loadProducts (d, "Products.txt");
  //queryA(d);
  //loadTransactions(d,"Transactions.txt");
  //queryB(d);
  //loadTran_details(d, "TransactionsDetails.txt" );
  /*queryC(d);

  string searchName;
  cout << "cin the searchname: ";
  cin >> searchName;
  queryD(d,searchName);*/
  //queryE(d);
  //queryF(d);
  //queryG(d);
  return 0;
}

void loadProducts(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    getline(instr,discard);
    d.noOfProducts = atoi(discard.c_str());
    while (getline(instr,discard,','))
    {
        d.products[count].pid = atoi(discard.c_str());
        getline(instr,discard,',');
        d.products[count].unitPrice = atoi(discard.c_str()) * 1.0;
        getline(instr,d.products[count].category,',');
        getline(instr,d.products[count].name);
        count++;
    }
    instr.close();
}

/*void queryA(Database d)
{
    for (int i=0; i<23; i++)
    {
        cout << d.products[i].pid << "\t";
        cout << d.products[i].unitPrice << "\t";
        cout << d.products[i].category << "\t";
        cout << d.products[i].name << "|" << endl;
    }
}
*/
/*void loadTransactions(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    getline(instr,discard);
    d.noOfTransactions = atoi(discard.c_str());
    while (getline(instr,discard,','))
    {
        d.transactions[count].tid = atoi(discard.c_str());
        getline(instr,d.transactions[count].datetime,',');
        getline(instr,d.transactions[count].place,',');
        count++;
    }
    instr.close();
}
*/
/*void queryB(Database d)
{
     for (int i=0; i<12; i++)
    {
        cout << d.transactions[i].tid << "\t";
        cout << d.transactions[i].datetime << "\t";
        cout << d.transactions[i].place << "|" << endl;
    }
}
*/
/*void loadTran_details(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    getline(instr,discard);
    d.noOfTran_details = atoi(discard.c_str());
    while (getline(instr,discard,','))
    {
        d.tran_details[count].tid = atoi(discard.c_str());
        getline(instr,discard,',');
        d.tran_details[count].pid = atoi(discard.c_str());
        getline(instr,discard,',');
        d.tran_details[count].quantity = atoi(discard.c_str());
        count++;
    }
    instr.close();
}*/

/*void queryC(Database d)
{
    for (int i=0; i<31; i++)
    {
        cout << d.tran_details[i].tid << "\t";
        cout << d.tran_details[i].pid << "\t";
        cout << d.tran_details[i].quantity << endl;
    }
}

 void queryD(Database d, string searchName)
 {
     string newname = to_lowercase(searchName);
     for (int i=0; i<23; i++)
     {
         string nproduct = to_lowercase(d.products[i].name);
         if (nproduct.find(newname) != string::npos)
            cout << d.products[i].name << " " << d.products[i].pid << endl;
     }
 }

string to_lowercase(string s)
 {
     int j=s.length();
     for (int i=0; i<j; i++)
     {
         if (s.at(i) <= 90)
            s.at(i) += 32;
     }
     return s;
 }

 void queryE(Database d, string place, int YYYY)
 {
    int arr[12] = {};
    for (int i=0; i< 12; i++)
    {
        int year = atoi(d.transactions[i].datetime.substr(0,4).c_str());
        if (d.transactions[i].place == place && year == YYYY)
        {
            int month = atoi(d.transactions[i].datetime.substr(5,2).c_str());
            arr[month] += d.tran_details[i].quantity;
        }

    }
    for (int j=0; j< 12; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
 }
*/
