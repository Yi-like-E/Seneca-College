package Shapes;

public class Triangle implements Shape{
    private double sideA;
    private double sideB;
    private double sideC;

    public Triangle(double s1, double s2, double s3) throws InvalidSideException{
        if(s1 > 0 && s2 > 0 && s3 > 0){
            if((s1+s2) > s3 && (s2+s3) > s1 && (s1+s3) > s2){
                sideA = s1;
                sideB = s2;
                sideC = s3;
            } else{
                throw new InvalidSideException ("Invalid side(s)!");
            }
         }else{
            throw new InvalidSideException ("Invalid side(s)!");
        }
    }

    public void setSideA(double s){
        sideA = s;
    }

    public void setSideB(double s){
        sideB = s;
    }

    public void setSideC(double s){
        sideC = s;
    }

    public double getSideA(){
        return sideA;
    }

    public double getSideB(){
        return sideB;
    }

    public double getSideC(){
        return sideC;
    }

    @Override
    public double perimeter() {
        return (getSideA() + getSideB() + getSideC());
    }

    @Override
    public String toString(){
        return String.format("Triangle {s1=%s, s2=%s, s3=%s} perimeter = %g\n\n", getSideA(),getSideB(), getSideC(), perimeter());
    }
}
