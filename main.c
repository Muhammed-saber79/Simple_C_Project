#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

struct product{
    int id;
    char product_name[10];
    float price;
};

#define DATA_SIZE 1000

void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void textattr(int i)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
}

//************ MOVE ON MENU **************
void move(int current,int size ,char menu[3][15]){
    for (int i=0;i<3;i++){
        if (i==current){
            textattr(0x70);
        }
        gotoxy(10,i+10);
        printf("%s",menu[i]);
        textattr(0x07);
    }
}

//************ WRITE DATA TO FILE **************
void write(struct product ptx){
    int n;
    printf("Enter Number Of Products: ");
    scanf("%d",&n);
    FILE * fptr;
    fptr = fopen("file.txt","a+");

    for(int i=0;i<n;i++){
        printf("enter product id: ");
        scanf("%d",&ptx.id);
        printf("enter product name: ");
        scanf("%s",ptx.product_name);
        printf("enter product price: ");
        scanf("%f",&ptx.price);

        fprintf(fptr,"\n************** product data *************\n");
        fprintf(fptr,"product id  : %d\n",ptx.id);
        fprintf(fptr,"product name: %s\n",ptx.product_name);
        fprintf(fptr,"price       : %f\n",ptx.price);
        if(fwrite != 0)
            printf("contents to file written successfully !\n");
        else
            printf("error writing file !\n");
        printf("\n=================================\n");
    }
    fclose (fptr);
}

//************ READ DATA FROM FILE **************
read(struct product data){
    FILE * fptr;
    char ch;
    fptr=fopen("file.txt","r");
    if(fptr == NULL){
        printf("file con not be opened !");
    }
    do {
        ch = fgetc(fptr);
        printf("%c", ch);

    } while (ch != EOF);
    fclose(fptr);
}

//************ MENU PROCESSES **************
void menuTest(struct product ptx, char menu[3][15]){
    int flag=1;
    int current=0;

    char ch;
    do{
        system("cls");
        move(current,sizeof(menu),menu);

        ch=getch();
        switch(ch){
            case -32:
                ch=getch();
                switch(ch){
                    case 72:
                        current--;
                        if(current < 0){
                            current=2;
                        }
                        break;
                    case 80:
                        current++;
                        if(current>2){
                            current=0;
                        }
                        break;
                }
            break;
            case 13:
                system("cls");
                if(current==0){
                    write(ptx);
                }else if(current == 1){
                    read(ptx);
                }else if(current == 2){
                    flag=0;
                }
            getch();
            break;
            case 27:
                flag=0;
                break;
        }
    }while(flag ==1);
}

int main()
{
    char menu[3][15]={"New","Display","Exit"};
    struct product ptx;
    menuTest(ptx,menu);
    return 0;
}

