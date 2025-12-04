#include <iostream>
#include <vector>
using namespace std;

long long slove(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    long long ret = 0;
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else
        {
            arr[k++] = R[j++];
            ret += n1 - i;
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    return ret;
}

long long count_ret(vector<int>& arr, int left, int right)
{
    long long ret = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        ret += count_ret(arr, left, mid);
        ret += count_ret(arr, mid + 1, right);
        ret += slove(arr, left, mid, right);
    }
    return ret;
}

int main()
{
    vector<int> arr = { 3, 1, 4, 5, 2 };
    cout << "逆序对计数: " << count_ret(arr, 0, arr.size() - 1) << endl;
    return 0;
}