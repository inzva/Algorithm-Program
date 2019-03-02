import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        anagram solver = new anagram();
        solver.solve(1, in, out);
        out.close();
    }

    static class anagram {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String first = in.next();
            String second = in.next();
            if (first.length() != second.length())
                out.println("No");
            else {
                char[] f = first.toCharArray();
                char[] s = second.toCharArray();
                Arrays.sort(f);
                Arrays.sort(s);
                for (int i = 0; i < first.length(); i++) {
                    if (f[i] != s[i]) {
                        out.println("No");
                        return;
                    }
                }
                out.println("Yes");

            }


        }

    }
}

