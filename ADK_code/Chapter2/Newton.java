/**
 * @file Newton.java   Java Example of Newton's method.
 * @brief
 *    Java implementation of Newton's method that also shows the binary digits
 * of the resulting floating point value to provide a sense of the
 * convergance of the approach.
 * 
 * @author George Heineman
 * @date 6/15/08
 */
public class Newton {

    /** The function whose roots are to be computed. */
    static double f(double x) {
	return x*Math.sin(x)-5*x-Math.cos(x);
    }

    /** The derivating of the function whose roots are to be computed. */
    static double fd(double x) {
	return x*Math.cos(x)+Math.sin(x)-5-Math.sin(x);
    }

    /** Launch Newton's method for ten steps. */
    public static void main (String []args) {
	double x = 0;
	for (int i = 0; i < 10; i++) {
	    System.out.println (x + " , " + Long.toBinaryString(Double.doubleToRawLongBits(x)));
	    x = x - f(x)/fd(x);
	}
    }
}
