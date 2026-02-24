/*count number of pairs whose sum is 11 for 2 unsorted arrays
Brute Force method: check all pairs in both arrays  O(n^2)
Better Method: Take one array sorted and the other as unsorted and apply binary search for upper bound*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr1[n];
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    int arr2[n];
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    sort(arr1, arr1 + n);
    int count = 0;
    for(int i = 0; i < n; i++){
        int target = 11 - arr2[i];
        int low = lower_bound(arr1, arr1 + n, target) - arr1;
        int high = upper_bound(arr1, arr1 + n, target) - arr1;
        count = count+(high - low);
    }
    cout << "Number of pairs = " << count;
    return 0;
}

