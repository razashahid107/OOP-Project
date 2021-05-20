#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class signup{
private:
    string first_name;
    string second_name;
    string Email;
    string Password;
    string con_Password;
    int day_birth;
    int month_birth;
    int year_birth;
    ofstream myfile;
public:
    int back_spaces(int b){
        for (int i = 0; i < b; i++)
        cout << '\b';
    }    
    signup(){
        new_entry();
        fsave();
    }
    
    void new_entry(){
        cout << endl << "First name: ";
        getline(cin, first_name);
        cout << endl << "Second Name: ";
        getline(cin, second_name);
        cout << endl << "Email: ";                                      // Email Authentication to be put here
        getline(cin, Email);
        while (1){
            cout << endl << "Password: ";
            getline(cin, Password);
            cout << endl << "Confirm Password: ";                       // Passsword asterik protection
            getline(cin, con_Password);
            if (Password = con_Password) break;
            else cout << "Wrong choice entered! Please try again";
        }
        cout << endl << "Day of Birth: ";
        cin >> day_birth;
        cout << endl << "Month of Birth: ";
        cin >> month_birth;
        cout << endl << "Year of Birth: ";
        cin >> year_birth;
    }

    	void fsave(){
            myfile.open("credentials.csv");
            myfile << first_name << ',' << second_name << ',' << Email << ',' 
                << Password << ',' << day_birth << ',' << month_birth << ',' 
                <<year_birth;
            myfile.close()
        }

    

};

int main(){
    signup s1;
    return 0;
}