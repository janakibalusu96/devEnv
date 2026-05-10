#include<stdio.h>
#include<iostream>

using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int x, bool firstOccurance)
{
    int result {-1};
    if(start > end)
        return result;

    int mid = start + (end - start)/2;
    if(arr[mid] == x) {
        result = mid;
        if(firstOccurance){
            int left_result = binarySearch(arr, start, mid-1, x, firstOccurance);
            if(left_result != -1)
                result = left_result;
        }
        else
        {
            int right_result = binarySearch(arr, mid+1, end, x, firstOccurance);
            if(right_result != -1)
                result = right_result;
        }
    }
    else if (x < arr[mid])
    {
        return binarySearch(arr, start, mid-1, x, firstOccurance);
    }
    else
    {
        return binarySearch(arr, mid+1, end, x, firstOccurance);
    }
    return result;
}
int main()
{
    vector<int> arr {3,1,2,5,7,4,8,3,3,3,3};
    std::sort(arr.begin(), arr.end());
    std::cout<<"Sorted Array : ";
    for(int x:arr) {
        cout<<x<<" ";
    }
    std::cout<<endl;
    int x{0};
    cout<<" Enter the element to search in a List " <<endl;
    std::cin>>x;
    int firstOccurance = binarySearch(arr, 0, arr.size()-1, x, 1);
    cout<<" First Occurance at index : "<<firstOccurance<<endl;

    int lastOccurance = binarySearch(arr, 0, arr.size()-1, x, 0);
    cout<<" Last Occurance at index : "<<lastOccurance<<endl;

    int Count = lastOccurance - firstOccurance +1;
    cout<<" Count of an Element "<<x<<" : "<<Count<<endl;

}