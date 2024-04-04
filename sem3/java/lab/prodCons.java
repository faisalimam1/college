class Buffer {
    int i, flag = 0;

    synchronized void put(int x) {
        try {
            if (flag == 1) {
                wait();
            }
        } catch (InterruptedException e) {
            System.out.println("Producer thread has to wait");
        }
        i = x;
        System.out.println("Produced : " + i);
        flag = 1;
        notify();
    }

    synchronized void get() {
        try {
            if (flag == 0) {
                wait();
            }
        } catch (InterruptedException e) {
            System.out.println("Consumer thread has to wait");
        }
        System.out.println("Consumed : " + i);
        flag = 0;
        notify();
    }
}

class Producer implements Runnable {
    Buffer b;
    Thread t;

    Producer(Buffer obj) {
        b = obj;
        t = new Thread(this, "Producer");
        t.start();
    }

    public void run() {
        int i = 0;
        while (true)
            b.put(i++);
    }
}

class Consumer implements Runnable {
    Buffer b;
    Thread t;

    Consumer(Buffer obj) {
        b = obj;
        t = new Thread(this, "Consumer");
        t.start();
    }

    public void run() {
        int i = 0;
        while (true)
            b.get();
    }
}

public class Example {
    public static void main(String[] args) {
        Buffer b = new Buffer();
        Producer p = new Producer(b);
        Consumer c = new Consumer(b);
    }
}
