#include <iostream>
#include <vector>
using namespace std;

// 用于合并两个有序子数组的函数
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左子数组的长度
    int n2 = right - mid;    // 右子数组的长度

    // 创建临时数组储存左子数组和右子数组
    vector<int> leftArr(n1), rightArr(n2);

    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // 归并两个临时数组至原数组
    int i = 0;    // 左子数组的初始索引
    int j = 0;    // 右子数组的初始索引
    int k = left; // 合并后数组的初始索引

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    } // 此时必有一个数组的内容没有输入完全！

    // 将左数组中剩余元素拷贝至原数组中
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// 归并排序函数，使用递归
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // 找到中心点
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并两部分
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 执行排序
    mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr)
        cout << num << " ";

    return 0;
}
// 归并排序