#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/msg.h>

/*Бесспорно, структура самого сообщения могла бы быть намного лучше. Я вижу возможные будущие проблемы.
А так же, можно было бы намного лучше отловить все возможные ошибки и исключения этого кода.
Как и в целом, рассширить функционал этого приложения.
Но к сожалению, у меня было мало свободного времени (меньше дня) а так же, я таким еще не занимался, как и в целом уже давно не писал на плюсах (хотя все еще очень его люблю)
Это мой, скажем любительский уровень. Но я все же хочу развиваться в данном направлении.
Спасибо за ваше внимание.
С уважением Антон.*/

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

class Message
    {
        public: string textMsg;
        public: uint delayVal;

        public: Message()
            {
                cout << "Please insert your message below" << endl;
                getline(cin, textMsg);

                cout << "Please insert your delay value (in range between 250 and 2000) below" << endl;
                cin >> delayVal;
                cin.ignore(256, '\n');
                while (delayVal < 250 || delayVal > 2000)
                    {
                        delayVal = 0;
                        cout << "Incorrect Input, Please Try Again!" << endl;
                        cin.sync(); // не знаю как пофиксить этот скрытый баг :(
                        cin.clear();
                        (cin >> delayVal).get();
                    }
            }
        ~Message()
            {

            }

        public: string SerializeToConsoleString()
            {
                string finalMessage = textMsg + to_string(delayVal);
                return finalMessage;
            }

        public: void ToGoodLookingMessageOutput ()
            {
                cout << "Message: " + textMsg + "\n" + "Delay Value: " + to_string(delayVal) << endl;
            }
    };

struct mesg_buffer {
        long mesg_type;
        char mesg_text[100];
    } message;

int main()
    {
        bool enabled = true;

        key_t key;
        int msgid;
        key = ftok("progfile", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);
        message.mesg_type = 1;

        while (enabled)
            {
            cout << "New Message Creation" << endl;
            Message *newMsg = new Message();
            cout << "Message Created" << endl;
            cout << newMsg->SerializeToConsoleString() << endl;
            cout << "Message Ready" << endl;
            newMsg->ToGoodLookingMessageOutput();
            cout << "Message Output" << endl;

            strcpy(message.mesg_text,newMsg->SerializeToConsoleString().c_str());

            msgsnd(msgid, &message, sizeof(message), 0);

            printf("Data send is : %s \n", message.mesg_text);

            cout << "Message Sent" << endl;
            }
    }
