public class WorldMap {
    public static void main(String[] args) {
        int width = StdIn.readInt();
        int height = StdIn.readInt();
        StdDraw.setCanvasSize(width, height);
        StdDraw.setXscale(0, width);
        StdDraw.setYscale(0, height);
        StdDraw.enableDoubleBuffering();

        int posNum;
        double[] aX;
        double[] aY;
        while (!StdIn.isEmpty()) {
            String line = StdIn.readString();
            if (line.matches(".*[a-zA-Z\\_]+.*")) {
//                StdOut.println(line);
                posNum = StdIn.readInt();
                aX = new double[posNum];
                aY = new double[posNum];
                for (int i = 0; i < posNum * 2; i = i + 2) {
                    aX[i/2] = StdIn.readDouble();
                    aY[i/2] = StdIn.readDouble();
//                    StdOut.println(aX[i/2]+"  "+aY[i/2]);
                }
                StdDraw.polygon(aX, aY);
            }
        }
        StdDraw.show();

    }
}
