import java.util.*;

class SnakeString {
    
    public static String solution(String word) {
        StringBuilder sb = new StringBuilder();
        int i = 1;
        while (i < word.length()) {
            sb.append(word.charAt(i));
            i += 4;
        }
        i = 0;
        while (i < word.length()) {
            sb.append(word.charAt(i));
            i += 2;
        }
        i = 3;
        while (i < word.length()) {
            sb.append(word.charAt(i));
            i += 4;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(solution("Hello_World"));
    }
}