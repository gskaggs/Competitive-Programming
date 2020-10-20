import java.util.*;

public class Solution {
    private static int count = 0;
    private static void recurse(List<Integer> A, int l) {
        if (l == A.size()) {
            for (Integer i : A) System.out.print(i + " ");
            System.out.println("");
            count++;
            return;
        }

        for(int i = l; i < A.size(); i++) {
            Collections.swap(A, i, l);
            recurse(A, l+1);
            Collections.swap(A, i, l);
        }
    }   
    private static void permute(List<Integer> A) {
        recurse(A, 0);
    }
    public static void main(String[] args) {
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            A.add(i);
        }

        Solution.permute(A);
        System.out.println("Num permutations: " + count);
    }
}