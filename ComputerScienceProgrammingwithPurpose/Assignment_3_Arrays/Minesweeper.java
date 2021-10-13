public class Minesweeper {
    public static void main(String[] args) {
        int m = Integer.parseInt(args[0]);
        int n = Integer.parseInt(args[1]);
        int randomNum = Integer.parseInt(args[2]);

        // init random array
//        a = initRandom(a, randomNum);

        int[][] a = new int[m][n];
        int row;
        int col;
        for (int i = 0; i < randomNum; i++) {
//            double rand = Math.random();
//            row = (int) (rand * m);
//            col = (int) (rand * n);
            row = (int) (Math.random() * m);
            col = (int) (Math.random() * n);

//            System.out.print("row is:" + row + "col is:" + col + "\n");

            if (a[row][col] == -1) randomNum++;
            else a[row][col] = -1;
//            a[row][col] = -1;
        }

        // change array
//        a = changeA(a);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == -1) {
                    if (1 <= j && a[i][j - 1] != -1) a[i][j - 1] += 1;
                    if (1 <= j && 1 <= i && a[i - 1][j - 1] != -1) a[i - 1][j - 1] += 1;

                    if (j <= n - 2 && a[i][j + 1] != -1) a[i][j + 1] += 1;
                    if (j <= n - 2 && i <= m - 2 && a[i + 1][j + 1] != -1) a[i + 1][j + 1] += 1;

                    if (1 <= i && a[i - 1][j] != -1) a[i - 1][j] += 1;
                    if (1 <= i && j <= n - 2 && a[i - 1][j + 1] != -1) a[i - 1][j + 1] += 1;

                    if (i <= m - 2 && a[i + 1][j] != -1) a[i + 1][j] += 1;
                    if (i <= m - 2 && 1 <= j && a[i + 1][j - 1] != -1) a[i + 1][j - 1] += 1;
                }
            }
        }

        // show array
//        showA(a);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == -1) System.out.print("*  ");
                else System.out.print(a[i][j] + "  ");
            }
            System.out.println();
        }
    }

}
