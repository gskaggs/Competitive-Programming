public class Solution {
    private void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    private int partition(int left, int right, int idx, int[] A) {
        int result = left;
        int pivotVal = A[idx];
        swap(A, idx, right);

        for (int i = left; i < right; i++) {
            if (A[i] < pivotVal) swap(A, i, result++);
        }

        swap(A, result, right);
        return result;
    }

    /**
     * T(N) = O(N) + T(N/2)
     * => Average case O(N) time
     */
    public int solve(int[] A, int k) {
        /**
         * Invariants:
         * left <= k
         * left < right
         * All values in A[...left-1] <= A[left...]
         * All values in A[...right+1] >= A[...right]
         */
        int left = 0;
        int right = A.length-1;
        if (right == left) return A[0];

        while (left <= k && left < right) {
            int mid = (left + right) / 2;
            int pivot = partition(left, right, mid, A);
            if (pivot < k) left = pivot+1;
            else if (pivot > k) right = pivot-1;
            else return A[pivot];
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] A = { 3, 4, 5, 17, 8, -1, 3, 9 };
        Solution soln = new Solution();
        
        for (int k = 0; k < A.length; k++) {
            A = new int[] { 3, 4, 5, 17, 8, -1, 3, 9 };
            System.out.println(k + " " + soln.solve(A, k));
        }
    }
}
