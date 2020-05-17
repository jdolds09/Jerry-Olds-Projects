package Homework5;
import static org.junit.Assert.*;

import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(JUnitParamsRunner.class)
public class Problem1ClassTest {

	private Problem1Class order;
	
	@Before
	public void setUp () {
		order = new Problem1Class();
	}
	
	@Test
	@FileParameters("src/Homework5/Problem1TestCaseTable.csv")	
	public void test(boolean deepDish, double ordAmount, int numPizzas, boolean specialOrderStatus, double total) {		
		order.setTotal(total);
        order.setSpecialOrderStatus(specialOrderStatus);
        order.specialOrder(deepDish, ordAmount, numPizzas);
		assertEquals(total, order.getTotal(), 0.01);
        assertEquals(specialOrderStatus, order.isSpecialOrderStatus());
    }
}