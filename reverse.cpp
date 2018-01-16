#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
   string inputSentence;
   getline(cin,inputSentence);
   stringstream text;
   string word;
   text << inputSentence;
   string final = "";
   char temp;
   while (text >> word)
   {
        int lth = word.length();
        for (int i=1; i<lth/2; i++){
            temp = word[i];
            word[i] = word[lth-1-i];
            word[lth-1-i] = temp;
        }
        final = final + word + " ";
    }
    int llth = final.length();
    final = final.erase(llth-1,1);
    cout << final;
    return 0;}