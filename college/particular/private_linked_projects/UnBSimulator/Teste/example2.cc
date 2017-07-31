#include <boost/thread.hpp>
#include <iostream>

using namespace std;

void ThreadFunction()
{
    int counter = 0;
    for(;;)
    {
        cout << "thread iteration " << ++counter << " Press Enter to stop" << endl;
        try
        {
            // Sleep and check for interrupt.
            // To check for interrupt without sleep,
            // use boost::this_thread::interruption_point()
            // which also throws boost::thread_interrupted
            // boost::this_thread::sleep(boost::posix_time::milliseconds(500));
            boost::this_thread::interruption_point();
        }
        catch(boost::thread_interrupted&)
        {
            cout << "Thread is stopped" << endl;
            return;
        }
    }
}

int main()
{
    // Start thread
    boost::thread t(ThreadFunction);

    // Wait for Enter 
    char ch;
    cin.get(ch);

    // Ask thread to stop
    t.interrupt();

    // Join - wait when thread actually exits
    t.join();
    cout << "main: thread ended" << endl;

    return 0;
}