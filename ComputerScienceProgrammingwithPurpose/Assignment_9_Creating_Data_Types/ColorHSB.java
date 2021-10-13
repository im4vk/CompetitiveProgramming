/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

public class ColorHSB {
    private final int h;
    private final int s;
    private final int b;

    // Creates a color with hue h, saturation s, and brightness b.
    public ColorHSB(int h, int s, int b) {
        if (!(0 <= h && h <= 359)) throw new IllegalArgumentException();
        if (!(0 <= s && s <= 100)) throw new IllegalArgumentException();
        if (!(0 <= b && b <= 100)) throw new IllegalArgumentException();

        this.h = h;
        this.s = s;
        this.b = b;
    }

    // Returns a string representation of this color, using the format (h, s, b).
    public String toString() {
        return "(" + h + ", " + s + ", " + b + ")";
    }

    // Is this color a shade of gray?
    public boolean isGrayscale() {
        return s == 0 || b == 0;
    }

    // Returns the squared distance between the two colors.
    public int distanceSquaredTo(ColorHSB that) {
        if (that == null) throw new IllegalArgumentException();
        return (int) (diffH(that) + diffS(that) + diffB(that));
    }

    private double diffH(ColorHSB that) {
        double r1 = Math.pow(this.h - that.h, 2);
        double r2 = Math.pow(360 - Math.abs(this.h - that.h), 2);
        return r1 < r2 ? r1 : r2;
    }

    private double diffS(ColorHSB that) {
        return Math.pow(this.s - that.s, 2);
    }

    private double diffB(ColorHSB that) {
        return Math.pow(this.b - that.b, 2);
    }


    // Sample client (see below).
    public static void main(String[] args) {
        int h = Integer.parseInt(args[0]);
        int s = Integer.parseInt(args[1]);
        int b = Integer.parseInt(args[2]);

        ColorHSB oriColor = new ColorHSB(h, s, b);

        String matchedColorName = "Nothing to be matched yet";
        ColorHSB matchedColor = new ColorHSB(0, 0, 0);
        int dist = Integer.MAX_VALUE;

        while (!StdIn.isEmpty()) {
            String newName = StdIn.readString();
            int newH = StdIn.readInt();
            int newS = StdIn.readInt();
            int newB = StdIn.readInt();
            ColorHSB newColor = new ColorHSB(newH, newS, newB);
            int newDist = oriColor.distanceSquaredTo(newColor);
            if (dist > newDist) {
                dist = newDist;
                matchedColorName = newName;
                matchedColor = newColor;
            }
        }

        StdOut.println(matchedColorName + " " + matchedColor);

        // test distanceSquaredTo method
        // ColorHSB c1 = new ColorHSB(350, 100, 45);
        // ColorHSB c2 = new ColorHSB(0, 100, 50);
        // StdOut.println(c1.distanceSquaredTo(c2));
    }
}