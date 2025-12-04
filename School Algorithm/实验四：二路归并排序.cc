#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void Sort(vector<int>& arr, int left, int right) 
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        Sort(arr, left, mid);
        Sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6 };
    Sort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    return 0;
}