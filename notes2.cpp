#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
using namespace std;

// notes

class Login
{
public:
    string email, password;
    char pass;
    int npass, char_count = 0;
    vector<char> temp {};
public:
    // we can have a contructor for the login
    Login(){
        cout << "Please enter your login credentials: " << endl;
        setEmail();
        setPassword();
    }
    // setters and getters
    void setEmail()
    {
        cout << endl
             << "E-Mail: ";
        cin >> email;
    }
    void setPassword(){
        cout << "Enter Password: ";
        for (int i=0 ; ;){
            pass = getch();
            npass = (int)pass;
            if (npass >= 20 && npass <= 126 && char_count <= 15){       //displays asterik instead of characters to maintain privacy
                temp.push_back(pass);
                char_count++;
                cout << '*'; 
            }
            else if (char_count > 15){
                cout << "Maximum Limit reached!\n";                     // Checks for maximunm limit
                break;
            }
            else if (npass == 8 && char_count != 0){
                cout << '\b' << " " << '\b';                            // Makes sure that user can use backspace and backspace do work
                temp.pop_back();
                char_count--;
            }
            else if (char_count == 0)                                   // stops to erase the characters already printed
                continue;
            else
            {
                cout << endl;
                break;
            }
        }
    }
    string getEmail()
    {
        return email;
    }
    string getPassword()
    {
        for (int i=0; i<=temp.size(); i++){
            std::cout << temp[i];
        }
    }

    // Adding a friend function to allow it to save the notes in an array
    friend void SaveNote();
};

class Note : public Login
{
    // date and time for note creation
public:
    string note_data;
    string note_title;
public:
    Note(){
        char choice_input_char;
        int choice_input_int;
        cout << "Do you want to create a new note? If yes then press y otherwise press n" << endl << "\t=> ";
        cin >> choice_input_char;
        if (choice_input_char == 'y') { AddNote(); }
        else if (choice_input_char == 'n') { 
            cout << "What do you want to do?" << endl; 
            cout << "\t1. Edit a previous note" << endl;
            cout << "\t2. Delete a previous note" ;
            cout << endl;
            cin >> choice_input_int;
            if (choice_input_int == 1) {
                EditNote();
            }
            else if (choice_input_int == 2){
                DelNote();
            }
        }
    }
    void AddNote() {
        int int_choice;
        // set note title
        cout << "Do you want to have a title" << endl << "\t1. Yes" << endl << "\t0. No\t" << "=> ";
        cin >> int_choice;
        
        while (true) {    
            if (int_choice == 1){
                setNote_Title();
                break;
            }
            else if (int_choice == 0) {
                break;
            }
            cout << "Wrong input. Try again :)";
            cin >> int_choice;
        }
        // since the while loop will break anyways, we'll now get to setting the data of the note
        setData();
        SaveNote(*this);

    }
    void setNote_Title() {   
        cout << "Title: ";
        cin >> note_title;        
    }
    string getNote_Title(){
        return note_title;
    }
    void setData(){
        cout << "Enter your Text: " << endl;
        cin >> note_data;
    }
    string getData(){
        return note_data;
    }

    void DelNote() {}
    void EditNote() {}

    // Adding a friend function to allow it to save the notes in an array
    friend void SaveNote(Note obj1);
};

// This is a friend function which adds an individual note to the dynamic array set_of_notes
void SaveNote(Note obj){
    vector<string> set_of_notes{};
    string temp_note;
    temp_note = obj.getData();
    set_of_notes.push_back(temp_note);
    // cout << "This is save note wala";
}

int main()
{
    // you will first need to login
    // I'll assume that the man is registerd
    Note person1;
    cout << endl;
}