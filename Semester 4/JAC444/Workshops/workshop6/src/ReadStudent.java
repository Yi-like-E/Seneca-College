import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;

public class ReadStudent extends Student{

    public static void main(String[] args) throws IOException, ClassCastException{

        JFrame frame = new JFrame("Read student.txt");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JPanel startPanel = new JPanel();
        startPanel.setLayout(new BoxLayout(startPanel, BoxLayout.Y_AXIS));
        frame.add(startPanel);

        JButton startButton = new JButton("START");
        startPanel.add(startButton);

        frame.setPreferredSize(new Dimension(300, 100));

        startButton.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        File f = new File("student.txt");

                        try{
                            FileInputStream fis = new FileInputStream(f);
                            ObjectInputStream ois = new ObjectInputStream(fis);
                            int count = 1;

                            JPanel dataPanel = new JPanel();
                            dataPanel.setLayout(new BoxLayout(dataPanel, BoxLayout.Y_AXIS));

                            while(fis.available() != 0){
                                Student student = (Student) ois.readObject();
                                if(student != null){

//                                    dataPanel.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(), "Student " + count +" data"));
                                    JLabel studentLabel = new JLabel("======Student " + count + " data======");
                                    dataPanel.add(studentLabel);

                                    JLabel studentIdLabel = new JLabel("Student ID: " + student.getStdID());
                                    dataPanel.add(studentIdLabel);

                                    JLabel studentfnameLabel = new JLabel("Student first name: " + student.getFirstName());
                                    dataPanel.add(studentfnameLabel);

                                    JLabel studentlnameLabel = new JLabel("Student last name: "+ student.getLastName());
                                    dataPanel.add(studentlnameLabel);

                                    JLabel courseLabel = new JLabel("Courses: " + student.getCourses());
                                    courseLabel.setBorder(new EmptyBorder(0,0, 10 ,0));
                                    dataPanel.add(courseLabel);

                                    dataPanel.setAlignmentX(Component.LEFT_ALIGNMENT);

                                    frame.remove(startPanel);
                                    frame.setSize(300, 500);
                                    frame.add(dataPanel);
                                    frame.validate();
                                    count++;
                                }
                            }
                            ois.close();
                        } catch (FileNotFoundException ex) {
                            throw new RuntimeException(ex);
                        } catch (IOException ex) {
                            throw new RuntimeException(ex);
                        } catch (ClassNotFoundException ex) {
                            throw new RuntimeException(ex);
                        }
                    }
                }
        );
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
