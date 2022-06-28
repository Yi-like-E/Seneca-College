package Shapes;

public class Parallelogram extends Rectangle{
    private double width;
    private double height;
    public Parallelogram(double w, double h) throws InvalidSideException {
        super(w, h);
    }

    @Override
    public String toString(){
        return String.format("Parallelogram {w=%s, h=%s} perimeter = %g\n\n", getWidth(),getLength(), perimeter());
    }
}
