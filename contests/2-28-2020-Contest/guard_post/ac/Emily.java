import java.io.*;
import java.util.*;

public class Emily {

    public static void main(String[] args) {
        // Basic solution exploiting constraints
        int[] timeSteps = new int[1000000];
        
        Scanner in = new Scanner(System.in);
        int firstNum = in.nextInt();
        int firstLastEnd = 0;
        int firstStart = 0;
        for (int i=0; i<firstNum; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            if (i==firstNum-1) {
                firstLastEnd = end;
            }
            if (i==0) {
                firstStart = start;
            }
            for (int t=start; t<end; t++) {
                timeSteps[t]++;
            }
        }
        int secondNum = in.nextInt();
        int secondLastEnd = 0;
        int secondStart = 0;
        for (int i=0; i<secondNum; i++) {
            int start = in.nextInt();
            int end = in.nextInt();
            if (i == secondNum-1) {
                secondLastEnd = end;
            }
            if (i==0) {
                secondStart = start;
            }
            for (int t=start; t<end; t++) {
                timeSteps[t]++;
            }
        }
        int[] overlapTimes = {0, 0, 0};
        for (int t=Math.min(firstStart, secondStart); t<Math.max(firstLastEnd, secondLastEnd); t++) {
            overlapTimes[timeSteps[t]]++;
        }
        System.out.println(overlapTimes[0] + " " + overlapTimes[1] +" " + overlapTimes[2]);


    }
}