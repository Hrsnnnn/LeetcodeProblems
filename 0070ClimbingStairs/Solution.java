import java.lang.System;

class Algorithm {
    public int res;

    public void climbing(int height, int n) {
        if(height > n) return;
        if(height == n) { res += 1; return; }
        climbing(height + 1, n);
        climbing(height + 2, n);
    }

    public int climbStairs(int n) {
        int[] arr = new int[n];
        arr[0] = 1;
        arr[1] = 2;
        for(int i=2;i<n;i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n-1];
    }
}

public class Solution {
    public static void main(String[] args) {
        var alg = new Algorithm();
        alg.climbStairs(2);
        System.out.println(alg.res);
    }
}