public class ShannonEntropy {
    public static void main(String[] args) {
        int m;
        if (args.length != 0) m = Integer.parseInt(args[0]);
        else m = 100;

        int len = 0;
        int[] freq = new int[m + 1];
        while (!StdIn.isEmpty()) {
            int x = StdIn.readInt();
            freq[x]++;
            len++;
        }

        double shannon = 0.0;
        for (int j = 1; j <= m; j++) {
            double pi = 1.0 * freq[j] / len;
//            StdOut.println("a[j] "+a[j]+" pi "+pi);
            if (pi != 0) shannon -= pi * (Math.log(pi) / Math.log(2));
        }


        StdOut.printf("%.4f\n",shannon);
    }
}