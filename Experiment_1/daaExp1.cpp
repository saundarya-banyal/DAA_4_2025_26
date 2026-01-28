#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int ops = 0;
int maxDepth = 0;

void complexRec(int n, int depth = 0) {
    ops++;
    if (depth > maxDepth) maxDepth = depth;
    
    if (n <= 2) {
        return;
    }

    int p = n;
    while (p > 0) {
        ops++;
        vector<int> temp(n);
        ops++;
        for (int i = 0; i < n; i++) {
            ops++;
            temp[i] = i ^ p;
            ops++;
        }
        p >>= 1;
        ops++;
    }

    vector<int> small(n);
    ops++;
    for (int i = 0; i < n; i++) {
        ops++;
        small[i] = i * i;
        ops++;
    }

    ops++;
    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        ops += n/2;
    } else {
        reverse(small.begin(), small.end());
        ops += n/2;
    }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
   int testSizes[] = {5, 10, 50, 100};
int sizeCount = 4;
    
for(int i = 0; i < sizeCount; i++) {
    int n = testSizes[i];
     ops = 0;
        maxDepth = 0;
        
        auto start = chrono::high_resolution_clock::now();
        complexRec(n);
        auto end = chrono::high_resolution_clock::now();
        
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        
        cout << n << " " << ops << " " << maxDepth << " " << duration.count() << endl;
}
    return 0;
}
// Recurrence relation: T(n) = 3T(n/2) + O(n log n)
// Masters Theorem: T(n) = 3T(n/2) + O(n log n)
// a = 3, b = 2, f(n) = n log n
// n^(logb a) = n^(log2 3)
// Case 1 applies: T(n) = Θ(n^(log2 3))

