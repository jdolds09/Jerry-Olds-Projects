package Homework4;
import static org.junit.Assert.*;
import java.util.Arrays;
import java.util.Collection;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class  Problem4ClassTestParameterized{

	private Problem4Class storeDiscount;
	private double cart, taxRate, total;
    private int bonusPoints;
    private boolean firstTimeBuyer, goldStatus, memberBonus;

    @Before
	public void setUp() throws Exception {
		storeDiscount = new Problem4Class();
	}

    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {     
//				Parameters are: (1,2,3,4,5,6,7,8)
//								1=cart, 2=firstTimeBuyer, 3=goldStatus, 4=bonusPoints, 5=taxRate, 6=total, 7=memberBonus
//				Test case 1
				{2_500.00,   true,   true,   750,  0.0825,  2_165.00,  true},
//				Test case 2
				{1_500.01,   true,   true,   750,  0.0825,  1_380.19,  true},
//				Test case 3
				{750.01,   true,   true,   750,  0.0825,  710.40,  true},
//				Test case 4
				{500.00,   true,   true,   750,  0.0825,  487.12,  true},
//				Test case 5
				{499.99,   true,   true,   750,  0.0825,  541.23,  true},
//				Test case 6
				{1_000.01,   false,   true,   750,  0.0825,  947.19,  true},
//				Test case 7
				{1_000.01,   false,   false,   751,  0.0825,  947.19,  true},
//				Test case 8
				{1_000.00,   false,   false,   751,  0.0825,  947.18,  false},
//				Test case 9
				{1_000.01,   false,   false,   750,  0.0825,  947.19,  false},
//				Test case 10
				{0.00,   false,   false,   751,  0.0825,  0.00,  false},
//				Test case 11
				{10_000.00,   false,   false,   751,  0.0825,  8_660.00,  true},
//				Test case 12
				{750.00,   true,   true,   750,  0.0825,  730.68,  true},
//				Test case 13
				{1_500.00,   true,   true,   750,  0.0825,  1_420.78,  true},
//				Test case 14
				{2_499.99,   true,   true,   750,  0.0825,  2_300.30,  true},
//				Test case 15
				{1_000.01,   true,   false,   750,  0.0825,  947.19,  true},
//				Test case 16
				{2_499.99,   true,   true,   0,  0.0825,  2_300.30,  true},
//				Test case 17
				{2_499.99,   true,   true,   1000,  0.0825,  2_300.30,  true}
       });
    }

    public Problem4ClassTestParameterized(double cart, boolean firstTimeBuyer, boolean goldStatus, int bonusPoints, double taxRate, double total, boolean memberBonus) {
    	this.cart=cart;
    	this.firstTimeBuyer=firstTimeBuyer;
    	this.goldStatus=goldStatus;
    	this.bonusPoints=bonusPoints;
        this.taxRate=taxRate;
        this.total=total;
        this.memberBonus=memberBonus;
    }
	@Test
	public void test() {
		storeDiscount.setTotal(total);
        storeDiscount.setMemberBonus(memberBonus);
        storeDiscount.determineMemberBonus(cart, firstTimeBuyer, goldStatus, bonusPoints, taxRate);
		assertEquals(total, storeDiscount.getTotal(), 0.01);
        assertEquals(memberBonus, storeDiscount.isMemberBonus());
		}
}
