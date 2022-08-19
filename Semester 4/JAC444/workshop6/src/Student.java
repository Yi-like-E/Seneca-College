import java.io.Serializable;
import java.util.ArrayList;

public class Student implements Serializable{
    private int stdID;
    private String firstName;
    private String lastName;
    private ArrayList<String> courses = new ArrayList<String>();

    public Student(){

    };

    public Student(int id, String fName, String lName, ArrayList<String> courses){
        this.stdID = id;
        this.firstName = fName;
        this.lastName = lName;
        this.courses = courses;
    }

    public void setStdID(int id){
        stdID = id;
    }

    public void setFirstName(String fName){
        firstName = fName;
    }

    public void setLastName(String lName){
        lastName = lName;
    }

    public void setCourses(String course){
        this.courses.add(course);
    }

    public int getStdID(){
        return stdID;
    }

    public String getFirstName(){
        return firstName;
    }

    public String getLastName(){
        return lastName;
    }

    public ArrayList<String> getCourses(){
        return courses;
    }
}

