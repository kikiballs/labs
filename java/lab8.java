import java.io.File;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner; 

public class lab8 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(" Лабораторна робота №8 (Робота з файлами) ");

      
        System.out.print("Введіть ім'я файлу (наприклад mynumbers.txt): ");
        String fileName = in.nextLine();

        System.out.print("Введіть нижню межу випадкових чисел: ");
        int b1 = in.nextInt();

        System.out.print("Введіть верхню межу випадкових чисел: ");
        int b2 = in.nextInt();

        int count = 15; 
        File myFile = new File(fileName);

      
        try {
            if (!myFile.exists()) {
                boolean created = myFile.createNewFile();
                if (created) {
                    System.out.println("\nФайл '" + fileName + "' не знайдено. Створено новий файл.");
                }
            } else {
                System.out.println("\nФайл '" + fileName + "' вже існує. Дані будуть перезаписані.");
            }

            FileWriter fw = new FileWriter(myFile);
            Random random = new Random();

            System.out.println("Генеруємо " + count + " випадкових чисел у діапазоні [" + b1 + "; " + b2 + "]...");
            
            for (int i = 0; i < count; i++) {
           
                int num = random.nextInt(b2 - b1 + 1) + b1;
                fw.write(num + " "); 
            }
            
            fw.close(); 
            System.out.println("Запис у файл успішно завершено!");

        } catch (IOException e) {
            System.out.println("Сталася помилка при роботі з файлом: " + e.getMessage());
        }

   
        System.out.println("\n Читання збереженого файлу ");
        try {
            FileReader fr = new FileReader(myFile);
            int character;
            
            System.out.print("Вміст файлу: ");
            while ((character = fr.read()) != -1) {
                System.out.print((char) character);
            }
            
            fr.close(); 
            System.out.println("\nЧитання завершено.");

        } catch (IOException e) {
            System.out.println("Сталася помилка при читанні файлу: " + e.getMessage());
        }
        
        in.close();
    }
}