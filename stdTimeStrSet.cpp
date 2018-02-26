#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <set>
using namespace std;

int n = 9;

string words[]={
    "inveigle","imbroglio","lament","inundate","ingratiate",
    "imperturbable","ineffable","haughty","insurgent","glean"
};
int SIZE = 10;

int** construct_chess(){
    int** a = new int*[n];
    for (int i=0; i<n; i++){
        a[i] = new int[n];
        for (int j=0; j<n; j++){
            a[i][j] = (int) rand()%2;
        }
    }
    return a;
}

void display_chess(int** a){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int max_nodes(int** a){
    int max=0;
    int temp_max;
    int temp;
    for (int i=0; i<n; i++){
        temp=1;
        temp_max=1;
        for (int j=1; j<n; j++){
            if (a[i][j]==a[i][j-1]) {
                temp++;
                if (temp>temp_max) temp_max=temp;
            }
            else temp=1;
        }
        if (temp_max>max) max=temp_max;
    }
    return max;
}

set<string> mastered(int m){
    set<string> s;
    int index;
    for (int i=0; i<SIZE; i++){
        index = rand()%SIZE;
        s.insert(words[index]);
        if (s.size()==m) return s;
    }
}

int score(set<string> s){
    int mark = 0;
    for (set<string>::iterator i=s.begin(); i!=s.end(); i++){
        mark+= (*i).length();
    }
    return mark;
}

int main() {

    srand(time(NULL));

    int** a = construct_chess();

    display_chess(a);

    cout << "max nodes: " << max_nodes(a) << endl;

    set<string> mas = mastered(6);
    for (set<string>::iterator i=mas.begin(); i!=mas.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;

    cout << "score is " << score(mas) << endl;
	return 0;
}
