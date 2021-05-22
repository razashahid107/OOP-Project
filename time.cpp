#include<iostream>
#include<ctime>
using namespace std;
class TimeStamp{
private:
    time_t now = time(0);
    tm t_now =  *localtime(&now);
    string weekdays[7] {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};
    string month_name[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    string hour(){
        cout << t_now.tm_hour;              // Invoking hour
    }
    string minute(){
        cout << t_now.tm_min;               // Invoking minute
    }
    string sec(){
        cout << t_now.tm_sec;               //Invoking seconds
    }
    string day(){
        cout << t_now.tm_mday;              // Invoking day
    }
    string month(){
        cout << month_name[t_now.tm_mon];   // Invoking month
    }
    string year(){
        cout << 1900 + t_now.tm_year;       // Invoking Year
    }
    string week_day_alphabet(){
        cout << weekdays[t_now.tm_wday];    // Invoking day of week in alphabets
    }
    string week_day_digit(){
        cout << t_now.tm_wday;              // Invoking day of week in digits
    }
    void timestamp(){
        cout << ctime(&now);
    }
};

void put_time(const string s){
    TimeStamp t1;
    if (s == "wda")       t1.week_day_alphabet();
    else if (s == "wdd")  t1.week_day_digit();
    else if (s == "hh")   t1.hour();
    else if (s == "mm")   t1.minute();
    else if (s == "ss")   t1.sec();
    else if (s == "wd")   t1.day();
    else if (s == "mo")   t1.month();
    else if (s == "yy")   t1.year();
    else if (s == "date") t1.timestamp();
}

int main(){
    string s = "mo";
    put_time(s);
}