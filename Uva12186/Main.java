/**
 * AC @ Dec 11 th
 * Run Time : 639ms
 */
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

    int N, T;
    List[] employees;
    public Main() {

        while (in.hasNext()) {
            N = in.nextInt();
            T = in.nextInt();
            if (N == T && T == 0) {
                return;
            }
            employees = new ArrayList[N + 1];
            for (int i = 0; i < employees.length; ++ i) {
                employees[i] = new ArrayList<Integer>();
            }
            for (int i = 1; i < N + 1; ++ i) {
                int order = in.nextInt();
                employees[order].add(i);
            }
            out.println(srh(0));
        }
    }

    int srh(int order) {
        if (employees[order].size() == 0) {
            return 1;
        }
        int need[] = new int[employees[order].size()];
        for (int i = 0; i < employees[order].size(); ++ i) {
            need[i] = srh((Integer) employees[order].get(i));
        }
        Arrays.sort(need);
        int limit = (int) Math.ceil(employees[order].size() * T / 100.0);
        int sum = 0;
        for (int i = 0; i < limit; ++ i) {
            sum += need[i];
        }
        return sum;
    }

    class Pair<T>{
        T first, second;
        Pair(T first, T second){
            this.first = first;
            this.second = second;
        }
        Pair(){}
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
