#include<iostream>
#include<ctime>
using namespace std;
void takeInputOFArray(char array[][3], int rows, int columns)
{
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < columns; j = j + 1)
		{
			cout << "[" << i << "][" << j << "] = ";
			cin >> array[i][j];
		}
	}
}
void displayArray(char array[][3], int rows, int columns)
{
	for (int i = 0; i < rows; i = i + 1)
	{
		for (int j = 0; j < columns; j = j + 1)
		{
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}
bool performToss()
{
	int n = rand() % 2;
	if (n == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool performAlgorithm(char array[][3])
{
	if (array[0][0] == array[1][1] && array[1][1] == array[2][2])
	{
		return true;
	}
	else if (array[0][0] == array[0][1] && array[0][1] == array[0][2])
	{
		return true;
	}
	else if (array[0][2] == array[1][1] && array[1][1] == array[2][0])
	{
		return true;
	}
	else if (array[1][0] == array[1][1] && array[1][1] == array[1][2])
	{
		return true;
	}
	else if (array[2][0] == array[2][1] && array[2][1] == array[2][2])
	{
		return true;
	}
	else if (array[0][0] == array[1][0] && array[1][0] == array[2][0])
	{
		return true;
	}
	else if (array[0][1] == array[1][1] && array[1][1] == array[2][1])
	{
		return true;
	}
	else if (array[0][2] == array[1][2] && array[1][2] == array[2][2])
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool findLocation(int userInput, char arrayTicTacToe[][3])
{
	int location = userInput - 1;
	int rows = location / 3;
	int columns = location % 3;
	if (arrayTicTacToe[rows][columns] == 'X' || arrayTicTacToe[rows][columns] == 'O')
	{
		return true;
	}
	return false;
}
void addElement(char arrayTic[][3], int userLocation, char element)
{
	int location = userLocation - 1;
	int rows = location / 3;
	int columns = location % 3;
	arrayTic[rows][columns] = element;
}
void playAgain();
void ticTacToeGame()
{
	char ticTacToeArray[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9' } };
	char choiceForToss;
	int indexOfMatrix;
	char PlayerChoice;

	cout << "\nPLayer X enter choice for toss from H/T :\n";
	cin >> choiceForToss;

	if (performToss())
	{
		cout << "PLayer X ,You won the toss \nLet's Start the Game \nPlease Enter your move in following matrix \n";
		PlayerChoice = 'X';
	}
	else
	{
		cout << "PLayer O,You won the toss \nLet's Start the Game \nPlease Enter your move in following matrix \n";
		PlayerChoice = 'O';
	}
	cout << "\n";
	displayArray(ticTacToeArray, 3, 3);

	for (int i = 0; i < 9; i = i + 1)
	{
		cout << "Player " << PlayerChoice << " ,At which location you want to enter : \t";
		do
		{
			cin >> indexOfMatrix;
		} while (findLocation(indexOfMatrix, ticTacToeArray) || (indexOfMatrix > 9));
		addElement(ticTacToeArray, indexOfMatrix, PlayerChoice);
		displayArray(ticTacToeArray, 3, 3);
		if (performAlgorithm(ticTacToeArray))
		{
			cout << "Player " << PlayerChoice << ", You Won" << endl;
			playAgain();
		}
		if (PlayerChoice == 'O')
		{
			PlayerChoice = 'X';
		}
		else
		{
			PlayerChoice = 'O';
		}
	}

	cout << " MATCH DRAW \n";
	playAgain();
}
void mainGame()
{
	cout << "There are two Players \"X\" and \"O\" ";
	ticTacToeGame();
	char c;
	cout << "You want to play again,Select from y/n (yes/no)";
	cin >> c;
	if (c == 'y')
	{
		ticTacToeGame();
	}
	else
	{
		exit(0);
	}
}
int main()
{
	srand(time(0));
	mainGame();
}
void playAgain()
{
	char c;
	cout << "You want to play again,Select from y/n (yes/no) : \t";
	cin >> c;
	if (c == 'y')
	{
		ticTacToeGame();
	}
	else
	{
		cout << "Thank you for playing!\n\n";
		exit(0);
	}
}



















//#include<iostream>
//using namespace std;
//int getSec(int* num)
//{
//	int sum = 0;
//	for (int i = 0; i < 5; i++)
//	{
//		sum = sum + num[i];
//	}
//	return sum;
//}
//
//
//int main()
//{
//	int sec[5] = {100,3,5,7,8};
//	int* ptr = &sec[0];
//	cout << *ptr;
//
//}




















//class person
//{
//	char name[20];
//	void strcpy(char* destination, const char* source)
//	{
//		int i = 0;
//		while (source[i] != '\0')
//		{
//			destination[i] = source[i];
//			i = i + 1;
//		}
//		destination[i] = '\0';
//	}
//public:
//	person(const char* tempName)
//	{
//		strcpy(name, tempName);
//	}
//	~person()
//	{
//		cout << name << "  Bye Bye ";
//	}
//};
//int main()
//{
//	person p1("zaha");
//	person p2("Emaan");
//}






//class BankAccount
//{
//	int accountNumber;
//	int bankBalance;
//public:
//	BankAccount(int accN , int bankB)
//	{
//		accountNumber = accN;
//		bankBalance = bankB;
//	}
//	void depositMoney(int bankacc , int amount)
//	{
//		if (bankacc == accountNumber)
//		{
//			bankBalance = bankBalance + amount;
//		}
//		else
//		{
//			cout << "Wrong acc number";
//		}
//	}
//	void withdrawMoney(int bankacc, int amount)
//	{
//		if (bankacc == accountNumber)
//		{
//			bankBalance = bankBalance - amount;
//		}
//		else
//		{
//			cout << "Wrong acc number";
//		}
//	}
//	int getBankBalance()
//	{
//		return bankBalance;
//	}
//};
//int main()
//{
//	BankAccount b(234,2000);
//	cout << b.getBankBalance() << endl;
//	b.withdrawMoney(1234, 100);
//	cout << b.getBankBalance() << endl;
//	b.depositMoney(1234, 200);
//	cout << b.getBankBalance() << endl;
//}


//class Rectangle
//{
//	int width;
//	int length;
//public:
//	Rectangle(int w , int l)
//	{
//		width = w;
//		length = l;
//	}
//	int calculateAreaOfRectangle()
//	{
//		return (width * length);
//	}
//};
//int main()
//{
//	Rectangle r(2, 3);
//	cout << r.calculateAreaOfRectangle();
//	return 0;
//}