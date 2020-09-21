package isPalindrome;

public class Solution {

	public static boolean isPalindrome(int n) {
		if (n <= 0) {
			return n == 0;
		}
		
		int numDigits = (int) (Math.floor(Math.log10(n)) + 1);
		int msdDigit = (int) (Math.pow(10, numDigits - 1));
		
		while (msdDigit > 0) {
			if (n / msdDigit != n % 10) {
				return false;
			}
			
			n %= msdDigit;
			n /= 10;
			msdDigit /= 100;
		}
		
		return true;
	}

}
