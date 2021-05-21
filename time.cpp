#include<iostream>
#include<ctime>
using namespace std;
class time_stamp{
private:
    time_t now = time(0);
    tm t_now =  *localtime(&now);
    string weekdays[7] {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};
    string month_name[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    string hour(){
        cout << t_now.tm_hour;
    }
    string minute(){
        cout << t_now.tm_min;
    }
    string sec(){
        cout << t_now.tm_sec;
    }
    string day(){
        cout << t_now.tm_mday;
    }
    string month(){
        cout << month_name[t_now.tm_mon];
    }
    string year(){
        cout << 1900 + t_now.tm_year;
    }
    string week_day(){
        cout << weekdays[t_now.tm_wday];
    }
    void timestamp(){
        cout << ctime(&now);
    }

    //friend void put_time(const string s);    
};

void put_time(const string s){
    time_stamp t1;
    if (s == "wd")        t1.week_day();
    else if (s == "hh")   t1.hour();
    else if (s == "mm")   t1.minute();
    else if (s == "ss")   t1.sec();
    else if (s == "wd")   t1.day();
    else if (s == "mo")   t1.month();
    else if (s == "yy")   t1.year();
}

int main(){
    string s = "mo";
    put_time(s);
}