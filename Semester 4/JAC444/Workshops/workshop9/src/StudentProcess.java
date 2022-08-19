import java.util.*;
import java.util.stream.Collectors;

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

        // Task 6
        System.out.println("Task 6:\n\nStudent names in order by last name then first name:");
        studentList.stream().sorted(Comparator.comparing(Student::getLastName).thenComparing(Student::getFirstName))
                            .map(s -> s.getName()).forEach(System.out::println);

        // Task 7
        System.out.println("\n\nTask 7:\n\nStudents by department:");
        Map<String, List<Student>> stringListMap = studentList.stream().collect(Collectors.groupingBy(Student::getDepartment));
        stringListMap.forEach((key, value) -> {
            System.out.println(key);
            value.forEach(v -> System.out.println("   " + v));
        });

        // Task 8
        System.out.println("\n\nTask 8:\n\nCount of Students by department:");
        Map<String, Long> stringLongMap = studentList.stream().collect(Collectors.groupingBy(Student::getDepartment, Collectors.counting()));
        new TreeMap<String, Long>(stringLongMap).forEach((key, value ) -> {
            System.out.println(key + " has " + value + " Student(s)");
        });

        // Task 9
        System.out.print("\n\nTask 9:\nSum of Students' grades: ");
        System.out.print(String.format("%.2f",studentList.stream().mapToDouble(s -> s.getGrade()).sum()));

        // Task 10
        System.out.print("\n\nTask 10:\nAverage of Students' grades: ");
        System.out.print(String.format("%.2f\n",studentList.stream().mapToDouble(s -> s.getGrade()).average().getAsDouble()));
    }
}
