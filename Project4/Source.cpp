#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

char Board[3][3]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char Player = 'X';
char Computer = 'O';
bool NotWin=false;
int PlayerWon = 0;
int ComputerWon = 0;
int Draw = 0;

bool CheckWin();
void ShowBoard();
void PlayerMove();
void ClearBoard();
void CheckWinLose();
void ComputerMove(int Moves);


int main()
{
	int Moves = 0;
	int Flag = 0;
	while (Flag != 2)
	{
		while (Flag == 0)
		{
			ShowBoard();
			PlayerMove();
			Moves++;
			ShowBoard();
			if (CheckWin() == 1)
				Flag = 1;
			if (Flag == 1)
				break;
			if (Moves == 9)
			{
				cout << endl << "Draw!    ";
				Draw++;
				Flag = 1;
			}
			if (Flag == 1)
				break;
			ComputerMove(Moves);
			Moves++;
			ShowBoard();
			if (CheckWin() == 1)
				Flag = 1;
			if (Flag == 1)
				break;
		}
		Sleep(2000);
		Flag = 0;
		ClearBoard();
		Moves = 0;
		while (Flag == 0)
		{
			ShowBoard();
			ComputerMove(Moves);
			Moves++;
			ShowBoard();
			if (CheckWin() == 1)
				Flag = 1;
			if (Flag == 1)
				break;
			if (Moves == 9)
			{
				cout << endl << "Draw!    ";
				Draw++;
				Flag = 1;
			}
			if (Flag == 1)
				break;
			PlayerMove();
			Moves++;
			ShowBoard();
			if (CheckWin() == 1)
				Flag = 1;
			if (Flag == 1)
				break;
		}
		Sleep(2000);
		Flag = 0;
		ClearBoard();
		Moves = 0;
	}

	return 0;
}
bool CheckWin()
{
	if ((Board[0][0] == Board[0][1]) && (Board[0][1] == Board[0][2]) && (Board[0][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[1][0] == Board[1][1]) && (Board[1][1] == Board[1][2]) && (Board[1][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[2][0] == Board[2][1]) && (Board[2][1] == Board[2][2]) && (Board[2][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[0][0] == Board[1][0]) && (Board[1][0] == Board[2][0]) && (Board[0][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[0][1] == Board[1][1]) && (Board[1][1] == Board[2][1]) && (Board[0][1] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[0][2] == Board[1][2]) && (Board[1][2] == Board[2][2]) && (Board[0][2] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[0][0] == Board[1][1]) && (Board[1][1] == Board[2][2]) && (Board[0][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[2][0] == Board[1][1]) && (Board[1][1] == Board[0][2]) && (Board[2][0] == Player))
	{
		cout << "You won!" << endl;
		PlayerWon++;
		return 1;
	}
	else if ((Board[0][0] == Board[0][1]) && (Board[0][1] == Board[0][2]) && (Board[0][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[1][0] == Board[1][1]) && (Board[1][1] == Board[1][2]) && (Board[1][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[2][0] == Board[2][1]) && (Board[2][1] == Board[2][2]) && (Board[2][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[0][0] == Board[1][0]) && (Board[1][0] == Board[2][0]) && (Board[0][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[0][1] == Board[1][1]) && (Board[1][1] == Board[2][1]) && (Board[0][1] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[0][2] == Board[1][2]) && (Board[1][2] == Board[2][2]) && (Board[0][2] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[0][0] == Board[1][1]) && (Board[1][1] == Board[2][2]) && (Board[0][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
	else if ((Board[2][0] == Board[1][1]) && (Board[1][1] == Board[0][2]) && (Board[2][0] == Computer))
	{
		cout << "You lost!" << endl;
		ComputerWon++;
		return 1;
	}
}
void ShowBoard()
{
	COORD p = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (Board[i][j] == Player || Board[i][j] == Computer)
				cout << Board[i][j];
			else
				cout << ' ';
			cout << " ";
		}
		cout << endl;
	}
	cout << "You won: " << PlayerWon << endl;
	cout << "You lost: " << ComputerWon << endl;
	cout << "Draw: " << Draw << endl;
}
void PlayerMove()
{
	bool Key = false;
	while (Key != true)
	{
		switch (_getch())
		{
		case '1':
			if ((Board[2][0] != Computer) && (Board[2][0] != Player))
			{
				Board[2][0] = Player;
				Key = true;
				break;
			}
			else break;
		case '2':
			if ((Board[2][1] != Computer) && (Board[2][1] != Player))
			{
				Board[2][1] = Player;
				Key = true;
				break;
			}
			else break;
		case '3':
			if ((Board[2][2] != Computer) && (Board[2][2] != Player))
			{
				Board[2][2] = Player;
				Key = true;
				break;
			}
			else break;
		case '4':
			if ((Board[1][0] != Computer) && (Board[1][0] != Player))
			{
				Board[1][0] = Player;
				Key = true;
				break;
			}
			else break;
		case '5':
			if ((Board[1][1] != Computer) && (Board[1][1] != Player))
			{
				Board[1][1] = Player;
				Key = true;
				break;
			}
			else break;
		case '6':
			if ((Board[1][2] != Computer) && (Board[1][2] != Player))
			{
				Board[1][2] = Player;
				Key = true;
				break;
			}
			else break;
		case '7':
			if ((Board[0][0] != Computer) && (Board[0][0] != Player))
			{
				Board[0][0] = Player;
				Key = true;
				break;
			}
			else break;
		case '8':
			if ((Board[0][1] != Computer) && (Board[0][1] != Player))
			{
				Board[0][1] = Player;
				Key = true;
				break;
			}
			else break;
		case '9':
			if ((Board[0][2] != Computer) && (Board[0][2] != Player))
			{
				Board[0][2] = Player;
				Key = true;
				break;
			}
			else break;
		}
	}
}
void ClearBoard()
{
	int l = 1;
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			Board[i][j] = l;
			l++;
		}
	}
}
void CheckWinLose()
{
	//horizontaliai
	if ((Board[0][0] == Computer) && (Board[0][1] == Computer) && (Board[0][2] != Player))
		Board[0][2] = Computer;
	else if ((Board[0][0] == Computer) && (Board[0][2] == Computer) && (Board[0][1] != Player))
		Board[0][1] = Computer;
	else if ((Board[0][1] == Computer) && (Board[0][2] == Computer) && (Board[0][0] != Player))
		Board[0][0] = Computer;
	else if ((Board[1][0] == Computer) && (Board[1][1] == Computer) && (Board[1][2] != Player))
		Board[1][2] = Computer;
	else if ((Board[1][0] == Computer) && (Board[1][2] == Computer) && (Board[1][1] != Player))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Computer) && (Board[1][2] == Computer) && (Board[1][0] != Player))
		Board[1][0] = Computer;
	else if ((Board[2][0] == Computer) && (Board[2][1] == Computer) && (Board[2][2] != Player))
		Board[2][2] = Computer;
	else if ((Board[2][0] == Computer) && (Board[2][2] == Computer) && (Board[2][1] != Player))
		Board[2][1] = Computer;
	else if ((Board[2][1] == Computer) && (Board[2][2] == Computer) && (Board[2][0] != Player))
		Board[2][0] = Computer;
	// vertikaliai
	else if ((Board[0][0] == Computer) && (Board[1][0] == Computer) && (Board[2][0] != Player))
		Board[2][0] = Computer;
	else if ((Board[0][0] == Computer) && (Board[2][0] == Computer) && (Board[1][0] != Player))
		Board[1][0] = Computer;
	else if ((Board[1][0] == Computer) && (Board[2][0] == Computer) && (Board[0][0] != Player))
		Board[0][0] = Computer;
	else if ((Board[0][1] == Computer) && (Board[1][1] == Computer) && (Board[2][1] != Player))
		Board[2][1] = Computer;
	else if ((Board[0][1] == Computer) && (Board[2][1] == Computer) && (Board[1][1] != Player))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Computer) && (Board[2][1] == Computer) && (Board[0][1] != Player))
		Board[0][1] = Computer;
	else if ((Board[0][2] == Computer) && (Board[1][2] == Computer) && (Board[2][2] != Player))
		Board[2][2] = Computer;
	else if ((Board[0][2] == Computer) && (Board[2][2] == Computer) && (Board[1][2] != Player))
		Board[1][2] = Computer;
	else if ((Board[1][2] == Computer) && (Board[2][2] == Computer) && (Board[0][2] != Player))
		Board[0][2] = Computer;
	//istrizai
	else if ((Board[0][0] == Computer) && (Board[1][1] == Computer) && (Board[2][2] != Player))
		Board[2][2] = Computer;
	else if ((Board[0][0] == Computer) && (Board[2][2] == Computer) && (Board[1][1] != Player))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Computer) && (Board[2][2] == Computer) && (Board[0][0] != Player))
		Board[0][0] = Computer;
	else if ((Board[0][2] == Computer) && (Board[1][1] == Computer) && (Board[2][0] != Player))
		Board[2][0] = Computer;
	else if ((Board[0][2] == Computer) && (Board[2][0] == Computer) && (Board[1][1] != Player))
		Board[1][1] = Computer;
	else if ((Board[2][0] == Computer) && (Board[1][1] == Computer) && (Board[0][2] != Player))
		Board[0][2] = Computer;
	//horizontaliai
	else if ((Board[0][0] == Player) && (Board[0][1] == Player) && (Board[0][2] != Computer))
		Board[0][2] = Computer;
	else if ((Board[0][0] == Player) && (Board[0][2] == Player) && (Board[0][1] != Computer))
		Board[0][1] = Computer;
	else if ((Board[0][1] == Player) && (Board[0][2] == Player) && (Board[0][0] != Computer))
		Board[0][0] = Computer;
	else if ((Board[1][0] == Player) && (Board[1][1] == Player) && (Board[1][2] != Computer))
		Board[1][2] = Computer;
	else if ((Board[1][0] == Player) && (Board[1][2] == Player) && (Board[1][1] != Computer))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Player) && (Board[1][2] == Player) && (Board[1][0] != Computer))
		Board[1][0] = Computer;
	else if ((Board[2][0] == Player) && (Board[2][1] == Player) && (Board[2][2] != Computer))
		Board[2][2] = Computer;
	else if ((Board[2][0] == Player) && (Board[2][2] == Player) && (Board[2][1] != Computer))
		Board[2][1] = Computer;
	else if ((Board[2][1] == Player) && (Board[2][2] == Player) && (Board[2][0] != Computer))
		Board[2][0] = Computer;
	//vertikaliai
	else if ((Board[0][0] == Player) && (Board[1][0] == Player) && (Board[2][0] != Computer))
		Board[2][0] = Computer;
	else if ((Board[0][0] == Player) && (Board[2][0] == Player) && (Board[1][0] != Computer))
		Board[1][0] = Computer;
	else if ((Board[1][0] == Player) && (Board[2][0] == Player) && (Board[0][0] != Computer))
		Board[0][0] = Computer;
	else if ((Board[0][1] == Player) && (Board[1][1] == Player) && (Board[2][1] != Computer))
		Board[2][1] = Computer;
	else if ((Board[0][1] == Player) && (Board[2][1] == Player) && (Board[1][1] != Computer))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Player) && (Board[2][1] == Player) && (Board[0][1] != Computer))
		Board[0][1] = Computer;
	else if ((Board[0][2] == Player) && (Board[1][2] == Player) && (Board[2][2] != Computer))
		Board[2][2] = Computer;
	else if ((Board[0][2] == Player) && (Board[2][2] == Player) && (Board[1][2] != Computer))
		Board[1][2] = Computer;
	else if ((Board[1][2] == Player) && (Board[2][2] == Player) && (Board[0][2] != Computer))
		Board[0][2] = Computer;
	//istrizai
	else if ((Board[0][0] == Player) && (Board[1][1] == Player) && (Board[2][2] != Computer))
		Board[2][2] = Computer;
	else if ((Board[0][0] == Player) && (Board[2][2] == Player) && (Board[1][1] != Computer))
		Board[1][1] = Computer;
	else if ((Board[1][1] == Player) && (Board[2][2] == Player) && (Board[0][0] != Computer))
		Board[0][0] = Computer;
	else if ((Board[0][2] == Player) && (Board[1][1] == Player) && (Board[2][0] != Computer))
		Board[2][0] = Computer;
	else if ((Board[0][2] == Player) && (Board[2][0] == Player) && (Board[1][1] != Computer))
		Board[1][1] = Computer;
	else if ((Board[2][0] == Player) && (Board[1][1] == Player) && (Board[0][2] != Computer))
		Board[0][2] = Computer;
	else NotWin = true;
}
void ComputerMove(int Moves)
{
	if (Moves == 0)
	{
		Board[0][0] = Computer;
	}
	else if (Moves == 1)
	{
		if (Board[1][1] == Player)
			Board[0][0] = Computer;
		else Board[1][1] = Computer;
	}
	else if (Moves == 2)
	{
		if (Board[1][1] == Player)
			Board[2][2] = Computer;
		else if ((Board[0][2] == Player) || (Board[2][0] == Player))
			Board[2][2] = Computer;
		else if (Board[2][2] == Player)
			Board[2][0] = Computer;
		else
			Board[1][1] = Computer;
	}
	else if (Moves == 3)
	{
		CheckWinLose();
		if (NotWin == true)
		{
			NotWin = false;
			if ((Board[0][0] == Player) && (Board[2][2] == Player))
				Board[1][0] = Computer;
			else if ((Board[2][0] == Player) && (Board[0][2] == Player))
				Board[1][0] = Computer;
			else if ((Board[1][0] == Player) && (Board[0][1] == Player))
				Board[0][0] = Computer;
			else if ((Board[2][1] == Player) && (Board[1][2] == Player))
				Board[2][2] = Computer;
			else if ((Board[1][0] == Player) && (Board[2][1] == Player))
				Board[2][0] = Computer;
			else if ((Board[0][1] == Player) && (Board[1][2] == Player))
				Board[0][2] = Computer;
			else if ((Board[1][1] == Player) && (Board[2][2] == Player))
				Board[2][0] = Computer;
			else if (Board[0][0] == Player)
				Board[2][2] = Computer;
			else if (Board[2][2] == Player)
				Board[0][0] = Computer;
			else if (Board[2][0] == Player)
				Board[0][2] = Computer;
			else if (Board[0][2] == Player)
				Board[2][0] = Computer;
			else Board[0][0] = Computer;
		}
	}
	else if (Moves == 4)
	{
		CheckWinLose();
		if (NotWin == true)
		{
			if ((Board[2][2] == Computer) && (Board[2][0] != Player))
				Board[2][0] = Computer;
			else if ((Board[2][2] == Computer) && (Board[0][2] != Player))
				Board[0][2] = Computer;
			else if (Board[2][0] == Computer)
				Board[0][2] = Computer;
			else if (Board[1][0] == Player)
				Board[0][2] = Computer;
			else if (Board[0][1] == Player)
				Board[2][0] = Computer;
			NotWin = false;
		}
	}

	else
	{
		CheckWinLose();
		if (NotWin == true)
		{
			NotWin = false;
		    if ((Board[0][2] != Player) && (Board[0][2] != Computer))
			    Board[0][2] = Computer;
			else if ((Board[2][0] != Player) && (Board[2][0] != Computer))
				Board[2][0] = Computer;
			else if ((Board[1][0] != Player) && (Board[1][0] != Computer))
				Board[1][0] = Computer;
			else if ((Board[0][1] != Player) && (Board[0][1] != Computer))
				Board[0][1] = Computer;
			else if ((Board[2][1] != Player) && (Board[2][1] != Computer))
				Board[2][1] = Computer;
			else if ((Board[1][2] != Player) && (Board[1][2] != Computer))
				Board[1][2] = Computer;
		}
	}
}