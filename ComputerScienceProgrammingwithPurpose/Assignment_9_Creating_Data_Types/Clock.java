/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

public class Clock {
    private int h;
    private int m;

    // Creates a clock whose initial time is h hours and m minutes.
    public Clock(int h, int m) {
        validate(h, m);
        this.h = h;
        this.m = m;
    }

    // Creates a clock whose initial time is specified as a string, using the format HH:MM.
    public Clock(String s) {
        if (!s.matches("^\\d{2}:\\d{2}$")) throw new IllegalArgumentException();
        String[] args = s.split(":");

        int newh = Integer.parseInt(args[0]);
        int newm = Integer.parseInt(args[1]);

        validate(newh, newm);
        this.h = newh;
        this.m = newm;
    }

    private void validate(int h, int m) {
        if (!(0 <= h && h <= 23)) throw new IllegalArgumentException();
        if (!(0 <= m && m <= 59)) throw new IllegalArgumentException();
    }

    // Returns a string representation of this clock, using the format HH:MM.
    public String toString() {
        String hour;
        String minu;
        hour = h < 10 ? "0" + h : "" + h;
        minu = m < 10 ? "0" + m : "" + m;
        return hour + ":" + minu;
    }

    // Is the time on this clock earlier than the time on that one?
    public boolean isEarlierThan(Clock that) {
        if (this.h < that.h) return true;
        if (this.h > that.h) return false;
        if (this.m < that.m) return true;
        if (this.m > that.m) return false;
        return false;
    }

    // Adds 1 minute to the time on this clock.
    public void tic() {
        if (m == 59) {
            m = 0;
            h += 1;
        }
        else m += 1;

        if (h == 24)
            h = 0;
    }


    // Adds Δ minutes to the time on this clock.
    public void toc(int delta) {
        if (delta < 0) throw new IllegalArgumentException();
        while (delta > 0) {
            tic();
            delta--;
        }
    }

    // Test client (see below).
    public static void main(String[] args) {
        Clock c = new Clock("00:00");
        StdOut.println(c);
        c.tic();
        StdOut.println(c);
        c.toc(60);
        StdOut.println(c);
    }

}
