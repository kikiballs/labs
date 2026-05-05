public class lab1 {
    public static void main(String[] args) {
        //choose task
        //task1();
         //task2();
         //task3();
         //task4();
         //task5();
    }

   
    public static void task1() {
        int q = 1000, w = 2, e = 6, a = 5, s = 11;
        int d = 3, z = 8, x = 1, c = 4, v = 14;

        int sum = q + w + e + a + s + d + z + x + c + v;
        int difference = q - w - e - a - s - d - z - x - c - v;
        int mult = q * w * e * a * s * d * z * x * c * v;
        int division = q / w / e / a / s / d / z / x / c / v;

        System.out.println(" додавання: " + sum);
        System.out.println(" віднімання: " + difference);
        System.out.println(" множення: " + mult);
        System.out.println(" ділення: " + division);
    }

    // --- TASK 2: String Array ---
    public static void task2() {
        String w1 = "Цю", w2 = "лабораторну", w3 = "робив", w4 = "пан", w5 = "Костянтин";
        String w6 = ",", w7 = "студент", w8 = "першої", w9 = "підгрупи", w10 = "з", w11 = "предмету", w12 = "ООП";

        String[] text = {w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12};

        for (int i = 0; i < text.length; i++) {
            System.out.print(text[i] + " ");
        }
        System.out.println();
    }

    public static void task3() {
        User u1 = new User(1, 20, "kiki", "first", 75.0, 180.0);
        User u2 = new User(2, 21, "kiki", "second", 60.5, 185.5);
        User u3 = new User(3, 22, "kiki", "third", 80, 190.0);
        User u4 = new User(4, 23, "kiki", "fourth", 55.0, 195.5);
        User u5 = new User(5, 24, "kiki", "fifth", 90.5, 200.0);
        User u6 = new User(6, 25, "kiki", "sixth", 50.0, 205.5);
        User u7 = new User(7, 25, "kiki", "seventh", 85.0, 210.0);
        User u8 = new User(8, 26, "kiki", "eighth", 62.5, 215.5);
        User u9 = new User(9, 28, "kiki", "nineth", 78.0, 220.0);
        User u10 = new User(10, 27, "kiki", "tenth", 58.0, 225.5);

        User[] users = {u1, u2, u3, u4, u5, u6, u7, u8, u9, u10};

        int totalAge = 0;
        double totalWeight = 0.0, totalHeight = 0.0;

        for (int i = 0; i < users.length; i++) {
            totalAge += users[i].age;
            totalWeight += users[i].weight;
            totalHeight += users[i].height;
        }

        System.out.println("Total Age: " + totalAge);
        System.out.println("Total Weight: " + totalWeight);
        System.out.println("Total Height: " + totalHeight);
    }

    
    public static void task4() {
        Car c1 = new Car(150, 2.0, "Toyota", "Camry", 2020, "Чорний", 25000);
        Car c2 = new Car(105, 1.6, "Volkswagen", "Golf", 2018, "Білий", 15000);
        Car c3 = new Car(300, 3.5, "Ford", "Mustang", 2021, "Червоний", 40000);
        Car c4 = new Car(110, 1.5, "Renault", "Megane", 2019, "Синій", 14000);
        Car c5 = new Car(190, 2.5, "Mazda", "6", 2022, "Сірий", 28000);
        Car c6 = new Car(250, 3.0, "BMW", "3 Series", 2020, "Чорний", 35000);
        Car c7 = new Car(140, 1.8, "Honda", "Civic", 2019, "Червоний", 18000);
        Car c8 = new Car(400, 4.4, "Audi", "RS6", 2023, "Зелений", 120000);
        Car c9 = new Car(130, 1.4, "Skoda", "Octavia", 2021, "Сріблястий", 22000);
        Car c10 = new Car(200, 2.0, "Subaru", "Impreza", 2018, "Синій", 20000);

        Car[] cars = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10};

        double totalVolume = 0.0;
        int totalHorsepower = 0;

        for (int i = 0; i < cars.length; i++) {
            totalVolume += cars[i].volume;
            totalHorsepower += cars[i].horsepower;
        }

        System.out.println("Total Volume: " + totalVolume);
        System.out.println("Total Horsepower: " + totalHorsepower);
    }

 
    public static void task5() {
        int number = 412;

        int digit3 = number % 10;
        int digit2 = (number / 10) % 10;
        int digit1 = number / 100;

        int reversedNumber = (digit3 * 100) + (digit2 * 10) + digit1;

        System.out.println("Оригінальне число: " + number);
        System.out.println("Реверснуте число: " + reversedNumber);
    }

  
    static class User {
        int id, age;
        String name, surname;
        double weight, height;

        public User(int id, int age, String name, String surname, double weight, double height) {
            this.id = id;
            this.age = age;
            this.name = name;
            this.surname = surname;
            this.weight = weight;
            this.height = height;
        }
    }

    static class Car {
        int horsepower, year;
        double volume, price;
        String brand, model, color;

        public Car(int horsepower, double volume, String brand, String model, int year, String color, double price) {
            this.horsepower = horsepower;
            this.volume = volume;
            this.brand = brand;
            this.model = model;
            this.year = year;
            this.color = color;
            this.price = price;
        }
    }
}