package Shapes;

public class Square extends Rectangle{
    private double side;
    private ShapeArea squareArea = () -> getLength() * getLength();
    public Square(double s) throws InvalidSideException {
        super(s, s);
    }

    public double getSquareArea(){
        return squareArea.getArea();
    }

    @Override
    public String toString(){
        return String.format("Square {s=%s} perimeter = %g area = %.5f\n\n", getLength(), perimeter(), getSquareArea());
    }
}
