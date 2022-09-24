#include <iostream>
#include <stack>

using namespace std;

int getNum()
{
    int blockInputAmount = 0;
    cout << "Please enter the amount of blocks you want Tower of Hanoi to have (up to 10): ";
    cin >> blockInputAmount;
    while (blockInputAmount < 1 || blockInputAmount > 10)
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "please enter a number between 1 and 10: ";
        cin >> blockInputAmount;
    }
    return blockInputAmount;
}

void TowerofHanoi()
{
    stack<int> firstRing;
    stack<int> secondRing;
    stack<int> thirdRing;

    int blockAmount = getNum();

    for (int i = 0; i < blockAmount; i++)
    {
        firstRing.push(i+1);
        cout << firstRing.top();
    }
    firstRing.pop();
    firstRing.pop();
    cout << endl << firstRing.top();


    cout << endl << blockAmount;

}

int main()
{
    TowerofHanoi();
    return 0;
}