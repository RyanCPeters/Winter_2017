
/**
 * Write a description of class FractionCounter here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class FractionCounter
{
    // instance variables - replace the example below with your own
    private int counter;
    private Fraction fraction;

    /**
     * Constructor for objects of class FractionCounter
     */
    public FractionCounter(Fraction theFraction)
    {
        fraction = theFraction;
    }

    /**
     * An example of a method - replace this comment with your own
     *
     * @param Fraction theFraction
     * @return    the sum of x and y
     */
    public boolean comapre(Fraction curr){
        return fraction.equals(curr);
    }
    public void toString(Fraction curr){
        System.out.println(curr.toString() + " has a count of " + counter);
    }
}
