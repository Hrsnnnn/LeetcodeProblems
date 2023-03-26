import java.util.Arrays;

class Algorithm {
    public int[] answerQueries(int[] nums, int[] queries) {
        Arrays.sort(nums);
        int sum[] = new int[nums.length];
        int ans[] = new int[queries.length];
        sum[0] = nums[0];
        for(int i=1;i<sum.length;i++) sum[i] = sum[i-1] + nums[i];
        for(int i=0;i<queries.length;i++) {
            for(int j=0;j<nums.length;j++) {
                if(sum[j] <= queries[i]) ans[i] = j;
                else break;
            }
        }
        return ans;
    }
}

public class Solution {
    public static void main(String[] args) {
        
    }
}
