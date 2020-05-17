package Homework5;

import static org.junit.Assert.assertEquals;
import org.easymock.EasyMock;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;

@RunWith(JUnitParamsRunner.class)
public class Problem4ClassTest {

	int points;
	Problem4ServerData mockobj;
	Problem4Class transaction;
	
	@Before
	public void setUp() {
		transaction = new Problem4Class();
		mockobj = EasyMock.strictMock(Problem4ServerData.class);
	}
	
	@Test
	@FileParameters("src/Homework5/Problem2TestCaseTable.csv")
	public void test (boolean existingMember, boolean validDiscount, int memberPoints, double total, double result) {
		EasyMock.expect(mockobj.getMemberPoints()).andReturn(memberPoints);
		EasyMock.replay(mockobj);
		assertEquals(result, transaction.calcTotal(total, existingMember, validDiscount, mockobj), 0.01);
	}
}