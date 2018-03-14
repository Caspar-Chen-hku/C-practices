#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

 struct Node{
     int num;
     Node* next;
 };

 Node** construct_graph(int n){
     Node** g = new Node*[n];
     for (int i=0; i<n; i++){
         g[i] = new Node;
         g[i]->num = i+1;
         g[i]->next=NULL;
     }

     Node* current = g[0];
     Node* prev = g[0];

     current = new Node;
     current->num = 2;
     prev->next = current;
     prev = current;

     current = new Node;
     current->num = 3;
     prev->next = current;
     current->next = NULL;

     current = g[1];
     prev = g[1];

     current = new Node;
     current->num = 3;
     prev->next = current;
     prev = current;

     current = new Node;
     current->num = 4;
     prev->next = current;
     current->next = NULL;

     current = g[2];
     prev = g[2];

     current = new Node;
     current->num = 1;
     prev->next = current;
     prev = current;

     current = new Node;
     current->num = 2;
     prev->next = current;
     current->next = NULL;

      current = g[3];
     prev = g[3];

     current = new Node;
     current->num = 2;
     prev->next = current;
     prev = current;
     current->next = NULL;

     return g;
 }

void dfs(int target, Node** graph, bool visited[]){
    cout << target << " ";
    visited[target-1]=true;
    Node* current = graph[target-1];
    while (current->next!=NULL){
        current=current->next;
        if (!visited[current->num -1]){
            dfs(current->num, graph,visited);
        }
    }
}

void bfs(int target, Node** graph){
    bool visit[4];
    for (int i=0; i<4; i++){
        visit[i]=false;
    }
    visit[target-1]=true;
    cout << target << " ";
    queue<int> q;
    q.push(target);
    int temp;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        Node* current = graph[temp-1];

        while (current->next!=NULL){
            current=current->next;
            if (!visit[current->num -1]){
               visit[current->num -1]=true;
               cout << current->num << " ";
               q.push(current->num);
            }
        }
    }
}

void detect_cycle(int target, Node** graph, bool visited[],int parent[]){
    visited[target-1]=true;
    Node* current = graph[target-1];
    while (current->next!=NULL){
        current=current->next;
        if (!visited[current->num -1]){
            parent[current->num-1] = target;
            detect_cycle(current->num, graph,visited,parent);
        }
        else if (visited[current->num-1] && parent[target]!=current->num){
            cout << "cycle exists: " << current->num << "," << target << endl;
            return;
        }
    }
}

   int main()
   {
    Node** graph = construct_graph(4);
    bool visited[4];
    for (int i=0; i<4; i++){
        visited[i]=false;
    }
    dfs(1,graph,visited);
    cout << endl;

    bfs(2,graph);
    cout << endl;

    for (int i=0; i<4; i++){
        visited[i]=false;
    }
    int parent[4];
    for (int i=0; i<4; i++){
        parent[i]=0;
    }

    detect_cycle(3,graph,visited,parent);
    return 0;
    }
