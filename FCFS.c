#include<stdio.h>
#include<string.h>
#include<math.h>
struct job
{
    char name[20];
    int at,bt,ct,tat,wt,st,tbt;
}
job[10];
int n,i,j;
float avg_tat=0;
float avg_wt=0;
void take_input()
{
    printf("Enter the no of jobs:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of the job:",i);
        scanf("%d",&job[i].at);
        printf("Enter the burst time of the job:",i);
        scanf("%d",&job[i].bt);
        printf("\nenter the name of job:",i);
        scanf("%s",&job[i].name);
        job[i].tbt=job[i].bt;
        printf("\n\n");
    }
}
void sort()
{
    struct job temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(job[i].at>job[i].at)
            {
                temp=job[i];
                job[i]=job[j];
                job[j]=temp;
                }
        }
    }
}
void process()
{
    int time=job[0].at;
    for(j=0;j<n;j++)
    {
        job[i].st=time;
        printf("| %d %s",job[i].st,job[i].name);
        time=time+job[j].tbt;
        job[j].ct=time;
        job[j].tat=time-job[j].at;
        job[j].wt=job[j].tat-job[j].tbt;
        printf("%d |",time);
        
        
    }
}
void print_output()
{
    printf("\n\n");
    printf("\n-----------");
    
    printf("\n pname  AT BT TAT WT");
    printf("\n-------------");
    for(i=0;i<n;i++)
    {
        printf("\n %s %d %d %d %d",job[i].name,job[i].at,job[i].bt,job[i].tat,job[i].wt);
        avg_tat=(float)avg_tat+(float)(job[i].tat);
        avg_wt=(float)avg_wt+(float)(job[i].wt);
    }
    printf("\n-----");
    printf("\n The average of the turn around time is %f",avg_tat/n);
    printf("\n the average of the waiting time is %f",avg_wt/n);
}
int main()
{
    int i;
    take_input();
    sort();
    process();
    print_output();
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        job[i].at=job[i].ct+2;
    }
    process();
    print_output();
}
