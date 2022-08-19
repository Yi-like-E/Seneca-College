package Student;

import java.io.*;

public class ReadStudent {
    public static void main(String[] args) throws IOException {
        try{
            FileInputStream fin = new FileInputStream("Student.txt");
            ObjectInputStream ois = new ObjectInputStream(fin);

            while(fin.available() != 0){
                System.out.println("======Student info======");
                Student student = (Student) ois.readObject();
                System.out.println("Student ID: " + student.getStdID());
                System.out.println("Student First Name: " + student.getFirstName());
                System.out.println("Student last Name: " + student.getLastName());
                System.out.println("Student First Name: " + student.getCourses());
            }
                fin.close();
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println(e.getMessage());
        }
    }
}
