import java.util.Scanner;

public class BankersAlgoritm 
{
	public static void main(String[] args)
	{
		boolean cont = true;
		
			while(cont) 
			{
					int[][] Need = { {7, 4, 3}, {1, 2, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1} };
					int[][] Allocation = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
					int[] Resource = {10, 5, 7};
					int[] Available = getAvailable(Allocation, Resource);
					printTest(Need, Allocation, Resource, Available);
					testProcesses(Need, Allocation, Available);
					cont = false;
			}
	}
	public static void printTest(int[][] claim, int[][] alloc, int[] resource, int[] available)
	{
		int i;
		int j;
		int col = claim[0].length;
		int row = claim.length;		
		System.out.println("\nAllocation:\n");
		for(i = 1; i < col + 1; i++)
		{
			System.out.print("\tR" + i);
		}
		System.out.print("\n");
		for(i = 1; i < row + 1; i++)
		{
			System.out.print("P" + i + ":\t");
			for(j = 0; j < col; j++)
			{
				System.out.print(alloc[i-1][j] + "\t");
			}
			System.out.print("\n");
		}
		System.out.println("\nNeed:\n");
		for(i = 1; i < col + 1; i++)
		{
			System.out.print("\tR" + i);
		}
		System.out.print("\n");
		for(i = 1; i < row + 1; i++)
		{
			System.out.print("P" + i + ":\t");
			for(j = 0; j < col; j++)
			{
				System.out.print(claim[i-1][j] + "\t");
			}
			System.out.print("\n");
		}		
		System.out.println("\nResource:");
		for(i = 1; i < col + 1; i++)
		{
			System.out.print("R" + i + "\t");
		}
		System.out.print("\n");
		for(i = 0; i < col; i++)
			System.out.print(resource[i] + "\t");
		
		System.out.println("\n");
		System.out.println("\nAvailable:");
		for(i = 1; i < col + 1; i++)
		{
			System.out.print("R" + i + "\t");
		}
		System.out.print("\n");
		for(i = 0; i < col; i++)
			System.out.print(available[i] + "\t");
		
		System.out.print("\n\n");
	}
	public static int[] getAvailable(int[][] alloc, int[] resource)
	{
		int i;
		int j;
		int col = alloc[0].length;
		int row = alloc.length;
		
		int[] available = new int[col];
		int[] temp = new int[col];
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < col; j++)
				temp[j] += alloc [i][j];
		}
		for(i = 0; i < col; i++)
			available[i] = resource[i] - temp[i];
		
		return available;
	}
	public static void testProcesses(int[][] claim, int[][] alloc, int[] available)
	{
		int i;
		int j;
		int x;
		int col = alloc[0].length;
		int row = alloc.length;
		int total = row;
		int lockCount = 0;
		int compCount = 0;
		int seq = 0;
		int[] sequence = new int[row];
		String safeSeq = "";
		boolean cont = true;
		boolean[] blocked = new boolean[row];
		boolean[] safe = new boolean[row];
		boolean[] complete = new boolean[row];
		for(i = 0; i < row; i++)
		{
			safe[i] = true;
			complete[i] = false;
			blocked[i] = false;
		}
		while(cont)
		{
			for(i = 0; i < row; i++)//แถว
			{
				if(safe[i] == true && complete[i] == false)
				{
					for(j = 0; j < col; j++)
					{
						if(available[j] + alloc[i][j] >= claim[i][j])
						{
							if(j == col - 1)
							{
								System.out.println("Process " + (i + 1) + " complete.\nState is safe, proceeding...");//ขั้นตอนที่การแสดงที่เสร็จสมบูรณ์
								for(x = 0; x < col; x++)
									available[x] += alloc[i][x];
								complete[i] = true;
								for(x = 0; x < safe.length; x++) 
									safe[x] = true;
								compCount++;
								sequence[seq] = i+1;
								seq++;
							}
							else
								continue;
						}						
						else if(available[j] + alloc[i][j] < claim[i][j])
						{
							System.out.println("Process " + (i + 1) + " could not be completed.\nState is unsafe, proceeding...");
							safe[i] = false; 
							j = col;
						}
						else
							continue;
					}		
				}
				else if(safe[i] == false && complete[i] == false)
				{
					cont = false;
					blocked[i] = true;
					lockCount++;
					total--;
				}
				else if(compCount == total)
					cont = false;
				else if(lockCount == row)
					cont = false;
			}
		}
		for(i = 0; i < row; i++)
			if(blocked[i] == true)
				System.out.println("Process " + (i+1) + " is blocked.");
		if(lockCount != 0)
		{
			if(lockCount == row)
				System.out.println("Processes are in deadlock.\nAll processes are locked.");
			else
				System.out.println("Processes are in deadlock;\n" + lockCount + " process(es) are blocked.");
		}
		else if(lockCount == 0)
		{
			System.out.println("Processes have been executed.");
			for(i = 0; i < row; i++)
				safeSeq += sequence[i] + ", ";
			System.out.println("Safe sequence: " + safeSeq);
		}		
		System.out.println("\n");
	}
}