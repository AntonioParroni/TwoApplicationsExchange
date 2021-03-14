#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

/*
Conditions
        a. Use GIT (GitHub) and just share the link to project with implementation
b. Project should be based on CMake
c. All interfaces should be POSIX compliant
d. Language: C/C++11
e. Usage of RAII idioms
Task:
Create 2 applications:
Requirement#1:
First application A sends messages to application B. Messages consist of two fields: string and
        delay value.
String value may be arbitrary, except the case with value "Quit".
Delay value must be in range from 250mS to 2S.
It would be good to have information about status of application in console.

Requirement#2:
Application B waits for incoming messages and prints "Hey, I am here." each 500ms while
waiting for the first message.
When it receives a message from app A string to print and delay value should be replaced with
        ones from messege payload.
Application should keep printing to console considering values update.
If message with payload string "Quit" is received application B should finish its execution with
return code 0.
If any improper payload received appropriate message should be output and values should
remain as they were.
Requirement#3:
In case of any error not mentioned before both application should exit with exit code 1 and
appropriate message printed
        to console.
Output:
1) Output from console for both applications (can be stored in file);
2) Link to source code in GitHub.
*/

using namespace std;

/*
Conditions
        a. Use GIT (GitHub) and just share the link to project with implementation
b. Project should be based on CMake
c. All interfaces should be POSIX compliant
d. Language: C/C++11
e. Usage of RAII idioms
Task:
Create 2 applications:
Requirement#1:
First application A sends messages to application B. Messages consist of two fields: string and
        delay value.
String value may be arbitrary, except the case with value "Quit".
Delay value must be in range from 250mS to 2S.
It would be good to have information about status of application in console.

Requirement#2:
Application B waits for incoming messages and prints "Hey, I am here." each 500ms while
waiting for the first message.
When it receives a message from app A string to print and delay value should be replaced with
        ones from messege payload.
Application should keep printing to console considering values update.
If message with payload string "Quit" is received application B should finish its execution with
return code 0.
If any improper payload received appropriate message should be output and values should
remain as they were.
Requirement#3:
In case of any error not mentioned before both application should exit with exit code 1 and
appropriate message printed
        to console.
Output:
1) Output from console for both applications (can be stored in file);
2) Link to source code in GitHub.
*/

struct mesg_buffer {
        long mesg_type;
        char mesg_text[100];
    } message;

void printMessage (const string& str, uint delayTime)
    {
        cout << str << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));
    }

uint parseNewDelayTime (const string& str)
    {
        uint newDelayTime = 0;
        size_t last_index = str.find_last_not_of("0123456789");
        string result = str.substr(last_index + 1);
        newDelayTime = std::stoi(result);
        return newDelayTime;
    }

string parseNewMsg(string str)
    {
        size_t last_index = str.find_last_not_of("0123456789");
        string result = str.substr(last_index + 1);

        size_t pos = str.find(result);
        if (pos != std::string::npos)
            {
                str.erase(pos, result.length());
            }
        return str;
    }

int main()
    {
        bool enabled = true;
        key_t key;
        int msgid;

        key = ftok("progfile", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);

        string outPutMsg = "Hey, I am here.";
        uint outPutDelayTime = 500;

        printMessage(outPutMsg, outPutDelayTime);

        while (enabled)
            {
                if (msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT) > 0)
                    {
                        outPutDelayTime = parseNewDelayTime(message.mesg_text);
                        outPutMsg = parseNewMsg(message.mesg_text);
                        if (outPutMsg == "Quit")
                            {
                                cout << "Received Quit Command \nAborting..." << endl;
                                enabled = false;
                            }
                    }
                printMessage(outPutMsg, outPutDelayTime);
            }
        msgctl(msgid, IPC_RMID, NULL);
        return 0;
    }