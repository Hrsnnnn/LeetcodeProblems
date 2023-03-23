import java.io.Console;
import java.util.ArrayList;
import java.util.List;

public class Solution {

    public static void main(String[] args) {
        // int[] a = {4,3,2,5,6,7,2,5,5};
        int[] a = {6,10,15,40,40,40,40,40,40};
        System.out.println(largestNumber(a, 47));
    }

    public static void display(String[] a) {
        for(int i=0;i<a.length;i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }

    public static void display(int[] a) {
        for(int i=0;i<a.length;i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    
    public static String largestNumber(int[] cost, int target) {
        ArrayList<Integer> exist = new ArrayList<>();
        display(cost);
        String[] dp = new String[target+1];
        dp[0] = "";
        for(int i=1;i<=target;i++) {   
            exist.clear();                 // dp[i]表示i的最大的内容
            for(int j=cost.length-1;j>-1;j--) {            // j是选择的数字
                if(cost[j] > i) continue;               // 如果当前的cost已经大于所有的cost 则跳过
                if(exist.contains(cost[j])) continue;
                exist.add(cost[j]);
                System.out.println("dp[" + i + "]=" + dp[i] + "\t j=" + j + "\t dp[" + (i-cost[j]) + "]=" + dp[i-cost[j]] + "\t cost[j]=" + cost[j] + "\t over!");
                dp[i] = larger(dp[i], getCombine(j+1, dp[i-cost[j]]));
                display(dp);
            }
        }
        return dp[target];
    }

    static String larger(String s1, String s2) {
        if(s1 == null || s1 == "") return s2;
        if(s2 == null || s2 == "") return s1;

        if(s1.length() > s2.length()) return s1;
        if(s1.length() < s2.length()) return s2;

        int l = s1.length();
        for(int i=0;i<l;i++) {
            var c1 = s1.charAt(i);
            var c2 = s2.charAt(i);
            if(c1 > c2) return s1;
            if(c1 < c2) return s2;
        }
        return s1;
    }

    static String getCombine(int integer, String s) {
        if(s == null) return null;
        if(s == "") return Integer.toString(integer);
        String result = "";
        for(int i=0;i<s.length();i++) {
            int b = Integer.parseInt(s.substring(i, i+1));
            if(b <= integer) {
                result += s.substring(0, i);
                result += Integer.toString(integer);
                result += s.substring(i, s.length());
                return result;
            }
        }
        return s + Integer.toString(integer);
    }
    
}