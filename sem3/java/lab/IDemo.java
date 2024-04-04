/*9. Develop a JAVA program to raise a custom exception (user defined exception) for DivisionByZero using 
try, catch, throw and finally.
*/
import java.util.Scanner;
class IException extends Exception{
    IException(String msg){
        super(msg);
    }
}
public class IDemo {
    static void divide(double a , double b)throws IException{
        if(b==0)
            throw new IException("Division by zero is not possible");
        double c=a/b;
        System.out.println("Result : "+c);
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the values of x and y : ");
        double x=s.nextDouble();
        double y=s.nextDouble();
        try{
            divide(x,y);
        }
        catch(Exception e){
            System.out.println(e);
        }
        finally{
            System.out.println("End");
        }
    }
}
