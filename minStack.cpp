#include <iostream>
#include <stack>
#include <stdlib.h>
#include <time.h>
using namespace std;

void construct(stack<int>& main_stack, stack<int>& min_stack, int size){
    int val = rand()%50 + 1;
    main_stack.push(val);
    min_stack.push(val);
    //cout << val << ' ';
    int compared;
    
    for (int i=1; i<size; i++){
       val = rand()%50 + 1;
       main_stack.push(val);
      // cout << val << ' ';
       
       compared=min_stack.top();
       if (compared>val){
           min_stack.push(val);
       }
       else{
           min_stack.push(compared);
       }
    }
}

void display(stack<int> main_stack, stack<int> min_stack){
    stack<int> temp_main;
    stack<int> temp_min;
    int temp;
    
    cout << "main stack is:" << endl;
    while (!main_stack.empty()){
        temp = main_stack.top();
        cout << temp << " ";
        temp_main.push(temp);
        main_stack.pop();
    }
    cout << endl;
    
    cout << "min stack is:" << endl;
    while (!min_stack.empty()){
        temp = min_stack.top();
        cout << temp << " ";
        temp_min.push(temp);
        min_stack.pop();
    }
    cout << endl;
}

void superPush(stack<int>& main_stack, stack<int>& min_stack, int target){
    main_stack.push(target);
    int compared = min_stack.top();
    if (compared<target) min_stack.push(compared);
    else min_stack.push(target);
}

void superPop(stack<int>& main_stack, stack<int>& min_stack){
    main_stack.pop();
    min_stack.pop();
}

int main() {
    srand(time(NULL));
    
    stack<int> main_stack;
    stack<int> min_stack;
    
    construct(main_stack,min_stack,6);
    display(main_stack,min_stack);
    
    superPush(main_stack,min_stack,10);
    superPush(main_stack,min_stack,20);
    display(main_stack,min_stack);
    
    return 0;
}