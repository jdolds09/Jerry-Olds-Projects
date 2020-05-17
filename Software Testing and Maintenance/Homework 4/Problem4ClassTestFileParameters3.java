package Homework4;
import static junitparams.JUnitParamsRunner.$;
import static org.junit.Assert.*;

import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;
import junitparams.Parameters;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(JUnitParamsRunner.class)
public class Problem4ClassTestFileParameters3 {

	private Problem4Class storeDiscount;
	
	@Before
	public void setUp () {
		storeDiscount = new Problem4Class();
	}
	
	@Test
	@FileParameters("src/Homework4/Problem4TestCaseTable.csv")	
	public void test(double cart, boolean firstTimeBuyer, boolean goldStatus, int bonusPoints, double taxRate, double total, boolean memberBonus) {		
		storeDiscount.setTotal(total);
        storeDiscount.setMemberBonus(memberBonus);
        storeDiscount.determineMemberBonus(cart, firstTimeBuyer, goldStatus, bonusPoints, taxRate);
		assertEquals(total, storeDiscount.getTotal(), 0.001);
        assertEquals(memberBonus, storeDiscount.isMemberBonus());
	}
}