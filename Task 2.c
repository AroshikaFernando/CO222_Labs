#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b,c,e,f,g;
	printf("Enter the colour: ");
	scanf("%d %d %d",&a,&b,&c);
	e=255-a;
	f=255-b;
	g=255-c;
	
	
		if(abs(a-e)<=32){
			if(a+128>255){
			e=a-128;
			}else{
				e=a+128;
			}
		}else{
			e=255-a;
			}
	if(abs(b-f)<=32){
		if(b+128>255){
			f=b-128;
			}else{
				f=b+128;
			}
		}else{
			f=255-b;
			}
	if(abs(c-g)<=32){
		if(c+128>255){
			g=c-128;
			}else{
				g=c+128;
			}
			}else{
			g=255-c;
		}if(a<=255 && b<=255 && c<=255){
			printf("The complement:%d %d %d \n",e,f,g);
	}
		else
			printf("Enter valid input\n");
		
		
		return 0; 
	}
