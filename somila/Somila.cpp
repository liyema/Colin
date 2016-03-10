#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

// Global variables
char Table[5][5];
string cipherText = "";
string plainMessage = "";
int positionCharRow1, positionCharRow2, positionCharCol1, positionCharCol2, plainTextlenght, cipherLenght;

//Function
string changePlainText(string);
void createTable(string);
void encryption(char, char);
void decryption(char, char);

int main()
{
	string keyword;
	string plainText;
	string cipher;

	cout << "Please enter the key word:  ";
	getline(cin, keyword);
	createTable(keyword);

	cout << "Enter 1 to encrypt or 0 to decrypt: ";
	int choice;
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		cout << "Enter the plaintext message:  ";
		cin.sync();
		getline(cin, plainText);
		cout << endl;
		cout << endl;
		string newPlainText = changePlainText(plainText);
		cout << "The plaintext with filler characters:  " << newPlainText << endl << endl;

		plainTextlenght = newPlainText.length();

		// passing the two paired characters
		int moveCol = 1;
		for (int i = 0; i < newPlainText.size(); i = i + 2)
		{
			encryption(newPlainText[i], newPlainText[moveCol]);
			moveCol = moveCol + 2;
		}
	}
	else if (choice == 0)
	{
		cout << "Enter the ciphertext message:  ";
		cin.sync();
		getline(cin, cipher);
		cout << endl;
		cipherLenght = cipher.length();

		int moveCol = 1;
		for (int i = 0; i < cipher.size(); i = i + 2)
		{
			decryption(cipher[i], cipher[moveCol]);
			moveCol = moveCol + 2;
		}
	}
	system("pause");
	return 0;
}

void decryption(char a1, char b1)
{
	bool a = false;
	bool b = false;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Table[i][j] == a1)
			{
				a = true;
				positionCharRow1 = i;
				positionCharCol1 = j;
			}
			if (Table[i][j] == b1)
			{
				b = true;
				positionCharRow2 = i;
				positionCharCol2 = j;
			}
		}

		if ((a == true) && (b == true))
		{


			if (positionCharRow1 == positionCharRow2) // same row
			{
				if (positionCharCol1 == 0)
				{
					plainMessage = plainMessage + Table[positionCharRow1][positionCharCol1 + 4] + Table[positionCharRow2][positionCharCol2 - 1];
				}
				else if (positionCharCol2 == 0)
				{
					plainMessage = plainMessage + Table[positionCharRow1][positionCharCol1 - 1] + Table[positionCharRow2][positionCharCol2 + 4];
				}
				else
				{
					plainMessage = plainMessage + Table[positionCharRow1][positionCharCol1 - 1] + Table[positionCharRow2][positionCharCol2 - 1];
				}
			}

			else if (positionCharCol1 == positionCharCol2) // same col
			{
				if (positionCharRow1 == 0)
				{
					plainMessage = plainMessage + Table[positionCharRow1 + 4][positionCharCol1] + Table[positionCharRow2 - 1][positionCharCol2];
				}
				else if (positionCharRow2 == 0)
				{
					plainMessage = plainMessage + Table[positionCharRow1 - 1][positionCharCol1] + Table[positionCharRow2 + 4][positionCharCol2];
				}
				else
				{
					plainMessage = plainMessage + Table[positionCharRow1 - 1][positionCharCol1] + Table[positionCharRow2 - 1][positionCharCol2];
				}
			}

			else // different row or col
			{
				plainMessage = plainMessage + Table[positionCharRow1][positionCharCol2] + Table[positionCharRow2][positionCharCol1];
			}
			break;
		}

	}

	if (plainMessage.length() == cipherLenght)
	{
		cout << "The plainText message:  " << plainMessage << endl << endl;
	}
}


void encryption(char a1, char b1)
{

	bool a = false;
	bool b = false;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Table[i][j] == a1)
			{
				a = true;
				positionCharRow1 = i;
				positionCharCol1 = j;
			}
			if (Table[i][j] == b1)
			{
				b = true;
				positionCharRow2 = i;
				positionCharCol2 = j;
			}
		}

		if ((a == true) && (b == true))
		{


			if (positionCharRow1 == positionCharRow2) // same row
			{
				if (positionCharCol1 == 4)
				{
					cipherText = cipherText + Table[positionCharRow1][positionCharCol1 - 4] + Table[positionCharRow2][positionCharCol2 + 1];
				}
				else if (positionCharCol2 == 4)
				{
					cipherText = cipherText + Table[positionCharRow1][positionCharCol1 + 1] + Table[positionCharRow2][positionCharCol2 - 4];
				}
				else
				{
					cipherText = cipherText + Table[positionCharRow1][positionCharCol1 + 1] + Table[positionCharRow2][positionCharCol2 + 1];
				}
			}

			else if (positionCharCol1 == positionCharCol2) // same col
			{
				if (positionCharRow1 == 4)
				{
					cipherText = cipherText + Table[positionCharRow1 - 4][positionCharCol1] + Table[positionCharRow2 + 1][positionCharCol2];
				}
				else if (positionCharRow2 == 4)
				{
					cipherText = cipherText + Table[positionCharRow1 + 1][positionCharCol1] + Table[positionCharRow2 - 4][positionCharCol2];
				}
				else
				{
					cipherText = cipherText + Table[positionCharRow1 + 1][positionCharCol1] + Table[positionCharRow2 + 1][positionCharCol2];
				}
			}

			else // different row or col
			{
				cipherText = cipherText + Table[positionCharRow1][positionCharCol2] + Table[positionCharRow2][positionCharCol1];
			}
			break;
		}

	}

	if (cipherText.length() == plainTextlenght)
	{
		cout << "The cipherText message is:  " << cipherText << endl << endl;
	}
}


string changePlainText(string plaintext)
{
	plaintext.erase(remove(plaintext.begin(), plaintext.end(), ' '), plaintext.end());

	//separating duplicate letter with a filler char
	string fillerChar = "x";
	int y = 1;
	for (int i = 0; i < plaintext.size(); i += 2)
	{
		if (plaintext[i] == plaintext[y])
		{
			plaintext.insert(i + 1, fillerChar);
		}
		y += 2;
	}
	//Adds the filler char in incomplete last pair
	if (plaintext.size() % 2 == 1)
	{
		plaintext.insert(plaintext.length(), fillerChar);
	}

	//checking for j in the plain text and replacing with i
	for (int w = 0; w < plaintext.size(); w++)
	{
		if (plaintext[w] == 'j')
		{
			plaintext[w] = 'i';
		}
	}
	cout << endl;
	return plaintext;
}


void createTable(string keyword)
{
	// start of creating table
	for (int w = 0; w < keyword.size(); w++)
	{
		if (keyword[w] == 'j')
		{
			keyword[w] = 'i';
		}
	}
	cout << endl;
	//erasing spaces between the words
	keyword.erase(remove(keyword.begin(), keyword.end(), ' '), keyword.end());

	//check duplicates of characters in the keyword
	for (int i = 0; i < keyword.size() - 1; i++)
	{
		for (int j = i + 1; j < keyword.size(); j++)
		{
			if (keyword[i] == keyword[j])
			{
				keyword.erase(keyword.begin() + j);
			}
		}
	}

	cout << "The new keyword without duplicates is:  ";
	for (int i = 0; i < keyword.size(); i++)
	{
		cout << keyword[i];
	}
	cout << endl;

	string alphabets = "abcdefghiklmnopqrstuvwxyz";			//Alphabets of 25 letters, j excluded
	string dummy = keyword + alphabets;

	// creating string alphabets without duplicates with keyword in first rows
	for (int k = 0; k < dummy.size() - 1; k++)
	{
		for (int m = k + 1; m < dummy.size(); m++)
		{
			if (dummy[k] == dummy[m])
			{
				dummy.erase(dummy.begin() + m);
			}
		}
	}
	//creating a 5x5 Table of Alphabets
	int l = 0;
	char c;

	for (int row = 0; row < 5; row++)
	{
		for (int column = 0; column < 5; column++)

		{
			c = dummy[l];
			Table[row][column] = c;
			l++;
		}
	}

	//Printing the Table
	for (int k = 0; k < 5; k++)
	{
		for (int m = 0; m < 5; m++)
		{
			cout << Table[k][m] << '\t';
		}

		cout << endl << endl;
	}
	// end of create table

}