#include <iostream>
#include <cmath>
using namespace std;

class Time
{
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int seconds, int minutes, int hours) : hours(hours), minutes(minutes), seconds(seconds)
    {
        this->seconds = (seconds > 0 && seconds < 60) ? seconds : 0;
        this->minutes = (minutes > 0 && minutes < 60) ? minutes : 0;
        this->hours = (hours > 0 && hours < 24) ? hours : 0;
    }

    Time(int minutes, int hours)
    {
        this->minutes = (minutes > 0 && minutes < 60) ? minutes : 0;
        this->hours = (hours > 0 && hours < 24) ? hours : 0;
    }

    void setHours(const int &hours)
    {
        this->hours = (hours > 0 && hours < 24) ? hours : 0;
    }

    void setMinutes(const int &minutes)
    {
        this->minutes = (minutes > 0 && minutes < 60) ? minutes : 0;
    }

    void setSeconds(const int &seconds)
    {
        this->seconds = (seconds > 0 && seconds < 60) ? seconds : 0;
    }

    int getHours() const
    {
        return this->hours;
    }

    int getMinutes() const
    {
        return this->minutes;
    }

    int getSeconds() const
    {
        return this->seconds;
    }

    Time operator++() // pre increment
    {
        if (this->seconds == 59)
        {
            this->seconds = 0;
            if (this->minutes == 59)
            {
                this->minutes = 0;
                if (this->hours == 23)
                {
                    this->hours = 00;
                }
                else
                {
                    ++(this->hours);
                }
            }
            else
            {
                ++(this->minutes);
            }
        }
        else
        {
            ++(this->seconds);
        }

        return *this;
    }

    Time operator--() // pre decrement
    {
        if (this->seconds == 00)
        {
            this->seconds = 59;
            if (this->minutes == 00)
            {
                this->minutes = 59;
                if (this->hours == 00)
                {
                    this->hours = 23;
                }
                else
                {
                    --(this->hours);
                }
            }
            else
            {
                --(this->minutes);
            }
        }
        else
        {
            --(this->seconds);
        }

        return *this;
    }

    Time operator++(int) // post increment
    {
        Time oldState(*this);

        if (this->seconds == 59)
        {
            this->seconds = 0;
            if (this->minutes == 59)
            {
                this->minutes = 0;
                if (this->hours == 23)
                {
                    this->hours = 00;
                }
                else
                {
                    ++(this->hours);
                }
            }
            else
            {
                ++(this->minutes);
            }
        }
        else
        {
            ++(this->seconds);
        }

        return oldState;
    }

    Time operator--(int) // post decrement
    {
        Time oldState(*this);

        if (this->seconds == 00)
        {
            this->seconds = 59;
            if (this->minutes == 00)
            {
                this->minutes = 59;
                if (this->hours == 00)
                {
                    this->hours = 23;
                }
                else
                {
                    --(this->hours);
                }
            }
            else
            {
                --(this->minutes);
            }
        }
        else
        {
            --(this->seconds);
        }

        return oldState;
    }

    int operator- (const Time& obj) const
    {
        int noOfSeconds = 0;

        noOfSeconds = noOfSeconds + 3600 * abs(this -> hours - obj.hours);

        noOfSeconds = noOfSeconds + 60 * abs(this -> minutes - obj.minutes);

        noOfSeconds = abs (noOfSeconds - abs (this -> seconds - obj.seconds));

        return noOfSeconds;
    }

    bool operator+ () const
    {
        if (this -> hours >= 9 && this -> hours <= 17)
        {
            return true;
        }
        return false;
    }

    friend ostream &operator<<(ostream &, const Time &);

    friend istream &operator>>(istream &, Time &);
};

ostream &operator<<(ostream &output, const Time &obj)
{
    output << obj.hours << ":" << obj.minutes << ":" << obj.seconds << endl;
    return output;
}

istream &operator>>(istream &input, Time &obj)
{
    cout << "Enter hours: ";
    input >> obj.hours;
    
    if (obj.hours >= 23 || obj.hours < 0)
    {
        obj.hours = 0;
    }

    cout << "Enter minutes: ";
    input >> obj.minutes;

    if (obj.minutes >= 60 || obj.minutes < 0)
    {
        obj.minutes = 0;
    }

    cout << "Enter seconds: ";
    input >> obj.seconds;

    if (obj.seconds >= 60 || obj.seconds < 0)
    {
        obj.seconds = 0;
    }

    return input;
}

int main()
{
    Time o2(45, 13, 17);

    // cin >> o1;

    // cout << o1 << endl;

    // cout << o2 << endl;

    // // cout << o1++;

    // // cout << --o1;

    // // cout << o2 - o1 << endl;

    if (o2.operator+ ())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}