package Shapes;

public class Rectangle implements Shape{
    private double width;
    private double length;

    public Rectangle(double w, double l) throws InvalidSideException{
        if(w > 0 && l > 0){
            this.width = w;
            this.length = l;
        } else{
            throw new InvalidSideException("Invalid side!");
        }
    }

    public void setWidth(double w){
        width = w;
    }

    public double getWidth(){
        return width;
    }

    public void setLength(double l){
        length = l;
    }

    public double getLength(){
        return length;
    }

    @Override
    public double perimeter() {
        return 2 * (width + length);
    }

    @Override
    public String toString(){
        return String.format("Rectangle {w=%s, h=%s} perimeter = %g\n\n",  getWidth(), getLength(), perimeter());
    }
}
