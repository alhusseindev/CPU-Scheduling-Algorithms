#include<stdio.h>


struct process{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaroundtime;
    int waiting_time;
    int f;
};



int main()
{
    int n;
    int i;
    int st=0;
    int total=0;
    int process_no=0;
    int no_of_switches=0;
    int c; 
    float averageturnaroundtime=0;
    float averagewaitingtime=0;
    printf("enter no of processes : \n");
    scanf("%d",&n);
    
    struct process parent[n];
    struct process temp;
    
    
    for (i=0;i<n;++i){
        parent[i].process_id = i+1;
        parent[i].f=0;
        printf("enter arrival_time: \n");
        scanf("%d", &parent[i].arrival_time);
        printf("enter the burst time : ");
        scanf("%d", &parent[i].burst_time);
        printf("---------------------------\n");
    }



    while(1){
        //do the initializations
        int min=999,c=n;
        if (total == n){
            break;
        }

        for (i=0;i<n;i++){
            if ( (parent[i].arrival_time <= st) && (parent[i].f==0) && (parent[i].arrival_time < min) ){
                min = parent[i].arrival_time;
                c = i;
            }
        }

        if(process_no != parent[c].process_id){
            ++no_of_switches;
        }


        if (c==n){
            st++;
        }else{
            parent[c].completion_time = st + parent[c].burst_time;
            st = st + parent[c].burst_time;
            parent[c].turnaroundtime = parent[c].completion_time - parent[c].arrival_time;
            averageturnaroundtime = averageturnaroundtime + parent[c].turnaroundtime;
            parent[c].waiting_time = parent[c].turnaroundtime - parent[c].burst_time;
            averagewaitingtime = averagewaitingtime + parent[c].waiting_time;
            parent[c].f = 1;
            ++total;
        }
    }



    printf(" Process AT BT WT FT TAT ");

    for(i=0;i<n;i++){
        printf("p%d %d %d %d %d %d ",i,parent[i].arrival_time,parent[i].burst_time,parent[i].waiting_time,parent[i].completion_time, parent[i].turnaroundtime);
    }

    printf("Average Turnaround Time is %f ",(float)(averageturnaroundtime/n));
    printf("Average Waiting Time is %f",(float)(averagewaitingtime/n));
    printf("No oF Switches: %d", no_of_switches);
}
