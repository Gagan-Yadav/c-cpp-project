
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
struct patient{
    char ID[15];
    char name[20],c;
    char add[20];
    char parname[20];
    int Class;
    char g[20];
    long unsigned int phone_no;
        
};
struct patient pat;
long int size = sizeof(pat);
FILE *fp,*ft;
///This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void ClearConsoleToColors(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

void SetColorAndBackground(int ForgC, int BackC)
{
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

COORD coord = {0,0}; ///set the cordinate to 0, 0 (top-left corner of window);
void gotoxy(int x, int y){//This function allows you to print text in any place of screen.//
    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//This function is used to draw a rectangle//
void drawRectangle(){
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",202);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",203);
        }else{
            printf("%c",205);
        }
    }

    for(i = 7; i < 25; i++){
        gotoxy(35,i);
        printf("%c",186);
    }

}
//This funtion is used to clear the window//
void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);printf(" ");
        }
    }
    return;
}
//This function is used to creat a window in the header of the patient record//
void window(){
    drawRectangle();
    gotoxy(32,1);
    SetColor(35);
    printf("----------");
    gotoxy(28,2);
    SetColor(35);
    printf("PATIENT RECORD SYSTEM");
    gotoxy(20,3);
    printf("IIPS , DAVV");
    gotoxy(31,4);
    printf("Sample Project");
    gotoxy(25,24);
    SetColor(17);

}

void print_h(const char st[]){
    SetColorAndBackground(31,28);
    gotoxy(45,8);printf(" Discharge Certificate %s",st);
    SetColorAndBackground(17,15);
}

////This function is used to Heading of the patient record//
void print_heading(const char st[]){
    SetColorAndBackground(31,28);
    gotoxy(38,8);printf("PRS : %s",st);
    SetColorAndBackground(17,15);
}

//This function is used to add the patient record//
void add_patient(){
    clearWindow();
    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("gt.txt","ab+");  // if gt.text is already exist then it will open and write otherwise it will create gt.txt file,
    // All data will be store in this file
    SetColor(45);
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake Sure Your File is Not Write Protected","Warning",0);

    }else{
        fflush(stdin);
   
        gotoxy(print,10);printf("ID: ");gets(pat.ID);
        //here you can confirms the ID
        gotoxy(print,12);printf("Name: ");gets(pat.name);
        gotoxy(print,14);printf("Address: ");gets(pat.add);
        gotoxy(print,16);printf("Father's Name: ");gets(pat.parname);
        gotoxy(print,18);printf("Bed No. : ");scanf("%d",&pat.Class);
        gotoxy(print,20);printf("Phone Number: ");scanf("%ld",&pat.phone_no);
           gotoxy(print,22);printf(" Report : ");gets(pat.g);
     
        fwrite(&pat, sizeof(pat), 1,fp);
        gotoxy(40,24); printf("The Record is Added Successfully !!");
    }
    SetColor(28);
    fclose(fp);
    return;
}
//This function is used to search the patient record//
void search_patient(){
    clearWindow();
    print_heading("Search Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("gt.txt","rb");
    while(fread(&pat,sizeof(pat),1,fp) == 1){
        if(strcmp(s_id,pat.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("The Record is Found");
        gotoxy(37,14);printf("ID: %s",pat.ID);
        gotoxy(37,15);printf("Name: %s",pat.name);
        gotoxy(37,16);printf("Address: %s",pat.add);
        gotoxy(37,17);printf("Father's Name: %s",pat.parname);
        gotoxy(37,18);printf("Bed No : %d",pat.Class);
        gotoxy(37,19);printf("Phone Number: %ld",pat.phone_no);
                gotoxy(37,20);printf(" Report : %d",pat.g);
        
    }else{
        gotoxy(37,12);printf("Sory, No Record Found in the Database");
    }
    SetColor(28);
    fclose(fp);
    return;
}
//This function is used to modify the patient record//
void mod_patient(){
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("gt.txt","rb+");
    while(fread(&pat, sizeof(pat),1,fp) == 1){
        if(strcmp(s_id, pat.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: %d",&pat.ID);
            gotoxy(print,13);printf("Name: ");gets(pat.name);
            gotoxy(print,14);printf("Address: ");gets(pat.add);
            gotoxy(print,15);printf("Father's name: ");gets(pat.parname);
            gotoxy(print,16);printf("Bed No : ");scanf("%d",&pat.Class);
            gotoxy(print,17);printf("Phone Number: ");scanf("%ld",&pat.phone_no);
               gotoxy(print,18);printf("Report : ");scanf("%d",&pat.g);
                   gotoxy(print,20);printf("The record is sucessfully Modified");
            fseek(fp,-sizeof(pat), SEEK_CUR);
            fwrite(&pat,sizeof(pat), 1, fp);
            isFound = 1;
            break;
           
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("404 !! No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}

//This function is used to delete the patient record//
void delete_patient(){
    
    
     clearWindow();
    print_heading("Delete Record");
    SetColor(45);
    char empname[15];
     int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Delete: ");fflush(stdin);
         scanf("%s", empname); 
    
    
        ft = fopen("temp.txt", "wb"); 

        rewind(fp); 

  

        while (fread(&pat, size, 

                     1, fp) 

               == 1) { 

            if (strcmp(pat.name, 

                       empname) 

                != 0) 

                fwrite(&pat, size, 1, ft); 

        } 

  

        fclose(fp); 

        fclose(ft); 

        remove("gt.txt"); 

        rename("temp.txt", "gt.txt"); 

        fp = fopen("gt.txt", "rb+"); 

    
    
    gotoxy(37,12);printf("The record is sucessfully deleted");
    SetColor(28);
    
    }
void certificate(){
    clearWindow();
    print_h("");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(37,10);printf("Enter ID to Get Certificate: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("gt.txt","rb");
    while(fread(&pat,sizeof(pat),1,fp) == 1){
        if(strcmp(s_id,pat.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);printf("         1st Dose    ");
        gotoxy(37,14);printf("ID: %s",pat.ID);
        gotoxy(37,15);printf("Name: %s",pat.name);
        gotoxy(37,16);printf("Father's Name: %s",pat.parname);
        gotoxy(37,17);printf("Phone Number: %ld",pat.phone_no);
        gotoxy(37,18);printf("Date of Dose : 25 july 2021");
        gotoxy(37,21);printf("  Vaccinated by : Dr. Gagan Yaduvanshi ");
        gotoxy(37,22);printf("Report: %s",pat.g);
    }else{
        gotoxy(37,12);printf("Sory, No Record Found in the Database");
    }
    SetColor(28);
    fclose(fp);
    return;
}


void displayrecord() 
{ 

    //system("cls"); 

  

    // sets pointer to start 

    // of the file 

    rewind(fp = fopen("gt.txt","rb")); 

  

    printf("\n========================="

           "==========================="

           "======"); 

    printf("\n   NAME\t\tParents_Name\t\tID\t\t"

           "\n", 

           pat.name, pat.parname, 

           pat.ID); 

    printf("==========================="

           "==========================="

           "====\n"); 

  

    while (fread(&pat, size, 1, fp) == 1) 

        printf("\n     %s\t\t   %s\t\t%s\t", 

               pat.name,pat.parname,pat.ID); 

  

    printf("\n\n\n\t");
    HIDE_WINDOW;
    //system("pause"); 
}

//In this function we can choose an option to interact with the patient record//
void main_window(){
    int choice;
    SetColor(28);
    int x = 2;
  
    while(1){
        gotoxy(x,8);printf("1. Add Patient");
        gotoxy(x,10);printf("2. Search Patient");
        gotoxy(x,12);printf("3. Modify  patient Record");
        gotoxy(x,14);printf("4. Delete Patient Record");
        gotoxy(x,16);printf("5. Get Certificate");
         gotoxy(x,18);printf("6. Clear Window");
         gotoxy(x,20);printf("7. Display all Records");
        gotoxy(x,22);printf("8. Exit");
        gotoxy(x,24);printf("Enter Your Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                add_patient();
                break;
            case 2:
                search_patient();
                break;
            case 3:
                mod_patient();
                break;
            case 4:
                delete_patient();
                break;
            case 5:
                certificate();
                break;
                case 6:
                clearWindow();
                break;
                case 7:
                displayrecord();
                break;
                case 8:
                exit(0);
                break;
            default:
                break;
        }
    }
    
}
void p()
{
      int k;
      char l[20];
    int x=2;
    gotoxy(x,12);printf("Enter UserName -  ");
     scanf("%s",l);
     if(strcmp(l,"gagan")==0)
     {
        gotoxy(x,14);
    printf("Enter Password -   ");
    scanf("%d",&k);
    if(k==12345)
    {
        main_window();
        HIDE_WINDOW;
        
    }
    else
    {
        gotoxy(x,16);
        printf(" Wrong Password \n");
        exit(0);
    }
    
     }
     else
     {gotoxy(x,16);printf("Wrong UserName  \n");}
}

//Main function started//
int main(){
    ClearConsoleToColors(17,15);
    SetConsoleTitle("BY GAGAN - patient Record System");
 window();
      p();
       
      
    return 0;
}//End of Main//
