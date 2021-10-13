public class Divisors {

    // Returns the greatest common divisor of a and b.
    public static int gcd(int a, int b) {
        int n = 0;
        int m = 0;
        int gcd = 0;
        int a1 = Math.abs(a);
        int b1 = Math.abs(b);
        if (a1 == 0 || b1 == 0) {
            if (a1 > b1) {
                gcd = a1;
                return gcd;
            }
            else {
                gcd = b1;
                return gcd;
            }
        }
        if (a1 > b1) { 
            n = b1;
            m = a1;
        }
        else if (a1 <= b1) {
            n = a1;
            m = b1;
        }
        while (m % n != 0) {
            int t = m % n;
            m = n;
            n = t;
        }
        gcd = n;
        return gcd;
    }

    // Returns the least common multiple of a and b.
    public static int lcm(int a, int b) {
        int lcm = 0;
        int a1 = Math.abs(a);
        int b1 = Math.abs(b);
        
        if (a1 == 0 || b1 == 0) return lcm;
        else lcm = (a1 / gcd(a, b)) * b1;
        
        return lcm;
    }
            
    // Returns true if a and b are relatively prime; false otherwise.
    public static boolean areRelativelyPrime(int a, int b) {
        int gcd = gcd(a, b);
        boolean prime = (gcd == 1);
        return prime;
    }

    // Returns the number of positive integers between 1 and n
    // that are relatively prime with n.
    public static int totient(int n) {
        int t = 0;
        if (n <= 0) return 0;
        for (int i = 1; i <= n; i++) {
            if (areRelativelyPrime(i, n)) t++;
        }
        return t;
    }
            
    // Takes two integer command-line arguments a ansd b and prints each
    // function, evaluated, in the format (and order) given below.
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        StdOut.println("gcd(" + a + ", " + b + ") = " + gcd(a, b));
        StdOut.println("lcm(" + a + ", " + b + ") = " + lcm(a, b));
        StdOut.println("areRelativelyPrime(" + a + ", " + b + ") = " + areRelativelyPrime(a, b));
        StdOut.println("totient(" + a + ") = " + totient(a));
        StdOut.println("totient(" + b + ") = " + totient(b));
    }
              
}