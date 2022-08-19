package Student;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class WriteStudent {
    public static void main(String[] args) throws IOException {
        FileOutputStream fout = null;
        ObjectOutputStream oos = null;
        try {
            fout = new FileOutputStream(new File("student.txt"));
            oos = new ObjectOutputStream(fout);
            Scanner input = new Scanner(System.in);
            boolean flag = true;

            do{
                System.out.println("Please enter the following information each in a new line: student id(Positive number), student first name, student last name, and a list of courses(separated by comma)");
                System.out.println("To exit the program, type 0 now!");
                int id = input.nextInt();
                if(id == 0){
                    flag = false;
                    System.out.println("exit program...");
                    System.exit(0);
                } else if (id < 0) {
                    System.out.println("Invalid student id!");
                    id = input.nextInt();
                }

                // to work around nextInt() doesn't read the new line character
                input.nextLine();

                String fname = input.nextLine();

                String lname = input.nextLine();

                String courseList = input.nextLine();
                if(courseList.isEmpty()){
                    System.out.println("Please enter at least one course!");
                    courseList = input.nextLine();
                }
                String[] temp = (courseList.split("\\s*,\\s*"));
                ArrayList<String> courses = new ArrayList<String>(Arrays.asList(temp));

                Student student = new Student(id, fname, lname, courses);
                oos.writeObject(student);

                System.out.println("Student created!\n");
            } while(flag);

        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (InputMismatchException e){
            System.out.println(e.getMessage());
        }finally {
            fout.close();
            oos.close();
        }
    }
}
