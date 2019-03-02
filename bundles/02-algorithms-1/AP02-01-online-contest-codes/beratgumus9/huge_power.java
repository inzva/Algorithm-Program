import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

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
        HugePower solver = new HugePower();
        solver.solve(1, in, out);
        out.close();
    }

    static class HugePower {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            BigInteger p = new BigInteger(String.valueOf(in.nextLong()));
            BigInteger a = new BigInteger(String.valueOf(in.nextInt()));
            BigInteger mod = new BigInteger(String.valueOf(in.nextInt()));

            a = a.mod(mod);
            // p = p.mod(mod.subtract(BigInteger.ONE));
            a = a.modPow(p, mod);
            out.println(a.intValue());


        }

    }
}

