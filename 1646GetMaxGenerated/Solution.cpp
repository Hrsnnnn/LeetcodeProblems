class Solution {
public:
    int getMaximumGenerated(int n) {
        int *array = new int[n];
        if(n == 1) return 0;
        if(n == 2) return 1;
        for(int i=2;i<n;i++) {
            if(i % 2 == 0) array[i] = array[i/2];
            else array[i] = array[i >> 1] + array[i >> 1 + 1];
        }
        int minval = 0;
        for(int i=0;i<n;i++) minval = minval < array[i] ? minval : array[i];
        delete array;
        return minval;
    }
};