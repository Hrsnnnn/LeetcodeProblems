import java.lang.Math;

public class Solution {
    public static void DisplayArray(int[] arr) {
        for(int i=0;i<arr.length;i++) {
            System.out.print(arr[i]);
            System.out.print(", ");
        }
        System.out.println("");
    }

    public static int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] rowmax, colmax;
        rowmax = new int[grid.length];
        colmax = new int[grid[0].length];

        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid.length;j++) {
                if(grid[i][j] > rowmax[i]) rowmax[i] = grid[i][j];
                if(grid[i][j] > colmax[j]) colmax[j] = grid[i][j];
            }
        }

        int res = 0;
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid.length;j++) {
                res = res + Math.min(rowmax[i], colmax[j]) - grid[i][j];
                grid[i][j] = Math.min(rowmax[i], colmax[j]);
            }
        }

        for(int i=0;i<grid.length;i++) DisplayArray(grid[i]);

        return res;

    }

    public static void main(String[] args) {
        int[][] grid = new int[][]{
            {3, 0, 8, 4},
            {2, 4, 5, 7},
            {9, 2, 6, 3},
            {0, 3, 1, 0}
        };
        int res = maxIncreaseKeepingSkyline(grid);
        System.out.println(res);
    }
}
