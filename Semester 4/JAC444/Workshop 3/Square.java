package Shapes;

public class Square extends Rectangle{
    private double side;
    public Square(double s) throws InvalidSideException {
        super(s, s);
    }

    @Override
    public String toString(){
        return String.format("Square {s=%s} perimeter = %g\n\n", getLength(), perimeter());
    }
}
