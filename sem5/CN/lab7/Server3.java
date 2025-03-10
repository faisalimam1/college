import java.net.*;  
import java.io.*;  
public class Server3 { 
public static void main(String args[]) throws Exception  
{  
{ 
try 
ServerSocket sersock = new ServerSocket(4000);  
System.out.println("Server ready for connection");  
Socket sock = sersock.accept(); // binding with port: 4000 
System.out.println("Connection is successful and wating for readinf the contents of 
file");  
// reading the file name from client 
InputStream istream = sock.getInputStream( ); 
BufferedReader fileRead =new BufferedReader(new InputStreamReader(istream)); 
String fname = fileRead.readLine( ); // reading file contents 
BufferedReader contentRead = new BufferedReader(new FileReader(fname) ); 
// keeping output stream ready to send the contents 
OutputStream ostream = sock.getOutputStream( );  
PrintWriter pwrite = new PrintWriter(ostream, true);  
String str; 
while((str = contentRead.readLine()) != null) // reading line-by-line from file 
{ 
pwrite.println(str); // sending each line to client 
} 
sock.close(); 
sersock.close(); // closing network sockets  
pwrite.close(); 
fileRead.close(); 
contentRead.close(); 
} 
catch(Exception e) 
{ 
System.out.println("An error occured while opening the file"); 
} 
} 
}

/*
Output: 
1. Open two terminals and create files client.java and Server.java 
2. Open a terminal and run the server program and provide the filename to 
send 
3.Open one more terminal,run the client programand provide the IP 
address of the server(Loopback address) 
4.Type “start” at the client side. 
Server side: 
Client side: 
*/
