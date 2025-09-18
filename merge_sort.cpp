#include<iostream>
#include<vector>

using namespace std;


void mergetwosortedarrays(int left , int mid , int right , vector<int> & arr, vector<int> & temp)
{
    int i = left;
    int j = mid+1;
    int ptr = left;
    while(i<= mid && j <= right)
        if(arr[i] <= arr[j])
         temp[ptr++] = arr[i++];
        else 
        temp[ptr++] = arr[j++]; 
    while(i<= mid)
     temp[ptr++] = arr[i++];
    while(j<=right)
    temp[ptr++] = arr[j++];

    for(int k = left; k<= right; k++)
     arr[k] = temp[k];
}

void mergesort(int left , int right , vector<int> & arr,vector<int> & temp)
{
    if(left >= right)
    return;

    int mid = (left+right)/2;

    mergesort(left ,mid, arr,temp);
    mergesort(mid+1, right, arr,temp);

    mergetwosortedarrays(left, mid, right, arr,temp);
}


int main()
{

   vector<int> first = {0,1,2,3,4,5,3,4,5,6,7,9};
   vector<int> temp(first.size()); // buffer array to save space


  mergesort(0,first.size()-1, first, temp);

  for(auto i: first)
   cout << i <<  " ";


}