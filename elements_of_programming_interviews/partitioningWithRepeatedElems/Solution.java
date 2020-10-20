import java.util.ArrayList;
import java.util.*;
import java.util.Map;

public class Solution {
    public static class Student {
        public int age;
        public int id;
        public Student(int age, int id) {
            this.age = age;
            this.id = id;
        }
    }

    public static void groupByAge(List<Student> students) {
        Map<Integer, Integer> toCount = new HashMap<>();
        for (Student s : students) {
            toCount.put(s.age, toCount.getOrDefault(s.age, 0) + 1);
        }

        int offset = 0;
        Map<Integer, Integer> toOffset = new HashMap<>();
        for (Map.Entry<Integer, Integer> kc : toCount.entrySet()) {
            toOffset.put(kc.getKey(), offset);
            offset += kc.getValue();
        }

        while(!toOffset.isEmpty()) {
            Map.Entry<Integer, Integer> from = toOffset.entrySet().iterator().next();
            Integer idx1 = from.getValue();
            Integer age1 = students.get(idx1).age;
            
            Integer idx2 = toOffset.get(age1);
            Collections.swap(students, idx1, idx2);

            Integer count = toCount.get(age1) - 1;
            toCount.put(age1, count);

            if (count > 0) toOffset.put(age1, idx2+1);
            else toOffset.remove(age1);
        }
    }

    public static void main(String[] args) {
        List<Student> students = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            Student s = new Student(i % 5 + 10, i);
            students.add(s);
        }

        groupByAge(students);

        for (Student s  : students) {
            System.out.println("id " + s.id + " : age " + s.age);
        }
    }
}
