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
public class Problem3ClassTestFileParameters {

	private Problem3Class trafficLight;
	
	@Before
	public void setUp () {
		trafficLight = new Problem3Class();
	}
	
	@Test
	@FileParameters("src/Homework4/Problem3TestCaseTable.csv")	
	public void test(double distance, int count, boolean greenLight, boolean yellowLight, boolean redLight, boolean buzzer, boolean brakes, int count2) {		
		trafficLight.setCount(count);
        trafficLight.setBrakes(brakes);
        trafficLight.setRedLight(redLight);
        trafficLight.setYellowLight(yellowLight);
        trafficLight.setGreenLight(greenLight);
        trafficLight.setBuzzer(buzzer);
        trafficLight.setWarnings(distance);
		assertEquals(count2, trafficLight.getCount());
        assertEquals(brakes, trafficLight.isBrakes());
        assertEquals(redLight, trafficLight.isRedLight());
        assertEquals(yellowLight, trafficLight.isYellowLight());
        assertEquals(greenLight, trafficLight.isGreenLight());
        assertEquals(buzzer, trafficLight.isBuzzer());
	}
}