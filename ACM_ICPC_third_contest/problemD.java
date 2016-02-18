import java.util.Scanner;


public class problemD
{
	public static void main(String[] args)
	{
		
	String D, N;
	Scanner sc = new Scanner(System.in);
	
	D = sc.next();
	N = sc.next();
	while(D.charAt(0) != '0')
	{
		int i = 0;
		boolean zero = true;
		if(N.charAt(0) == D.charAt(0))
		{
			while(i < N.length() && (N.charAt(i) == '0' || N.charAt(i) == D.charAt(0)))
			{
				i++;
			}
		}
		while(i < N.length())
		{
			if(N.charAt(i) != D.charAt(0))
			{
				System.out.print(N.charAt(i));
				zero = false;
			}
			i++;
		}

		if(zero) System.out.print("0");

		System.out.println();
		D = sc.next();
		N = sc.next();
	}
		
	}
}
