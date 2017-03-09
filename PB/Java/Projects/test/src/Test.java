class Animal {
    public void eat() {
        System.out.println("Animal->eat");
    }
}

class Dog extends Animal{
    public void eat(){
        System.out.println("Dog->eat");
    }
}

class Cat extends Animal{
    @Override
    public void eat(){
        System.out.println("Cat->eat");
    }
}

public class Test{
    public static void main(String[] args){
        Animal obj1 = new Animal();
        Animal obj2 = new Dog();
        Animal obj3 = new Cat();
        obj1.eat();
        obj2.eat();
        obj3.eat();
    }
}