#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

/** ������������������ʵ����ĿҪ��Ĺ��� **/
 /** ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^  **/
int minCost(vector< vector<int> >& costs)
{
/**costsΪͼ����ÿһ��������Ҫ�Ļ���**/
/**��������ֻ�豣֤���ڷ�����ɫ��һ��������ֻ���ҳ�cost��С��������ɫ��������ͼ��ɫ����**/

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
