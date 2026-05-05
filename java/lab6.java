public class lab6 {
    public static void main(String[] args) {
        System.out.println(" 1. Клас Person ");
     
        Person person1 = new Person(); 
        Person person2 = new Person("Іван Іванов", 20); 
        
        person1.talk();
        person2.move();

        System.out.println("\n 2. Клас Phone ");
   
        Phone phone1 = new Phone("097-111-22-33", "Samsung S23", 168.5);
        Phone phone2 = new Phone("050-444-55-66", "iPhone 15");
        Phone phone3 = new Phone();
        
     
        System.out.println("Телефон 1: " + phone1.number + ", " + phone1.model + ", " + phone1.weight + "г");
        System.out.println("Телефон 2: " + phone2.number + ", " + phone2.model + ", " + phone2.weight + "г");
        System.out.println("Телефон 3: " + phone3.number + ", " + phone3.model + ", " + phone3.weight + "г");
        
    
        phone1.receiveCall("Мама");
        System.out.println("Номер: " + phone1.getNumber());
        
     
        phone2.receiveCall("Олег", "063-999-88-77");
        
  
        System.out.print("Розсилка повідомлень на номери: ");
        phone1.sendMessage("099-123-45-67", "098-765-43-21", "073-111-22-33");

        System.out.println("\n 3. Ієрархія фігур (Shape) ");
        Cylinder cylinder = new Cylinder(5, 10);
        Ball ball = new Ball(7);
        Pyramid pyramid = new Pyramid(25, 12);
        
        System.out.println("Об'єм циліндра: " + cylinder.getVolume());
        System.out.println("Об'єм кулі: " + ball.getVolume());
        System.out.println("Об'єм піраміди: " + pyramid.getVolume());

        System.out.println("\n 4. Абстрактний клас Car ");
        
        Sedan mySedan = new Sedan("Toyota Camry", "Чорний", 220);
        Truck myTruck = new Truck("Volvo FH", "Білий", 120);
        
        
        mySedan.gas();
        mySedan.brake();
        myTruck.brake();

        System.out.println("\n 5. Індивідуальне завдання (Комплексні числа) ");
        ComplexNumber cn = new ComplexNumber();
        cn.input(3, 4); 
        cn.print();    
        cn.printModulus();
        cn.printArgument();

        System.out.println("\n 6. Клас-спадкоємець (Розширені комплексні числа) ");
        ExtendedComplexNumber ecn = new ExtendedComplexNumber();
        ecn.input(5, -2);
        ecn.name = "Z1";
        ecn.color = "Червоний";
       
        ecn.print(); 
    }
}

class Person {
    String fullName; 
    int age;         

  
    public Person() {
        this.fullName = "Невідомий";
        this.age = 0;
    }

    
    public Person(String fullName, int age) {
        this.fullName = fullName;
        this.age = age;
    }


    public void move() {
        System.out.println(fullName + " говорить.");
    }

    public void talk() {
        System.out.println(fullName + " говорить.");
    }
}

class Phone {
    String number; 
    String model;   
    double weight;  

   
    public Phone(String number, String model, double weight) {
        this.number = number;
        this.model = model;
        this.weight = weight;
    }

  
    public Phone(String number, String model) {
        this.number = number;
        this.model = model;
        this.weight = 0.0;
    }


    public Phone() {
        this.number = "Не задано";
        this.model = "Не задано";
        this.weight = 0.0;
    }

  
    public void receiveCall(String callerName) {
        System.out.println("Дзвонить " + callerName);
    }

    
    public void receiveCall(String callerName, String callerNumber) {
        System.out.println("Дзвонить " + callerName + " з номеру " + callerNumber);
    }


    public String getNumber() {
        return number;
    }

    
    public void sendMessage(String... numbers) {
        for (String num : numbers) {
            System.out.print(num + " "); 
        }
        System.out.println();
    }
}


class Shape {
    double volume;
    public double getVolume() {
        return volume;
    }
}

class SolidOfRevolution extends Shape {
    double radius;
    public double getRadius() {
        return radius;
    }
}

class Cylinder extends SolidOfRevolution {
    double height;
    public Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
        this.volume = Math.PI * radius * radius * height;
    }
}

class Ball extends SolidOfRevolution {
    public Ball(double radius) {
        this.radius = radius;
        this.volume = (4.0 / 3.0) * Math.PI * Math.pow(radius, 3);
    }
}

class Pyramid extends Shape {
    double s;
    double h;
    public Pyramid(double s, double h) {
        this.s = s;
        this.h = h;
        this.volume = (1.0 / 3.0) * s * h;
    }
}


abstract class Car {
    String model;     
    String color;   
    int maxSpeed;    

    public Car(String model, String color, int maxSpeed) {
        this.model = model;
        this.color = color;
        this.maxSpeed = maxSpeed;
    }

   
    public void gas() {
        System.out.println("Газуємо!");
    }


    public abstract void brake();
}

class Sedan extends Car { 
    public Sedan(String model, String color, int maxSpeed) {
        super(model, color, maxSpeed);
    }

    @Override
    public void brake() {
        System.out.println("Седан " + model + " плавно гальмує.");
    }
}

class Truck extends Car { 
    public Truck(String model, String color, int maxSpeed) {
        super(model, color, maxSpeed);
    }

    @Override
    public void brake() {
        System.out.println("Вантажівка " + model + " використовує пневматичні гальма.");
    }
}


class ComplexNumber {
    double a; 
    double b; 

   
    public void input(double a, double b) {
        this.a = a;
        this.b = b;
    }

  
    public void print() {
        System.out.println(a + " + " + b + " * i");
    }

    public void printModulus() {
        double modulus = Math.sqrt(a * a + b * b);
        System.out.println("Модуль комплексного числа: " + modulus);
    }

 
    public void printArgument() {
        double argument = Math.atan2(b, a);
        System.out.println("Аргумент комплексного числа (в радіанах): " + argument);
    }
}


class ExtendedComplexNumber extends ComplexNumber {
    
    String name;  
    String color; 

    
    @Override
    public void print() {
        System.out.println("Комплексне число " + name + " (Колір: " + color + "): " + a + " + " + b + " * i");
    }
}