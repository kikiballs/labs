
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
        System.out.println(" Перевірка методів Лабораторної роботи 5 ");

        
        double length = 5.0;
        double width = 10.0;
        double area = getRectangleArea(length, width);
        System.out.println("1. Площа прямокутника зі сторонами " + length + " та " + width + " = " + area);
       

        
        System.out.println("2. Шукаємо мінімум серед чисел: 15.5, 7.2, 22.8");
        double minResult = getMinOfThree(15.5, 7.2, 22.8);
        System.out.println("   (Метод повернув значення у main: " + minResult + ")");

       
        System.out.println("3 та 4. Робота з масивом");
        int[] myNumbers = {12, 45, -7, 68, 23, 100, 4};
        
       
        printArray(myNumbers);
        
        
        int maxNumber = getMaxFromArray(myNumbers);
        System.out.println("Найбільше число в масиві: " + maxNumber);

    }
}