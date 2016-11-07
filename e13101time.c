#include <stdio.h>

int main(){

    int t_start,duration,t_end;
    printf("Enter start time: ");
    scanf("%d",&t_start);
    printf("Enter duration: ");
    scanf("%d",&duration);
    int sum = t_start+duration;
    if(duration >=60){
        int t = duration/60;
        t_end = t_start+(t*100)+(duration%60);
        }else{
            if(sum%100>=60){
                t_end=sum-60+100;
            }else{
                t_end=sum;
            }
        }
        if(t_end <= 2359){
            printf("End time is %d",t_end);
        }else{
            if(t_end==2400){
                printf("End time is 0000");
            }else{
                int e_time=t_end;
                while(e_time>2359){
                e_time=t_end-2400;
                }
                if(e_time<1000){
                    printf("End time is 0%d.",e_time);
                }else{
            printf("End time is %d.",e_time);
            }
            }


        return 0;
}




