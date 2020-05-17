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
public class Problem2ClassTestFileParameters2 {

	private Problem2Class conditions;
	
	@Before
	public void setUp () {
		conditions = new Problem2Class();
	}
	
	@Test
	@FileParameters("src/Homework4/Problem2TestCaseTable.csv")	
	public void test(Problem2ClassStatus status, double temp, double pressure, boolean result) {		
		assertEquals(result, conditions.highPressCell(status, temp, pressure));
	}
}