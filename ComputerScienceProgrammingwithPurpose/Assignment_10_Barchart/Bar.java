import java.util.Arrays;

public class Bar implements Comparable<Bar> {
    private final String name;
    private final int value;
    private final String category;

    // Creates a new bar.
    public Bar(String name, int value, String category) {
        if (name == null || value < 0 || category == null)
            throw new IllegalArgumentException("bad arguments for constructor.");
        this.name = name;
        this.value = value;
        this.category = category;
    }

    // Returns the name of this bar.
    public String getName() {
        return this.name;
    }

    // Returns the value of this bar.
    public int getValue() {
        return this.value;
    }

    // Returns the category of this bar.
    public String getCategory() {
        return this.category;
    }

    // Compare two bars by value.
    public int compareTo(Bar that) {
        if (that == null)
            throw new NullPointerException("comparing to null.");
        if (this.value < that.value)
            return -1;
        else if (this.value > that.value)
            return 1;
        else
            return 0;
    }

    // Sample client (see below).
    public static void main(String[] args) {
        Bar[] bars = new Bar[2];
        bars[0] = new Bar("Beijing", 22674, "East Asia");
        bars[1] = new Bar("Cairo", 19850, "Middle East");

        Arrays.sort(bars);

    }

}