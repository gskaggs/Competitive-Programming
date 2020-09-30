package applyPermutation;

import static org.junit.jupiter.api.Assertions.*;

class Test {

	@org.junit.jupiter.api.Test
	void test() {
		int[] A = {0, 1, 2, 3};
		int[] P = {2, 0, 1, 3};
		int[] soln = {1, 2, 0, 3};
		Solution.solution(A, P);
		
		for(int i = 0; i < soln.length; i++) {
			assertEquals(soln[i], A[i]);
		}
	}

}
