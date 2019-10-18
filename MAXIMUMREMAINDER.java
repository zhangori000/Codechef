/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int arr[] = new int[N];
		int max = 0;
		int secondmax = 0;
		for(int i = 0; i < N; i++) {
			arr[i] = input.nextInt();
			if(arr[i] > max) {
				secondmax = max;
				max = arr[i];
			}
			if(arr[i] < max && arr[i] > secondmax) {
				secondmax = arr[i];
			}
		}
		System.out.println(secondmax % max);







		input.close();
	}
}
