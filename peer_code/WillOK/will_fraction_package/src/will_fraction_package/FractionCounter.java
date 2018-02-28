package will_fraction_package;

/**
 * Write a description of class will_fraction_package.FractionCounter here.
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
   * Constructor for objects of class will_fraction_package.FractionCounter
   */
  public FractionCounter(Fraction theFraction)
    {
    fraction = theFraction;
    }
  
  /**
   * An example of a method - replace this comment with your own
   *
   * @param curr : type Fraction; the Fraction that the class state member "Fraction fraction" will be compared
   *             against
   * @return the sum of x and y
   */
  public boolean comapre(Fraction curr)
    {
    return fraction.equals(curr);
    }
  
  public void toString(Fraction curr)
    {
    System.out.println(curr.toString() + " has a count of " + counter);
    }
  }
