package shapes;

/** This class creates a shape of type circle */
public class Circle implements Shape {

	/** circle's radius */
	private double radius;

	/**
	 * Constructor accepts a double for the radius, throws exception if data is not valid
	 * @param radius A positive double representing the radius of the circle
	 * */
	public Circle(double radius) throws CircleException {
		if(radius > 0)
			this.radius = radius;
		else
			throw new CircleException("Invalid radius!");
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) throws CircleException {
		if(radius > 0)
			this.radius = radius;
		else
			throw new CircleException("Invalid radius!");
	}

	/**
	 * Getting the perimeter of the circle
	 * @return a double indicating the perimeter of the circle
	 * */
	@Override
	public double getPerimeter() {
		return 2 * Math.PI * getRadius();
	}


	/**
	 * Returning a String representing the circle
	 * @return a String representing the circle
	 * */
	@Override
	public String toString(){ 
		return "Circle {r=" + getRadius() + "}";
	}

}