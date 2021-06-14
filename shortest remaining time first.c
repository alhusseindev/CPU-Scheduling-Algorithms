#include<stdio.h>

struct process{
int process_id;
int arrival_time;
int burst_time,burst_time2,completion_time,turnaroundtime,waiting_time,f;
};


int main(){
    int num;
    int i;
    int st=0;
    int c;
    int total=0;
    float average_turnaroundtime=0;
    float average_waitingtime=0;
    printf("enter number of processes:\n");
    scanf("%d", &num);
    struct process parent[num];
    struct process temp;

    for (i=0;i<num;i++){
        parent[i].process_id = i + 1;
        parent[i].f=0;
        printf("enter arrival time : ");
        scanf("%d", &parent[i].arrival_time);
        printf("enter burst time : ");
        scanf("%d",&parent[i].burst_time);
        parent[i].burst_time2 = parent[i].burst_time;
        printf("--------------------------- ");
    }

    while(1){
        int min=999;
        int c=num;
        if (total==num){
            break;
        }
        for (i=0;i<num;i++){
            if ((parent[i].arrival_time <= st)&&(parent[i].f==0)&&(parent[i].burst_time<min)){
                min = parent[i].burst_time;
                c = i;
            }
        }
        if (c == num){
            st++;
        }else{
            parent[c].completion_time = st+1;
            st = st+1;
            parent[c].burst_time--;
            if (parent[c].burst_time == 0){
                ++total;
                parent[c].f=1;
                parent[c].turnaroundtime = parent[c].completion_time - parent[c].arrival_time;
                average_turnaroundtime = average_turnaroundtime + parent[c].turnaroundtime;
                parent[c].waiting_time = parent[c].turnaroundtime - parent[c].burst_time2;
                average_waitingtime = average_waitingtime + parent[c].waiting_time;
            }
        }
    }
    printf(" average turn around time is %.2f ",(float)(average_turnaroundtime/num));
    printf("average waiting time is %.2f",(float)(average_waitingtime/num));
}
