
import java.util.*;

public class Solution {

    private static class Star implements Comparable<Star> {
        private double x, y, z;

        public Star(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        private double distance() {
            return Math.sqrt(x * x + y * y + z * z);
        }
        @Override
        public int compareTo(Star that) {
            return Double.compare(this.distance(), that.distance());
        }

        public String toString() {
            return x + " " + y + " " + z;
        }
    }

    private static List<Star> solution(List<Star> stars, int k) {
        PriorityQueue<Star> maxHeap = new PriorityQueue<>(k, Collections.reverseOrder());

        for(Star s : stars) {
            maxHeap.add(s);
            if(maxHeap.size() > k) maxHeap.poll();
        }

        List<Star> result = new ArrayList<>();
        for (Star s : maxHeap) {
            result.add(s);
        }
        
        Collections.reverse(result);
        return result;
    }

    public static void main(String[] args) {
        List<Star> stars = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            Star cur = new Star(i * i, i * i, i * i);
            stars.add(cur);
        }

        Collections.shuffle(stars);
        List<Star> result = Solution.solution(stars, 4);
        for (Star s : result) {
            System.out.println(s);
        }
    }
}