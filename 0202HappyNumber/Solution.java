import java.util.HashMap;

public class Solution {

    int calSquare(int n) {
        int ret = 0;
        int buf = 0;
        while(n>10) {
            buf = n % 10;
            n = n / 10;
            ret += (buf*buf);
        }
        return ret;
    }

    public boolean isHappy(int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int buf = 0;
        while(n!=1) {
            buf = calSquare(n);
            if(map.containsKey(buf)) return false;
            map.put(n, buf);
            n = buf;
        }
        return true;
    }
    public static void main(String[] args) {
        
    }
}