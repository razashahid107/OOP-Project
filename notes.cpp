#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// ntoes

class Person
{
private:
    int user_ID;
    string password;

public:
    void AddMember();
    void DelMember();
    void EditMember();

    // constructor
};
class Note
{
    // date and time for note creation
private:
    string note_data;

public:
    void AddNote();
    void DelNote();
    void EditNote();
};
class Login
{
private:
    string email, password;

public:
    // we can have a contructor for the login
    // setters and getters
    void setEmail()
    {
        cout << endl
             << "E-Mail: ";
        cin >> email;
    }
    void setPassword()
    {
        cout << endl
             << "Password: ";
        cin >> password;
    }
    string getEmail()
    {
        return email;
    }
    string getPassword()
    {
        return password;
    }

    void check_2()
    {
        bool valid = false;
        while (valid = false)
        {
            // Read from tha array
            

            // Extracting Email and Password to Compare them
            
            // email
            string user_email;
           
            // password
            
            // use the user_email, user_password to compare them to the attributes email and password

            // comparing email
            if (((email.compare(user_email)) && (password.compare(user_password))) == 0)
            {
                valid = true;
                break;
            }
        }
    }
    void check()
    {
        bool valid = false;
        while (valid = false)
        {
            // Read from the text file
            fstream MyReadFile("data.txt");

            // Use a while loop together with the getline() function to read the file line by line
            string myText;
            while (getline(MyReadFile, myText))
            {
                // this saves the line of text in myText
            }

            // Extracting Email and Password to Compare them
            int count = 0;
            // email
            string user_email;
            while (1)
            {
                if (myText[count] != ',')
                {
                    user_email[count] = myText[count];
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }
            // password
            string user_password;
            while (1)
            {
                if (myText[count] != ',')
                {
                    user_password[count] = myText[count];
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }

            // use the user_email, user_password to compare them to the attributes email and password

            // comparing email
            if (((email.compare(user_email)) && (password.compare(user_password))) == 0)
            {
                valid = true;
                break;
            }
        }
    }
};

int main()
{
    ofstream MyFile("data.txt");
    // you will first need to login
    // I'll assume that the man is registerd
    Login person1;
    cout << "Please enter your login creditials ";
    person1.setEmail();
    person1.setPassword();
    person1.check();
    // Close the file
    MyFile.close();
}