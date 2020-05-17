package FileParam;
import static junitparams.JUnitParamsRunner.$;
import static org.junit.Assert.*;

import junitparams.FileParameters;
import junitparams.JUnitParamsRunner;
import junitparams.Parameters;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;

import Code.microwaveClass;

@RunWith(JUnitParamsRunner.class)
public class microwaveClassTest {

	private microwaveClass micOven;
	
	@Before
	public void setUp () {
		micOven = new microwaveClass(false, false, 0);
	}
	
	@Test
	@FileParameters("src/FileParam/microwave.csv")	
	public void test(int testcaseNumber, boolean cooking, boolean doorOpen, boolean stopButton, int timer, boolean cookState_res, boolean stop_res, int timer_res, String bpNumber) {		
		micOven.setTimer(timer);
		micOven.operateMicrowave(cooking, doorOpen, stopButton);
		assertEquals(cookState_res,micOven.isCookState());
		assertEquals(stop_res,micOven.isStop());
		assertEquals(timer_res,micOven.getTimer());
	}
}