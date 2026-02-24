#include <vector>
#include <iostream>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int ans = n;  

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= target) {
            ans = mid;    
            end = mid - 1;  
        } else {
            start = mid + 1;   
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6, 8};
    int target = 4;

    int result = lowerBound(arr, target);
    cout << "Lower bound index for " << target << " is: " << result << endl;

    return 0;
}