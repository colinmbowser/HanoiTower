#include <iostream>
#include <stack>
#include <thread>
#include <chrono>

using namespace std;

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
    cout << ringName << " Ring: ";
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

    // will make variables equal to the top block of each stack,
    // unless there is no top block in a stack then it will equal to .
int changeNum(stack<int> changeNumStack)
{
    int newNumber = 0;
    if (!(changeNumStack.empty())) 
    {newNumber = changeNumStack.top();}
    return newNumber;
}

void TowerofHanoi()
{
    myStack firstRing;
    myStack secondRing;
    myStack thirdRing;

    firstRing.ringName = " First";
    secondRing.ringName = "Second";
    thirdRing.ringName = " Third";

    int blockAmount = getNum();

    for (int i = blockAmount; i > 0; i--)
    {
        firstRing.ringStack.push(i);
    }

    int switchMaster;
    int first = changeNum(firstRing.ringStack);
    int second = changeNum(secondRing.ringStack);
    int third = changeNum(thirdRing.ringStack);
    //cout << first;

    while (!(firstRing.ringStack.empty() && secondRing.ringStack.empty()))
    {
        if ((second > first || second == 0) && first != 0)
        {
            secondRing.ringStack.push(firstRing.ringStack.top());
            firstRing.ringStack.pop();
        }
        else if ((first > second || first == 0) && second != 0)
        {
            firstRing.ringStack.push(secondRing.ringStack.top());
            secondRing.ringStack.pop();
        }
        cout << string(20, '\n' );
        printAllStacks(firstRing.ringName, firstRing.ringStack, secondRing.ringName, secondRing.ringStack, thirdRing.ringName, thirdRing.ringStack);
        first = changeNum(firstRing.ringStack);
        second = changeNum(secondRing.ringStack);
        this_thread::sleep_for(1000ms);

        if ((third > first || third == 0) && first != 0)
        {
            thirdRing.ringStack.push(firstRing.ringStack.top());
            firstRing.ringStack.pop();
        }
        else if ((first > third || first == 0) && third != 0)
        {
            firstRing.ringStack.push(thirdRing.ringStack.top());
            thirdRing.ringStack.pop();
        }
        cout << string(20, '\n' );
        printAllStacks(firstRing.ringName, firstRing.ringStack, secondRing.ringName, secondRing.ringStack, thirdRing.ringName, thirdRing.ringStack);
        first = changeNum(firstRing.ringStack);
        third = changeNum(thirdRing.ringStack);
        this_thread::sleep_for(1000ms);

        if ((third > second || third == 0) && second != 0)
        {
            thirdRing.ringStack.push(secondRing.ringStack.top());
            secondRing.ringStack.pop();
        }
        else if ((second > third || second == 0) && third != 0)
        {
            secondRing.ringStack.push(thirdRing.ringStack.top());
            thirdRing.ringStack.pop();
        }
        cout << string(20, '\n' );
        printAllStacks(firstRing.ringName, firstRing.ringStack, secondRing.ringName, secondRing.ringStack, thirdRing.ringName, thirdRing.ringStack);
        second = changeNum(secondRing.ringStack);
        third = changeNum(thirdRing.ringStack);
        this_thread::sleep_for(1000ms);
    }

    
    /*
    //will clear terminal by adding 50 empty lines of code
    cout << string(50, '\n' );

    //will pause the code for 1000 ms (1 second) and then resume
    this_thread::sleep_for(1000ms);
    */
}

int main()
{
    TowerofHanoi();
    return 0;
}