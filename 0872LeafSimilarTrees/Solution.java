import java.lang.System;
import java.util.ArrayList;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Algorithm {
    public TreeNode BuildTree(Integer[] arr, int index) {
        if (index >= arr.length) return null;
        if(arr[index] == null) return null;
        TreeNode root = new TreeNode(arr[index]);
        root.left = BuildTree(arr, 2 * index + 1);
        root.right = BuildTree(arr, 2 * index + 2);
        return root;
    }

    public void DisplayTree(TreeNode root, int col, int depth) {
        if(root == null) return;
        System.out.print(root.val); System.out.print("(" + depth + ", " + col + ") ");
        // DisplayTree(root.left, col, depth+1);
        // DisplayTree(root.right, col+1, depth+1);
        if(col == 0 && depth == 0) System.out.println();
    }

    public void DisplayList(ArrayList<Integer> l) {
        for(int i=0;i<l.size();i++) System.out.print(l.get(i) + ", ");
        System.out.println();
    }

    public void LeafTree(TreeNode root, ArrayList<Integer> leaves) {
        if(root == null) return;
        if(root.left == null && root.right == null) leaves.add(root.val);
        LeafTree(root.left, leaves);
        LeafTree(root.right, leaves);
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();
        LeafTree(root1, arr1);
        LeafTree(root2, arr2);
        // DisplayList(arr1);
        // DisplayList(arr2);

        if(arr1.size() != arr2.size()) return false;
        for(int i=0;i<arr1.size();i++) {
            if(arr1.get(i) != arr2.get(i)) return false;
        }

        return true;
    }
}

public class Solution {
    public static void main(String[] args) {
        Algorithm alg = new Algorithm();
        Integer arr1[] = new Integer[]{3,5,1,6,2,9,8,null,null,7,4};
        Integer arr2[] = new Integer[]{3,5,1,6,7,4,2,null,null,null,null,null,null,9,8};
        TreeNode node1 = alg.BuildTree(arr1, 0);
        TreeNode node2 = alg.BuildTree(arr2, 0);
        alg.DisplayTree(node1, 0, 0);
        alg.DisplayTree(node2, 0, 0);
        alg.leafSimilar(node1, node2);
    }
}

