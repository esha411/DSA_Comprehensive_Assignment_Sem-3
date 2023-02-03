//Esha Patel
//19BCE169
//DSA Comprehensive Assignment
//2CS301

/*PROGRAM DEFINITION ----------> In a school, students of 5th Grade are going for a picnic.
For a particular game between 10 players, they needs to be organized in the ascending order of their height.
Teacher selects a one random student out of 10.
That student acts as a mediator, all students having height less than mediator goes on left and rest on his right.
The same process repeats again between the left and right group.
The process continues and will stop when all the players are in ascending order of their height.
Implement the given model.  */

/*QUESTION--------->Signify which sorting algorithm can be helpful to design this model and how.
  ANSWERE--------->QUICK sorting algorithm can be helpful here.....
  QUICKSORT is a divide and conquer algorithm. It works by selecting a "pivot" element from the array
  and partitioning the other element into two sub-arrays , according to whether they are less than or greater than the pivot.
  The sub-array are then sorted recursively */

/*QUESTION---------->What additional functionality can you add to this.
  ANSWERE----------->first off all I sort student into Ascending order by them height.
  I give option to user that add more student or remove any student and then sort into Ascending Order and display them
  Then I give option for searching that you can search student position by name or you can search student name and height by position*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student              //Declaring structure STUDENT
    {
        char name[100];             //structure members that store student name, height and position rank
        float height;
        int rank;
    }stu;

 stu s[30];

void quick_sort(int p, int q);                  //function declaration
int partion( int p, int r);
void swap(stu *s1, stu *s2);
void print_data(int n);
void search(int n);
void search_data(int n);
void delete_detail(struct student s[],int n);
void delete_name(struct student s[],int n);

void quick_sort(int p, int q)                   //Recursive Function for quick sort
{
    int j;
    if (p < q)
    {
        j = partion(p, q);
        quick_sort( p, j-1);
        quick_sort(j+1, q);
    }
}
int partion( int p, int r)                              //function for partitioning array element into two sub-arrays
{
    int pivotIndex = p + rand()%(r - p + 1);            //generates a random number as a pivot
    int pivot;
    int i = p - 1;
    int j;
    pivot = s[pivotIndex].height;
    swap(&s[pivotIndex], &s[r]);
    for (j = p; j < r; j++)
    {
        if (s[j].height < pivot)
        {
            i++;
            swap(&s[i], &s[j]);
        }

    }
    swap(&s[i+1], &s[r]);
    return i + 1;
}

void swap(stu *s1, stu *s2)                             //function for swapping two structure
{
    stu temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
void print_data(int n)                                  //function for print student height in Ascending order
{
    int i=0,j;
        printf("\nAscending order of student heights ");
        printf("\n---------------------------");
        printf("\nRANK\tNAME\tHEIGHT");
        printf("\n---------------------------\n");
        do{
            for(j=0;j<n;j++)
            {
                s[i].rank=i+1;
                printf("%d \t",i+1);
                printf("%s \t",s[j].name);
                printf("%.2f \n",s[j].height);
                i=i+1;
            }
         }while(i<n);
}
void add(struct student s[],int n)                      //function for add more student
{
    int i,sal;
    char ename;
        printf("\n Enter Student Name:");
        scanf("%s",s[n].name);
        printf("\n Enter Height:");
        scanf("%f",&s[n].height);
        quick_sort(0, n);
        print_data(n+1);
}

void search(int n)                                          //function for search student name by position
{
    int eid,i,j,p=1,g;
    printf("Enter Student Position to be Searched:");
    scanf("%d",&eid);
    for(i=0;i<n;i++)
    {
        if(s[i].rank==eid)
        {
            p++;
            g=i;
        }
    }
    if(p==2)
    {
        printf("\nStudent Name:%s",s[g].name);
        printf("\nStudent Height:%.2f",s[g].height);
        printf("\n");
    }
    else
    {
        printf("No Such Name found!");
    }
}
void search_data(int n)                             //function for search student position by name
{
    int i;
    char name[100];
    printf("Name of Student to be searched :");
    scanf("%s",name);
    for(i=0;i<n;i++)
        {
            if(!strcmp(name,s[i].name))
            {
                printf("\nStudent Position");
                printf("%d ",s[i].rank);
                printf("\nStudent Name");
                printf("%s ",s[i].name);
                printf("\nStudent Height");
                printf(".2%f ",s[i].height);
            }
        }
}
void delete_detail(struct student s[],int n)                    //function for remove student by position
{
    int f,t=1,eid,i;
    printf("Enter student position:");
    scanf("%d",&eid);
        for(i=0;i<n;i++)
        {
                                    //to search id to be deleted
            if(s[i].rank==eid)
            {
                f=i;
                t++;
            }
                           else
                                    continue;
        }
        if(t=2)
        {
            for(i=f;i<n;i++)
            {
                s[i]=s[i+1];
            }
	}
	else
	printf("Student not found!");
	 print_data(n-1);
}
void delete_name(struct student s[],int n)                      //function for remove student by name
{
    int f,t=1,eid,i;
    char dlname[10];
    printf("Enter student name:");
    scanf("%s",dlname);
    for(i=0;i<n;i++)
    {
                                    //to search id to be deleted
        if(!strcmp(dlname,s[i].name))
        {
            f=i;
            t++;
        }
        else
            continue;
    }
        if(t=2)
        {
            for(i=f;i<n;i++)
            {
                s[i]=s[i+1];
            }
        }
        else
        {
            printf("Student not found!");
	    }
         print_data(n-1);
}
/***************************************************************main function*/
int main()
{
    int i,j,n,opt,DL;
    printf("Enter Total Number of the Students: ");
    scanf("%d",&n);
    printf("Enter the NAME and HEIGHT of the student \n");
    for(i=0;i<n;i++)
    {
        printf("\nName of Student %d = ",i+1);
        scanf("%s",s[i].name);
        printf("Height of student %d =",i+1);
        scanf("%f",&s[i].height);
        printf("\n");
            //arr[i]=s[i].height;
    }
        quick_sort(0, n - 1);
        print_data(n);
    while(1)
         {
            int ch,ex=0;
            printf("\n1 Add more Student ");
            printf("\n2 Search Student");
            printf("\n3 Remove Student");
            printf("\n4 Exit");
            printf("\n---->");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    add(s,n);
                    break;
                case 2:
                    printf("\n1) Search Student by them POSITION");
                    printf("\n2) search Student by NAME");
                    printf("\n----->");
                    scanf("%d",&opt);
                    switch(opt)
                    {
                        case 1:
                            search(n);
                            break;
                        case 2:

                            search_data(n);
                            break;
                        default:
                            printf("\nNO SUCH INPUT!");
                            break;
                    }
                  break;
                  case 3:
                           printf("\n1) Remove Student by Position");
                           printf("\n2) Remove Student by Name");
                           printf("\n---->");
                           scanf("%d",&DL);
                           switch(DL)
                           {
                                case 1:
                                    delete_detail(s,n);
                                    break;
                                case 2:
                                    delete_name(s,n);
                                    break;
                                default:
                                    printf("NO SUCH INPUT!");
                                    break;
                           }
                    break;
                  case 4:
                           ex++;
                           break;
                  default:
                           printf("NO SUCH INPUT!! ");
        }
    if(ex==1)
    return 0;
    }
}


