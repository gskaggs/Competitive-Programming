import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SolutionTest {

	@Test
	void test() {
		Solution soln = new Solution();
		assertEquals(soln.minDistance("horse", "ros"), 3);
	}

}
