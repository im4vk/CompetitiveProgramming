public class MaximumSquareSubmatrix {

    // Returns the size of the largest contiguous square submatrix
    // of a[][] containing only 1s.
    public static int size(int[][] a) {
        
        int n = a.length;
        long sum = 0;
        int size = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
              sum += a[i][j];
            }
        }
        if (sum == n * n) {
            size = n;
            return size;
        } 
        else if (sum == 0) {
            size = 0;
            return size;
        }    
            
        int m = (int) Math.sqrt(sum);
        //StdOut.println("sum = " + sum);
        //StdOut.println("m = " + m);
        sum = 0;
        int max = 1;
        
        while (m >= 2) {
            for (int j = 0; j <= (n - m); j++) {
                for (int p = 0; p <=(n - m); p++) {

                    for (int k = j; k <= (j + (m - 1)); k++) {
                        for (int l = p; l <= (p + (m - 1)); l++) {
                            sum += a[k][l];
                        }
                    }
                    
                    if (sum == m * m) {
                        size = m;
                        return size;
                    }
                    if ((int) Math.sqrt(sum) > max) max = (int) Math.sqrt(sum);
                    sum = 0;
                }
            }
            m = max;
            max = 1;
        }
        
        size = m;
        return size;
    }

    // Reads an n-by-n matrix of 0s and 1s from standard input
    // and prints the size of the largest contiguous square submatrix
    // containing only 1s.
        public static void main(String[] args) {
        int n = StdIn.readInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j ++) {
                a[i][j] = StdIn.readInt();
            }
        }
        StdOut.println(size(a));
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n;j ++) {
                StdOut.print(a[i][j] + " ");
            }
            StdOut.println();
        }*/
        }
}