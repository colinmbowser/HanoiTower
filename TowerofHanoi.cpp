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

void printAllStacks(stack<int> firstRing, stack<int> secondRing, stack<int> thirdRing)
{
    stack<int> fakeFirstRing = firstRing;
    stack<int> fakeSecondRing = secondRing;
    stack<int> fakeThirdRing = thirdRing;

    stack<int> outputFirstRing;
    stack<int> outputSecondRing;
    stack<int> outputThirdRing;
    
    while (!(fakeFirstRing.empty()))
    {
        outputFirstRing.push(fakeFirstRing.top());
        fakeFirstRing.pop();
    }
    while (!(fakeSecondRing.empty()))
    {
        outputSecondRing.push(fakeSecondRing.top());
        fakeSecondRing.pop();
    }
    while (!(fakeThirdRing.empty()))
    {
        outputThirdRing.push(fakeThirdRing.top());
        fakeThirdRing.pop();
    }

    cout << "First Ring: ";
    while(!(outputFirstRing.empty()))
    {
        cout << outputFirstRing.top() << " ";
        outputFirstRing.pop();
    }
    cout << endl << "Second Ring: ";
    while(!(outputSecondRing.empty()))
    {
        cout << outputSecondRing.top() << " ";
        outputSecondRing.pop();
    }
    cout << endl << "Third Ring: ";
    while(!(outputThirdRing.empty()))
    {
        cout << outputThirdRing.top() << " ";
        outputThirdRing.pop();
    }
    cout << endl;
}

void TowerofHanoi()
{
    stack<int> firstRing;
    stack<int> secondRing;
    stack<int> thirdRing;

    int blockAmount = getNum();
    int newHighest = blockAmount;

    int first;
    int second;
    int third;

    for (int i = blockAmount; i > 0; i--)
    {
        firstRing.push(i);
        cout << firstRing.top() << ' ';
    }
    cout << endl;
    
    while (!(firstRing.empty() && secondRing.empty()))
    {
        while(newHighest != 0)
        {

            // will make variables equal to the top block of each stack,
            // unless there is no top block in a stack then it will equal to 0.
            if (!(firstRing.empty())) {first = firstRing.top();}
            else {first = 0;}
            if (secondRing.empty()) {second = 0;}
            else {second = secondRing.top();}
            if (thirdRing.empty()) {third = 0;}
            else {third = thirdRing.top();}

            printAllStacks(firstRing, secondRing, thirdRing);

            if ((third > newHighest || third == 0) && (first == newHighest || second == newHighest))
            {
                cout << "blocks should move";
                newHighest--;
                cout << endl << newHighest;
                continue;
            }
            else 
            {
                cout << "ERROR! SHOULD NEVER SEE THIS ERROR!";
            }
            break;
        }
        break;
    }

    
    /*
    while (!(firstRing.empty() && secondRing.empty()))
    {
    cout << endl << firstRing.top();
    firstRing.pop();
    firstRing.pop();
    }
    */
    cout << endl << blockAmount;
}

int main()
{
    TowerofHanoi();
    return 0;
}