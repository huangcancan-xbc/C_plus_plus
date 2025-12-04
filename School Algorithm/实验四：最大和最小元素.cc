#include <iostream>
#include <vector>
using namespace std;
pair<int, int> find(vector<int>& arr, int left, int right)
{
    if (left == right) return { arr[left], arr[left] };
    if (right == left + 1)
    {
        if (arr[left] < arr[right]) return { arr[left], arr[right] };
        else return { arr[right], arr[left] };
    }
    int mid = left + (right - left) / 2;
    auto leftMinMax = find(arr, left, mid);
    auto rightMinMax = find(arr, mid + 1, right);
    int minVal = min(leftMinMax.first, rightMinMax.first);
    int maxVal = max(leftMinMax.second, rightMinMax.second);
    return { minVal, maxVal };
}

int main()
{
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6 };
    auto result = find(arr, 0, arr.size() - 1);
    cout << "Min: " << result.first << ", Max: " << result.second << endl;
    return 0;
}