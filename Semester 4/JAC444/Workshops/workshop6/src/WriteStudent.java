import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;

import static java.awt.Component.LEFT_ALIGNMENT;

public class WriteStudent extends Student{
    public static void main(String [] args) {
        ArrayList<Student> studentList = new ArrayList<Student>();

        JFrame frame = new JFrame("Add student into file");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS));
        frame.setLayout(new FlowLayout());

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new BoxLayout(inputPanel, BoxLayout.Y_AXIS));
        frame.add(inputPanel);

        JLabel studentIDLabel = new JLabel("Student ID: ");
        studentIDLabel.setAlignmentX(LEFT_ALIGNMENT);
        JTextField studentIDTxt = new JTextField(15);
        studentIDTxt.setAlignmentX(LEFT_ALIGNMENT);
        inputPanel.add(studentIDLabel);
        inputPanel.add(studentIDTxt);

        JLabel studentFnameLabel = new JLabel("Student First Name: ");
        studentFnameLabel.setAlignmentX(LEFT_ALIGNMENT);
        JTextField studentFnameTxt = new JTextField(30);
        studentFnameTxt.setAlignmentX(LEFT_ALIGNMENT);
        inputPanel.add(studentFnameLabel);
        inputPanel.add(studentFnameTxt);

        JLabel studentLnameLabel = new JLabel("Student Last Name: ");
        studentLnameLabel.setAlignmentX(LEFT_ALIGNMENT);
        JTextField studentLnameTxt = new JTextField(50);
        studentLnameTxt.setAlignmentX(LEFT_ALIGNMENT);
        inputPanel.add(studentLnameLabel);
        inputPanel.add(studentLnameTxt);

        JLabel studentCourseLabel = new JLabel("Student Courses(new line separated): ");
        studentCourseLabel.setAlignmentX(LEFT_ALIGNMENT);
        JTextArea studentCourseTxt = new JTextArea();
        JScrollPane scrollPane = new JScrollPane(studentCourseTxt);
        scrollPane.setAlignmentX(LEFT_ALIGNMENT);
        scrollPane.getViewport().setPreferredSize(new Dimension(10, 150));
        inputPanel.add(studentCourseLabel);
        inputPanel.add(scrollPane);

        JButton submitButton = new JButton("SUBMIT");
        submitButton.setAlignmentX(LEFT_ALIGNMENT);
        inputPanel.add(submitButton);

        JButton doneButton = new JButton("EXIT");
        doneButton.setAlignmentX(LEFT_ALIGNMENT);
        inputPanel.add(doneButton);

        submitButton.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        try{
                            Student student = new Student();

                            int studentId = Integer.parseInt(studentIDTxt.getText());
                            student.setStdID(studentId);

                            String fname = studentFnameTxt.getText();
                            student.setFirstName(fname);

                            String lname = studentLnameTxt.getText();
                            student.setLastName(lname);

                            String courses = studentCourseTxt.getText();
                            String[] temp = courses.split("\\r?\\n");
                            for (String s : temp) {
                                student.setCourses(s);
                            }

                            studentList.add(student);

                            File f = new File("student.txt");
                            FileOutputStream fos = new FileOutputStream(f);
                            ObjectOutputStream oos = new ObjectOutputStream(fos);
                            for(Student s : studentList){
                                oos.writeObject(s);
                            }
                            fos.close();

                            JOptionPane.showMessageDialog(frame, "Student successfully write to file", "", JOptionPane.PLAIN_MESSAGE);

                            studentIDTxt.setText("");
                            studentFnameTxt.setText("");
                            studentLnameTxt.setText("");
                            studentCourseTxt.setText("");

//                            frame.remove(inputPanel);
//                            frame.setSize(300, 100);
                            frame.validate();

                        } catch (FileNotFoundException ex) {
                            throw new RuntimeException(ex);
                        } catch (IOException ex) {
                            throw new RuntimeException(ex);
                        }
                    }
                });
        doneButton.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {

//                        JPanel exitPanel = new JPanel();
//                        exitPanel.setLayout(new BoxLayout(exitPanel, BoxLayout.Y_AXIS));
//
//                        JLabel existLabel = new JLabel("Student successfully write to file");
//                        exitPanel.add(existLabel);
//
//                        frame.remove(inputPanel);
//                        frame.setSize(300, 100);
//                        frame.add(exitPanel);
//                        frame.validate();
                        System.exit(0);

                    }
                });
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
