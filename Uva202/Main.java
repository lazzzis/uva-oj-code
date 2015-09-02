import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by emerald on 8/18/15.
 *
 */
public class Main {
    public static void main(String []args) {
        Scanner in = new Scanner(System.in);
        final int MAXN = 5000 + 50;
        int vis[] = new int[MAXN];
        int path[] = new int[MAXN];
        while(in.hasNext()) {
            Arrays.fill(vis, -1);
            Arrays.fill(path, 0);
            int numer = in.nextInt(),
                    demon = in.nextInt();
            int a = numer;
            int cycle, start, end;
            path[0] = numer / demon;
            vis[numer = numer % demon] = 0;
            for(int i=1; ; ++ i) {
                numer *= 10;
                path[i] = numer / demon;
                if( vis[numer % demon] != -1 ) {
                    cycle = i - vis[numer % demon];
                    start = vis[numer % demon];
                    end = i;
                    break;
                }
                vis[numer = numer % demon] = i;
            }
            System.out.print(a + "/" + demon + " = " + path[0] + ".");
            int i;
            for(i=1; i<=start; ++i) {
                System.out.print(path[i]);
            }
            System.out.print("(");
            while (i-start<=50 && i < end + 1) {
                System.out.print(path[i]);
                ++ i;
            }
            if(i-start>=50 && cycle > 50) {
                System.out.print("...");
            }
            System.out.println(")");
            System.out.println("   " + cycle + " = number of digits in repeating cycle" + "\n");
        }
    }
}
