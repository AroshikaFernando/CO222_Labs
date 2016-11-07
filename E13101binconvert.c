#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(int argc , char** argv){
	if (argc!=4) {                                                                  //check weather the input is not valid
		printf("Usage: ./binconvert -<input format> -<output format> <input>\n");   //output the suitable error message
 return EXIT_FAILURE;                                                               //terminate the programme if inputs are invalid
}
	int j=0;
	if (argv[1][1]=='H' && argv[2][1]=='B'){              // convert hexadecimal to binary
			for (j=0;j<sizeof(argv[3]);j++){
			 switch (argv[3][j]) {
				 case '0':
					printf("0000"); break;
				case '1':
		     		printf("0001"); break;
				case '2':
					printf("0010"); break;
				case '3':
					printf("0011"); break;
				case '4':    
					printf("0100"); break;
				case '5':
					printf("0101"); break;
				case '6':
					printf("0110"); break;
				case '7':
					printf("0111"); break;
				case '8':
					printf("1000"); break;
				case '9':
					printf("1001"); break;
				case 'A':
					printf("1010"); break;
				case 'B':
					printf("1011"); break;
				case 'C':
					printf("1100"); break;
				case 'D':
					printf("1101"); break;
				case 'E':
					printf("1110"); break;
				case 'F':
					printf("1111"); break;
				default:
					printf("invalid input");
			
				}
			 
			}
			printf("\n");
		}
	if (argv[1][1]=='B' && argv[2][1]=='H'){              // converting binary to hexadecimal
	int i=0;
	int x[32];
	int a = sizeof(argv[3]);                             
		for(i=0;i<a;i++){
		if(argv[3][i]=='0'){
			x[i]=0;
			}else{
				x[i]=1;
				}
			}
			printf("0x");
		int k =0;
		while(k<31){
		   if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			  printf("0");
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			   printf("1");
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			   printf("2");
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			  printf("3");
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			  printf("4");
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			  printf("5");
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			  printf("6");
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			  printf("7");
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			  printf("8");
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			  printf("9");
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			  printf("A");
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			  printf("B");
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			  printf("C");
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			  printf("D");
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==0){
			  printf("E");
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			  printf("F");
		  }
		  k=k+4;
		  }
		  printf("\n");
	  }

	if (argv[1][1]=='B' && argv[2][1]=='I'){          // converting binary into integer
	   int j=1;
	   int number = 0;
	   for(j=1;j<sizeof(argv[3]);j++){
		   if(argv[3][j]=='1'){
			   int x=31-j;
			   int y=pow(2,x);
			   number = number+y;
			   }
			   if(argv[3][0]=='1'){
				   number = number*(-1);
				   }
				   printf("%d\n",number);
		   }
	}
	
	 if(argv[1][1]=='I' && argv[2][1]=='B'){          // converting integer into binary
		  int x= atoi(argv[3]);
		  int y=0;
			if(x<0){                                 // to remove negative sign and get positive integers
			  x = x*(-1);
			  y=1;
				}else{
			  x = x;
			  }
				  int j=0;
				  int i=1;
				  int binary[32];
				  while (x!=0){
				  int rem=x%2;
				  binary[i++]= rem;
				  x=x/2;
				  }
				  
				  if(y==1){
					  printf("1");
				  }else{
					  printf("0");
				  }
				  
				  int z= 31-(i+1);
				  int p =1;
				  for(p=1;p<=z;p++){
					  printf("0");
					  }
				for(j=i-1;j>0;j--){
				 printf("%d",binary[j]);
				}
				printf("\n");
}

	 
	  if(argv[1][1]=='I' && argv[2][1]=='F'){         // converting integer into floating point numbers
		  int x=atoi(argv[3]);
		  printf("%d.00\n",x);
		  }
		  
	  if(argv[1][1]=='F' && argv[2][1]=='I'){         // converting floating point numbers into integers
		  int x = atoi(argv[3]);
		  printf("%d\n",x);
		  }
		  
	  if(argv[1][1]=='B' && argv[2][1]=='B'){         // converting binary into binary
		  printf("%s\n",argv[3]);
	  }
	  
	  if(argv[1][1]=='I' && argv[2][1]=='I'){         // converting integer into integer
		  printf("%s\n",argv[3]);
	  }
	  
	  if(argv[1][1]=='H' && argv[2][1]=='H'){         // converting hexadecimal numbers into hexadecimal numbers
		  printf("%s\n",argv[3]);
	  }
	  
	  if(argv[1][1]=='F' && argv[2][1]=='F'){         // converting floating point numbers into floating point numbers
			  printf("%s\n",argv[3]);
	  }
	  
	return 0;

}
