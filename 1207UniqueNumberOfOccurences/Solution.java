import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;

public class Solution
{
    public static boolean UniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> occur = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if(!occur.keySet().contains(arr[i])) occur.put(arr[i], 1);
            else occur.put(arr[i], occur.get(arr[i]) + 1);
        }

        HashSet<Integer> set = new HashSet<>();
        Iterator<Integer> iterator = occur.values().iterator();
        while(iterator.hasNext()) set.add(iterator.next());

        return set.size() == occur.values().size();
    }

    public static void main(String[] args) {
        int[] arr = new int[]{1, 2, 2, 1, 1, 1, 3};
        System.out.println(UniqueOccurrences(arr));
    }
}
