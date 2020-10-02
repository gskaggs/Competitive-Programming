public class Solution {
    private int binSearch(int[] row, int target, int hi) {
        int lo = 0;
        if (row[lo] > target)
            return -1;
        if (row[hi] <= target)
            return hi;

        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (row[mid] <= target)
                lo = mid;
            else
                hi = mid;
        }

        return lo;
    }

    public boolean solution(int[][] grid, int target) {
        int hi = grid[0].length - 1;
        for (int r = 0; r < grid.length; r++) {
            int i = binSearch(grid[r], target, hi);
            if (i == -1)
                return false;
            if (grid[r][i] == target)
                return true;
            hi = i;
        }
        return false;
    }

    public static void main(String[] args) {
        Solution soln = new Solution();
        int[][] grid = { { -1, 2, 4, 6 }, { 1, 5, 9, 21 }, { 6, 8, 9, 25 }, { 8, 10, 12, 40 } };
        System.out.println(soln.solution(grid, 7));
        System.out.println(soln.solution(grid, 8));
    }
}
