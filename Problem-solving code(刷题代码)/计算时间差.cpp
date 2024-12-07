#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 将时间字符串转换为分钟数
int convertToMinutes(const string& timeStr) 
{
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3, 2));
    return hour * 60 + minute;
}

// 计算两个时间之间的差值，并输出格式化的时间
void calculateTimeDifference(const string& startTime, const string& endTime) 
{
    int startMinutes = convertToMinutes(startTime);
    int endMinutes = convertToMinutes(endTime);

    // 如果结束时间小于开始时间，表示跨越了午夜
    if (endMinutes < startMinutes) 
    {
        endMinutes += 60 * 24;
    }

    int difference = endMinutes - startMinutes;
    int hours = difference / 60;
    int minutes = difference % 60;

    // 输出格式化的结果
    cout << setw(2) << setfill('0') << hours << "h" << setw(2) << minutes << "min" << endl;
}

int main() 
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        string beginTime, endTime;
        cin >> beginTime >> endTime;
        calculateTimeDifference(beginTime, endTime);
    }

    return 0;
}
//示例：
//输入：
//3
//12:00 15 : 00
//18 : 15 23 : 30
//23 : 00 1 : 00
//
//输出：
//03h00min
//05h15min
//02h00min