package Homework4;
import static junitparams.JUnitParamsRunner.$;
import static org.junit.Assert.*;
import org.junit.Before;
import junitparams.JUnitParamsRunner;
import junitparams.Parameters;
import org.junit.Test;
import org.junit.runner.RunWith;


@RunWith(JUnitParamsRunner.class)
public class Problem4ClassTestJUnitParams {

	private Problem4Class storeDiscount;
	
	@SuppressWarnings("unused")
	private static final Object[] parametersForProblem4Class () {
		return $(
//				Parameters are: (1,2,3,4,5,6,7,8)
//								1=cart, 2=firstTimeBuyer, 3=goldStatus, 4=bonusPoints, 5=taxRate, 6=total, 7=memberBonus
//				Test case 1
				$(2_500.00,   true,   true,   750,  0.0825,  2_165.00,  true),
//				Test case 2
				$(1_500.01,   true,   true,   750,  0.0825,  1_380.19,  true),
//				Test case 3
				$(750.01,   true,   true,   750,  0.0825,  710.40,  true),
//				Test case 4
				$(500.00,   true,   true,   750,  0.0825,  487.12,  true),
//				Test case 5
				$(499.99,   true,   true,   750,  0.0825,  541.23,  true),
//				Test case 6
				$(1_000.01,   false,   true,   750,  0.0825,  947.19,  true),
//				Test case 7
				$(1_000.01,   false,   false,   751,  0.0825,  947.19,  true),
//				Test case 8
				$(1_000.00,   false,   false,   751,  0.0825,  947.18,  false),
//				Test case 9
				$(1_000.01,   false,   false,   750,  0.0825,  947.19,  false),
//				Test case 10
				$(0.00,   false,   false,   751,  0.0825,  0.00,  false),
//				Test case 11
				$(10_000.00,   false,   false,   751,  0.0825,  8_660.00,  true),
//				Test case 12
				$(750.00,   true,   true,   750,  0.0825,  730.68,  true),
//				Test case 13
				$(1_500.00,   true,   true,   750,  0.0825,  1_420.78,  true),
//				Test case 14
				$(2_499.99,   true,   true,   750,  0.0825,  2_300.30,  true),
//				Test case 15
				$(1_000.01,   true,   false,   750,  0.0825,  947.19,  true),
//				Test case 16
				$(2_499.99,   true,   true,   0,  0.0825,  2_300.30,  true),
//				Test case 17
				$(2_499.99,   true,   true,   1000,  0.0825,  2_300.30,  true)
		);
	}
	
	@Before
	public void setUp () {
		storeDiscount = new Problem4Class();
	}
	
	@Test
	@Parameters(method="parametersForProblem4Class")
	public void test(double cart, boolean firstTimeBuyer, boolean goldStatus, int bonusPoints, double taxRate, double total, boolean memberBonus) {
        storeDiscount.setTotal(total);
        storeDiscount.setMemberBonus(memberBonus);
        storeDiscount.determineMemberBonus(cart, firstTimeBuyer, goldStatus, bonusPoints, taxRate);
		assertEquals(total, storeDiscount.getTotal(), 0.001);
        assertEquals(memberBonus, storeDiscount.isMemberBonus());
	}

}