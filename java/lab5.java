import java.util.Scanner;

public class lab5 {

    public static double getRectangleArea(double a, double b) {
        return a * b;
    }

    public static double getMinOfThree(double num1, double num2, double num3) {
        double min = num1;

        if (num2 < min) {
            min = num2;
        }

        if (num3 < min) {
            min = num3;
        }

        System.out.println("Найменше число серед переданих: " + min);
        return min;
    }

    public static void printArray(int[] array) {
        System.out.print("Елементи масиву: [");

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);

            if (i < array.length - 1) {
                System.out.print(", ");
            }
        }

        System.out.println("]");
    }

    public static int getMaxFromArray(int[] array) {
        int max = array[0];

        for (int i = 1; i < array.length; i++) {
            if (array[i] > max) {
                max = array[i];
            }
        }

        return max;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Перевірка методів Лабораторної роботи 5");

        System.out.println("\n1. Обчислення площі прямокутника");
        System.out.print("Введіть довжину прямокутника: ");
        double length = in.nextDouble();

        System.out.print("Введіть ширину прямокутника: ");
        double width = in.nextDouble();

        double area = getRectangleArea(length, width);
        System.out.println("Площа прямокутника = " + area);

        System.out.println("\n2. Знаходження найменшого з трьох чисел");
        System.out.print("Введіть перше число: ");
        double num1 = in.nextDouble();

        System.out.print("Введіть друге число: ");
        double num2 = in.nextDouble();

        System.out.print("Введіть третє число: ");
        double num3 = in.nextDouble();

        double minResult = getMinOfThree(num1, num2, num3);
        System.out.println("Метод повернув значення у main: " + minResult);

        System.out.println("\n3. Виведення масиву");
        System.out.println("4. Знаходження найбільшого числа з масиву");

        System.out.print("Введіть кількість елементів масиву: ");
        int n = in.nextInt();

        int[] myNumbers = new int[n];

        for (int i = 0; i < myNumbers.length; i++) {
            System.out.print("Введіть елемент масиву [" + i + "]: ");
            myNumbers[i] = in.nextInt();
        }

        printArray(myNumbers);

        int maxNumber = getMaxFromArray(myNumbers);
        System.out.println("Найбільше число в масиві: " + maxNumber);

        in.close();
    }
}