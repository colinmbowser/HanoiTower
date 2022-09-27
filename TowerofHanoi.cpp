#include <iostream>
#include <stack>
#include <thread>

using namespace std;
using namespace chrono_literals;

class myStack
{
    public:
        string ringName;
        stack<int> ringStack;
};

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

void printStack(string ringName, stack<int> fakeRing)
{
    stack<int> outputRing;

    while (!(fakeRing.empty()))
    {
    outputRing.push(fakeRing.top());
    fakeRing.pop();
    }
    cout << ringName << "Ring: ";
    while(!(outputRing.empty()))
    {
        cout << outputRing.top() << " ";
        outputRing.pop();
    }
    cout << endl;
}

void printAllStacks(string firstRingName, stack<int> newFirstRing, string secondRingName, stack<int> newSecondRing, string thirdRingName, stack<int> newThirdRing)
{
    printStack(firstRingName, newFirstRing);
    printStack(secondRingName, newSecondRing);
    printStack(thirdRingName, newThirdRing);
}

void TowerofHanoi()
{
    myStack firstRing;
    myStack secondRing;
    myStack thirdRing;

    firstRing.ringName = "First";
    secondRing.ringName = "Second";
    thirdRing.ringName = "Third";

    int blockAmount = getNum();
    int newHighest = blockAmount;

    int first;
    int second;
    int third;
    printAllStacks(firstRing.ringName, firstRing.ringStack, secondRing.ringName, secondRing.ringStack, thirdRing.ringName, thirdRing.ringStack);

    for (int i = blockAmount; i > 0; i--)
    {
        firstRing.ringStack.push(i);
        cout << firstRing.ringStack.top() << ' ';
    }
    cout << endl;

    while (!(firstRing.ringStack.empty() && secondRing.ringStack.empty()))
    {
        while(newHighest != 0)
        {

            // will make variables equal to the top block of each stack,
            // unless there is no top block in a stack then it will equal to 0.
            if (!(firstRing.ringStack.empty())) {first = firstRing.ringStack.top();}
            else {first = 0;}
            if (!(secondRing.ringStack.empty())) {second = secondRing.ringStack.top();}
            else {second = 0;}
            if (!(thirdRing.ringStack.empty())) {third = thirdRing.ringStack.top();}
            else {third = 0;}

            if ((third > newHighest || third == 0) && (first == newHighest || second == newHighest))
            {
                cout << "blocks should move";
                newHighest--;
                cout << endl << newHighest;
                continue;
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

    //will clear terminal by adding 50 empty lines of code
    cout << string(50, '\n' );

    //will pause the code for 1000 ms (1 second) and then resume
    this_thread::sleep_for(1000ms);


    */
    cout << blockAmount;

}

int main()
{
    TowerofHanoi();
    return 0;
}