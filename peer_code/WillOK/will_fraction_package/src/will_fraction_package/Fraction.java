package will_fraction_package;

/**
 * Write a description of class will_fraction_package.Fraction here.
 *
 * @author Will O'Keeffe
 * @version 01/16/2018
 */
public class Fraction
  {
  // instance variables - replace the example below with your own
  private double numerator;
  private double denominator;
  //will_fraction_package.Fraction class to store your ratio in reduced form
  
  /**
   * Constructor for objects of class will_fraction_package.Fraction
   */
  public Fraction()
    {
    }
  
  /**
   * @param newN (int)
   * @param newD (int)
   */
  public Fraction(int newN, int newD)
    {
    if (newN % newD == 0) {
      numerator = newN / newD;
      denominator = 1;
    } else {
      numerator = newN;
      denominator = newD;
    }
    }
  
  /**
   * @param newN
   * @param newD
   */
  public Fraction(double newN, double newD)
    {
    if (newN % newD == 0) {
      numerator = newN / newD;
      denominator = 1;
    } else {
      numerator = newN;
      denominator = newD;
    }
    }
  
  /**
   * @param other
   * @return
   */
  public boolean equals(Fraction other)
    {
    return this.numerator / this.denominator == other.numerator / other.denominator;
    
    }
  
  /**
   * @return
   */
  @Override
  public String toString()
    {
    return numerator + "/" + denominator;
    }
  
  /**
   * @return
   */
  public double getNumerator()
    {
    return numerator;
    }
  
  /**
   * @return
   */
  public double getDenominator()
    {
    return denominator;
    }
  
  /**
   * @param newN
   * @param newD
   */
  public void setFraction(int newN, int newD)
    {
    if (newN % newD == 0) {
      numerator = newN / newD;
      denominator = 1;
    } else {
      numerator = newN;
      denominator = newD;
    }
    }
  
  /**
   * @param newN
   * @param newD
   */
  public void setFraction(double newN, double newD)
    {
    if (newN % newD == 0) {
      numerator = newN / newD;
      denominator = 1;
    } else {
      numerator = newN;
      denominator = newD;
    }
    }
  }
