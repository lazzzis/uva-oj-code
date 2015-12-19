import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        ioInit();
        new Main();
        out.flush();
        out.close();
    }

    static InputStream inputStream;
    static OutputStream outputStream;
    static QuickScanner in;
    static PrintWriter out;

    static void ioInit() {
        inputStream = System.in;
        outputStream = System.out;
        in = new QuickScanner(inputStream);
        out = new PrintWriter(outputStream);
    }

    public static Comparator<Integer> compArgl = new Comparator<Integer>() {
        public int compare(Integer a, Integer b) {
            return a - b;
        }
    };

    final int MAXN = 200 + 50;
    Map<String, Integer> map = new HashMap<>();
    List[] employee = new List[MAXN];
    int d[][] = new int[MAXN][2];
    int f[][] = new int[MAXN][2];
    int N;
    public Main() {
        while (in.hasNext()) {
            N = in.nextInt();
            if (N == 0) {
                return;
            }
            for (int i = 0; i < N + 2; ++ i) {
                employee[i] = new ArrayList<Integer>();
            }
            map.clear();
            String emp, boss;
            boss = in.next();
            getId(boss);
            for (int i = 0; i < N - 1; ++ i) {
                emp = in.next();
                boss = in.next();
                employee[getId(boss)].add(getId(emp));
            }
            srh(0, 1);
            srh(0, 0);
            if (d[0][0] > d[0][1]) {
                out.println(d[0][0] + " " + (f[0][0] == 1 ? "Yes" : "No"));
            } else if (d[0][0] < d[0][1]) {
                out.println(d[0][1] + " " + (f[0][1] == 1 ? "Yes" : "No"));
            } else {
                out.println(d[0][1] + " " + "No");
            }
        }
    }

    int srh(int order, int flag) {
        if (employee[order].size() == 0) {
            f[order][flag] = 1;
            return d[order][flag] = flag;
        }
        f[order][flag] = 1;
        int sum = 0;
        if (flag == 0) {
            for (Object object : employee[order]) {
                int emp = (Integer) object;
                int choose = srh(emp, 1);
                int nochoose = srh(emp, 0);
                if (choose == nochoose) {
                    sum += choose;
                    f[order][flag] &= 0;
                } else if (choose > nochoose) {
                    sum += choose;
                    f[order][flag] = f[order][flag] & f[emp][1];
                } else if (nochoose > choose) {
                    sum += nochoose;
                    f[order][flag] = f[order][flag] & f[emp][0];
                }
            }
        } else {
            for (Object object : employee[order]) {
                int emp = (Integer) object;
                int nochoose = srh(emp, 0);
                sum += nochoose;
                f[order][flag] = f[order][flag] & f[emp][0];
            }
            sum += 1; // self
        }
        return d[order][flag] = sum;
    }

    int getId(String str) {
        if (map.containsKey(str)) {
            return map.get(str);
        }
        int size = map.size();
        map.put(str, size);
        return size;
    }



    class Pair<T> {
        T first, second;

        Pair(T first, T second) {
            this.first = first;
            this.second = second;
        }
        Pair() {}
    }
}

class QuickScanner {
    BufferedReader in;
    StringTokenizer token;
    String delim;
    public QuickScanner(InputStream inputStream) {
        this.in=new BufferedReader(new InputStreamReader(inputStream));
        this.delim=" \n\t";
        this.token=new StringTokenizer("",delim);
    }

    public boolean hasNext() {
        while(!token.hasMoreTokens()) {
            try {
                String s=in.readLine();
                if(s==null) return false;
                token=new StringTokenizer(s,delim);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }
        return true;
    }

    public String next() {
        hasNext();
        return token.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int[] nextInts(int n) {
        int[] res=new int[n];
        for(int i=0;i<n;i++)
            res[i]=nextInt();
        return res;
    }
}
