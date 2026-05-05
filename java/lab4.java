
import java.util.Scanner;
import java.util.Arrays;

public class lab4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        System.out.println(" Лабораторна робота №4 (Масиви)");
        System.out.println("1. Масиви з 50 парними та непарними числами");
        System.out.println("2. Робота з заданим масивом (цикли for та while)");
        System.out.println("3. Сума n дійсних елементів");
        System.out.println("4. Зміна знаку непарних елементів");
        System.out.print("Виберіть номер завдання (1-4): ");
        
        int task = in.nextInt();
        
        switch (task) {
            case 1:
                System.out.println("\n Завдання 1 ");
                
                int[] evenNumbers = new int[50];
                int[] oddNumbers = new int[50];
                
                
                for (int i = 0; i < 50; i++) {
                    evenNumbers[i] = i * 2;        
                    oddNumbers[i] = (i * 2) + 1;   
                }
                
                System.out.println("Масив парних чисел:");
                System.out.println(Arrays.toString(evenNumbers));
                System.out.println("Масив непарних чисел:");
                System.out.println(Arrays.toString(oddNumbers));
                break;
                
            case 2:
                System.out.println("\n Завдання 2 ");
                int[] arr = {2, 17, 13, 6, 22, 31, 45, 66, 100, -18}; 
                
                System.out.println("a) Перебір циклом while: [cite: 100]");
                int i = 0;
                while (i < arr.length) {
                    System.out.print(arr[i] + " ");
                    i++;
                }
                
                System.out.println("\n\nб) Перебір циклом for: [cite: 101]");
                for (int j = 0; j < arr.length; j++) {
                    System.out.print(arr[j] + " ");
                }
                
                System.out.println("\n\nв) Цикл while (тільки непарні ІНДЕКСИ): [cite: 102]");
                int k = 1; 
                while (k < arr.length) {
                    System.out.print(arr[k] + " ");
                    k += 2; 
                }
                
                System.out.println("\n\nг) Цикл for (тільки парні індекси): [cite: 103]");
                for (int m = 0; m < arr.length; m += 2) { 
                    System.out.print(arr[m] + " ");
                }
                
                System.out.println("\n\nд) Масив у зворотньому порядку: [cite: 104]");
                for (int rev = arr.length - 1; rev >= 0; rev--) {
                    System.out.print(arr[rev] + " ");
                }
                System.out.println();
                break;
                
            case 3:
                System.out.println("\n Завдання 3 ");
                System.out.print("Введіть кількість елементів n: ");
                int n = in.nextInt();
                
               
                double[] realNumbers = new double[n];
                double sum = 0;
                
                System.out.println("Введіть " + n + " дійсних чисел (через кому, якщо це десятковий дріб):");
                for (int idx = 0; idx < n; idx++) {
                    realNumbers[idx] = in.nextDouble();
                    sum += realNumbers[idx];
                }
                
                System.out.println("Введений масив: " + Arrays.toString(realNumbers));
                System.out.println("Сума елементів: " + sum); 
                break;
                
            case 4:
                System.out.println("\n Завдання 4 ");
                
                int[] numbersToChange = {5, -2, 7, 8, -11, 4, 9};
                System.out.println("Початковий масив: " + Arrays.toString(numbersToChange));
                
               
                for (int idx = 0; idx < numbersToChange.length; idx++) {
                    if (numbersToChange[idx] % 2 != 0) { 
                        numbersToChange[idx] = -numbersToChange[idx];
                    }
                }
                
                System.out.println("Масив після зміни знаків непарних елементів:");
                System.out.println(Arrays.toString(numbersToChange));
                break;
                
            default:
                System.out.println("Такого завдання нема");
        }
        
        in.close();
    }
}