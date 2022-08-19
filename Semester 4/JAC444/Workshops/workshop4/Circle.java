package Shapes;

public class Circle implements Shape{
    private double radius;

    public Circle (double r) throws InvalidSideException {
        if(r > 0){
            this.radius = r;
        } else{
            throw new InvalidSideException("Invalid radius!");
        }
    }

    public void setRadius(double r){
        radius = r;
    }

    public double getRadius(){
        return radius;
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * getRadius();
    }

    @Override
    public String toString(){
        return String.format("Circle {r=%s} perimeter = %g\n\n", getRadius(), perimeter());
    }
}
