

/*5. Design a super class called staff with details as staff id, name, phone number and salary. Extend this class by writing 3 sub classes namely
teaching (domain,publications), technical (skills) and contract (period). Write a JAVA program to read and display the staff objects of all 3 
categories*/
import java.util.Scanner;

class Staff {
    String sid, name, phone, salary;
    Scanner s = new Scanner(System.in);

    void read() {
        System.out.println("Enter SID,Name,Phone No.,Salary");
        sid = s.nextLine();
        name = s.nextLine();
        phone = s.nextLine();
        salary = s.nextLine();
    }

    void display() {
        System.out.print(sid + "\t" + name + "\t" + phone + "\t" + salary + "\t");
    }
}

class Teaching extends Staff {
    String domain, publication;

    void read() {
        super.read();
        System.out.println("Enter domain, publication");
        domain = s.nextLine();
        publication = s.nextLine();
    }

    void display() {
        super.display();
        System.out.print(domain + "\t" + publication + "\n");
    }
}

class Technical extends Staff {
    String skill;

    void read() {
        super.read();
        System.out.println("Enter skill");
        skill = s.nextLine();
    }

    void display() {
        super.display();
        System.out.print(skill + "\n");
    }
}

class Contract extends Staff {
    String period;

    void read() {
        super.read();
        System.out.println("Enter period");
        period = s.nextLine();
    }

    void display() {
        super.display();
        System.out.print(period + "\n");
    }
}

public class Demo {
    public static void main(String[] args) {
        Teaching t = new Teaching();
        t.read();
        System.out.println("SID\tName\tPhone No.\tSalary\tDomain\tPublication");
        t.display();
        Technical th = new Technical();
        th.read();
        System.out.println("SID\tName\tPhone No.\tSalary\tSkill");
        th.display();
        Contract c = new Contract();
        c.read();
        System.out.println("SID\tName\tPhone No.\tSalary\tPeriod");
        c.display();
    }
}
