public class Inversions {

    // Return the number of inversions in the permutation a[].
    public static long count(int[] a) {
        int n = a.length;
        long count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) count++;
            }
        }
        return count;
    }

    // Return a permutation of length n with exactly k inversions.
    public static int[] generate(int n, long k) {
        int[] a = new int[n];
        // StdOut.println("length of a = " + a.length);
        int ic = 1;
        long kc = k;
        // for (int i = 0; i < n; i++) a[i] = i;
        for (int i = 1; (kc - (n - i)) >= 0 && (n - i) > 0; i++) {
            //StdOut.println("i = " + i);
            a[i - 1] = (n - i);
            kc = kc - (n - i);
            ic = i + 1;
        }
        
        int t = (n - 1) - (int)kc;
        
        if (t >= 0) a[t] = (n - ic);
        
        for (int j = (ic - 1); j < t; j++) a[j] = j - (ic - 1);
        for (int j = t + 1; j < n; j++) a[j] = j - ic;
        return a;
    }

    // Takes an integer n and a long k as command-line arguments,
    // and prints a permutation of length n with exactly k inversions.
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        long k = Long.parseLong(args[1]);
        //double start = System.currentTimeMillis() / 1000.0;
        int[] a = generate(n, k);
        //double now = System.currentTimeMillis() / 1000.0;
        //StdOut.printf("(%.0f seconds)\n", now - start); 
        for (int i = 0; i < n; i++) StdOut.print(a[i] + " ");
        StdOut.println();
        //StdOut.println(count(a));
    }   
}








