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
void display1(char str[3][3],int);
void Yes_No(int arr[3][3],const char str[3][3]);

// Text Color change function
void red ()     {   printf("\033[1;31m");   }
void yellow()   {   printf("\033[1;33m");   }
void Blue()     {   printf("\033[0;34m");   }
void Green()    {   printf("\033[0;32m");   }
void Purple()   {   printf("\033[0;35m");   }
void White()    {   printf("\033[0;37m");   }
void Cyan()     {   printf("\033[0;36m");   }
void reset ()   {   printf("\033[0m");      }



int main()
{
    char str[3][3],a='1',pl1[20],pl2[20];
    int x,z;
    while("TasiNCoder") {
        for(x=0; x<3; x++)
            for(z=0; z<3; str[x][z]=a,a++,z++);
        Green();
        printf("\n---------------------------\n");
        printf("Enter 1 For Play Game\n");
        printf("Enter 2 For Exit This Game\n");
        printf("Enter Your Choice : ");
        scanf("%d",&x);
        printf("\n---------------------------\n");
        reset();
        switch(x)   {
            case 1:
                name_input();
                display(str);
                user_input(str);
                break;
            case 2:
                Cyan();
                printf("\n   |---------------|");
                printf("\n   |   Thank you   |");
                printf("\n   |---------------|\n");
                reset();
                return 0;
            default:
                red();
                printf("\nYour Choice Invalid...!\n");
                reset();
        }
    }
    return 0;
}

void name_input()
{
    fflush(stdin);
    printf("Enter First Player Name  : ");
    gets(pl1);
    printf("Enter Second Player Name : ");
    gets(pl2);
}

void display(char str[3][3])
{
    int x,z;
    system("cls");
    yellow();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\n");
    red();
    printf("|-------------------------------|\n");
    printf("|  %s Player X\n",pl1);
    printf("|-------------------------------|\n\n");
    Blue();
    printf("|-------------------------------|\n");
    printf("|  %s Player O\n",pl2);
    printf("|-------------------------------|\n");
    reset();
    printf(" -------------------------\n");
    for(x=0; x<3; x++)
       {
           printf(" |       |       |       |\n");
            for(z=0; z<3; z++)  {
                printf(" |   ");
                if(str[x][z] == 'X')
                    red();
                else if(str[x][z] == 'O')
                    Blue();
                printf("%c  ",str[x][z]);
                reset();
            }
            printf(" |\n |       |       |       |\n");
            printf(" -------------------------\n");
       }
    printf("\n\n");
    yellow();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    reset();
    user_input(str);
}

void user_input(char str[3][3])
{
    static int A[9],y=0;
    int x;
    char choice;
    printf("\n");
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
    int c;
    char a;
    if(x%2)
        a='X';
    else
        a='O';
    x++;
    c = choice%49;
    if('0' <= choice && '9' >= choice)
        str[c/3][c%3] = a;

    Win(str);
    if(st==9)
    {
        system("cls");
        Purple();
        printf("\n         |-----------|");
        printf("\n         | Game Drow |");
        printf("\n         |-----------|\n\n");
        reset();
        display1(str,10);
        getch();
        exit(0);
    }
    st++;
    display(str);
}

void Win(char str[3][3])
{
    if(str[2][0] == str[1][1] && str[2][0] == str[0][2])
        if(str[2][0] == 'X')
            name_X(str);
        else
            name_O(str);
    else if(str[0][0] == str[1][1] && str[1][1] == str[2][2])
        if(str[0][0] == 'X')
            name_X(str);
        else
            name_O(str);
    else
        for(int x = 0; x<3; x++)    {
            if(str[x][0] == str[x][1] && str[x][0] == str[x][2])
                if(str[x][0] == 'X')
                    name_X(str);
                else
                    name_O(str);
            else if(str[0][x] == str[1][x] && str[0][x] == str[2][x])
                if(str[0][x] == 'X')
                    name_X(str);
                else
                    name_O(str);
        }
}

void name_X(char str[3][3])
{
    system("cls");
    Green();
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("| Congratulation, %s Win the Game",pl1);
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    reset();
    display1(str,1);
    getch();
    exit(0);
}

void name_O(char str[3][3])
{
    system("cls");
    Green();
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    printf("| Congratulation, %s Win the Game",pl2);
    printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
    reset();
    display1(str,0);
    getch();
    exit(0);
}

void display1(char str[3][3], int n)
{
    int x,z,arr[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    yellow();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    reset();
    Yes_No(arr,str);
    if(n==10)
        Cyan();
    printf("\n\n");
    printf(" -------------------------\n");
    for(x=0; x<3; x++)  {
        printf(" |       |       |       |\n");
        for(z=0; z<3; z++){
            printf(" |   ");
            if(arr[x][z] == 1)  {
                Green();
                printf("%c  ",str[x][z]);
                reset();
            }
            else
                printf("%c  ",str[x][z]);
        }
        printf(" |\n |       |       |       |\n");
        printf(" -------------------------\n");
    }
    printf("\n\n");
    yellow();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    reset();
}




void Yes_No(int arr[3][3], const char str[3][3])
{
    if(str[2][0] == str[1][1] && str[2][0] == str[0][2])    {
        arr[2][0] = 1;
        arr[1][1] = 1;
        arr[0][2] = 1;
    }
    else if(str[0][0] == str[1][1] && str[1][1] == str[2][2])   {
        arr[0][0] = 1;
        arr[1][1] = 1;
        arr[2][2] = 1;
    }
    else
        for(int x = 0; x<3; x++)
            if(str[x][0] == str[x][1] && str[x][0] == str[x][2])    {
                arr[x][0] = 1;
                arr[x][1] = 1;
                arr[x][2] = 1;
                break;
            }
            else if(str[0][x] == str[1][x] && str[0][x] == str[2][x])   {
                arr[0][x] = 1;
                arr[1][x] = 1;
                arr[2][x] = 1;
                break;
            }
}


