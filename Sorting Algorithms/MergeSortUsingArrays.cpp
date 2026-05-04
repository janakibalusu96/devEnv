#include<stdio.h>
#include<iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void merge(int arr[], int n, int left[], int ln, int right[], int rn)
{
    int i{0}, j{0}, k{0};
    while(i<ln && j<rn)
    {
        if(left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < ln)
    {
        arr[k] = left[i];
        i++;
        k++; 
    }
    while (j < rn)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    if(n < 2)
        return;

    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for(int i = 0; i < mid; i++)
        left[i] = arr[i];

    for(int i = mid; i < n; i++)
        right[i-mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, n-mid);
    merge(arr, n, left, mid, right, n-mid);
}

int main()
{

    // Manual input array 
    int arr[] = {3,4,1,8,5,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original Array : ";
    printArr(arr,n);
    mergeSort(arr,n);

    cout<<"Sorted Array : ";
    printArr(arr,n);
}