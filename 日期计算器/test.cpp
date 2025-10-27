#include "test.h"

class Date
{
private:
    int year, month, day;

    static const int Days_per_month[13];

    // 判断是否为合法日期
    static bool is_valid_date(int y, int m, int d)
    {
        if((y < 999 || y > 9999) || (m < 1 || m > 12) || (d < 1 || d > get_month(y, m)))
        {
            return false;
        }

        return true;
    }

    // 判断是否为闰年
    static bool is_leap_year(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    // 获取每月的天数
    static int get_month(int year, int month)
    {
        if(month == 2)
        {
            return is_leap_year(year)? 29 : 28;
        }

        return Days_per_month[month];
    }
    
    // 判断两个日期的“大小”
    static bool compare_dates(const Date& d1, const Date& d2)
    {
        if(d1.year < d2.year)
        {
            return true;
        }
        else if(d1.year > d2.year)
        {
            return false;
        }
        else
        {
            if(d1.month < d2.month)
            {
                return true;
            }
            else if(d1.month > d2.month)
            {
                return false;
            }
            else
            {
                if(d1.day < d2.day)
                {
                    return true;
                }
                else if(d1.day > d2.day)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }

        return false;                               // 理论上不会走到这里
    }

    // 日期转为天数
    int to_days() const
    {
        int total = 0;

        for(int y = 1; y < year; ++y)
        {
            total += is_leap_year(y) ? 366 : 365;
        }

        for(int m = 1; m < month; ++m)
        {
            total += get_month(year, m);
        }

        total += day;

        return total;
    }

public:
    // 构造函数
    Date(int y, int m, int d)
    {
        if(!is_valid_date(y, m, d))
        {
            cout << "日期不合法！" << endl;
            return;
        }

        year = y;
        month = m;
        day = d;
    }

    void print()
    {
        cout << year << "-" << month << "-" << day << endl;
    }

    // 日期加法：推算 X 天后的日期
    void add_days(int x)
    {
        day += x;                                   // 当前日期加上 x 天
        while(day > get_month(year, month))         // 如果当前日期大于该月的天数，则减去该月的天数，并加上月份和年份
        {
            day -= get_month(year, month);
            month++;

            if(month > 12)
            {
                year++;
                month = 1;
            }
        }
    }

    // 日期减法：推算 X 天前的日期
    void sub_days(int x)
    {
        day -= x;
        while(day < 1)
        {
            day += get_month(year, month);
            month--;

            if(month < 1)
            {
                year--;
                month = 12;
            }
        }
    }

    // 日期之差：计算两个日期之间的天数
    int date_difference(const Date& other) const
    {
        return abs(this->to_days() - other.to_days());
    }

};

const int Date::Days_per_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    Date d1(2024, 6, 18);
    Date d2(2025, 1, 1);

    cout << "日期 d1："; d1.print();
    cout << "日期 d2："; d2.print();

    d2.add_days(100);
    cout << "日期 d2 加 100 天后："; d2.print();
    d2.sub_days(1150);
    cout << "日期 d2 减 1150 天后："; d2.print();

    cout << "日期 d1："; d1.print();
    cout << "日期 d2："; d2.print();

    cout << "两个日期相差天数：" << d1.date_difference(d2) << " 天" << endl;

    return 0;
}
