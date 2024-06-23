/*#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<mmsystem.h>
using namespace std;
int main()
{
   char ch[100];
  cout<<"   !!!! For Singles !!!! \n         BY GAGAN \n";
 while(1)
{
cout<<"\n\n";
gets(ch);
if(strcmp(ch,"hii")==0)

    {    PlaySound(TEXT("hi.wav"),NULL,SND_SYNC);
} 
else if(strcmp(ch,"how are you")==0)
{
    PlaySound(TEXT("i am fine.wav"),NULL,SND_SYNC);
}
else if(strcmp(ch,"crush")==0)
{
  PlaySound(TEXT("sundar.wav"),NULL,SND_SYNC);   
//     std::string phrase = "main itni sundar hoon main kyaa karu";
//    std::string command = "espeak -v +f3 \""+phrase+"\"";
//    const char* charCommand=command.c_str();
//    system(charCommand);
}
else if(strcmp(ch,"bye")==0)
{
    PlaySound(TEXT("bye.wav"),NULL,SND_SYNC);
    exit(0);
}
}
return 0;
}
*/
#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<mmsystem.h>
using namespace std;
int main()
{
   char ch[100];
  cout<<"                   !!!! For Testing !!!! \n                          BY GAGAN \n";
 while(1)
{
cout<<"\n\n";
cout<<"        ";gets(ch);
if(strcmp(ch,"hii")==0)

    {   
	   PlaySound(TEXT("hi.WAV"),NULL,SND_SYNC);
	   cout<<"                   Hi\n";
	} 
else if(strcmp(ch,"how are you")==0)
{
    PlaySound(TEXT("i am fine.wav"),NULL,SND_SYNC);
    cout<<"              I am fine \n";
}
else if(strcmp(ch,"what is your name")==0)
{
	PlaySound(TEXT("niharika.wav"),NULL,SND_SYNC);
	cout<<"              I am NIHARIKA\n";
}

else if(strcmp(ch,"open calculator")==0)
{
   int  clrscr();
   
     std::string phrase = "         opening calculator     ";
      std::string command = "espeak \""+phrase+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
    cout<<"                      !!!  OPENING  CALCULATOR   !!!      \n";
        char gb;
        char bb;
        int a,b,c,d=0;
     cout<<"         NOTE - First Enter value then Press enter then enter operator  \n\n";
     do
     {
    cout<<"                     Enter value -       "<<endl;
    cin>>a;
    cout<<"                     Enter another Value -    "<<endl;
    cin>>b;
    cout<<"                     Enter Operand -   "<<endl;
    cin>>gb; 
    switch(gb)
    {
        case '+':
        c = a+b;
        cout<<"          Result = "<<c<<endl;
        break;
        
        case '-':
        c = a-b;
        cout<<"         Result = "<<c<<endl;
        break;
        
        case '*':
        c = a*b;
        cout<<"         Result = "<<c<<endl;
        break;
        
        case '/':
        c = a/b;
        cout<<"         Result = "<<c<<endl;
        break;
        
        default:
        cout<<"               !!! ERROR !!!           "<<endl;
    }
    char bh;
    do
    {
    cout<<"           Want to Add more values in this   ?"<<endl;
cin>>bh;
if(bh=='y')
{ 
    cout<<"Enter value - "<<endl;
        cin>>d;
        cout<<" Enter operand - "<<endl;
        cin>>gb;
        switch(gb)
    {
        case '+':
        c = c+d;
        cout<<" Result = "<<c<<endl;
        break;
        
        case '-':
        c = c-d;
        cout<<" Result = "<<c<<endl;
        break;
        
        case '*':
        c = c*d;
        cout<<" Result = "<<c<<endl;
        break;
        
        case '/':
        c = c/d;
        cout<<" Result = "<<c<<endl;
        break;
        
        default:
        cout<<"!!! ERROR !!!"<<endl;
    }
}
else
    break;
    }while(bh!='n');
    cout<<" want to exit from calculator  ? \n    for YES enter y  \n    for NO enter n\n"<<endl;
    cin>>bb;
}while(bb!='y');
}
else if(strcmp(ch,"do you like me")==0)
{
	 PlaySound(TEXT("yes.wav"),NULL,SND_SYNC);
	 cout<<"             YES\n";
}   
else if(strcmp(ch,"switch to hydron")==0)
{
    
    int a;
     std::string phrase = "Enter password";
      std::string command = "espeak \""+phrase+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
     cout<<"        Enter Password\n    ";
     cin>>a;
     if(a==12345)
     {
          std::string phrase1 = "starting ,  HYDRON,        ";
   // std::string command = "espeak \""+phrase1+"\"";
    //const char* charCommand=command.c_str();
   //system(charCommand);
   cout<<"          Starting HYDRON\n";
      std::string phrase2 = "               ,welcome , gagan sir , how may i help you";
    std::string command = "espeak \""+phrase1 + phrase2+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
  cout<<"       welcome ,\n           GAGAN Sir ,\n                 how may i help you  ?\n";
     
}

else if(strcmp(ch,"close hydron")==0)
{
       std::string phrase1 = "         closing hydron ,      ";
       for(int i=10;i>=0;i--)
   cout<<"                    "<<endl<<i;
       std::string phrase2 = "         ten       ,    nine,      eight , seven , six , five , four , three , two , one      ";
      std::string command = "espeak \""+phrase1+phrase2+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
   
}
else
{
     std::string phrase = "         , Access Denied     ";
      std::string command = "espeak \""+phrase+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
   cout<<"                        !!!  Access Denied  !!!             \n";

}

} 

else if(strcmp(ch,"tell me about gagan")==0)
{
     std::string phrase = "gagan, he is a genius";
    std::string command = "espeak -v +f3 \""+phrase+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
  cout<<"     gagan, he is a genius  \n";
  

}
else if(strcmp(ch,"exit")==0)
{
    exit(0);
}
else if(strcmp(ch,"bye")==0)
{
    PlaySound(TEXT("bye.wav"),NULL,SND_SYNC);
    cout<<"          Take care, bye!\n";
    exit(0);
}
else
{
     std::string phrase = "I can't understand";
    std::string command = "espeak -v  +f3 \""+phrase+"\"";
    const char* charCommand=command.c_str();
   system(charCommand);
  cout<<"            I can't Understand  \n";
}
}
}


