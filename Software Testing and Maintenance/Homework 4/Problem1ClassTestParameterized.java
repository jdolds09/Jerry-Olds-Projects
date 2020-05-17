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
public class  Problem1ClassTestParameterized{

	private Problem1Class rateDecider;
	private double cart, rate;
    private boolean member, primeStatus;

    @Before
	public void setUp() throws Exception {
		rateDecider = new Problem1Class();
	}

    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {     
//			Parameters are: (1,2,3,4)
//			1=member, 2=primeStatus, 3=cart, 4=rate
//				Test case 1
				{true,   true,     5_000.00,   0.950},
//				Test case 2
				{false,   true,	5_000.00,   0.975},
//				Test case 3
				{true,   false,	5_000.00,   0.925},
//				Test case 4
			    {false,   false,   5_000.00,   0.965},
//				Test case 5
				{true,  true,		4_999.99,   0.900},
//				Test case 6
				{true,  false,		4_999.99,   0.950},
//				Test case 7
				{false,  true,		4_999.99,   0.955},
//				Test case 8
				{false,  false,	4_999.99,   0.985},
//				Test case 9
				{true,  true,		0.00,   0.900},
//				Test case 10
				{true,  true,		10_000.00,  0.950}
       });
    }

    public Problem1ClassTestParameterized(boolean member, boolean primeStatus, double cart, double rate) {
    	this.member=member;
    	this.primeStatus=primeStatus;
    	this.cart=cart;
    	this.rate=rate;
    }
	@Test
	public void test() {
		assertEquals(rate, rateDecider.calcRate(member, primeStatus, cart), 0.001);
		}
}
