#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int> & arr)
{
    int n = arr.size();
    for(int i = 0; i<n-1; i++)
    {
        bool sorted = true;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                sorted = false;
            }
        }
        if(sorted)
        return;
    }
}

int main()
{

    vector<int> testarr = {4,2,3,7,6};
    cout << "before sorting \n";
    for(auto i: testarr)
    cout << i << " ";

     cout << "\nAfter sorting \n";
     
    bubblesort(testarr);
    for(auto i: testarr)
     cout << i << " ";

}