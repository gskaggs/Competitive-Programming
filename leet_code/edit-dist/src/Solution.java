import java.util.*;

class Solution {
    private class Node {
        public int dist;
        public String word;
        public Node(String str, int d) {
            dist = d;
            word = str;
        }
    }
    
    private Set<String> seen = new HashSet<String>();
    private String target;

    private List<String> nextStrings(String word) {
        List<String> res = new ArrayList<String>();
        int len = word.length();
        for (int i = 0; i < len; i++) {
            res.add(word.substring(0,i) + word.substring(i+1, len));
            for (int j = 0; j < target.length(); j++) {
                char c = target.toCharArray()[j];
                res.add(word.substring(0,i) + c + word.substring(i+1, len));
                res.add(word.substring(0,i) + c + word.substring(i, len));
            }
        }
        
        for (int j = 0; j < target.length(); j++) {
            char c = target.toCharArray()[j];
            res.add(word + c);
        }
        
        return res;
    }
    
    public int minDistance(String word1, String word2) {
        Queue<Node> q = new LinkedList<Node>();
        target = word2;
        Node firstNode = new Node(word1, 0);
        q.add(firstNode);
        
        // BFS
        while (!q.isEmpty()) {
            Node cur = q.poll();
            
            System.out.println(cur.word);
            if (seen.contains(cur.word)) 
                continue;
            seen.add(cur.word);
            
            if (word2.equals(cur.word)) 
                return cur.dist;
            
            List<String> next = nextStrings(cur.word);
            
            for (String nextString : next) {
                q.add(new Node(nextString, cur.dist+1));
            }
        }
        return -1;
    }
}