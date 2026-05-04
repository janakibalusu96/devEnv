#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while( i <= mid) {
        temp[k++] = arr[i++];
    }
    while ( j <= right) {
        temp[k++] = arr[j++];
    }

    for( int x = left; x <= right; x++)
        arr[x] = temp[x];
}

void mergeSort(vector<int> &arr, vector<int>&temp, int left, int right)
{
    if(left >= right) return; // breaks the recursion loop

    int mid = (left+right)/2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid+1, right);

    if(arr[mid]<= arr[mid+1]) return; // already sorted 
    merge(arr, temp, left, mid, right);

}
int main()
{
    vector<int> arr {5,2,1,7,6,3,9};
    vector<int> temp(arr.size());

    std::cout<<"Before Merge sorting : ";
    for(int i:arr) cout<<i<<"  ";
    cout<<endl;

    mergeSort(arr, temp, 0, arr.size()-1);
    std::cout<<"After sorting : ";
    for(int i:arr) cout<<i<<"  ";
    cout<<endl;


}
