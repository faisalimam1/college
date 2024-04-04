/*8. Develop a JAVA program to create an outer class with a function display. Create another class inside the 
outer class named inner with a function called display and call the two functions in the main class.*/
class Outer {
    private int x = 10;

    class Inner {
        private int y = 20;

        void display() {
            System.out.println("Inner display method");
            System.out.println("x= " + x + "y= " + y);
        }
    }

    void display() {
        Inner i = new Inner();
        i.display();
        System.out.println("Outer display method");
        System.out.println("y= " + i.y);
    }
}

public class Test {
    public static void main(String[] args) {
        Outer o = new Outer();
        o.display();
    }
}
