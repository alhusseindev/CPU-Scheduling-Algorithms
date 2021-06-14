#include<stdio.h>

struct process{
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int burst_time2;
    int turn_around_time;
    int waiting_time;
    int f;
    int at1;
    int response;
    int finished;
};


int main(){
    int no_of_processes;
    int i;
    int quantum;
    int st=0;
    int c=0;
    int count=0;
    int number;
    float average_turnaround_time=0;
    float average_waiting_time=0;
    float art=0;
    printf("enter no of processes:\n");
    scanf("%d", &no_of_processes);
    printf("Enter time quantum :\n");
    scanf("%d", &quantum);
    number = no_of_processes;

    struct process parent[no_of_processes];
    struct process temp;

    for (i=0;i < no_of_processes; ++i){
        parent[i].process_id = i+1;
        parent[i].f = 0;
        parent[i].finished = 0;
        printf("enter arraival time:");
        scanf("%d", &parent[i].arrival_time);
        printf("enter the burst time:");
        scanf("%d",&parent[i].burst_time);
        parent[i].burst_time2 = parent[i].burst_time;
        parent[i].at1 = parent[i].arrival_time;
        printf("--------------------------- ");
    }

    int m=999,max=-1;

    for(i=0;i<no_of_processes;i++)
    {
        if(parent[i].burst_time < m){
            m = parent[i].burst_time;
        }
    }
    while (1){
        int r=no_of_processes,min=999;
        for (i=0;i<no_of_processes;i++){
            if ((parent[i].arrival_time < min) && (parent[i].f == 0) && (parent[i].arrival_time <= st)){
                min = parent[i].arrival_time;
                r = i;
            }
        }
        if(parent[r].finished == 0){
            parent[r].response = st - parent[r].arrival_time;
        
        }
        if(c == no_of_processes){
            break;
        }else if(r==no_of_processes){
            ++st;
            if(c == no_of_processes - 1){
                ++count;
            }
        }
        else if(parent[r].burst_time <= quantum)
        {
            st= st + parent[r].burst_time - count;
            parent[r].finished = 1;
            parent[r].burst_time = 0;
            parent[r].f=1;
            ++c;
            parent[r].completion_time = st;
            parent[r].turn_around_time = parent[r].completion_time - parent[r].at1;
            average_turnaround_time = average_turnaround_time + parent[r].turn_around_time;
            parent[r].waiting_time = parent[r].turn_around_time - parent[r].burst_time2;
            average_waiting_time = average_waiting_time + parent[r].waiting_time;
        }
        else{
            st = st + quantum - count;
            parent[r].arrival_time = st + 1;
            parent[r].burst_time = parent[r].burst_time - quantum;
            parent[r].finished = 1;
        }
    }

    for(i=0;i<no_of_processes;i++){
        art += parent[i].response;
    }
    
    printf(" average turn around time is %f",(float)(average_turnaround_time/number));
    printf(" average waiting time is %f ",(float)(average_waiting_time/number));
    printf(" average response time is %f ",(float)(art/number));
    printf(" Process At Bt Wt Ft Tat Res");



    for(i=0; i < no_of_processes; ++i){
        printf(" P%d %d %d %d %d %d %d", parent[i].process_id, parent[i].at1, parent[i].burst_time2, parent[i].waiting_time, parent[i].completion_time, parent[i].turn_around_time, parent[i].response);
    }
}
