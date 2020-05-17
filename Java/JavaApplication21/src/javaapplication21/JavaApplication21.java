/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication21;

import static java.lang.Math.pow;

/**
 *
 * @author jdold
 */
public class JavaApplication21 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int number;
        number = puzzle();
        System.out.println(number);
    }
    public static int puzzle()
    {
        int count = 10000;
        int value = 0;
        int v, a, l, u, e;
        int sum;
        int cubed;
        boolean notFound = true;
        while(notFound)
        {
            value = count;
            v = count / 10000;
            count %= 10000;
            a = count / 1000;
            count %= 1000;
            l = count / 100;
            count %= 100;
            u = count / 10;
            count %= 10;
            e = count;
            sum = v + a + l + u + e;
            cubed = (int) pow(sum, 3);
            if(cubed == value)
            {
                notFound = false;
            }
            count = value;
            count++;
        }
        return value;
    }
}
