package isPalindrome;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class TestIsPalindrome {

	@Test
	void test() {
		Solution soln = new Solution();
		
		assert(soln.isPalindrome(1));
		assert(soln.isPalindrome(121));
		assert(soln.isPalindrome(33311333));
		assert(!soln.isPalindrome(-1));
		assert(!soln.isPalindrome(123));
	}

}
