import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Set;
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
        UniqueDivisors solver = new UniqueDivisors();
        solver.solve(1, in, out);
        out.close();
    }

    static class UniqueDivisors {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int q = in.nextInt();
            for (int t = 0; t < q; t++) {
                Set<Integer> set = new TreeSet();
                int number = in.nextInt();
                if (number % 2 == 0)
                    set.add(2);
                while (number % 2 == 0) {
                    number /= 2;
                }
                for (int i = 3; i <= Math.sqrt(number); i += 2) {
                    while (number % i == 0) {
                        set.add(i);
                        number /= i;
                    }

                }
                if (number > 2)
                    set.add(number);
                set.forEach(integer -> out.print(integer + " "));

                out.println();
            }
        }

    }
}

