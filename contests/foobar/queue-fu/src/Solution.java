public class Solution {
	private static int xorOneToN(int n) {
		switch (n % 4) {
		case 0:
			return n;
		case 1:
			return 1;
		case 2:
			return n+1;
		default:
			return 0;
		}
	}
	
	private static int xorMToN(int m, int n) {
		return xorOneToN(m) ^ xorOneToN(n) ^ m;
	}
	
    public static int solution(int start, int length) {
    	int result = 0, cur = start;
    	
    	for (int i = length; i >= 1; i--) {
    		result ^= xorMToN(cur, cur + i - 1);
    		cur += length;
    	}
    	
    	return result;
    }
}