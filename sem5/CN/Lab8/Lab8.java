import java.net.*;

public class DatagramApp {
    public static int serverPort = 6666;
    public static int clientPort = 9999;
    public static int buffer_size = 1024;
    public static DatagramSocket ds;
    public static byte buffer[] = new byte[buffer_size];

    public static void TheServer() throws Exception {
        System.out.println("Server started. Type messages to send to the client:");
        int pos = 0;
        while (true) {
            int c = System.in.read();
            switch (c) {
                case -1: 
                    System.out.println("Server Quits.");
                    return;
                case '\r':
                    break;
                case '\n':
                    ds.send(new DatagramPacket(buffer, pos, InetAddress.getLocalHost(), clientPort));
                    pos = 0;
                    break;
                default:
                    if (pos < buffer_size) {
                        buffer[pos++] = (byte) c;
                    } else {
                        System.out.println("Buffer overflow. Message too long!");
                        pos = 0;
                    }
            }
        }
    }

    public static void TheClient() throws Exception {
        System.out.println("Client started. Waiting for messages...");
        while (true) {
            DatagramPacket p = new DatagramPacket(buffer, buffer.length);
            ds.receive(p);
            System.out.println("Received: " + new String(p.getData(), 0, p.getLength()));
        }
    }

    public static void main(String args[]) throws Exception {
        if (args.length == 1) {
            ds = new DatagramSocket(serverPort);
            TheServer();
        } else {
            ds = new DatagramSocket(clientPort);
            TheClient();
        }
    }
}
/*
output 
1)TERMINAL 1
javac DatagramApp.java
java DatagramApp server
Server started. Type messages to send to the client:
Hiii hello

2)TERMINAL 2
java DatagramApp
Client started. Waiting for messages...
Received: Hiii hello

*/
