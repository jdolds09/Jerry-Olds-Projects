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
public class Problem5ClassTestFileParameters {

	private Problem5Class graph;
	
	@Before
	public void setUp () {
		graph = new Problem5Class();
	}
	
	@Test
	@FileParameters("src/Homework4/Problem5TestCaseTable.csv")	
	public void test(double x, double y) {		
		graph.setY(y);
        graph.calcY(x);
		assertEquals(y, graph.getY(), 0.01);
	}
}