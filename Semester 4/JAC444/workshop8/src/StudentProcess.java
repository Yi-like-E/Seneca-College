import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class StudentProcess{
    private static Student[] students = {
            new Student("Jack", "Smith", 50.0, "IT"),
            new Student("Aaron", "Johnson", 76.0, "IT"),
            new Student("Maaria", "White", 35.8, "Business"),
            new Student("John", "White", 47.0, "Media"),
            new Student("Laney", "White", 62.0, "IT"),
            new Student("Jack", "Jones", 32.9, "Business"),
            new Student("Wesley", "Jones", 42.89, "Media")
    };

    public static void main(String[] args){
        List<Student> studentList = Arrays.asList(students);

        // Task 1
        System.out.println("Task 1:\n\nComplete Student list:");
        studentList.forEach(System.out::println);

        // Task 2
        System.out.println("\n\nTask 2:\n\nStudents who got 50.0-100.0 sorted by grade:");
        studentList.stream().filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
                   .sorted(Comparator.comparing(Student::getGrade)).forEach(System.out::println);

        // Task 3
        System.out.println("\n\nTask 3:\n\nFirst Student who got 50.0-100.0:");
        studentList.stream().filter(s -> s.getGrade() >= 50.0 && s.getGrade() <= 100.0)
                .sorted(Comparator.comparing(Student::getGrade)).findFirst().ifPresent(System.out::println);

        // Task 4
        System.out.println("\n\nTask 4:\n\nStudents in ascending order by last name then first:");
        studentList.stream().sorted(Comparator.comparing(Student::getFirstName))
                            .sorted(Comparator.comparing(Student::getLastName)).forEach(System.out::println);
        System.out.println("\nStudents in descending order by last name then first:");
        studentList.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName).reversed())
                            .forEach(System.out::println);

        // Task 5
        System.out.println("\n\nTask 5:\n\nUnique Student last names:");
        studentList.stream().map(s -> s.getLastName()).distinct().sorted().forEach(System.out::println);
    }
}
