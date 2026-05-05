import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class lab9 extends JFrame {
    
    private JTextField textFieldX;
    private JTextField textFieldResult;

    
    public lab9() {
        
        setTitle("Обчислення кускової функції");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 320, 200); 
        setLayout(null); 

        
        JLabel labelX = new JLabel("Введіть x:");
        labelX.setBounds(30, 30, 100, 20);
        add(labelX);

      
        textFieldX = new JTextField();
        textFieldX.setBounds(140, 30, 130, 20);
        add(textFieldX);

        
        JLabel labelResult = new JLabel("Результат f(x):");
        labelResult.setBounds(30, 70, 100, 20);
        add(labelResult);

        
        textFieldResult = new JTextField();
        textFieldResult.setBounds(140, 70, 130, 20);
        textFieldResult.setEditable(false); 
        add(textFieldResult);

     
        JButton btnCalculate = new JButton("Обчислити");
        btnCalculate.setBounds(90, 110, 120, 30);
        add(btnCalculate);

        
        btnCalculate.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                 
                    double x = Double.parseDouble(textFieldX.getText());
                    double f;

                    
                    if (x < -2) {
                        f = 3 * Math.abs(x);
                    } else if (x >= -2 && x <= 2) {
                        f = 9 * x;
                    } else {
                        f = Math.sin(x);
                    }

                  
                    textFieldResult.setText(String.format("%.4f", f));
                    
                } catch (NumberFormatException ex) {
                   
                    JOptionPane.showMessageDialog(lab9.this, 
                            "Будь ласка, введіть коректне число!", 
                            "Помилка вводу", 
                            JOptionPane.ERROR_MESSAGE);
                }
            }
        });

       
        setVisible(true);
    }

  
    public static void main(String[] args) {
        new lab9(); 
    }
}