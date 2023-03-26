
class Algorithm {
    public int rob(int[] nums) {
        if(nums.length == 1) return nums[0];
        if(nums.length == 2) return Math.max(nums[0], nums[1]);
        int[] res = new int[nums.length];
        res[0] = nums[0]; res[1] = nums[1]; res[2] = Math.max(res[0] + nums[2], res[1]);
        int idx = 2;
        for(;idx<nums.length;idx++) res[idx] = Math.max(res[idx-2], res[idx-3]) + nums[idx];
        return Math.max(res[res.length-1], res[res.length-2]);
    }
}

public class Solution {
    public static void main(String[] args) {
        var alg = new Algorithm();
        int[] nums = new int[]{1, 2, 3};
        alg.rob(nums);
    }
}
