import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class solnTest {

	@Test
	void test() {
		int[] in = {0, 3};
		assertEquals(Solution.solution(in[0], in[1]), 2);
	}

	@Test
	void test1() {
		int[] in = {17, 4};
		assertEquals(Solution.solution(in[0], in[1]), 14);
	}
}
