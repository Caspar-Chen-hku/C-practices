#include <iostream>
#include <string>
#include <vector>
using namespace std;
//J:11, Q:12, K:13, A:14, 2:15, joker: 16, JOKER: 17

vector<int> vectorize(string s){
    vector<int> result;
    for (int i=0; i<s.length(); i++){
        if (s[i]==' ') continue;
        else if (s[i]>='3'&&s[i]<='9')  result.push_back(s[i]-'0');
        else if (s[i]=='1') result.push_back(10);
        else if (s[i]=='j') {
                result.push_back(16);
                i+=5;
        }
        else if (s[i]=='J'&&s[i+1]=='O') {
                result.push_back(17);
                i+=5;
        }
        else if (s[i]=='2') result.push_back(15);
        else if(s[i]=='A') result.push_back(14);
        else if(s[i]=='K') result.push_back(13);
        else if(s[i]=='Q') result.push_back(12);
        else if(s[i]=='J') result.push_back(11);
    }
    return result;
}

string which(string s1, string s2){
    //cout << s1 << endl;
    //cout << s2 << endl;
    vector<int> v1 = vectorize(s1);
    vector<int> v2 = vectorize(s2);
    int len1 = v1.size();
    int len2 = v2.size();
    /*cout << "v1: ";
    for (int i=0; i<len1; i++){
        cout << v1[i] << ' ';
    }
    cout << "\nv2: ";
    for (int i=0; i<len2; i++){
        cout << v2[i] << ' ';
    }*/
    if (len1==len2){
        if (v1[0]>v2[0]){
            return s1;
        }
        else return s2;
    }
    if (len1==4){
        if (len2==2&&v2[0]==16) return s2;
        else return s1;
    }else if (len2==4){
        if (len1==2&&v1[0]==16) return s1;
        else return s2;
    }else if (len1==2&&v1[0]==16){
        return s1;
    }else if (len2==2&&v2[0]==16){
        return s2;
    }else return "ERROR";
}
int main(){
    string cards;
    getline(cin,cards);
    int index = cards.find("-");
    string cards1 = cards.substr(0,index);
    string cards2 = cards.substr(index+1);
    cout << which(cards1,cards2) << endl;
    return 0;
}
