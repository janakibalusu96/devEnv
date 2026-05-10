#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int findRotationCount(vector<int> &arr, int start, int end)
{
    int n = arr.size();
    while(start <= end)
    {
        if(arr[start] <= arr[end]) // Case 1 : Sorted array 
        {
            return start;
        }
        int mid = (start + end)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;

        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) // case 2 : minimum element in an array
            return mid;
        else if(arr[mid] <= arr[end]) // case 3 : right sorted 
            end = mid-1;
        else if(arr[mid] >= arr[start]) // Case 4 : left sorted
            start = mid+1;
    }
    return -1;
}
int main()
{
    std::vector<int> arr{2,3,5,8,11};
    for(int x : arr)
        cout<<x<<" ";

    cout<<endl;

    int count = findRotationCount(arr, 0, arr.size()-1);
    cout<<"Rotation count of an array : "<<count<<endl;

}