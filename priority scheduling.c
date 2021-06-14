#include<stdio.h>
#include<conio.h>
#include<string.h>



int main()
{
    int execution_time[20];
    int average_time[10];
    int num;
    int i,j;
    int temp;
    int p[10],st[10],ft[10],waiting_time[10],ta[10];
    int totwtconversion=0,totta=0;
    float average_wainting_time;
    float average_turnaround_time;
    char process_name[10][10];
    char t[10];
    
    printf("Enter the number of processes:");
    scanf("%d", &num);
    for(i=0; i < num; i++)
    {
        printf("Enter process name:\n");
       
        scanf("%s", process_name[i]); //notice we do not use & ampersand with string types.
        printf("Enter the process arrival time\n");
        scanf("%d", &average_time[i]);
        printf("Enter the process execution time\n");
        scanf("%d", &execution_time[i]);
        printf("Enter the process priority");
        scanf("%d", &p[i]);
    }

    for(i=0; i<num; i++){
        for(j=0; j<num; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=average_time[i];
                average_time[i] = average_time[j];
                average_time[j] = temp;
                temp=execution_time[i];
                execution_time[i] = execution_time[j];
                execution_time[j] = temp;
                strcpy(t,process_name[i]);
                strcpy(process_name[i],process_name[j]);
                strcpy(process_name[j],t);
            }
        }
    }
    for(i=0; i<num; i++)
 
    {
 
        if(i==0)
        {
            st[i]=average_time[i];
            waiting_time[i]=st[i]-average_time[i];
            ft[i]=st[i]+execution_time[i];
            ta[i]=ft[i]-average_time[i];
        }
        else
        {
            st[i]= ft[i-1];
            waiting_time[i]= st[i] - average_time[i];
            ft[i]= st[i] + execution_time[i];
            ta[i]= ft[i] - average_time[i];
        }
        totwtconversion += waiting_time[i];
        totta += ta[i];
    }
    average_wainting_time = (float)totwtconversion/num;
    average_turnaround_time = (float)totta/num;
    printf("\nProcessname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
    for(i=0; i<num; i++){
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",process_name[i], average_time[i], execution_time[i],p[i],waiting_time[i],ta[i]);
    }
    printf("\nAverage waiting time is:%f",average_wainting_time);
    printf("\nAverage turnaroundtime is:%f", average_turnaround_time);
    getch();
}