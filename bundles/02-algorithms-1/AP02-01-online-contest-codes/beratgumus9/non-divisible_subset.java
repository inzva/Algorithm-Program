import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        NonDivisibleSubset solver = new NonDivisibleSubset();
        solver.solve(1, in, out);
        out.close();
    }

    static class NonDivisibleSubset {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int k = in.nextInt();
            int[] arr = new int[k];
            for (int i = 0; i < n; i++)
                arr[in.nextInt() % k]++;

            int result = 0;
            if (k % 2 == 0) result++;
            result += Math.min(arr[0], 1);
            for (int i = 1; i <= k / 2; i++) {
                if (i != k - i)
                    result += Math.max(arr[i], arr[k - i]);
            }
            out.println(result);

        }

    }
}

