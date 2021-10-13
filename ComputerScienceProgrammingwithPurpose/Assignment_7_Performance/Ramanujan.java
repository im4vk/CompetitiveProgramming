public class Ramanujan {

    // Is n a Ramanujan number?
    public static boolean isRamanujan(long n) {
        double r = Math.cbrt(n);
        int c = 0;
        double a2 = 0.0; //use to remember the value of b in a1^2 + a2^2; data type = double
        
        for (long i = 1; (i < r) && (c < 2); i++) {
            double a = n - Math.pow(i, 3.0);
            //StdOut.println("a = " + a);
            double ac = Math.cbrt(a);
            if (ac % 1.0 == 0.0 && c == 0) {
                c++;
                a2 = ac;
                //StdOut.println("a2 = " + a2);
            }
            else if (ac % 1.0 == 0.0 && c == 1 && i != a2) c++;//
        }
        //StdOut.println("c = " + c);
        return (c == 2);
    }

    // Takes a long integer command-line arguments n and prints true if
    // n is a Ramanujan number, and false otherwise.
        public static void main(String[] args) {       
        long n = Long.parseLong(args[0]);
        StdOut.println(isRamanujan(n));
    }
        
}