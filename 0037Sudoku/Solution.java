class Solution {

    public static final char UNKNOWN = '0';
    public int sudoku[][];

    public int finalRes[][];

    public boolean rows[][];
    public boolean cols[][];
    public boolean areas[][];

    public boolean check(int fig, int i, int j) {
        return (!rows[i][fig]) && (!cols[j][fig]) && (!areas[getAreaIndex(i, j)][fig]);
    }

    public void addPoint(int fig, int i, int j) {
        assert (check(fig, i, j));

        rows[i][fig] = true;
        cols[j][fig] = true;
        areas[getAreaIndex(i, j)][fig] = true;

        sudoku[i][j] = fig;
    }

    public void removePoint(int fig, int i, int j) {
        assert sudoku[i][j] != -1;
        
        rows[i][fig] = false;
        cols[j][fig] = false;
        areas[getAreaIndex(i, j)][fig] = false;

        sudoku[i][j] = -1;
    }

    public int toFig(char c) {
        if(c == '.') return -1;
        return c - '1';
    }

    public int getAreaIndex(int i, int j) {
        return Math.floorDiv(i,3)*3+j/3;
    }

    public void solveSudoku(char[][] board) {
        this.sudoku = new int[board.length][board[0].length];
        this.finalRes = new int[board.length][board[0].length];
        this.rows = new boolean[9][9];
        this.cols = new boolean[9][9];
        this.areas = new boolean[9][9];

        for(int i=0;i<sudoku.length;i++) {
            for(int j=0;j<sudoku[i].length;j++) {
                int fig = toFig(board[i][j]);
                sudoku[i][j] = fig;
                if(fig == -1) continue;
                rows[i][fig] = true;
                cols[j][fig] = true;
                areas[getAreaIndex(i, j)][fig] = true;
            }
        }  

        boolean hasResult = backtrack(0, 0);

        if(!hasResult) {
            System.out.printf("no result!");
            return;
        }

        for(int i=0;i<board.length;i++) {
            for(int j=0;j<board[i].length;j++) {
                board[i][j] = toChar(finalRes[i][j]);
            }
        }

    }

    public char toChar(int f) {
        return (char)(f+'1');
    }

    public void copyResult() {
        for(int i=0;i<finalRes.length;i++) {
            for(int j=0;j<finalRes[i].length;j++) {
                finalRes[i][j] = sudoku[i][j];
            }
        }
    }

    boolean solved = false;

    public boolean backtrack(int i, int j) {
        
        if(i == 9 && j == 0) {
            solved = true;
            copyResult();
            return true;
        }

        int nexti;
        int nextj;

        if(j == 8) {
            nexti = i+1;
            nextj = 0;
        }
        else {
            nexti = i;
            nextj = j+1;
        }

        if(sudoku[i][j] != -1) return backtrack(nexti, nextj);

        int minAvail = 0;
        boolean flag = false;
        for(;minAvail<9;minAvail++) {
            if(!check(minAvail, i, j)) continue;
            addPoint(minAvail, i, j);
            flag = flag | backtrack(nexti, nextj);
            if(flag) return true;
            removePoint(minAvail, i, j);
        }

        return false;

    }
}