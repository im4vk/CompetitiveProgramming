public class ActivationFunction {

    // Returns the Heaviside function of x.
    public static double heaviside(double x) {
        if (x < 0.0) return 0.0;
        else if (x == 0.0) return 0.5;
        else return 1.0;
    }

    // Returns the sigmoid function of x.
    public static double sigmoid(double x) {
        return 1.0 / (1.0 + Math.exp(-x));
    }

    // Returns the hyperbolic tangent of x.
    public static double tanh(double x) {
        return (Math.exp(x) - Math.exp(-x)) / (Math.exp(x) + Math.exp(-x));
    }

    // Returns the softsign function of x.
    public static double softsign(double x) {
        return x / (1.0 + Math.abs(x));
    }

    // Returns the square nonlinearity function of x.
     public static double sqnl(double x) {
         double a = 4.0;
         if (x <= -2.0) return -1.0;
         if (-2.0 < x && x < 0.0) return (x + x * x / a);
         if (0.0 <= x && x < 2.0) return (x - x * x / a);
         return 1.0;
     }
    // Takes a double command-line argument x and prints each activation
    // function, evaluated, in the format (and order) given below.
     public static void main(String[] args) {
         double x = Double.parseDouble(args[0]);
         StdOut.println("heaviside(" + x + ") = " + heaviside(x));
         StdOut.println("  sigmoid(" + x + ") = " + sigmoid(x));
         StdOut.println("     tanh(" + x + ") = " + tanh(x));
         StdOut.println(" softsign(" + x + ") = " + softsign(x));
         StdOut.println("     sqnl(" + x + ") = " + sqnl(x));
     }
         
}