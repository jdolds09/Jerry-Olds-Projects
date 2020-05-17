/*
 * CSE 1305-005
 * Lab 3 Part 2
 */
package lab3part2;

/**
 *
 * @author Jerry Olds
 */
public class Lab3Part2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int dayA = 5;
        int monthA = 1;
        String monthAName = "January";
        int yearA = 1935;
        int dayB = 15;
        int monthB = 10;
        String monthBName = "October";
        int yearB = 1963;
        
        boolean laterDay, laterMonth, laterYear;
        boolean laterMonthName;
        
        String subAName = monthAName.substring(0,3);
        String sp = "";
        String sl = "/";
        System.out.println("Values to test with: dateA (monthA/dayA/yearA)"+monthA+sl+dayA+sl+yearA
                +", dateB "+monthB+sl+dayB+sl+yearB);
        System.out.printf("Strings: monthAName is \"%s\", monthBName is \"%s\", and subAName is \"%s\"\n",
                monthAName, monthBName, subAName);
       
        boolean bLogic1, bLogic2, bLogic3;
        boolean bRela1, bRela2, bRela3;
        boolean bString1, bString2, bString3;
        boolean poop;
        
        bRela1 = (dayA > dayB);
        bRela2 = (monthA < monthB);
        bRela3 = (yearA == yearB);
        System.out.println();
        
        System.out.println("Relational operator tests");
        System.out.println("bRela1 is (dayA > dayB) ** "+bRela1);
        System.out.println("bRela2 is (monthA < monthB) ** "+bRela2);
        System.out.println("bRela3 is (yearA == yearB) ** "+bRela3);
        
        bLogic1 = (yearB > yearA) && bRela2;
        bLogic2 =!(bRela3);
        bLogic3 =!(bRela1 || bLogic1);
        System.out.println();
        
        System.out.println("Logical operator tests");
        System.out.println("bLogic1 is (yearB > yearA) && bRela2 ** " +bLogic1);
        System.out.println("bLogic2 is !(bRela3) ** "+bLogic2);
        System.out.println("bLogic3 is  !(bRela1 || bLogic1) ** "+bLogic3); 

        bString1 = (monthAName == monthBName);
        bString2 = (monthAName.equals(monthBName)); 
        bString3 = (monthBName.equalsIgnoreCase("october"));    
        System.out.println();

        System.out.println("String equality tests");
        System.out.println("bString1 is (monthAName == monthBName) ** "+bString1);
        System.out.println("bString2 is (monthAName.equals(monthBName)) ** "+bString2);
        System.out.println("bString3 is (monthBName.equalsIgnoreCase(\"october\")) ** "+bString3);  

        bString1 = (("May".compareTo(subAName)) < 0);
        bString2 = (("May".compareTo(subAName)) == 0);   
        bString3 = (("May".compareTo(subAName)) > 0);  // lexigraphic comparisons 
        System.out.println();

        System.out.println("Comparison tests for ordering");
        System.out.println("bString1 is ((\"May\".compareTo(\""+subAName+"\")) < 0) ** "+bString1);
        System.out.println("bString2 is ((\"May\".compareTo(\""+subAName+"\")) == 0) ** "+bString2);
        System.out.println("bString3 is ((\"May\".compareTo(\""+subAName+"\")) > 0) ** "+bString3);
        poop = (!false || (yearA != yearB)) || ((monthBName.compareTo(monthAName) > 0)&&true);
        System.out.println(poop);
    }
    
}
