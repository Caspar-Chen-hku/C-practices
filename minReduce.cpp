#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int minReduce(int h){
    int e = (int) (sqrt(h)-0.5);
    for (int i=e+1; i<h; i++){
        if (pow(i,2)+i>h) return i-1;
    }
}

bool child(string s,string t){
    if (s=="") return true;
    if (t=="") return false;
    int index = t.find_first_of(s.substr(0,1));
    if (index==-1) return false;
    return child(s.substr(1),t.substr(index+1));
}

int main() {
    cout << "minReduce: " << minReduce(10000) << endl;

    if (child("qsc","qwerasdfzxcv")) cout << "yes\n";
    else cout << "No\n";
    if (child("qaz","qsdcxzsae")) cout << "yes\n";
    else cout << "No\n";
	return 0;
}
