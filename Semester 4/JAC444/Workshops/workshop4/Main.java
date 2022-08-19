package Shapes;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args){
        System.out.println("------->JAC 444 Assignment 4<-------");
//        System.out.println("------->Task 1 ... <-------");


        int count = 0;
        String s;
        try (BufferedReader br = new BufferedReader(new FileReader("shapes.txt"))) {
            while ((s = br.readLine()) != null) {
                count++;
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }


        Shape[] shapes = new Shape[count];
        int numShapes = 0;
        try (BufferedReader br = new BufferedReader(new FileReader("shapes.txt"))) {
            while ((s = br.readLine()) != null) {
                String[] tokens = s.split(",");

                switch(tokens[0]){
                    case "Circle":
                        if(tokens.length == 2){
                            try{
                                shapes[numShapes] = new Circle(Double.parseDouble(tokens[1]));
                                numShapes++;
                            } catch (InvalidSideException e) {
                                System.out.println(e.getMessage());
                            }
                        }
                        break;
                    case "Rectangle":
                        if(tokens.length == 3){
                            try{
                                shapes[numShapes] = new Rectangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
                                numShapes++;
                            } catch (InvalidSideException e){
                                System.out.println(e.getMessage());
                            }
                        }
                        break;
                    case "Square":
                        if(tokens.length == 2){
                            try{
                                shapes[numShapes] = new Square(Double.parseDouble(tokens[1]));
                                numShapes++;
                            } catch (InvalidSideException e){
                                System.out.println(e.getMessage());
                            }
                        }
                        break;
                    case "Parallelogram":
                        if(tokens.length == 3){
                            try{
                                shapes[numShapes] = new Parallelogram(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
                                numShapes++;
                            } catch (InvalidSideException e){
                                System.out.println(e.getMessage());
                            }
                        }
                        break;
                    case "Triangle":
                        if(tokens.length == 4){
                            try{
                                shapes[numShapes] = new Triangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[3]));
                                numShapes++;
                            } catch (InvalidSideException e){
                                System.out.println(e.getMessage());
                            }
                        }
                        break;
                }
            }
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }

        // Task 1
        System.out.println("\n" + numShapes + " shapes were created:");
        printResult(shapes);

        // Task 2
        double min = 100;

        // find minimum perimeter for Triangle
        for(Shape sp: shapes){
            if(sp instanceof Triangle && sp.perimeter() < min){
                min = sp.perimeter();
            }
        }

        // delete minimum Triangle in the array
        for(int i = 0; i < numShapes; i++) {
            if (shapes[i] instanceof Triangle && shapes[i].perimeter() == min) {
                shapes[i] = null;
            }
        }

        double max = 0;

        // find maximum perimeter for Circle
        for(Shape sp: shapes){
            if(sp instanceof Circle && sp.perimeter() > max){
                max = sp.perimeter();
            }
        }

        // delete maximum Circle in the array
        for(int i = 0; i < numShapes; i++) {
            if (shapes[i] instanceof Circle && shapes[i].perimeter() == max) {
                shapes[i] = null;
            }
        }
        // task 2 result
        System.out.println("------->Task 2 ... <-------");
        printResult(shapes);

        // task 3
        double totalP = 0;
        double totalT = 0;
        for(Shape sp : shapes){
            if(sp instanceof Parallelogram){
                totalP += sp.perimeter();
            } else if (sp instanceof Triangle) {
                totalT += sp.perimeter();
            }
        }

        // task 3 result
        System.out.println("------->Task 3 ... <-------");
        System.out.println("Total perimeter of Parallelogram is: " + totalP);
        System.out.println("Total perimeter of Triangle is: " + totalT);
    }

    public static void printResult(Shape[] shapes){
        for(Shape sp: shapes){
            if(sp != null){
                System.out.printf("%s",sp);
            }
        }
    }
}
