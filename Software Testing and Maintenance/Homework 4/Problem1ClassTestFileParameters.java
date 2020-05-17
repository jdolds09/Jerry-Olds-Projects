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
public class Problem1ClassTestFileParameters {

	private Problem1Class rateDecider;
	
	@Before
	public void setUp () {
		rateDecider = new Problem1Class();
	}
	
	@Test
	@FileParameters("src/Homework4/Problem1TestCaseTable.csv")	
	public void test(boolean member, boolean primeStatus, double cart, double rate) {		
		assertEquals(rate, rateDecider.calcRate(member, primeStatus, cart), 0.001);
	}
}