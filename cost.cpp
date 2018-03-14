#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

/** 请完成下面这个函数，实现题目要求的功能 **/
 /** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int minCost(vector< vector<int> >& costs)
{
/**costs为图画中每一个方块需要的花销**/
/**由于我们只需保证相邻方块颜色不一样，我们只需找出cost最小的两种颜色，给整张图上色即可**/

int min = costs[0][0];
int outersize = costs.size();
int innersize = costs[0].size();

for (int i=0; i<outersize; i++){
    for (int j=0; j<innersize; j++){
        if (costs[i][j]<min){
            min = costs[i][j];
        }
    }
}

int secondmin=-1;
bool finish = false;

for (int i=0; i<outersize&&!finish; i++){
    for (int j=0; j<innersize&&!finish; j++){
        if (costs[i][j]!=min){
            secondmin = costs[i][j];
            finish=true;
        }
    }
}

if (secondmin==-1){
    cout << "the costs vector is invalid" << endl;
    return -1;
}

for (int i=0; i<outersize; i++){
    for (int j=0; j<innersize; j++){
        if (costs[i][j]!=min&&costs[i][j]<secondmin){
            secondmin = costs[i][j];
        }
    }
}

if (outersize*innersize%2==0){
return (min+secondmin)*outersize*innersize/2;
}
else {
return min*outersize*innersize/2 + secondmin*(outersize*innersize/2+1);
}
}

int main()
{
	int N,K;
	int cost;
	vector<vector<int> > costs;
	string s;
	istringstream is;

	getline(cin, s);
	is.str(s);
	is>>N>>K;
	for(int i =0 ; i < N; i++)
	{
		vector<int> t;
		getline(cin, s);
		is.clear();
		is.str(s);
		for(int j = 0; j < K; j++) {
			is >> cost;
			t.push_back(cost);
		}
		costs.push_back(t);
	}
	cout<<minCost(costs)<<endl;
	return 0;
}
