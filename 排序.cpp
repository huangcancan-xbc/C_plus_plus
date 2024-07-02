#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // 外层循环控制遍历的轮数
    for (int i = 0; i < n - 1; i++) {
        // 内层循环负责每一轮中的元素比较和交换
        for (int j = 0; j < n - 1 - i; j++) { // 注意：n-1-i是因为每轮结束后最大的元素已经排好序了
            // 如果前一个元素大于后一个元素，则交换它们
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // C++标准库提供的交换函数
            }
        }
    }
}

// 用于打印数组的辅助函数
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 主函数来测试冒泡排序
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "原始数组: \n";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "排序后的数组: \n";
    printArray(arr, n);
    return 0;
}