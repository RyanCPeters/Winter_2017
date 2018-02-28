package will_fraction_package;
/**
 * Write a description of class will_fraction_package.FractionsV2Driver here.
 *
 * @author Will O'Keeffe
 * @version (a version number or a date)
 */

//imports necessary libraries

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FractionsV2Driver
  {
  public static void main(String[] args)
    {
    int SIZE = 1000; //"global" variable
    String fileName = "fractions.txt";
    ObjectList fractions = new ObjectList(SIZE);
    int length = buildList(fileName, fractions);
    /* TESTING*/
    System.out.print("Fractions: \n" + fractions.toString() + "\nlegnth: " + length);
    /* END TESTING */
    countRepeats(fractions, length);
    }
  
  /**
   * @param list : type OvjectList; a list of fractions (type will_fraction_package.ObjectList)
   * @param file : type String; file to be read from (type String)
   *             <p>
   *             buildList reads fraction from file and then adds it as a will_fraction_package.Fraction object to
   *             the list of fractions
   */
  public static int buildList(String file, ObjectList list)
    {
    FileInputStream fos = null;
    Scanner in = null;
    int fractionCounter = 0;
    try {
      in = new Scanner(new FileInputStream("fractions.txt"));
      while (in.hasNextLine()) {
        String line = in.nextLine();
        String[] split = line.split("/");
        Fraction curr = new Fraction(Integer.valueOf(split[0]), Integer.valueOf(split[1]));
        list.add(curr);
        fractionCounter++;
      }
      in.close();
    } catch (FileNotFoundException e) {
      System.out.println("Could not locate file fractions.txt in current directory");
      System.exit(0);
    }
    return fractionCounter++;
    }
  
  private static boolean countRepeatsHelperMethod(Fraction curr, Fraction fromList)
    {
    return fromList == curr &&
           fromList.getNumerator() / curr.getNumerator() == fromList.getDenominator() / curr.getDenominator();
    }
  
  /**
   * @param list of fractions 'list' (type will_fraction_package.ObjectList)
   * @param size of array (the global variable, lenght of occupied space in will_fraction_package.ObjectList []
   *             fractions)
   *             <p>
   *             countRepeats counts the occurances of a cerian instance of a ratio, reporting the lowest value
   *             occurance.
   *             prints most reduced fraction in list with number of occurances to console.
   */
  public static void countRepeats(ObjectList list, int size)
    {
    int[] counts = new int[size];
    for (int i = 0; i < size; ++i) {
      Fraction curr =
          list.getElement(i);/*  Ryan: I want this to be a fraction type , but cannot get it to work that way  */
      double currN = curr.getNumerator();
      double currD = curr.getDenominator();
      for (int j = 0; j < size; ++j) {
        if (countRepeatsHelperMethod(curr, list.getElement(j))) {
          //allows for access of fraction counts neq 0 in order we want to display
          if (list.getElement(j).getNumerator() < curr.getNumerator()) {
            counts[j] = counts[i] + 1;
            counts[i] = 0;
          } else {
            ++counts[i];
            counts[j] = 0;
          }
        }
      }
    }
    for (int i = 0; i < counts.length; i++) {
      if (counts[i] != 0)
        System.out.println(list.getElement(i) + " has a count of: " + counts[i]);
    }
    }
  }
