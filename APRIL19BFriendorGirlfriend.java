/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
    Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		
		ArrayList<Long> answers = new ArrayList<Long>();
		
		for(int runs = 0; runs < T; runs++) {
			long n = input.nextLong();
			String string = input.next();
			char c = input.next().charAt(0);
			
			long possible = 0L;
			long swiggleSum = 0L;
			long set = -1L;
			
			for(int index = 0; index < n; index++) {
				if(c == string.charAt(index)) {
					possible += (index+1)*(n-index);
					
					if(set == -1) {
						set = index+1;
						
					}
					else {
						
						swiggleSum += (set*(n-index));
						set = index+1;
					}
				}
			}
			
			answers.add((possible-swiggleSum));
		}
		for(int i = 0; i < answers.size(); i++) {
			System.out.println(answers.get(i));
		}
		
		
		
		
		
		
		input.close();
	}
}
