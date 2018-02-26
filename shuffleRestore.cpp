#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n = 10;
int size = 10;

vector<int> shuffle(vector<int> cards){
    vector<int>::iterator it = cards.begin();
    int half_n = n/2;
    vector<int> c1(it,it+half_n);
    vector<int> c2(it+half_n, cards.end());
    vector<int> result;
    for (int i=0; i<half_n; i++){
        result.push_back(c1[i]);
        result.push_back(c2[i]);
    }
    return result;
}


void display(vector<int> cards){
    for (int i=0; i<n; i++){
        cout << cards[i] << " ";
    }
    cout << endl;
}

void shuffle_k(vector<int> cards, int k){
    vector<int> temp = cards;
    cout << "The original cards are: ";
    display(cards);
    for (int i=0; i<k; i++){
        temp = shuffle(temp);
        cout << "Shuffled " << i+1 << " times: ";
        display(temp);
    }
}

int* restore(queue<int> arr){
    int* narr = new int[size];
    for (int i=0; i<size; i++){
        narr[i] = 0;
    }
    int i=-1;
    int temp;
    int count = 0;
    while (!arr.empty()){
        temp = arr.front();
        arr.pop();
        while (count!=2){
            i++;
            if (i>=size){
                i%=size;
            }
            if (narr[i]==0) count++;
        }
        narr[i] = temp;
        count=0;
    }
    return narr;
}

void display_arr(int* arr){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

   int main()
   {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    vector<int> cards(arr, arr+10);

    shuffle_k(cards,5);

    queue<int> arr;
    for (int i=1; i<=size; i++){
        arr.push(i);
    }
    int* restored = restore(arr);
    display_arr(restored);

    return 0;
    }
