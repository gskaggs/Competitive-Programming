public class Solution {
    private static void swap(int[] A, int i, int j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    // Reverse A from idx to the end
    private static void reverse(int[] A, int idx) {
        for (int i = idx; i < (A.length + idx) / 2; i++) {
            swap(A, i, A.length - (i - idx) - 1);
        }
    }

    public static boolean nextPermutation(int[] A) {
        // Find the first index which is not in a sorted suffix
        int i = A.length-2;
        while (i >= 0 && A[i] < A[i+1]) i--;
        if (i < 0) return false; 

        // Find the smallest element in the sorted suffix which is less than A[i]
        int j = A.length-1;
        while (j > i && A[j] >= A[i]) j--;

        swap(A, i, j);
        reverse(A, i+1);
        return true;
    }

    public static void main(String[] args) {
        int[] A = {4, 3, 2, 1};
        while(Solution.nextPermutation(A)) {
            for(int i = 0; i < A.length; i++) {
                System.out.print(A[i] + " ");
            }
            System.out.print("\n");
        }
    }
}
