class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<String>();
        for (String str : wordDict) dict.add(str);
        
        boolean[] dp = new boolean[s.length()];
        for (int l = s.length()-1; l >= 0; l--) {
            for (int r = l+1; r <= s.length(); r++) {
                String cur = s.substring(l, r);
                if (dict.contains(cur) && (r == s.length() || dp[r])) 
                    dp[l] = true;
            }
        }
        return dp[0];
    }
}
