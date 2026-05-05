import java.util.Scanner;

public class lab2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.print("Виберіть номер завдання (1-4): ");
        int task = in.nextInt();
        
        switch (task) {
            case 1:

                System.out.println(" Завдання 1 ");
                System.out.print("a = ");
                double a = in.nextDouble();
                System.out.print("b = ");
                double b = in.nextDouble();
                System.out.print("c = ");
                double c = in.nextDouble();
                
                double d = b * b - 4 * a * c;
                
                if (d > 0) {
                    double x1 = (-b + Math.sqrt(d)) / (2 * a);
                    double x2 = (-b - Math.sqrt(d)) / (2 * a);
                    System.out.println("x1 = " + x1);
                    System.out.println("x2 = " + x2);
                } else if (d == 0) {
                    double x = -b / (2 * a);
                    System.out.println("x = " + x);
                } else {
                    System.out.println("Коренів немає");
                }
                break;
                
            case 2:

                System.out.println(" Завдання 2 ");
                System.out.print("x = ");
                double x = in.nextDouble();
                System.out.print("y = ");
                double y = in.nextDouble();
                
                if (x > 0 && y > 0) System.out.println("1 чверть");
                else if (x < 0 && y > 0) System.out.println("2 чверть");
                else if (x < 0 && y < 0) System.out.println("3 чверть");
                else if (x > 0 && y < 0) System.out.println("4 чверть");
                else System.out.println("Точка на осі або в центрі");
                break;
                
            case 3:

                System.out.println(" Завдання 3 ");
                System.out.print("Введіть число: ");
                int num = in.nextInt();
                
                if (num >= 10 && num <= 99 && num % 2 == 0) {
                    System.out.println("Двозначне і парне");
                } else {
                    System.out.println("Не підходить");
                }
                break;
                
            case 4:
                System.out.println(" Завдання 4 ");
                System.out.print("x = ");
                double x4 = in.nextDouble(); 
                double f = 0;
                
                if (x4 < -2) {
                    f = 3 * Math.abs(x4);
                } else if (x4 >= -2 && x4 <= 2) {
                    f = 9 * x4;
                } else if (x4 > 2) {
                    f = Math.sin(x4);
                }
                
                System.out.println("f(x) = " + f);
                break;
            
                


            




            
            default:
                System.out.println("Такого завдання немає");
        }
        
        in.close();
    }
}