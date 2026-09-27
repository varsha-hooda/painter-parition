#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int>& arr, int n, int k, int maxTime)
{
    int painter = 1;
    int time = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxTime)
            return false;

        if(time + arr[i] <= maxTime)
        {
            time += arr[i];
        }
        else
        {
            painter++;
            time = arr[i];
        }
    }

    return painter <= k;
}

int painterPartition(vector<int>& arr, int n, int k)
{
    // Painters boards se zyada hain
    if(k > n)
        return -1;

    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = -1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;

        if(isValid(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {40,30,10,20};

    int n = 4;
    int k = 2;

    cout << painterPartition(arr, n, k) << endl;

    return 0;
}