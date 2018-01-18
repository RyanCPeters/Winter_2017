/**
 * CSSKL 143 Week 2 Lab 1: ObjectList.
 *
 * @author Will O'Keeffe
 * @version 01/14/2018
 */

import java.io.*;
import java.util.*;
public class ObjectList
{
    // instance variables - replace the example below with your own
    private Object [] myFractions;
    private int numElements;
   
    /**
     * Constructor for objects of class ObjectList
     */
    public ObjectList()
    {
        myFractions = new Object [1];
        numElements = 0;
    }
    public ObjectList(int n)
    {
        myFractions = new Object [n];
        numElements = 0;
    }
    public void add(Object nx)
    {
        myFractions[numElements] = nx;
        numElements ++;
    }
    @Override//overrideing the method String toString();
    public String toString(){
        String retVal = "";
        for(int i = 0; i < numElements; i++)
            retVal += myFractions[i].toString() + "\n";        
        return retVal;
    }
    public Object getElement(int i){
        return myFractions[i];
    }
}

