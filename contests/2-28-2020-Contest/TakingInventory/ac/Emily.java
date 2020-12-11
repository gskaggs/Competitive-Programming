import static java.lang.System.*;
import java.util.*;

public class Emily {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int B = in.nextInt();
        int R = in.nextInt();
        int C = in.nextInt();
        int A = in.nextInt();
        long total = B*1440L + R*590 + C*224 + A*130;
        out.println(total/2000);
    }
}
