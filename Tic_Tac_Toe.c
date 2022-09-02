#include<stdio.h>
#include<conio.h>
char pl1[20],pl2[20],st=1;
void name_input();
void display(char str[3][3]);
void user_input(char str[3][3]);
void Check_ele(char str[3][3], char choice);
void Win(char str[3][3]);
void name_O(char str[3][3]);
void name_X(char str[3][3]);
void display1(char str[3][3]);
void main()
{
    char str[3][3],a='1',pl1[20],pl2[20];
    int x,z;
    name_input();
    for(x=0; x<3; x++)
        for(z=0; z<3; str[x][z]=a,a++,z++);
    display(str);
    user_input(str);
}

void name_input()
{
    printf("Enter a first player name : ");
    gets(pl1);
    printf("Enter a second player name : ");
    gets(pl2);
}

void display(char str[3][3])
{
    int x,z;
    system("cls");
    printf("#######################################################################################");
    printf("\n\n\n\n");
    printf("%s Player X\n",pl1);
    printf("%s Player O\n\n",pl2);
    printf(" -------------------------\n");
    for(x=0; x<3; x++)
       {
           printf(" |       |       |       |\n");
            for(z=0; z<3; z++)
                printf(" |   %c  ",str[x][z]);
            printf(" |");
            printf("\n |       |       |       |\n");
            printf(" -------------------------\n");
       }
    printf("\n\n\n\n");
    printf("#######################################################################################");
    user_input(str);
}

void user_input(char str[3][3])
{
    static int A[9],y=0;
    int x;
    char choice;
    choice=getch();
    for(x=0; x<9; x++)
        if(choice==A[x])
            display(str);
    if(choice>='1' && choice<='9' && x==9)
    {
        A[y]=choice;
        y++;
        Check_ele(str,choice);
    }
    else
        display(str);
}

void Check_ele(char str[3][3], char choice)
{
    static int x=1;
    char a;
    if(x%2)
        a='X';
    else
        a='O';
    x++;
    switch(choice)
        {
        case 49:
            str[0][0]=a;
            break;
        case 50:
            str[0][1]=a;
            break;
        case 51:
            str[0][2]=a;
            break;
        case 52:
            str[1][0]=a;
            break;
        case 53:
            str[1][1]=a;
            break;
        case 54:
            str[1][2]=a;
            break;
        case 55:
            str[2][0]=a;
            break;
        case 56:
            str[2][1]=a;
            break;
        case 57:
            str[2][2]=a;
            break;
        default:
            printf("Enter the Valid value..!");
        }
        Win(str);
        if(st==9)
        {
            system("cls");
            printf("\n\n\nGame Drow\n\n");
            display1(str);
            getch();
            exit(0);
        }
        st++;
        display(str);
}

void Win(char str[3][3])
{
    if(str[0][0]==str[0][1] && str[0][2]==str[0][0])
        if(str[0][0]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[1][0]==str[1][1] && str[1][2]==str[1][0])
        if(str[1][0]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[2][0]==str[2][1] && str[2][2]==str[2][0])
        if(str[2][0]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][0]==str[1][1] && str[1][1]==str[2][2])
        if(str[1][1]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][2]==str[1][1] && str[2][0]==str[1][1])
        if(str[1][1]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][0]==str[1][0] && str[2][0]==str[1][0])
        if(str[1][0]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][1]==str[1][1] && str[2][1]==str[1][1])
        if(str[1][1]=='X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][2]==str[1][2] && str[2][2]==str[1][2])
        if(str[1][2]=='X')
            name_X(str);
        else
            name_O(str);
}

void name_X(char str[3][3])
{
    system("cls");
    printf("\nCongratulation, %s Win the game\n\n",pl1);
    display1(str);
    getch();
    exit(0);
}

void name_O(char str[3][3])
{
    system("cls");
    printf("\nCongratulation, %s Win the game\n\n",pl2);
    display1(str);
    getch();
    exit(0);
}

void display1(char str[3][3])
{
    int x,z;
    printf("#######################################################################################");
    printf("\n\n\n\n");
    printf(" -------------------------\n");
    for(x=0; x<3; x++)
       {
           printf(" |       |       |       |\n");
            for(z=0; z<3; z++)
                printf(" |   %c  ",str[x][z]);
            printf(" |");
            printf("\n |       |       |       |\n");
            printf(" -------------------------\n");
       }
    printf("\n\n\n\n");
    printf("#######################################################################################");
}
