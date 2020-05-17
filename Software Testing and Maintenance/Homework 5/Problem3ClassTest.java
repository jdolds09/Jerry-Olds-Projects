package Homework5;
import static org.junit.Assert.*;

import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(JUnitParamsRunner.class)
public class Problem3ClassTest {

	private Problem3Class train;
	
	@Before
	public void setUp () {
		train = new Problem3Class();
	}
	
	@Test
	@FileParameters("src/Homework5/Problem3TestCaseTable.csv")	
	public void test(int boxInCarNum, int rrCarNum, int shipmentNum, int expectedBoxNumber) {		
		assertEquals(expectedBoxNumber, train.calcPrevBoxNumber(boxInCarNum, rrCarNum, shipmentNum));
    }
}