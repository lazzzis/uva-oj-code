/**
 * AC @ Sep 4th 2015
 * Run Time : 0.488s
 */
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N;
        while (true) {
            N = in.nextInt();
            if (N == 0) {
                break;
            }
            long ans = 0, last = 0, a;
            for (int i=0; i<N; ++i) {
                a = in.nextInt();
                ans += Math.abs(last);
                last += a;
            }
            System.out.println(ans);
        }
    }
}