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
public class  Problem5ClassTestParameterized{

	private Problem5Class graph;
	private double x, y;

    @Before
	public void setUp() throws Exception {
		graph = new Problem5Class();
	}

    @Parameters
    public static Collection<Object[]> data() {
        return Arrays.asList(new Object[][] {     
//				Parameters are: (1, 2)
//								1=x, 2=y
//				Test case 1
				{-4.01, 0.00},
//				Test case 20
				{-3.01, 0.99},
//				Test case 3
				{-2.00, 0.00},
//				Test case 4
				{-0.01, 7.96},
//				Test case 5
				{3.99, 0.06},
//				Test case 6
				{5.00, -1.00},
//				Test case 7
				{5.99, -0.01},
//				Test case 8
				{6.00, 0.00},
//				Test case 9
				{-4.00, 0.00},
//				Test case 10
				{-3.00, 1.00},
//				Test case 11
				{-1.99, 0.04},
//				Test case 12
				{0.00, 8.00},
//				Test case 13
				{4.00, 0.00},
//				Test case 14
				{5.01, -0.99},
//				Test case 15
				{-3.50, 0.50},
//				Test case 16
				{-2.50, 0.50},
//				Test case 17
				{-1.00, 4.00},
//				Test case 18
				{1.00, 9.00},
//				Test case 19
				{2.50, 6.75},
//				Test case 20
				{4.50, -0.50},
//				Test case 21
				{5.50, -0.50},
//				Test case 22
				{-5.00, 0.00},
//				Test case 23
				{8.00, 0.00}
       });
    }

    public Problem5ClassTestParameterized(double x, double y) {
    	this.x=x;
        this.y=y;
    }
	@Test
	public void test() {
		graph.setY(y);
        graph.calcY(x);
		assertEquals(y, graph.getY(), 0.01);
		}
}