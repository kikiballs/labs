
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;

public class lab7 {
    public static void main(String[] args) {

        System.out.println("  1: таксі");
        runTaxiService();

        System.out.println("\n2: телефонна книгга");
        runPhoneBook();
    }

  
    public static void runTaxiService() {
        ArrayList<Car> cars = new ArrayList<>();

       
        cars.add(new Car("Toyota Corolla", 110, new Driver("Іван", 26, 4), 15000, 2015));
        cars.add(new Car("Skoda Octavia", 150, new Driver("Олег", 30, 8), 18000, 2017));
        cars.add(new Car("Renault Logan", 90, new Driver("Петро", 22, 2), 10000, 2014));
        cars.add(new Car("Volkswagen Golf", 140, new Driver("Максим", 28, 3), 16000, 2016));
        cars.add(new Car("Ford Focus", 125, new Driver("Сергій", 35, 10), 14000, 2013));
        cars.add(new Car("Hyundai Accent", 100, new Driver("Дмитро", 27, 4), 12000, 2018));
        cars.add(new Car("Kia Rio", 123, new Driver("Андрій", 40, 15), 13000, 2019));
        cars.add(new Car("Mazda 3", 150, new Driver("Василь", 24, 1), 17000, 2016));
        cars.add(new Car("Honda Civic", 142, new Driver("Юрій", 31, 7), 16500, 2017));
        cars.add(new Car("Nissan Sentra", 130, new Driver("Віталій", 29, 6), 14500, 2015));

       
        System.out.println("-> Ремонтуємо половину автопарку та міняємо водіїв...");
        for (int i = 0; i < cars.size() / 2; i++) {
            Car car = cars.get(i);
            car.power = car.power * 1.10;
            car.driver = new Driver("Новий Водій " + (i + 1), 30, 5); 
        }

        
        System.out.println("-> Тюнінгуємо кожну другу машину...");
        for (int i = 0; i < cars.size(); i += 2) {
            Car car = cars.get(i);
            car.power = car.power * 1.10;
            car.price = car.price * 1.05;
        }

        
        System.out.println("-> Перевіряємо досвід водіїв (відправляємо на курси)...");
        for (Car car : cars) {
            Driver d = car.driver;
            if (d.experience < 5 && d.age > 25) {
                d.experience += 1; 
            }
        }

       
        System.out.println("\n-> Виклик таксі:");
        Car dispatchedCar = Helper.dispatchCar(cars);
        Helper.arrive(dispatchedCar);
    }


    public static void runPhoneBook() {
        HashMap<String, String> phoneBook = new HashMap<>();

    
        phoneBook.put("Шевченко", "097-111-22-33");
        phoneBook.put("Коваленко", "050-444-55-66");
        phoneBook.put("Бойко", "063-777-88-99");
        phoneBook.put("Ткаченко", "099-123-45-67");
        phoneBook.put("Кравченко", "098-765-43-21");
        phoneBook.put("Олійник", "073-111-00-00");
        phoneBook.put("Мельник", "067-999-11-22");
        phoneBook.put("Лисенко", "066-555-44-33");
        phoneBook.put("Гриценко", "093-222-33-44");
        phoneBook.put("Сидоренко", "050-999-88-77");

    
        System.out.println("Поточна телефонна книга:");
        for (String key : phoneBook.keySet()) {
            System.out.println("Прізвище: " + key + ", Номер: " + phoneBook.get(key));
        }

       
        System.out.println("\n-> Пошук абонента 'Бойко':");
        String searchName = "Бойко";
        if (phoneBook.containsKey(searchName)) {
            System.out.println("Знайдено номер: " + phoneBook.get(searchName));
        } else {
            System.out.println("У книзі відсутній такий абонент");
        }

        System.out.println("-> Пошук абонента 'Петренко' (якого немає):");
        if (phoneBook.containsKey("Петренко")) {
            System.out.println("Знайдено номер: " + phoneBook.get("Петренко"));
        } else {
            System.out.println("У книзі відсутній такий абонент");
        }

      
        System.out.println("\n-> Чи є в базі номер '073-111-00-00'? " + phoneBook.containsValue("073-111-00-00"));

   
        System.out.println("\n-> Видаляємо запис 'Коваленко'...");
        phoneBook.remove("Коваленко");

        System.out.println("Кількість записів у книзі після видалення: " + phoneBook.size());
    }
}


class Driver {
    String name;
    int age;
    int experience;

    public Driver(String name, int age, int experience) {
        this.name = name;
        this.age = age;
        this.experience = experience;
    }
}

class Car {
    String brand;
    double power;
    Driver driver;
    double price;
    int year;

    public Car(String brand, double power, Driver driver, double price, int year) {
        this.brand = brand;
        this.power = power;
        this.driver = driver;
        this.price = price;
        this.year = year;
    }
}

class Helper {
 
    public static Car dispatchCar(ArrayList<Car> cars) {
        Random rand = new Random();
        int randomIndex = rand.nextInt(cars.size());
        Car selectedCar = cars.get(randomIndex);
        
        System.out.println("Автомобіль марки " + selectedCar.brand + " з водієм " + selectedCar.driver.name + " виїхав за вами");
        return selectedCar;
    }

  
    public static void arrive(Car car) {
        System.out.println("Водій " + car.driver.name + " прибув на місце");
    }
}