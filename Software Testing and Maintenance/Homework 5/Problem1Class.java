package Homework5;

public class Problem1Class {
	
	private double total;
	private boolean specialOrderStatus;

	public void specialOrder (boolean deepDish, double ordAmount, int numPizzas) {

		double discount;
		if (ordAmount >= 500.01)
			discount = 0.80;
		else
			if (ordAmount >= 250.01)
				discount = 0.85;
			else
				if (ordAmount >= 100.01)
					discount = 0.90;
				else
					if (ordAmount >= 50.01)
						discount = 0.95;
					else
						discount = 1.0;
		total = ordAmount*(discount)*1.0825;
				
		specialOrderStatus = (deepDish) && ((ordAmount > 50.0) || (numPizzas > 4)) || (!deepDish);
		}

	public double getTotal() {
		return total;
	}

	public void setTotal(double total) {
		this.total = total;
	}

	public boolean isSpecialOrderStatus() {
		return specialOrderStatus;
	}

	public void setSpecialOrderStatus(boolean specialOrderStatus) {
		this.specialOrderStatus = specialOrderStatus;
	}
	
}