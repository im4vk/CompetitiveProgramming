public class TrinomialDP {

    // Returns the trinomial coefficient T(n, k).
    public static long trinomial(int n, int k) {
        long[][] t = new long[n+1][n*2+1];
        //should add exceptional case for k > n && k < -n
        if (k > n || k < -n) return 0;
        t[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= n*2; j++) {
                if (j == 0) t[i][j] = 1;
                else if (j == 1) t[i][j] = t[i-1][j-1] + t[i-1][j];
                else t[i][j] = t[i-1][j-2] + t[i-1][j-1] + t[i-1][j];
            }
        }
        
        return t[n][n+k];       
    }   

    // Takes two integer command-line arguments n and k and prints T(n, k).
        public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int k = Integer.parseInt(args[1]);
        StdOut.println(trinomial(n, k));
    }
        
}