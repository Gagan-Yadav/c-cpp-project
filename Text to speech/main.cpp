#include <stdio.h>
#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
int main()
{
char ch[50];
     cout<<"\t GAGAN ";
    cout<<"\n Enter text to speech\n";
   cin. getline(ch,50);
   //for(int i=0;i<=100;i++)
//   cout<<ch[i];                                                                                                
   // {
        std::string phrase = ch;
    std::string command = "espeak -v +f4 \""+phrase+"\"";
    const char* charCommand=command.c_str();
    system(charCommand);
    // break;
    // }
    
}
