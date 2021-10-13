public class DiscreteDistribution {
    public static void main(String[] args) {
        int m = Integer.parseInt(args[0]);
        int[] a = new int[args.length];

        for (int i = 1; i < args.length; i++) {
            a[i] = Integer.parseInt(args[i]);
        }


        int total = 0;
        for (int i = 1; i < a.length; i++) total += a[i];

        for (int i = 0; i < m; i++) {
            int r = (int) (Math.random() * total);
            int whole = 0;
            int j = 1;
            while (whole < r) {
                whole += a[j];
                j++;
            }
            System.out.print(j + " ");
        }
        System.out.println();
    }
}
