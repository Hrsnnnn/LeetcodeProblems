

public class Solution {
    public static boolean carPooling(int[][] trips, int capacity) {
        int num, from, end;
        int seated = 0;
        int[] downward = new int[trips.length];
        int[] upward = new int[trips.length];
        for(int i=0;i<trips.length;i++) {
            var trip = trips[i];
            num = trip[0];
            from = trip[1];
            end = trip[2];
            downward[end] += num;
            upward[from] += num;
        }

        for(int i=0;i<trips.length;i++) {
            seated += upward[i];
            seated -= downward[i];
            if(seated > capacity) return false;
        }

        return true;
    }
    
    public static void main(String[] args) {
        
    }
}