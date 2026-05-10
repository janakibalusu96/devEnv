#include<stdio.h>
#include<iostream>

using namespace std;

int binarySearchUsingRecursion(vector<int> &arr, int start, int end, int x)
{
    if(start > end)
        return -1;

    int mid = start + (end - start)/2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] > x){
        return binarySearchUsingRecursion(arr, start, mid-1, x);
    }
    else {
        return binarySearchUsingRecursion(arr, mid+1, end, x);
    }
}
int main()
{
    vector<int> arr {3,1,2,5,7,4,8};
    std::sort(arr.begin(), arr.end());
    std::cout<<"Sorted Array : ";
    for(int x:arr) {
        cout<<x<<" ";
    }
    std::cout<<endl;
    int x{0};
    cout<<" Enter the element to search in a List " <<endl;
    std::cin>>x;
    int index = binarySearchUsingRecursion(arr, 0, arr.size()-1, x);
    cout<<" Element found at index : "<<index<<endl;

}