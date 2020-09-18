#include <iostream>
#include <time.h>

using namespace std;

void Print(char arr[9])
{
    int count = 0;
    cout << "_____________\n";
    for (size_t i = 0; i < 9; i++)
    {
        cout << "|" << arr[i] << "|";
        count++;
        if (count == 3 || count == 6)
            cout << endl;
    }
    cout << "\n_________\n";
}
void Play(char token, char arr[9])
{
    int number = 0;
    while (true)
    {
        cout << "Enter number: ";
        cin >> number;
        if (number > 0 && number <= 9 && arr[number - 1] != 'X' && arr[number - 1] != 'O')
        {
            arr[number - 1] = token;
            break;
        }
        else
        {
            cout << "Error!\n";
        }
    }
}
void Playboot(char token, char arr[9])
{
    srand(time(0));
    int number = 0;
    while (true)
    {        
        number=1+rand()%9;
        if (number > 0 && number <= 9 && arr[number - 1] != 'X' && arr[number - 1] != '0')
        {
            arr[number - 1] = token;
            break;
        }
        else
        {
            cout << "Error\n";
        }
    }
}


char Win(char token, char arr[9])
{
    if (arr[0] == token && arr[1] == token && arr[2] == token) return true;
    if (arr[3] == token && arr[4] == token && arr[5] == token) return true;
    if (arr[6] == token && arr[7] == token && arr[8] == token) return true;
    if (arr[0] == token && arr[3] == token && arr[6] == token) return true;
    if (arr[1] == token && arr[4] == token && arr[7] == token) return true;
    if (arr[2] == token && arr[5] == token && arr[8] == token) return true;
    if (arr[0] == token && arr[4] == token && arr[8] == token) return true;
    if (arr[2] == token && arr[4] == token && arr[6] == token) return true;

    return false;
}


int main()
{
    int counter = 0;
    char arr[9] = { '1','2','3','4','5','6','7','8','9' };
    //char Win;
    while (true)
    {
        Print(arr);
        if (counter % 2 == 0)
        {
            Play('X', arr);
            if (Win('X', arr))
            {
                Print(arr);
                cout << "Won X";
                break;
            }

        }
        else
        {
            Playboot('0', arr);
            if (Win('0', arr))
            {
                Print(arr);
                cout << "Won 0";
                break;
            }

        }
        counter++;
        system("CLS");
        if (counter == 9)
        {
            cout << "Nichiya" << endl;
            break;
        }

    }
    cout << endl;
    //system("CLS");
    //Print(arr);
    //return 0;
}


