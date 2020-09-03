class Solution {
    private List<List<Integer>> dp;
    private List<String> answers = new ArrayList<String>();
    
    private void formatAns(int i, String s, List<String> stack) {
        if (i == s.length()) {
            StringBuilder res = new StringBuilder();
            for (String word : stack) res.append(word + " ");
            answers.add(res.toString().trim());
            return;
        }
        
        for (int r : dp.get(i)) {
            stack.add(s.substring(i, r));
            formatAns(r, s, stack);
            stack.remove(stack.size()-1);
        }
    }
    
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<String>();
        for (String str : wordDict) dict.add(str);
        
        dp = new ArrayList<List<Integer>>(s.length());
        for (int i = 0; i < s.length(); i++) {
            dp.add(new ArrayList<Integer>());
        }
        for (int l = s.length()-1; l >= 0; l--) {
            List<Integer> curList = new ArrayList<Integer>();
            for (int r = l+1; r <= s.length(); r++) {
                String cur = s.substring(l, r);
                if (dict.contains(cur) && (r == s.length() || dp.get(r).size() > 0)) 
                    curList.add(r);
            }
            dp.set(l, curList);
        }
        
        formatAns(0, s, new ArrayList<String>());
        return answers;
    }
}
