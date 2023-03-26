import java.util.HashMap;

class MapSum {
    HashMap<String, Integer> map;

    boolean isPrefix(String str, String prefix) {
        if(prefix.length() > str.length()) return false;
        for(int i=0;i<prefix.length();i++) 
            if(prefix.charAt(i) != str.charAt(i)) return false;
        return true;
    }

    public MapSum() {
        map = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        map.put(key, val);
    }
    
    public int sum(String prefix) {
        int res = 0;
        for (var key : map.keySet())
            if(isPrefix(key, prefix)) res += map.get(key);
        return res;
    }
}

public class Solution {

}
