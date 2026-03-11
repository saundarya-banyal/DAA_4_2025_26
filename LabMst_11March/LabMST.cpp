class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> maxarray;
        int maxnum = arr[0];
        for(int i = 0; i < k; i++){
            if(arr[i] > maxnum)
                maxnum = arr[i];
        }
        maxarray.push_back(maxnum);

        for(int i = k; i < n; i++) {
            if(arr[i - k] == maxnum) {
                maxnum = arr[i - k + 1];

                for(int j = i - k + 1; j <= i; j++) {
                    if(arr[j] > maxnum)
                        maxnum = arr[j];
                }
            }
            else {
                if(arr[i] > maxnum)
                    maxnum = arr[i];
            }
            maxarray.push_back(maxnum);
        }
        return maxarray;
    }
};