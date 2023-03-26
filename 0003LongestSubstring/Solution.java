import java.util.HashMap;

public class Solution {

    boolean checkString(String s){
        HashMap<Character, Boolean> alphabet = new HashMap<>();
        for(int i=0;i<s.length();i++) {
            if(alphabet.getOrDefault(s.charAt(i), false)) return false;
            alphabet.put(s.charAt(i), true);
        }
        return true;
    }

    boolean SlidingWindow(String s, int start, int length) {
        return checkString(s.substring(start, start+length));
    }

    public int lengthOfLongestSubstring(String s) {
        int beginIndex = 0;
        int maxLength = 1;
        if(s.length() == 1) return 1;
        for(;beginIndex<=s.length()-maxLength;beginIndex++) {
            for(;maxLength+beginIndex<=s.length();maxLength++) {
                if(!SlidingWindow(s, beginIndex, maxLength)) {
                    break;
                }
            }
        }
        return maxLength-1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.lengthOfLongestSubstring(args[0]));
    }
}