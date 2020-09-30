package applyPermutation;

public class Solution {

	public static void solution(int[] A, int[] P) {
		for (int i = 0; i < A.length; i++) {
			int cur = A[i];
			while (P[i] != -1) {
				int next = P[i];
				int temp = A[next];
				A[next] = cur;
				cur = temp;
				P[i] = -1;
				i = next;
			}
		}
	}
}
