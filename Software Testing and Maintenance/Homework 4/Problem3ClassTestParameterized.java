package Homework4;
import static org.junit.Assert.*;
import java.util.Arrays;
import java.util.Collection;
import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(Parameterized.class)
public class  Problem3ClassTestParameterized{

	private Problem3Class trafficLight;
	private double distance;
    private int count, count2;
    private boolean greenLight, yellowLight, redLight, buzzer, brakes;

    @Before
	public void setUp() throws Exception {
		trafficLight = new Problem3Class();
	}

    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {     
//			Parameters are: (1,2,3,4,5,6.7,8,9,10,11,12)
//			1=distance(ft), 2=count, 3=greenLight, 4=yellowLight, 5=redLight, 6=buzzer, 7=brakes, 8=count
//				Test case 1
				{400.0,   2,   true,   false,  false,  false,  false,  0},
//				Test case 2
				{95.1,   2,   false,   true,  false,  false,  false,  0},
//				Test case 3
				{50.0,   2,   false,   true,  false,  true,  false,  0},
//				Test case 4
				{25.1,   2,   false,   false,  true,  true,  false,  0},
//				Test case 5
				{25.0,   1,   false,   false,  true,  true,  false,  0},
//				Test case 6
				{25.0,   2,   false,   false,  true,  true,  true,  3},
//				Test case 7
				{49.9,   2,   false,   false,  true,  true,  false,  0},
//				Test case 8
				{95.0,   2,   false,   true,  false,  true,  false,  0},
//				Test case 9
				{399.9,   2,   false,   true,  false,  false,  false,  0},
//				Test case 10
				{25.0,   0,   false,   false,  true,  true,  true,  1},
//				Test case 11
				{0.0,   2,   false,   false,  true,  true,  true,  3},
//				Test case 12
				{1000.0,   2,   true,   false,  false,  false,  false,  0}
       });
    }

    public Problem3ClassTestParameterized(double distance, int count, boolean greenLight, boolean yellowLight, boolean redLight, boolean buzzer, boolean brakes, int count2) {
    	this.distance=distance;
    	this.count=count;
    	this.count2=count2;
    	this.greenLight=greenLight;
    	this.yellowLight=yellowLight;
        this.redLight=redLight;
        this.buzzer=buzzer;
        this.brakes=brakes;
    }
	@Test
	public void test() {
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
