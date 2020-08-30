class Solution {
    private static Map<Integer, String> makeMap() {
        Map<Integer, String> res = new HashMap<Integer, String>();
        res.put(2, "abc");
        res.put(3, "def");
        res.put(4, "ghi");
        res.put(5, "jkl");
        res.put(6, "mno");
        res.put(7, "pqrs");
        res.put(8, "tuv");
        res.put(9, "wxyz");
        return res;
    }
    
    public List<String> letterCombinations(String digits) {
        List<String> prev = new ArrayList<String>();
        if (digits.length() < 1) return prev;
        prev.add("");
        
        Map<Integer, String> chars = makeMap();
        
        for (int i = 0; i < digits.length(); i++) {
            List<String> cur = new ArrayList<String>();
            for (char c : chars.get(Integer.parseInt("" + digits.charAt(i))).toCharArray()) {
                for (String prevStr : prev) {
                    cur.add(prevStr + c);
                }
            }
            prev = cur;
        }
        
        return prev;
    }
}
