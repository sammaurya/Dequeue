#include <stdio.h>
#include <stdlib.h>
void main_menu();
void Input_Restricted();
void RS_Insertion();
void LS_Insertion();
void RS_Deletion();
void LS_Deletion();
void Insert_RS(int [],int *,int *);
void Insert_LS(int [],int *,int *);
void Delete_RS(int [],int *,int *);
void Delete_LS(int [],int *,int *);
void Print(int [],int *,int *);
void Output_Restricted();

#define MAX 5
int stack1[MAX],stack2[MAX],front1=-1,rear1=-1,front2=-1,rear2=-1;
int stack3[MAX],stack4[MAX],front3=-1,rear3=-1,front4=-1,rear4=-1;
int main()
{
    main_menu();
    return 0;
}
void main_menu()
{
    system("cls");
    int choice;
    printf("\n\n\t\tDEQUEUE");
    printf("\n\t----------------------");
    printf("\n\n1.Input Restricted\n2.Output Restricted\n3.Exit\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Input_Restricted();
            break;
        case 2:
            Output_Restricted();
            break;
        case 3:
            printf("\nExiting...");
            exit(1);
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=3);
}
void Input_Restricted()
{
    system("cls");
    int choice;
    printf("\n\t   Input Restricted");
    printf("\n\t-----------------------");
    printf("\n1.Right Side Insertion\n2.Left Side Insertion\n3.Main Menu\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            RS_Insertion();
            break;
        case 2:
            LS_Insertion();
        case 3:
            main_menu();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    } while(choice!=3);
}
void RS_Insertion()
{
    int choice;
    START:
    printf("\n\n1.Insert\n2.Deletion RS\n3.Deletion LS\n4.Print\n5.Clear Screen\n6.Main Menu\n7.Back");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Insert_RS(stack1,&front1,&rear1);
            break;
        case 2:
            Delete_RS(stack1,&front1,&rear1);
            break;
        case 3:
            Delete_LS(stack1,&front1,&rear1);
            break;
        case 4:
            Print(stack1,&front1,&rear1);
            break;
        case 5:
            system("cls");
            goto START;
            break;
        case 6:
            main_menu();
            break;
        case 7:
            Input_Restricted();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=5&&choice!=6);
}

void LS_Insertion()
{
    int choice;
    START:
    printf("\n\n1.Insert\n2.Deletion RS\n3.Deletion LS\n4.Print\n5.Clear Screen\n6.Main Menu\n7.Back");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Insert_LS(stack2,&front2,&rear2);
            break;
        case 2:
            Delete_RS(stack2,&front2,&rear2);
            break;
        case 3:
            Delete_LS(stack2,&front2,&rear2);
            break;
        case 4:
            Print(stack2,&front2,&rear2);
            break;
        case 5:
            system("cls");
            goto START;
            break;
        case 6:
            main_menu();
            break;
        case 7:
            Input_Restricted();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=5&&choice!=6);
}

void Insert_RS(int arr[],int *front,int *rear)
{
    if(((*front)==0&&(*rear)==MAX-1)||(*front)==(*rear)+1)
    {
        printf("\nOverflow");
        return;
    }
    else if((*front)==-1)
    {
        *front=*rear=0;
    }
    else if((*rear)==MAX-1)
    {
        *rear=0;
    }
    else
    {
        *rear=*rear+1;
    }
    printf("\nEnter Data : ");
    scanf("%d",&arr[*rear]);
}

void Insert_LS(int arr[],int *front,int *rear)
{
    if(((*front==0)&&(*rear==MAX-1))||(*front==*rear+1))
    {
        printf("\nOverflow");
        return;
    }
    if(*front==-1)
    {
        *front=*rear=0;
    }
    else if(*front==0)
    {
        *front=MAX-1;
    }
    else
    {
        *front=*front-1;
    }
    printf("\nEnter Data : ");
    scanf("%d",&arr[*front]);
}

void Delete_RS(int arr[],int *front,int*rear)
{
    if((*front)==-1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\n Data Deleted : %d",arr[*rear]);
    arr[*rear]=NULL;
    if((*rear)==(*front))
    {
        *rear=*front=-1;
    }
    else if((*rear)==0)
    {
        *rear=MAX-1;
    }
    else
    {
        *rear-=1;
    }
}
void Delete_LS(int arr[],int *front,int*rear)
{
    if((*front)==-1)
    {
        printf("\nUnderflow");
        return;
    }
    printf("\n Data Deleted : %d",arr[*front]);
    arr[*front]=NULL;
    if((*front)==(*rear))
    {
        *front=*rear=-1;
    }
    else if((*front==MAX-1))
    {
        *front=0;
    }
    else
    {
        *front+=1;
    }
}
void Print(int arr[],int *front,int *rear)
{
    int f=*front,r=*rear;
    int k=f;
    if(f==-1)
    {
        printf("\nUnderflow");
    }
    else
    {
        while(f<=MAX-1)
        {
            printf(" %d",arr[f]);
            f++;
            if(arr[f]==NULL)
            {
                break;
            }
        }
        if(r<k)
        {
            r=0;
            while(r<k)
            {
                printf(" %d",arr[r]);
                r++;
                if(arr[r]==NULL)
                {
                    break;
                }
            }
        }
    }
    printf("\n");

}
void Output_Restricted()
{
    system("cls");
    int choice;
    printf("\n\t   Output Restricted");
    printf("\n\t-----------------------");
    printf("\n1.Right Side Deletion\n2.Left Side Deletion\n3.Main Menu\n");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            RS_Deletion();
            break;
        case 2:
            LS_Deletion();
        case 3:
            main_menu();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    } while(choice!=3);
}
void RS_Deletion()
{
    int choice;
    START:
    printf("\n\n1.Insert RS\n2.Insert LS\n3.Deletion RS\n4.Print\n5.Clear Screen\n6.Main Menu\n7.Back");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Insert_RS(stack3,&front3,&rear3);
            break;
        case 2:
            Insert_LS(stack3,&front3,&rear3);
            break;
        case 3:
            Delete_RS(stack3,&front3,&rear3);
            break;
        case 4:
            Print(stack3,&front3,&rear3);
            break;
        case 5:
            system("cls");
            goto START;
            break;
        case 6:
            main_menu();
            break;
        case 7:
            Output_Restricted();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=5&&choice!=6);
}
void LS_Deletion()
{
    int choice;
    START:
    printf("\n\n1.Insert RS\n2.Insert LS\n3.Deletion LS\n4.Print\n5.Clear Screen\n6.Main Menu\n7.Back");
    do
    {
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Insert_RS(stack4,&front4,&rear4);
            break;
        case 2:
            Insert_LS(stack4,&front4,&rear4);
            break;
        case 3:
            Delete_LS(stack4,&front4,&rear4);
            break;
        case 4:
            Print(stack4,&front4,&rear4);
            break;
        case 5:
            system("cls");
            goto START;
            break;
        case 6:
            main_menu();
            break;
        case 7:
            Output_Restricted();
            break;
        default:
            printf("\nWrong Choice!!!");
        }
    }while(choice!=5&&choice!=6);
}
