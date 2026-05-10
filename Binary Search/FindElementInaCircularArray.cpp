#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int findElementCircularArray(vector<int> &arr, int start, int end, int x)
{
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == x) // Case 1 : mid = element
        {
            return mid;
        }
        
        if(arr[mid] <= arr[end]) // case 3 : right sorted 
        {
            if(x > arr[mid] && x <= arr[end])
                start = mid+1;
            else
                end = mid-1;
        }
        else if(arr[mid] >= arr[start]) // Case 4 : left sorted
        {
            if(x > arr[start] && x <= arr[mid])
                end = mid-1;
            else
                start = mid+1;
        }
    }
    return -1;
}
int main()
{
    std::vector<int> arr{12,14,18,21,3,6,8,9};
    for(int x : arr)
        cout<<x<<" ";

    cout<<endl;

    int index = findElementCircularArray(arr, 0, arr.size()-1, 8);
    cout<<"Element found at index : "<<index<<endl;

}