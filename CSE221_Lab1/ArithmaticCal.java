import java.util.*;

public class ArithmaticCal {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();

        for (int i = 0; i < input; i++) {
            System.out.print("calculate ");
            String str = sc.next();
            System.out.println(calculation(str));
        }
        
    }

    static double calculation(String str) {
        String num1 = "";
        String num2 = "";
        char op = 'w';
        char ch = 'w';

        for (int i = 0; i < str.length(); i++) {
            ch = str.charAt(i);
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
                num1 = str.substring(0, i-1);
                op = ch;
                num2 = str.substring(i+2);
                break;
            }
        }

        double n1 = (double) (Integer.parseInt(num1));
        double n2 = (double) (Integer.parseInt(num2)); 
        
        if (op == '+') {
            return (n1 + n2);
        } else if (op == '-') {
            return (n1 - n2);
        } else if (op == '*') {
            return (n1*n2);
        } else if (op == '/') {
            return (n1/n2);
        } else {
            return (n1%n2);
        }
    }
}
