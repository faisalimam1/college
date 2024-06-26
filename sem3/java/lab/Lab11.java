// write a java program that implements a multi thread application that has 3 threads.
// 1. Thread Generate generates a random number between 1 to 100.
// 2. Thread Square calculates the square of the number generated by the thread generate.
// 3. Thread Cube calculates the cube of the number generated by the thread generate.

import java.util.Random;

class Square implements Runnable {
    Thread t;
    int x;

    Square(int n) {
        x = n;
        t = new Thread(this, "Square");
        t.start();
    }

    public void run() {
        System.out.println("Square: " + x * x);
    }
}

class Cube implements Runnable {
    Thread t;
    int x;

    Cube(int n) {
        x = n;
        t = new Thread(this, "Cube");
        t.start();
    }

    public void run() {
        System.out.println("Cube: " + x * x * x);
    }
}

class Generate implements Runnable {
    Thread t;

    Generate() {
        t = new Thread(this, "Generate");
        t.start();
    }

    public void run() {
        int n, i = 3;

        Random r = new Random();
        while (i-- > 0) {
            n = r.nextInt(100);
            System.out.println("Generate: " + n);
            new Square(n);
            new Cube(n);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
    }
}

public class Lab11 {
    public static void main(String[] args) {
        new Generate();
    }
}

/*
 * Output:
 * Generate: 39
 * Square: 1521
 * Cube: 59319
 * Generate: 67
 * Square: 4489
 * Cube: 300763
 * Generate: 90
 * Square: 8100
 * Cube: 729000
 */
