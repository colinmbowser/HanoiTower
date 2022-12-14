#include <iostream>
#include <stack>
#include <thread>
#include <chrono>

using namespace std;

    //class for the ring stacks and the name for each stack
class myStack
{
    public:
        string ringName;
        stack<int> ringStack;
};

    //will get amount of rings to go through the tower of hanoi and make sure
    //it fits the correct parameters.
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

    //will output the ring that is sent to this function in order
void printStack(string ringName, stack<int> printRing)
{
    stack<int> outputRing;

    while (!(printRing.empty()))
    {
    outputRing.push(printRing.top());
    printRing.pop();
    }
    cout << ringName << " Ring: ";
    while(!(outputRing.empty()))
    {
        cout << outputRing.top() << " ";
        outputRing.pop();
    }
    cout << endl;
}

    //will clear the terminal by printing 20 blank lines then it
    //will output each of the rings at once then freeze the program for 1 second.
void printAllStacks(myStack firstRing, myStack secondRing, myStack thirdRing)
{
    cout << string(20, '\n' );
    printStack(firstRing.ringName, firstRing.ringStack);
    printStack(secondRing.ringName, secondRing.ringStack);
    printStack(thirdRing.ringName, thirdRing.ringStack);
    this_thread::sleep_for(1000ms);
}

    // will make variables equal to the top block of each stack,
    // unless there is no top block in a stack then it will equal to.
int changeNum(stack<int> changeNumStack)
{
    int newNumber = 0;
    if (!(changeNumStack.empty())) 
    {newNumber = changeNumStack.top();}
    return newNumber;
}

    //will solve the even numbered blocks in tower of hanoi by parsing through
    //and moving each values from one stack to another.
void isEven(myStack firstRing, myStack secondRing, myStack thirdRing, int blockAmount)
{
    int first = changeNum(firstRing.ringStack);
    int second = changeNum(secondRing.ringStack);
    int third = changeNum(thirdRing.ringStack);

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
        printAllStacks(firstRing, secondRing, thirdRing);
        first = changeNum(firstRing.ringStack);
        second = changeNum(secondRing.ringStack);

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
        printAllStacks(firstRing, secondRing, thirdRing);
        first = changeNum(firstRing.ringStack);
        third = changeNum(thirdRing.ringStack);

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
        printAllStacks(firstRing, secondRing, thirdRing);
        second = changeNum(secondRing.ringStack);
        third = changeNum(thirdRing.ringStack);
    }
}

    //will solve the odd numbered blocks in tower of hanoi by parsing through
    //and moving each values from one stack to another.
void isOdd(myStack firstRing, myStack secondRing, myStack thirdRing, int blockAmount)
{
    int first = changeNum(firstRing.ringStack);
    int second = changeNum(secondRing.ringStack);
    int third = changeNum(thirdRing.ringStack);

    while (!(firstRing.ringStack.empty() && secondRing.ringStack.empty()))
    {
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
        printAllStacks(firstRing, secondRing, thirdRing);
        first = changeNum(firstRing.ringStack);
        third = changeNum(thirdRing.ringStack);
        if (firstRing.ringStack.empty() && secondRing.ringStack.empty()) {break;}

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
        printAllStacks(firstRing, secondRing, thirdRing);
        first = changeNum(firstRing.ringStack);
        second = changeNum(secondRing.ringStack);

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
        printAllStacks(firstRing, secondRing, thirdRing);
        second = changeNum(secondRing.ringStack);
        third = changeNum(thirdRing.ringStack);
    }
}

    //base of tower of hanoi program. Used to declare
    // values and call functions.
void TowerofHanoi()
{
    myStack firstRing;
    myStack secondRing;
    myStack thirdRing;

    firstRing.ringName = " First";
    secondRing.ringName = "Second";
    thirdRing.ringName = " Third";

    int blockAmount = getNum();

    for (int i = blockAmount; i > 0; i--) {firstRing.ringStack.push(i);}

    int first = changeNum(firstRing.ringStack);
    int second = changeNum(secondRing.ringStack);
    int third = changeNum(thirdRing.ringStack);

    if (blockAmount % 2 == 0) {isEven(firstRing, secondRing, thirdRing, blockAmount);}

    if (blockAmount % 2 == 1) {isOdd(firstRing, secondRing, thirdRing, blockAmount);}
}

    //used to call Tower of Hanoi.
int main()
{
    TowerofHanoi();
    return 0;
}