package Homework5;
import static org.junit.Assert.*;

import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(JUnitParamsRunner.class)
public class Problem2ClassTest {

	private Problem2Class transaction;
	
	@Before
	public void setUp () {
		transaction = new Problem2Class();
	}
	
	@Test
	@FileParameters("src/Homework5/Problem2TestCaseTable.csv")	
	public void test(boolean existingMember, boolean validDiscount, int memberPoints, double total, double result) {		
		assertEquals(result, transaction.calcTotal(total, existingMember, validDiscount, memberPoints), 0.01);
    }
}