#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,m;
    cout << "Enter the configuration of the space: ";
    cin >> n >> m;
    int coord[4][2];
    cout << "Enter the positions of 3 weapons as well as the enemy: ";
    for (int i=0; i<4; i++){
        cin >> coord[i][0] >> coord[i][1];
    }
    int damage = 0;
    double distance;
    int maxdistance;
    cout << "Enter the maximum distance that is able to cause damage: ";
    cin >> maxdistance;
    for (int i=0; i<3; i++){
            distance = pow((coord[i][0]-coord[3][0]),2) + pow((coord[i][1]-coord[3][1]),2);
        if (sqrt(distance)<maxdistance) damage++;
    }
    cout << "Damage: " << damage << endl;


return 0;}
