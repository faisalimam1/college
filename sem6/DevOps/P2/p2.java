package th_cse_C.first;
import org.apache.commons.lang3.StringUtils;

public class App 
{
    public static void main( String[] args )
    {
    	String text="Hii Faisal     ";
    	String t2= "Hii";
        System.out.println( "Hello World!" );
        System.out.println("Starts with:"+StringUtils.startsWith(text,t2));
        System.out.println("Ends with:"+StringUtils.endsWith(text,t2));
        System.out.println("Trimmed:"+StringUtils.trim(text));
        System.out.println("Is equals:"+StringUtils.equals(text,t2));
        System.out.println("Is empty:"+StringUtils.isEmpty(""));
    }
}
