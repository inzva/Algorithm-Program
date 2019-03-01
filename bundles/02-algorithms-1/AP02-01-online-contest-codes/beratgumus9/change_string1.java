import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Set;

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
        ChangeString1 solver = new ChangeString1();
        solver.solve(1, in, out);
        out.close();
    }

    static class ChangeString1 {
        Set wowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        Set consonant = new HashSet(Arrays.asList('b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'));

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String first = in.next();
            String second = in.next();
            if (first.length() != second.length())
                out.println("No");
            else {
                char[] f = first.toCharArray();
                char[] s = second.toCharArray();
                for (int i = 0; i < f.length; i++) {
                    if (f[i] != s[i]) {
                        if ((wowels.contains(f[i]) && wowels.contains(s[i])) || (consonant.contains(f[i]) && consonant.contains(s[i])))
                            continue;
                        else {
                            out.println("No");
                            return;
                        }

                    }
                }
                out.println("Yes");
            }
        }

    }
}

