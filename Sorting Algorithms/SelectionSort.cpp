#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

// Function for sorting the elements using selection sort
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int imin = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[imin])
            {
                imin = j;
            }
        }
        swap(arr[i],arr[imin]);
    }
}

void printArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

int main()
{

    // Manual input array 
    int arr[] = {3,4,1,8,5,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original Array : ";
    printArr(arr,n);
    selectionSort(arr,n);

    cout<<"Sorted Array : ";
    printArr(arr,n);
    cout<<"----------------------------------------------------------"<<endl;

    //User interaction input array
    int size;
    cout << "Enter the size of the Array : "<<endl;
    cin >> size;

    vector<int> arr1(size);
    
    cout << "Enter the elements of the Array :  "<<endl;
    for(int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }

    cout<<"Given Array : ";
    printArr(arr1.data(), size);

    selectionSort(arr1.data(), size);
    cout<<"Sorted Array : ";
    printArr(arr1.data(), size);
}