#include <iostream>
using namespace std;

bool isLeap(int year){
    if (year%4 == 0) {
        if (year%100 == 0) {
            if (year%400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}
int main() {

    int year;
    cout << "Enter a year: ";
    cin >> year;
    const string MONTH[] = {"January","February","March","April","May",
    "June", "July","August","September","October","November","December"}; 
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    if (isLeap(year)) days_in_month[1]=29;
    int days=0;
    if (year==2016) days=0;
    else if (year>2016){
        for (int i=2016; i<year; i++){
            if (isLeap(i)) days+=366;
            else days+=365;
        }
    }
    else{
        for (int i=year; i<2016; i++){
            if (isLeap(i)) days-= 366;
            else days-=365;
        }
        while(days<0) days+=7;
    }
    days+=12;
    int i =0;
    while (i<12){
        if (days%7==0){
            cout << MONTH[i] << endl;
        }
        days+=days_in_month[i];
        i++;
    }
    return 0;
}