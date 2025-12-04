#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Sort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        Sort(arr, low, pi - 1);
        Sort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6 };
    Sort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}