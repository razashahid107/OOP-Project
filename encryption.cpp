#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string encr(string str){
    int code, count = 0;
    vector<int> veccode {};
    vector<char> vecstr {};
    vector<char> vecenc {}; 
    int length = str.size();
    char ch[length +1];
    strcpy(ch, str.c_str());                    // Converting string datatype into character data type

    for (int i = 0; i < length; i++){           // assigning characters to vector characters
        vecstr.push_back(ch[i]);
    }

    for (int i = 0; i < vecstr.size(); i++){    // encoding the vectors and assigning it to the other vector
        code = (int)vecstr[i];
        if (code < 38){
            veccode.push_back('f');
            veccode.push_back('#');             // each and every character ranging from 37 ASCII to 126 is assigned to it 5 less ASCII.
            veccode.push_back('f');
            veccode.push_back(code);            // while below ASCII 37 characters are not changed while set of characters: "f#f" 
            count++;                            // are put behind them to be able to be decrypted
        }
        else
        veccode.push_back(code - 5 );
    }
    for (int i = 0; i < vecstr.size() + count * 3; i++){        // The ASCCI code - 5 is assigned to 
        vecenc.push_back((char)veccode[i]);                     // their respective characters and saved to the vector
    }
    string f_str(vecenc.begin(), vecenc.end());                 // Finally the vector characters are converted to simple string 
    return f_str;                                               // which is then returned.
}