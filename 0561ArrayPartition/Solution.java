public class Solution {
    public static void Swap(int i1, int i2, int[] nums) {
        int b = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = b;
        return;
    }

    public static void main(String[] args) {
        int[] nums = {6 ,2 ,6, 5, 1, 2};
        arrayPairSum(nums);
    }
    
    public static int arrayPairSum(int[] nums) {
        int l = nums.length;
        for(int i=0;i<l;i++) {
            for(int j=i;j<l;j++) {
                if (nums[i] > nums[j]) Swap(i, j, nums);
            }
        }

        int sum = 0;
        for(int i=0;i<l;i+=2) {
            sum += nums[i];
            System.out.println(nums[i]);
        }

        for(int i=0;i<l;i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();

        return sum;
    }
}