package Shapes;

public class Circle implements Shape{
    private double radius;
    private ShapeArea circleArea = () -> Math.PI * getRadius() * getRadius();

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

    public double getCircleArea(){
        return circleArea.getArea();
    }

    @Override
    public double perimeter() {
        return 2 * Math.PI * getRadius();
    }

    @Override
    public String toString(){
        return String.format("Circle {r=%s} perimeter = %g area = %.5f\n\n", getRadius(), perimeter(), getCircleArea());
    }
}
