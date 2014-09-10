//Longest-Common-Subsequence
//==========================

//An implementation of LCS in C++


#include <iostream>
#include <string>


using namespace std;


void backTraceTheTable(string word1, string word2, int lscTable[100][100], int i, int j, string acc, string acc2, string acc3, int lsc)
{
	
	
	
	
	if (lscTable[i][j] == 1)
	backTraceTheTable(word1, word2, lscTable, i-1, j-1, word1[i-1]+acc, "|"+acc2, word2[j-1]+acc3, lsc);     //Diagonal
	
	else if (lscTable[i][j] == 4)
	backTraceTheTable(word1, word2, lscTable, i-1, j,word1[i-1]+acc, "|"+acc2, "-"+acc3, lsc);              //Up
	
	else if (lscTable[i][j] == 2)
	backTraceTheTable(word1, word2, lscTable, i, j-1, "-"+acc, "|"+acc2, word2[j-1]+acc3, lsc);              //Left
	
	else if (lscTable[i][j] == 5)
	{
		backTraceTheTable(word1, word2, lscTable, i-1, j-1,word1[i-1]+acc, "|"+acc2, word2[j-1]+acc3, lsc); //Diagonal
		backTraceTheTable(word1, word2, lscTable, i-1, j,word1[i-1]+acc, "|"+acc2, "-"+acc3, lsc);          //Up
	}
	
	else if (lscTable[i][j] == 3)
	{
		backTraceTheTable(word1, word2, lscTable, i-1, j-1,word1[i-1]+acc, "|"+acc2, word2[j-1]+acc3, lsc); //Diagonal
		backTraceTheTable(word1, word2, lscTable, i, j-1, "-"+acc, "|"+acc2, word2[j-1]+acc3, lsc);          //Left
	}
	
	else if (lscTable[i][j] == 6)
	{
		backTraceTheTable(word1, word2, lscTable, i-1, j, word1[i-1]+acc, "|"+acc2, "-"+acc3, lsc);          //Up
		backTraceTheTable(word1, word2, lscTable, i, j-1, "-"+acc, "|"+acc2, word2[j-1]+acc3, lsc);          //Left
	}
	
	else if (lscTable[i][j] == 7)
	{
		backTraceTheTable(word1, word2, lscTable, i-1, j-1,word1[i-1]+acc, "|"+acc2, word2[j-1]+acc3, lsc); //Diagonal
		backTraceTheTable(word1, word2, lscTable, i-1, j, word1[i-1]+acc, "|"+acc2, "-"+acc3, lsc);          //Up
		backTraceTheTable(word1, word2, lscTable, i, j-1, "-"+acc, "|"+acc2, word2[j-1]+acc3, lsc);          //Left
	}
	
	int temp2 = 0;
	
	int temp1 = word2.length();
	
	if (temp1 < word1.length())
	temp1 = word1.length();
	
	
	
	if (lsc != 0 )
	{
		if (acc.length() == temp1)
		
		for (int k = 0; k < temp1; k++)
		{
			if (acc[k] == acc3[k])
			{
				++temp2;
			}
		}
		if (temp2 == lsc)
		cout << "Backtrace: " << "\n" << acc << "\n" << acc2 << "\n" << acc3 << endl;
	}
	//}
	//cout << "i is " << i << " and j is " << j << ". Lastly, lscTable[" << i << "][" << j << "] is "<< lscTable[i][j] << "." << endl;
}


void printTable(string word1, string word2, int lscTable[100][100])
{
	
	
	
	
	for (int i = 0; i < word2.length()+1; i++)
	{
		if (i > 0)
		cout << "  " << word2[i-1] << flush;
		
		else
		cout << "   " << flush;
	}
	cout << "" << endl;
	
	for (int i = 0; i < word1.length()+1; i++)
	{
		if (i > 0)
		cout << word1[i-1] << flush;
		
		else
		cout << " " << flush;
		
		cout << "[" << flush;
		for (int j = 0; j < word2.length()+1; j++)
		{
			if (j == word2.length())
			cout << lscTable[i][j] << flush;
			
			else
			cout << lscTable[i][j] << ", " << flush;
		}
		cout << "]" << flush;
		cout << "" << endl;
	}
	
}

string lcsTable(string word1, string word2)
{
	string lcs = "";
	
	int lscTable[100][100]; 
	int backTraceTable[100][100];
	
	for (int i = 0; i <= word1.length(); i++)
	{
		
		for (int j = 0; j <=word2.length(); j++)
		{
			
		
		lscTable[i][j] = 0;
		
		
		
		}
	}
	
	
	//for the backtracing step, we are defining as follows:
	//
	//diagonal = 1
	//up = 4
	//left = 2
	//
	//
	//Therefore:
	//
	//diagonal + up = 5
	//diagonal + left = 3
	//up + left = 6
	//diagonal + up + left = 7
	
	
	for (int i = 1; i <= word1.length(); i++)
	{
		for (int j = 1; j <= word2.length(); j++)
		{
			int choice1 = lscTable[i][j-1]; //gets the item to the left
			int choice2 = lscTable[i-1][j]; //gets the item above
			int choice3 = lscTable[i-1][j-1]; // gets the item at the diagonal
			
			
			
			if (word1[i-1] == word2[j-1])
			{
				
			if (choice1 > choice2)
			{
				if (choice1 > choice3+1)
				{
				lscTable[i][j] = choice1;
				backTraceTable[i][j] = 2;
				}
				
				
				else if (choice1 == choice3+1)
				{
				lscTable[i][j] = choice3+1;
				backTraceTable[i][j] = 3;
				}
				
				else 
				{
				lscTable[i][j] = choice3+1;
				backTraceTable[i][j] = 1;
				}
			}
			
			else if (choice1 == choice2)
			{
				
				if (choice3+1 > choice1)
				{
					backTraceTable[i][j] = 1;
					lscTable[i][j] = choice3+1;
				}
				
				else if (choice3+1 == choice1)
				{
					backTraceTable[i][j] = 7;
					lscTable[i][j] = choice3+1;
				}
				
				else
				{
					backTraceTable[i][j] = 6;
					lscTable[i][j] = choice1;
				}
			}
			
			else
			{
				if (choice2 > choice3+1)
				{
					lscTable[i][j] = choice2;
					backTraceTable[i][j] = 4;
				}
				
				else if (choice2 == choice3+1)
				{
					backTraceTable[i][j] = 5;
					lscTable[i][j] = choice3+1;
				}
				
				else 
				{
					lscTable[i][j] = choice3+1;
					backTraceTable[i][j] = 1;
				
				}
			}
			
		    }
		    
		    
		    else
		    {
				if (choice1 > choice2)
				{
					lscTable[i][j] = choice1;
					backTraceTable[i][j] = 2;
				}
				
				else if (choice1 == choice2)
				{
					backTraceTable[i][j] = 6;
					lscTable[i][j] = choice1;
				}
				
				else
				{
					lscTable[i][j] = choice2;
					backTraceTable[i][j] = 4;
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	printTable(word1, word2, lscTable);
	
	cout << "\n\n\nRight, now here is the backTraceTable:\n\n" << endl;
	
	printTable(word1, word2, backTraceTable);
	cout << "\n\n" << endl;
	backTraceTheTable(word1, word2, backTraceTable, word1.length(), word2.length(), "", "", "", lscTable[word1.length()][word2.length()]);
	
	return lcs;
}



int main()
{

string word1;
string word2;

cout << "Please enter the first string!\n" << endl;
cin >> word1;

cout << "" << endl;
cout << "" << endl;

cout << "Please be so kind as to enter the second string!\n" << endl;
cin >> word2;

cout << "" << endl;
cout << "" << endl;

lcsTable(word1, word2);

return 0;

}
