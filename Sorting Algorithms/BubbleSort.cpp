#include<stdio.h>
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i]<<' ';
    cout << endl;
}

int main()
{
    int arr[] = {3,1,7,8,9,2,5,6,4,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Orginal array : ";
    printArr(arr,n);
    bubbleSort(arr, n);
    cout << "Sorted array : ";
    printArr(arr, n);

}