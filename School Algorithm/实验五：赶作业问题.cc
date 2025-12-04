#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Homework
{
    int deadline;
    int score;
};

bool cmp(Homework a, Homework b)
{
    if (a.score != b.score) return a.score > b.score;
    return a.deadline < b.deadline;
}

int main()
{
    vector<Homework> hw = { {1,6}, {3,2}, {1,3} };
    sort(hw.begin(), hw.end(), cmp);
    int day = 1, total = 0;
    for (auto h : hw)
    {
        if (day > h.deadline) total += h.score;
        day++;
    }
    cout << total << endl;
    return 0;
}