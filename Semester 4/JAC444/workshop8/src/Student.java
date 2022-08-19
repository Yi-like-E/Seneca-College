public class Student {
    private String firstName;
    private String lastName;
    private double grade;
    private String department;

    public Student(String fName, String lName, double mark, String dep){
        firstName = fName;
        lastName = lName;
        grade = mark;
        department = dep;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String fName){
        this.firstName = fName;
    }

    public String getLastName(){
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public double getGrade() {
        return grade;
    }

    public void setGrade(double mark){
        this.grade = mark;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String dep){
        this.department = dep;
    }

    public String getName(){
        return this.firstName + ' ' + this.lastName;
    }

    @Override
    public String toString(){
        return String.format("%-8s %-11s %-7.2f %s", getFirstName(), getLastName(), getGrade(), getDepartment());
    }

    public boolean equals(Student s){
        return this.getFirstName() == s.getFirstName() && this.getLastName() == s.getLastName()
                && this.getGrade() == s.getGrade() && this.getDepartment() == s.getDepartment();
    }
}
