public class Solution {
  private static void swap(int[] A, int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }

  private static int partition(int left, int right, int idx, int[] A) {
    int result = left;
    int pivot = A[idx];
    swap(A, idx, right);

    for (int i = 0; i < right; i++) {
      if (A[i] < pivot)
        swap(A, i, result++);
    }

    swap(A, right, result);
    return result;
  }

  private static void recurse(int left, int right, int[] A) {
    if (left >= right)
      return;

    int partitionIdx = partition(left, right, (left + right) / 2, A);
    recurse(left, partitionIdx - 1, A);
    recurse(partitionIdx + 1, right, A);
  }

  public static void quickSort(int[] A) {
    recurse(0, A.length - 1, A);
  }

  public static void main(String[] args) {
    int[] A = { 3, 4, 5, 17, 8, -1, 3, 9 };
    Solution.quickSort(A);
    for (int a : A) {
      System.out.print(a + " ");
    }
    System.out.print("\n");
  }
}
