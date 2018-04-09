#include <iostream>
#include <string>
using namespace std;

struct element
{
     unsigned int elementLength;    //表示uiElementValue占用BIT数，范围1~32
     unsigned int elementValue;     //从字节流中按顺序解析的数值，用于输出
};

string character_change(char s){
    switch(s){
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'a': return "1010";
        case 'b': return "1011";
        case 'c': return "1100";
        case 'd': return "1101";
        case 'e': return "1110";
        case 'f': return "1111";
    }
    return "";
}

string hex_to_binary(string s){
    s = s.substr(2);
    string result = "";
    int len = s.length();
    for (int i=0; i<len; i++){
        result += character_change(s[i]);
    }
    return result;
}

int binary_to_decimal(int n){
    int b = 1;
    int result = 0;
    while (n>0){
        result += (n%10)*b;
        b *= 2;
        n /= 10;
    }
    return result;
}

void Decode(int len, string* input, int elementNum, element* elem){
    string result = "";
    for (int i=0; i<len; i++){
        result += hex_to_binary(input[i]);
    }
    int index = 0;
    int temp;
    string hold;
    for (int i=0; i<elementNum; i++){
        hold = result.substr(index,elem[i].elementLength);
        temp = binary_to_decimal(atoi(hold.c_str()));
        elem[i].elementValue = temp;
        index += elem[i].elementLength;
    }
}

int main(){
    int len,elementNum;
    cin >> len;
    string* input = new string[len];
    for (int i=0; i<len; i++){
        cin >> input[i];
    }
    cin >> elementNum;
    element* elem = new element[elementNum];
    for (int i=0; i<elementNum; i++){
        cin >> elem[i].elementLength;
    }
    Decode(len, input, elementNum,elem);
    for (int i=0; i<elementNum; i++){
        cout << elem[i].elementValue << endl;
    }
    delete[] input;
    delete[] elem;
    return 0;
}
