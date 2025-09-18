#include <iostream>
#include <vector>

using namespace std;

int findpivot(int left, int right, vector<int> &arr)
{
    int pivot = arr[left];
    int count = 0;
    for (int i = left + 1; i <= right; i++)
        if (arr[i] <= pivot)
            count++;
    swap(arr[left + count], arr[left]);

    int i = left;
    int j = right;
    int p = left + count;

    while (i < p && j > p)
    {
        if (arr[i] < arr[p])
        {
            i++;
        }
        else if (arr[j] > arr[p])
        {
            j--;
        }
        else
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return p;
}

void quicksort(int left, int right, vector<int> &arr)
{

    if(left>= right)
    return ;

    int p = findpivot(left, right, arr);
    quicksort(left, p-1, arr);
    quicksort(p+1, right, arr);

}

int main()
{

    vector<int> testarr = {1,2,3,8,2,3,5,1,2};

    quicksort(0, testarr.size()-1, testarr);

    for(auto i: testarr)
     cout << i << " ";
}