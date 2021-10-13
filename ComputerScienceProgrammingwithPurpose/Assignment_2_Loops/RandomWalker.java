public class RandomWalker {
    public static void main(String[] args) {
        int mht = Integer.parseInt(args[0]);
        int steps = 0;
        int x = 0;
        int y = 0;

        while (Math.abs(x) + Math.abs(y) != mht) {
            System.out.printf("(%d, %d)\n", x, y);
            int rand = (int) (Math.random() * 4);
            if (rand == 0) x += 1;
            if (rand == 1) x -= 1;
            if (rand == 2) y += 1;
            if (rand == 3) y -= 1;
            steps++;
        }
        System.out.printf("(%d, %d)\n", x, y);
        System.out.println("steps = " + steps);
    }
}
