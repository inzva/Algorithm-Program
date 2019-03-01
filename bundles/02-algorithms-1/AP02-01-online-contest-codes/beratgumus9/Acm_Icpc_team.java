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
        AcmIcpcTeam solver = new AcmIcpcTeam();
        solver.solve(1, in, out);
        out.close();
    }

    static class AcmIcpcTeam {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            String[] topic = new String[n];
            for (int i = 0; i < n; i++) {
                String topicItem = in.next();
                topic[i] = topicItem;
            }
            int count = 0;
            int max = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    char[] f = topic[i].toCharArray();
                    char[] s = topic[j].toCharArray();
                    int counter = 0;
                    for (int x = 0; x < f.length; x++) {
                        int bf = Character.getNumericValue(f[x]);
                        int bs = Character.getNumericValue(s[x]);
                        if ((bf | bs) == 1)
                            counter++;
                    }
                    if (counter > max) {
                        max = counter;
                        count = 1;
                    } else if (max == counter)
                        count++;
                }
            }
            out.println(max);
            out.println(count);
        }

    }
}

