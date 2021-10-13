public class RevesPuzzle {

  // hanoi solution for 3 columns
  private static void hanoi(int n, int k, String from, String to, String temp) {
    if (n == k) return;
    if (n == k + 1) {
      StdOut.println("Move disk " + n + " from " + from + " to " + to);
      return;
    }
    hanoi(n - 1, k, from, temp, to);
    StdOut.println("Move disk " + n + " from " + from + " to " + to);
    hanoi(n - 1, k, temp, to, from);
  }


  // hanoi Solution for 4 columns
  private static void reves(int n, String from, String temp1, String temp2, String to) {
    if (n == 1) {
      StdOut.println("Move disk " + n + " from " + from + " to " + to);
      return;
    }
    int k = (int) Math.round(n + 1.0 - (Math.sqrt(2.0 * n + 1)));
    reves(k, from, to, temp2, temp1);
    hanoi(n, k, from, to, temp2);
    reves(k, temp1, from, temp2, to);
  }

  // Take integer n from command line and formulate solution for Reves Puzzle with n disks
  public static void main(String[] args) {
    int n = Integer.parseInt(args[0]);
    reves(n, "A", "B", "C", "D");
  }
}