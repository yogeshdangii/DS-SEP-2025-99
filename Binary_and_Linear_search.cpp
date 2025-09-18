#include<iostream>
#include<vector>

using namespace std;

int linear_search(vector<int> & arr , int target)
{
    for(int i = 0; i< arr.size(); i++)
     if(arr[i] == target)
     return i;
    return -1;
}

int binary_search(vector<int> & arr, int target)
{
    int left= 0;
    int right = arr.size()-1;

    while(left <= right)
    {
        int mid = (left+right)/2;
        if(arr[mid] == target)
         return mid;
         if(arr[mid] > target)
          right = mid-1;
        else
         left = mid+1;
    }
    return -1;
}

int main(){

    vector<int> arr = {1,2,4,6,8,9,11,12,15,40,95};
    cout << " -1 indicates the element is not present in the array \n " ;


     cout << "Searching 15's index in the array using binary search ->" << binary_search(arr, 15) << endl;
     cout << "Searching 15's index in the array using linear search ->" << linear_search(arr, 15) << endl;

}