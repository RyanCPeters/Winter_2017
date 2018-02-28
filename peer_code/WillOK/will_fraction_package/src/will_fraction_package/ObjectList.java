package will_fraction_package;

/**
 * CSSKL 143 Week 2 Lab 1: will_fraction_package.ObjectList.
 *
 * @author Will O'Keeffe
 * @version 01/14/2018
 */

import java.util.ArrayList;
import java.util.stream.Collectors;


public class ObjectList
  {
  // instance variables - replace the example below with your own
  private ArrayList<Fraction> myFractions;
  private int numElements;
  
  /**
   * Constructor for objects of class will_fraction_package.ObjectList
   */
  public ObjectList()
    {
    myFractions = new ArrayList<>();
    numElements = 0;
    }
  
  /**
   * @param n
   */
  public ObjectList(int n)
    {
    myFractions = new ArrayList<>(n);
    numElements = 0;
    }
  
  /**
   * @param nx
   */
  public void add(Fraction nx)
    {
    myFractions.add(nx);
    ++numElements;
    }
  
  /**
   * @return
   */
  @Override//overrideing the method String toString();
  public String toString()
    {
    String retVal = myFractions.stream().map(i -> i.toString()).collect(Collectors.joining("\n"));
    return retVal;
    }
  
  /**
   * @param position
   * @return
   */
  public Fraction getElement(int position)
    {
    return myFractions.get(position);
    }
  }

