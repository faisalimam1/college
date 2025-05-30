package client3; 
import java.net.*;  
import java.io.*;  
public class Client3 { 
public static void main( String args[ ] ) throws Exception 
{ 
Socket sock = new Socket( "127.0.0.1", 4000); 
// reading the file name from keyboard. Uses input stream  
System.out.print("Enter the file name to display the contents of file"); 
BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));  
String fname = keyRead.readLine();     // sending the file name to server. Uses PrintWriter  
try 
{ 
OutputStream ostream = sock.getOutputStream( );  
PrintWriter pwrite = new PrintWriter(ostream, true);  
pwrite.println(fname); // receiving the contents from server. Uses input stream  
InputStream istream = sock.getInputStream(); 
BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));  
String str; 
while((str = socketRead.readLine()) != null) // reading line-by-line 
{ 
System.out.println(str); 
} 
pwrite.close(); 
socketRead.close(); 
keyRead.close(); 
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
