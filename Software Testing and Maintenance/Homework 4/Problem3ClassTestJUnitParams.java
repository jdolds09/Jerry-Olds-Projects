package Homework4;
import static junitparams.JUnitParamsRunner.$;
import static org.junit.Assert.*;
import org.junit.Before;
import junitparams.JUnitParamsRunner;
import junitparams.Parameters;
import org.junit.Test;
import org.junit.runner.RunWith;


@RunWith(JUnitParamsRunner.class)
public class Problem3ClassTestJUnitParams {

	private Problem3Class trafficLight;
	
	@SuppressWarnings("unused")
	private static final Object[] parametersForProblem3Class () {
		return $(
//				Parameters are: (1,2,3,4,5,6,7,8)
//								1=distance(ft), 2=count, 3=greenLight, 4=yellowLight, 5=redLight, 6=buzzer, 7=brakes, 8=count
//				Test case 1
				$(400.0,   2,   true,   false,  false,  false,  false,  0),
//				Test case 2
				$(95.1,   2,   false,   true,  false,  false,  false,  0),
//				Test case 3
				$(50.0,   2,   false,   true,  false,  true,  false,  0),
//				Test case 4
				$(25.1,   2,   false,   false,  true,  true,  false,  0),
//				Test case 5
				$(25.0,   1,   false,   false,  true,  true,  false,  0),
//				Test case 6
				$(25.0,   2,   false,   false,  true,  true,  true,  3),
//				Test case 7
				$(49.9,   2,   false,   false,  true,  true,  false,  0),
//				Test case 8
				$(95.0,   2,   false,   true,  false,  true,  false,  0),
//				Test case 9
				$(399.9,   2,   false,   true,  false,  false,  false,  0),
//				Test case 10
				$(25.0,   0,   false,   false,  true,  true,  true,  1),
//				Test case 11
				$(0.0,   2,   false,   false,  true,  true,  true,  3),
//				Test case 12
				$(1000.0,   2,   true,   false,  false,  false,  false,  0)              
		);
	}
	
	@Before
	public void setUp () {
		trafficLight = new Problem3Class();
	}
	
	@Test
	@Parameters(method="parametersForProblem3Class")
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