#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    // ���ѭ�����Ʊ���������
    for (int i = 0; i < n - 1; i++) {
        // �ڲ�ѭ������ÿһ���е�Ԫ�رȽϺͽ���
        for (int j = 0; j < n - 1 - i; j++) { // ע�⣺n-1-i����Ϊÿ�ֽ���������Ԫ���Ѿ��ź�����
            // ���ǰһ��Ԫ�ش��ں�һ��Ԫ�أ��򽻻�����
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // C++��׼���ṩ�Ľ�������
            }
        }
    }
}

// ���ڴ�ӡ����ĸ�������
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// ������������ð������
int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "ԭʼ����: \n";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "����������: \n";
    printArray(arr, n);
    return 0;
}