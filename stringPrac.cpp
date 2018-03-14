#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void display(list<int> p){
    for (list<int>::iterator i=p.begin(); i!=p.end(); i++){
        cout << (*i) << ' ';
    }
    cout << endl;
}

bool compare(int i,int j){
    return i<j;
}
   int main()
   {
       list<int> l;
       for (int i=0; i<10; i++){
          l.push_back(i);
          l.push_front(i);
       }

       display(l);

       l.remove(1);

       sort(l.begin(),l.end(),compare);
       display(l);



    return 0;
    }
