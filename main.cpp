/*
 * File: main.cpp
 *
 * This is the main() to test and demonstrate
 * a simple integer Stack
 */

#include "main.h"

int main() {
    // seeds the rand() function
    // call only ONCE per application!
    srand(time(NULL));

    // create stack
    Stack stack;

    // generic int used for testing
    int value;
        
    /************************************************
    ******* EMPTY TESTS *****************************
    ************************************************/

    cout << "Beginning tests..." << endl << endl << "Testing empty operations." << endl;
    cout << "=====================================================" << endl;

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }

    /* NOTE: peek() and pop() use different techniques in this example ONLY
     * for demonstration purposes. normally peek() and pop() should have
     * identical interfaces and calls.
     */

    // testing peek() and pop() on empty stack
    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    
    try{
        value = stack.pop();
        cout << "popped: " << value << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;
    
    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/
    
    cout << "Testing full operations." << endl;
    cout << "=====================================================" << endl;

    // testing filling the stack and overflow
    cout << "Filling stack..." << endl;
    for (int i = 0; i < STACKSIZE*MULTIPLIER; i++) {
        value = rand()%2 ? -(i + 1) : i+1; // 50/50 negative or positive number
        if (stack.push(value)) {
            cout << "pushed: " << value << endl;
        } else {
            cout << "overflow error: " << value << " not pushed" << endl;
        }
    }
    cout << endl;

    // testing isEmpty() on full stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }
    cout << endl;

    // testing peek() and pop() on full stack
    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    
    try{
        value = stack.pop();
        cout << "popped: " << value << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty" << value << endl;
    }
    cout << endl;

    // this is a programmer debug routine used for debugging during development
    // and is normally not used for final testing but is shown here for demonstration
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();

    /************************************************
    ******** EMPTYING AND EMPTY TESTS ***************
    ************************************************/

    cout << "Testing peek and pop, and emptying stack..." << endl;
    cout << "=====================================================" << endl;

    // testing popping and peeking whole stack
    for (int i = 0; i < MULTIPLIER*STACKSIZE; i++) {
        if(stack.peek(&value)){
            cout << "peeked: " << value  << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
        try {
            cout << "popped: " << stack.pop() << endl;
        } catch (...) {
            cout << "pop underflow error: stack is empty" << endl;
        }
    }
    cout << endl;

    // this is a programmer debug routine used for debugging during development
    // and is normally not used for final testing but is shown here for demonstration
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();

    // testing isEmpty() on empty stack
    if (stack.isEmpty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is NOT empty" << endl;
    }

    // testing peek() and pop() on empty stack
    if(stack.peek(&value)){
        cout << "peeked: " << value << endl;
    } else {
        cout << "peek underflow error: stack is empty" << endl;
    }
    
    try{
        value = stack.pop();
        cout << "popped: " << value << endl;
    } catch(...){
        cout << "pop underflow error: stack is empty" << endl;
    }
    cout << endl;

    /************************************************
    ******** MID-STACK TESTS ************************
    ************************************************/
    cout << "Filling stack halfway and testing the middle of the stack..." << endl;
    cout << "============================================================" << endl;
    // filling the stack half way to test the middle of the stack
    for (int i = 0; i< int(STACKSIZE / 2); i++) {
        // using positive and negative "big" numbers
        value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
        if (stack.push(value)) {
            cout << "pushed: " << value << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }
    // testing middle in a narrow band
    for (int i = 0; i<STACKSIZE*NARROW; i++) {
        if (stack.isEmpty()) {
            cout << "stack is empty" << endl;
        } else {
            cout << "stack is NOT empty" << endl;
        }
        cout << endl;

        // testing peek() and pop() on empty stack
        if(stack.peek(&value)){
            cout << "peeked: " << value << endl;
        } else {
            cout << "peek underflow error: stack is empty" << endl;
        }
    
        try{
            value = stack.pop();
            cout << "popped: " << value << endl;
        } catch(...){
            cout << "pop underflow error: stack is empty" << endl;
        }
        value = rand()%2 ? rand() % MAX_INT/2 + 1 : -(rand() % MAX_INT/2 + 1);
        if (stack.push(value)) {
            cout << "pushed: " << value << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }
    cout << endl;


    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/
    
    cout << "Random testing..." << endl;
    cout << "============================================================" << endl;
    // clearing stack to start
    while(!stack.isEmpty()){
        stack.pop();
    }

    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACKSIZE / 2); i++) {
        value = rand() % MAX_INT + 1;
        if (stack.push(value)) {
            cout << "pushed: " << value << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }

    /*
     * the following will test random operations. push() and pop()
     * are called twice as often as peek and isempty because they
     * change the stack and should be tested more rigorously.
     */
    int choice = rand() % CHOICES + 1;
    for (int i = 0; i < STACKSIZE*RANDOM_MULTIPLIER; i++) {
        switch (choice) {
            case 1:
            case 2:
                // push
                value = (rand() % MAX_INT) + 1;
                if (stack.push(value)) {
                    cout << "pushed: " << value << endl;
                } else {
                    cout << "overflow error: " << value << " not pushed" << endl;
                }
                break;
            case 3:
            case 4:
                // pop
                try{
                    value = stack.pop();
                    cout << "popped: " << value << endl;
                } catch(...){
                    cout << "pop underflow error: stack is empty" << endl;
                }
                break;
            case 5:
                // peek
                if(stack.peek(&value)){
                    cout << "peeked: " << value << endl;
                } else {
                    cout << "peek underflow error: stack is empty" << endl;
                }
                break;
            case 6:
                // isempty
                if (stack.isEmpty()) {
                    cout << "stack is empty" << endl;
                } else {
                    cout << "stack is NOT empty" << endl;
                }
                break;
        }
        choice = rand() % CHOICES + 1;

    }
    cout << endl;

    // this is a programmer debug routine used for debugging during development
    // and is normally not used for final testing but is shown here for demonstration
    cout << "Dumping stack..." << endl;
    cout << "=====================================================" << endl;
    stack.dumpStack();
    
   cout << "Testing complete." << endl;
   return 0;
}
