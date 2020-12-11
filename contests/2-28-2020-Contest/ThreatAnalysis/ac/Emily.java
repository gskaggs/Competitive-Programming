import static java.lang.System.*;
import java.util.*;

public class Emily {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numReports = in.nextInt();
        List<Threat> reports = new ArrayList<>(numReports);
        for (int i=0; i<numReports; i++) {
            String L = in.next();
            int Z = in.nextInt();
            int D = in.nextInt();
            double A = in.nextDouble();
            reports.add(new Threat(L, D, Z, A));
        }
        reports.sort((t1, t2) -> {
            if (t1.distance != t2.distance) {
                return t1.distance < t2.distance ? -1 : 1;
            } else {
                if (t1.zombieCount != t2.zombieCount) {
                    return t1.zombieCount < t2.zombieCount ? 1 : -1;
                } else {
                    if (t1.aggression != t2.aggression) {
                        return t1.aggression < t2.aggression ? 1 : -1;
                    } else {
                        return t1.label.compareTo(t2.label);
                    }
                }
            }
        });
        for (int i=0; i<reports.size(); i++) {
            out.println(reports.get(i).label);
        }
    }

    static class Threat {
        public String label;
        public int distance;
        public int zombieCount;
        public double aggression;
        public Threat(String l, int d, int z, double a) {
            label = l;
            distance = d;
            zombieCount = z;
            aggression = a;
        }
    }
}
