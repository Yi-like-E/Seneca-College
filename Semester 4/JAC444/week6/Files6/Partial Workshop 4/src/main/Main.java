package main;

import shapes.Circle;
import shapes.CircleException;

public class Main {
	public static void main(String[] args) {
		Circle c1 = null;
		
		try {
			c1 = new Circle(1);
		} catch (CircleException e) {
			System.out.println(e.getMessage());
		}
		finally {
			System.out.println(c1);
		}
	}
}
