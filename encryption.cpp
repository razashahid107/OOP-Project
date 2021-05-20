#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string encr(string str){
    int code, count = 0;
    vector<int> veccode {};
    int length = str.size();
    char ch[length +1];
    vector<char> vecstr {};
    vector<char> vecenc {}; 
    strcpy(ch, str.c_str());

    for (int i = 0; i < length; i++){
        vecstr.push_back(ch[i]);
    }

    for (int i = 0; i < vecstr.size(); i++){
        code = (int)vecstr[i];
        if (code < 38){
            veccode.push_back('f');
            veccode.push_back('#');
            veccode.push_back('f');
            veccode.push_back(code);
            count++;
        }
        else
        veccode.push_back(code - 5 );
    }
    for (int i = 0; i < vecstr.size() + count * 3; i++){
        vecenc.push_back((char)veccode[i]);
    }
    string f_str(vecenc.begin(), vecenc.end());
    return f_str;

}