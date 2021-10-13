public class ThueMorse {
//    private static boolean[] genTM(int n) {
//        boolean[] tm = new boolean[n * n];
//        tm[0] = true;
//
//        int count = 4;
//        while (count <= tm.length) {
//            for (int i = count / 2; i < count; i++) {
//                tm[i] = !tm[i - count / 2];
//            }
//            count *= 2;
//        }
//        return tm;
//    }
//
//    private static void showArray(boolean[] a, int n) {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (a[i * n + j]) System.out.print("+ ");
//                else System.out.print("- ");
//            }
//            System.out.println();
//        }
//    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);

        int evenN = 1;
        while (evenN < n) {
            evenN *= 2;
        }

        // generate the array
        boolean[] tm = new boolean[evenN * evenN];
        tm[0] = true;
        int count = 4;
        while (count <= tm.length) {
            for (int i = count / 2; i < count; i++) {
                tm[i] = !tm[i - count / 2];
            }
            count *= 2;
        }


        // show tm array
//        showArray(tmArray, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tm[i * evenN + j]) System.out.print("+  ");
                else System.out.print("-  ");
            }
            System.out.println();
        }
    }

}
