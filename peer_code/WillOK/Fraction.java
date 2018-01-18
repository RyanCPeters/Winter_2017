
/**
 * Write a description of class Fraction here.
 *
 * @author Will O'Keeffe
 * @version 01/16/2018
 */
public class Fraction
{
    // instance variables - replace the example below with your own
    private double numerator ;
    private double denominator;
    //Fraction class to store your ratio in reduced form
    /**
     * Constructor for objects of class Fraction
     */
    public Fraction()
    {
    }
    /**
     * @param new numerator (int)
     * @param new denominator (int)
     */
    public Fraction(int newN, int newD){
        if(newN % newD == 0){
            numerator = newN/newD;
            denominator = 1;
        }
        else{
            numerator = newN;
            denominator = newD;
        }
    }
    /**
     * @param new numerator (double)
     * @param new denominator (double)
     */
    public Fraction(double newN, double newD){
        if(newN % newD == 0){
            numerator = newN/newD;
            denominator = 1;
        }
        else{
            numerator = newN;
            denominator = newD;
        }
    }
    /**
     * @param Fraction other: a fraction to cmpare current fraction instance to
     * @return boolean: true if equal ratio false otherwise
     */
    public boolean equals(Fraction other){
        if(this.numerator/this.denominator == other.numerator/other.denominator)
            return true;
        return false;
    }
    @Override
    /**
     * @param: none
     * @return string of the fraction
     */
    public String toString(){
        return numerator + "/" + denominator;
    }
    /**
     * @return numerator (double)
     */
    public double getNumerator(){
        return numerator;
    }
    /**
     * @return denominator
     */
    public double getDenominator(){
        return denominator;
    }
    public void setFraction(int newN, int newD){
        if(newN % newD == 0){
            numerator = newN/newD;
            denominator = 1;
        }
        else{
            numerator = newN;
            denominator = newD;
        }
    }
    public void setFraction(double newN, double newD){
        if(newN % newD == 0){
            numerator = newN/newD;
            denominator = 1;
        }
        else{
            numerator = newN;
            denominator = newD;
        }
    }
}
