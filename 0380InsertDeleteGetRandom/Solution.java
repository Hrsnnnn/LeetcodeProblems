import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;

class RandomizedSet {
    HashMap<Integer, Integer> loc;
    ArrayList<Integer> set;
    Random rand;
    
    public RandomizedSet() {
        loc = new HashMap<>();
        set = new ArrayList<>();
        rand = new Random();
    }

    public boolean insert(int val) {
        if(loc.containsKey(val)) return false;
        loc.put(val, set.size());
        set.add(val);
        return true;
    }

    public boolean remove(int val) {
        if(!loc.containsKey(val)) return false;
        int removeIndex = loc.get(val);
        int lastval = set.get(set.size() - 1);
        set.set(removeIndex, lastval);
        set.remove(set.size() - 1);
        loc.put(lastval, removeIndex);
        loc.remove(val);
        return true;
    }

    public int getRandom() {
        int loc = rand.nextInt(set.size());
        return set.get(loc);
    }

}

public class Solution {
    
}
