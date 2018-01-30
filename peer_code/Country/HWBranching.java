/**
 * Eli Countrywood; CSC 110 A; Jan 28 2018
 * This program asks a user for the sales numbers of three stores
 * and a sales threshold. If a store's sales are over the threshold,
 * that is reported in a sales report along with the average sales
 * of those stores which sold more than the threshold amount.
 */
import java.util.Scanner;

public class HWBranching {
    // private member fields of HWBranching
//  private float salesStore1, salesStore2, salesStore3, salesThreshold;


    /**
     * use the scanner class to get sales data and threshold value from user.
     */
    public static void getSalesDataFromUser(){
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Please enter Store 1 sales: ");
        float salesStore1 = keyboard.nextFloat();
        System.out.println("Please enter Store 2 sales: ");
        float salesStore2 = keyboard.nextFloat();
        System.out.println("Please enter Store 3 sales: ");
        float salesStore3 = keyboard.nextFloat();
        System.out.println("Please enter a sales threshold: ");
        float salesThreshold = keyboard.nextFloat();
    }

    /**
     * use branching to parse sales data
     */
    public static void processSalesData(){
        float sumHighSales = 0;
        int countHighSales = 0;
        if(salesStore1 > salesThreshold){
            // do stuff
        }
    }
    /**
     * calculate the average sales of the high sales stores
     */
    public static void calculateAverageHighSales(){

    }
    /**
     * report the findings of the report:
     * 1) Stores that have high sales
     * 2) Average sales of the high-sales stores
     */
    public static void generateSalesReport(){

    }
}