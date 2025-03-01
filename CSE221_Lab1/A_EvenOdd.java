import java.util.*;

public class A_EvenOdd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list = new ArrayList<>();

        int input = sc.nextInt();

        for (int i = 0; i < input; i++) {
            list.add(sc.nextInt());
        }
        
        int num = 0;
        for (int j = 0; j < input; j++) {
            num = list.get(j);
            if (num%2 == 0) {
                System.out.println(num + " is an Even number.");
            } else {
                System.out.println(num + " is an Odd number.");
            }
        }
    }        
    
}