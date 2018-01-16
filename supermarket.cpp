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
  Product* products;
  int numberOfProducts;
  Transaction* transactions;
  int numberOfTransactions;
  TransactionDetail* TransactionDetails;
  int numberOfTran_details;
};

void loadProducts(Database &d, string fileName);
void queryA(Database d);
void loadTransactions(Database &d, string fileName);
void queryB(Database d);
void loadTran_details(Database &d, string fileName);
void queryC(Database d);
void queryD(Database d, string searchName);
string to_lowercase(string s);
void queryE(Database d, string place, int YYYY);
void queryF(Database d, int tid);
void queryG(Database d, int tid);

int main()
{
  Database d;

  loadProducts (d, "Products.txt");
  queryA(d);

  cout << endl;

  loadTransactions(d,"Transactions.txt");
  queryB(d);

  cout << endl;

  loadTran_details(d, "TransactionDetails.txt" );
  queryC(d);

  cout << endl;

  string searchName;
  cout << "cin the searchname: ";
  cin >> searchName;
  queryD(d,searchName);

  cout << endl;

  queryE(d,"Times Square, Causeway Bay",2015);

  cout << endl;

  queryF(d,10);

  cout << endl;

  queryG(d,10);

  delete []d.products;
  d.products=0;
  delete []d.transactions;
  d.transactions=0;
  delete []d.TransactionDetails;
  d.TransactionDetails=0;

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

    string discard;
    getline(instr,discard);
    d.numberOfProducts = atoi(discard.c_str());

    d.products = new Product[d.numberOfProducts];

    int count=0;
    while (getline(instr,discard,','))
    {
        d.products[count].pid = atoi(discard.c_str());
        instr >> d.products[count].unitPrice;
        instr.ignore();
        getline(instr,d.products[count].category,',');
        getline(instr,d.products[count].name);
        count++;
    }
    instr.close();
}

void queryA(Database d)
{
    for (int i=0; i<d.numberOfProducts; i++)
    {
        cout << d.products[i].pid << "\t";
        cout << d.products[i].unitPrice << "\t";
        cout << d.products[i].category << "\t";
        cout << d.products[i].name << "|" << endl;
    }
}

void loadTransactions(Database &d, string fileName)
{
    ifstream instr(fileName.c_str());
    if (!instr.is_open())
    {
      cout << "Failed to open the file.";
      exit(1);
    }

    int count = 0;
    string discard;
    string add;
    getline(instr,discard);
    d.numberOfTransactions = atoi(discard.c_str());

    d.transactions = new Transaction[d.numberOfTransactions];
    while (getline(instr,discard,' '))
    {
        d.transactions[count].tid = atoi(discard.c_str());
        getline(instr,discard,' ');
        getline(instr,add,' ');
        d.transactions[count].datetime = discard + '\t' + add;
        getline(instr,d.transactions[count].place);
        count++;
    }
    instr.close();
}

void queryB(Database d)
{
    for (int i=0; i<d.numberOfTransactions; i++)
    {
        cout << d.transactions[i].tid << "\t";
        cout << d.transactions[i].datetime << "\t";
        cout << d.transactions[i].place << "|" << endl;
    }
}

void loadTran_details(Database &d, string fileName)
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
    d.numberOfTran_details = atoi(discard.c_str());

    d.TransactionDetails = new TransactionDetail[d.numberOfTran_details];
    while (getline(instr,discard,' '))
    {
        d.TransactionDetails[count].tid = atoi(discard.c_str());
        getline(instr,discard,' ');
        d.TransactionDetails[count].pid = atoi(discard.c_str());
        getline(instr,discard);
        d.TransactionDetails[count].quantity = atoi(discard.c_str());
        count++;
    }
    instr.close();
}

void queryC(Database d)
{
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        cout << d.TransactionDetails[i].tid << "\t";
        cout << d.TransactionDetails[i].pid << "\t";
        cout << d.TransactionDetails[i].quantity << endl;
    }
}

void queryD(Database d, string searchName)
 {
     int count;
     string newname = to_lowercase(searchName);
     for (int i=0; i<d.numberOfProducts; i++)
     {
         string nproduct = to_lowercase(d.products[i].name);
         if (nproduct.find(newname) != string::npos)
         {
             count = 0;
             for (int j=0; j<d.numberOfTran_details; j++)
             {
                 if (d.TransactionDetails[j].pid==d.products[i].pid)
                 {
                    count += d.TransactionDetails[j].quantity;
                 }
             }
              cout << d.products[i].name << " " << count << endl;
         }
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
            arr[month-1] ++;
        }
    }
    for (int j=0; j< 12; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
 }

void queryF(Database d, int tid)
{
    int count = 0;
    double sum = 0;
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        if (d.TransactionDetails[i].tid == tid)
        {
            cout << d.products[d.TransactionDetails[i].pid].name <<'\t';
            cout << d.products[d.TransactionDetails[i].pid].unitPrice << '\t';
            cout << d.TransactionDetails[i].quantity << '\t';
            cout << d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity
            << endl;
            count++;
            sum += d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity;
        }
    }
    if (count==0)
    {
        cout << "Not found!";
    }
    else
    {
        cout << "Total:" << sum << endl;
    }
}

void queryG(Database d, int tid)
{
    int count = 0;
    double sum = 0;
    double* arr = new double[d.numberOfTran_details];
    for (int i=0; i<d.numberOfTran_details; i++)
    {
        if (d.TransactionDetails[i].tid == tid)
        {
            arr[i]= d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity;
            count++;
            sum += d.products[d.TransactionDetails[i].pid].unitPrice * d.TransactionDetails[i].quantity;
        }
    }
    if (count==0)
    {
        cout << "Not found!";
    }
    else
    {
        double biggest;
        int index;
        for (int i=0; i<count; i++)
        {
            biggest=0;
            index = 0;
            for (int j=0; j<d.numberOfTran_details; j++)
            {
              if(arr[j]>biggest)
              {
                index=j;
                biggest=arr[j];
              }
            }
            cout << d.products[d.TransactionDetails[index].pid].name <<'\t';
            cout << d.products[d.TransactionDetails[index].pid].unitPrice << '\t';
            cout << d.TransactionDetails[index].quantity << '\t';
            cout << arr[index] << endl;
            arr[index]=0;
        }
        cout << "Total:" << sum << endl;
    }
    delete []arr;
    arr = 0;
}
