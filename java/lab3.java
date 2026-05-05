import java.util.Scanner;

public class lab3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.println(" Лабораторна робота №3 (Цикли) ");
        System.out.println("1. Фраза 50 разів (for та while)");
        System.out.println("2. Години та хвилини (цикл for)");
        System.out.println("3. Години та хвилини (цикл while)");
        System.out.println("4. Години, хвилини та секунди");
        System.out.println("5. Табулювання функції (Варіант 2)");
        System.out.print("Виберіть номер завдання (1-5): ");
        
        int task = in.nextInt();
        
        switch (task) {
            case 1:
                System.out.println("\n Завдання 1 ");
                String phrase = "костикослав";
                
                System.out.println("Виведення циклом FOR:");
                for (int i = 1; i <= 50; i++) {
                    System.out.println(i + ". " + phrase);
                }
                
                System.out.println("\n Виведення циклом WHILE:");
                int j = 1;
                while (j <= 50) {
                    System.out.println(j + ". " + phrase);
                    j++;
                }
                break;
                
            case 2:
                System.out.println("\n Завдання 2 (цикл for) ");
                for (int h = 0; h <= 2; h++) {
                    for (int m = 0; m <= 59; m++) {
                        System.out.println(h + " h " + m + " min");
                    }
                }
                break;
                
            case 3:
                System.out.println("\n Завдання 3 (цикл while) ");
                int h3 = 0;
                while (h3 <= 2) {
                    int m3 = 0;
                    while (m3 <= 59) {
                        System.out.println(h3 + " h " + m3 + " min");
                        m3++;
                    }
                    h3++;
                }
                break;
                
            case 4:
                System.out.println("\n Завдання 4 ");
                
                for (int h = 0; h <= 2; h++) {
                    for (int m = 0; m <= 59; m++) {
                        for (int s = 0; s <= 59; s++) {
                            System.out.println(h + " h " + m + " min " + s + " sec");
                        }
                    }
                }
                break;
                
            case 5:
                System.out.println("\n Завдання 5 (Варіант 2) ");
                System.out.print("Введіть нижню границю діапазону значень f(x): ");
                double minVal = in.nextDouble();
                System.out.print("Введіть верхню границю діапазону значень f(x): ");
                double maxVal = in.nextDouble();
                
                System.out.println("\n Реалізація циклом ");
                double xWhile = 3.0; 
                int countWhile = 0;
                
                
                while (xWhile <= 6.01) { 
                    double f;
                    if (xWhile < -2) {
                        f = 3 * Math.abs(xWhile);
                    } else if (xWhile >= -2 && xWhile <= 2) {
                        f = 9 * xWhile;
                    } else {
                        f = Math.sin(xWhile);
                    }
                    
                    System.out.printf("x = %.1f \t f(x) = %.4f\n", xWhile, f);
                    
                    if (f >= minVal && f <= maxVal) {
                        countWhile++;
                    }
                    
                    xWhile += 0.2; 
                }
                
                if (countWhile > 0) {
                    System.out.println("Кількість значень у заданому діапазоні : " + countWhile);
                } else {
                    System.out.println("Значень у заданому діапазоні немає .");
                }
                
                System.out.println("\n Реалізація циклом FOR ");
                int countFor = 0;
                
                for (double xFor = 3.0; xFor <= 6.01; xFor += 0.2) {
                    double f;
                    if (xFor < -2) {
                        f = 3 * Math.abs(xFor);
                    } else if (xFor >= -2 && xFor <= 2) {
                        f = 9 * xFor;
                    } else {
                        f = Math.sin(xFor);
                    }
                    
                    System.out.printf("x = %.1f \t f(x) = %.4f\n", xFor, f);
                    
                    if (f >= minVal && f <= maxVal) {
                        countFor++;
                    }
                }
                
                if (countFor > 0) {
                    System.out.println("Кількість значень у заданому діапазоні (for): " + countFor);
                } else {
                    System.out.println("Значень у заданому діапазоні немає (for).");
                }
                break;
                
            default:
                System.out.println("Такого завдання нема");
        }
        
        in.close();
    }
}