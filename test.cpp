// CPP program to create a timer
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
using namespace std;
 
// hours, minutes, seconds of timer
int hours = 0;
int minutes = 0;
int seconds = 0;
 
// function to display the timer
void displayClock()
{
    // system call to clear the screen
    system("clear");
 
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << "| " << setfill('0') << setw(2) << hours << " hrs | ";
    cout << setfill('0') << setw(2) << minutes << " min | ";
    cout << setfill('0') << setw(2) << seconds << " sec |" << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
}
 
void timer()
{
    // infinite loop because timer will keep
    // counting. To kill the process press
    // Ctrl+D. If it does not work ask
    // ubuntu for other ways.
    while (true) {
         
        // display the timer
        displayClock();
 
        // sleep system call to sleep
        // for 1 second
        sleep(1);
 
        // increment seconds
        seconds++;
 
        // if seconds reaches 60
        if (seconds == 60) {
         
            // increment minutes
            minutes++;
 
            // if minutes reaches 60
            if (minutes == 60) {
         
                // increment hours
                hours++;
                minutes = 0;
            }
            seconds = 0;
        }
        srand (time(NULL));
        int losowaliczba=rand()%100;
        cout<<"Losowanie liczby losowej z \033[1;31mlimitem czasowym!\033[0m"<<endl;
    }
}

// Driver Code
int main()
{
    timer();
    return 0;
}
