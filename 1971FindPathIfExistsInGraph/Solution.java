import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

class Algorithm {
    HashMap<Integer, ArrayList<Integer>> graph;
    HashSet<Integer> connect = new HashSet<>();
    HashSet<Integer> buffer = new HashSet<>();
    HashSet<Integer> bfs = new HashSet<>();
    void getConnect(int start) {
        connect.add(start);
        while(true) {
            int origin_size = connect.size();
            buffer.clear();
            for (Integer i : connect) {
                var arr = graph.getOrDefault(i, null);
                if(arr == null) continue;
                else if(bfs.contains(i)) continue;
                else {
                    System.out.println(arr.toString());
                    for (Integer j : arr) buffer.add(j);
                    bfs.add(i);
                }
            }
            for (Integer integer : buffer) connect.add(integer);
            System.out.println(connect.toString());
            if(origin_size == connect.size()) break;
        }
    }
    void InitGraph(int[][] edges) {
        graph = new HashMap<Integer, ArrayList<Integer>>();
        for (int[] e : edges) {
            int start = e[0]; int dest = e[1];
            var es = graph.getOrDefault(start, null);
            if(es == null) graph.put(start, new ArrayList<Integer>());
            graph.get(start).add(dest);
            es = graph.getOrDefault(dest, null);
            if(es == null) graph.put(dest, new ArrayList<Integer>());
            graph.get(dest).add(start);
        }
    }

    HashSet<Integer> travel = new HashSet<>();
    ArrayList<Integer> queue = new ArrayList<>();

    boolean bfs(int value) {
        if(queue.size() == 0) return false;
        int start = queue.get(0);
        var a = graph.getOrDefault(start, null);
        if(a == null) return false;
        else if(a.contains(value)) return true;
        for(int i=0;i<a.size();i++) {
            if(travel.contains(a.get(i))) continue;
            queue.add(a.get(i));
        }
        queue.remove(0);
        travel.add(start);
        System.out.println(queue.toString());
        return bfs(value);
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        InitGraph(edges);
        queue.add(source);
        return bfs(destination);
    }
}

public class Solution {
    public static void main(String[] args) {
        var alg = new Algorithm();
        int[][] edges = new int[][]{
            {2,9},{7,8},{5,9},{7,2},{3,8},{2,8},{1,6},{3,0},{7,0},{8,5}
        };
        alg.validPath(3, edges, 1, 0);
    }
}
