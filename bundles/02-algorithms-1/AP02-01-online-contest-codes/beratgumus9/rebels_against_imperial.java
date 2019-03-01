import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.HashMap;
import java.util.NavigableSet;
import java.util.TreeSet;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author berat
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        RebelAgainstImperial solver = new RebelAgainstImperial();
        solver.solve(1, in, out);
        out.close();
    }

    static class RebelAgainstImperial {
        TreeSet<Integer> set;
        HashMap<Integer, Integer> map;
        int B;
        int A;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            A = in.nextInt();
            B = in.nextInt();
            set = new TreeSet<>();
            map = new HashMap<>();
            while (in.hasNextInt()) {
                int value = in.nextInt();
                set.add(value);
                map.merge(value, 1, Integer::sum);
            }
            int end = (int) Math.pow(2, n);
            int start = 1;
            long res = daq(start, end);
            out.println(res);

        }

        long daq(int start, int end) {
            if (start == end) {
                if (set.contains(start))
                    return B * map.get(start);
                else
                    return A;
            }
            long l = end - start + 1;
            long na = 0;
            NavigableSet<Integer> range = set.subSet(start, true, end, true);
            for (Integer item : range)
                na += map.get(item);
            int middle = (start + end) / 2;
            if (na == 0)
                return A;
            return Math.min(B * na * l, daq(start, middle) + daq(middle + 1, end));

        }

    }
}

