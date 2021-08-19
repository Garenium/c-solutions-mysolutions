import java.util.Scanner;

public class Main{
    public static void main(String[] args)
    {
        Scanner inp = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        String input;
        System.out.println("Enter a two digit number: ");
    
        input = inp.nextLine();

        if(input.matches("[0-9]+") && input.length() == 2)
        {
            sb.append(input);
            sb.reverse();
            System.out.println(sb);
        }
        else
        {
            System.out.println("Invalid input");
        }
        
    }
}
