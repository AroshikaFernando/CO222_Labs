#include <stdio.h>

int Atoi(char *);
float Atof(char *);
int myStrlen(char *);
int power(int a , int b);

int binary_int(char *);
int int_float(char *);
int binary_int(char *);
float binary_float(char *);
double binary_double(char *);

void float_int(char *);
void hexa_int(char *);
void int_binary(char *);
void binary_hexa(char *);
void hexa_binary(char *);
void int_hexa(char *);
void hexa_float(char *);
void hexa64_binary(char *);
void hexa_double(char *);
void float_binary(char *);
void float_hexa(char *);
void double_binary(char *);
void double_hexa(char *);

int binary[32];
char hexa[8];
int hexbinary[32];
int binaryArr[32];
int hex64binary[64];
int floatbinary[32];
int doublebinary[64];
int hexa64[16];

int main(int argc,char** argv){
   
   //Wrong input arguments numbers(Error)
   if(argc != 4){
        fprintf(stderr,"ERROR: The number of arguments is wrong.\n");
        fprintf(stderr,"Usage: ./clc -<input format> -<output format> <input>\n");
        return 1;
    }
    //Wrong input argument(Error)
    if(!(argv[1][1]=='B' || argv[1][1]=='H' || argv[1][1]=='I' || argv[1][1]=='F' || argv[1][1]=='D')){
        fprintf(stderr,"ERROR: The input argument is wrong.\n");
        fprintf(stderr,"Possible input arguments are -B, -H, -I, -F and -D.\n");
        return 1;
    }

    //Wrong output argument(Error)
    if(!(argv[2][1]=='B' || argv[2][1]=='H' || argv[2][1]=='I' || argv[2][1]=='F' || argv[2][1]=='D')){
        fprintf(stderr,"ERROR: The output argument is wrong.\n");
        fprintf(stderr,"Possible output arguments are -B, -H, -I, -F and -D.\n");
        return 1;
    }
//BINARY input format
if(argv[1][1]=='B'){
	int i;
	int x = myStrlen(argv[3]);
	
	//format error
	for(i=0;i<x;i++){
	  if(argv[3][i] != '1' && argv[3][i] != '0'){
		int a = i;
		fprintf(stderr,"Error:  Input format error at location %d\n.",a);
		return 1;
		}
	}
	 
	//input size error
	if(argv[2][1]!='D'){
		if(x!=32){
			fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
		}
	}else{
		if(x!=64){
			fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
			}
		} 
     if(argv[2][1]=='B'){
		 fprintf(stdout,"%s\n",argv[3]);
	} if(argv[2][1]=='H'){
		binary_hexa(argv[3]);
		for(i=0;i<8;i++){
			  fprintf(stdout,"%c",hexa[i]);
			  }
		  fprintf(stdout,"\n");
	} if(argv[2][1]=='I'){
		int a = binary_int(argv[3]);
		fprintf(stdout,"%d\n",a);
	} if(argv[2][1]=='F'){
		float a = binary_float(argv[3]);
		fprintf(stdout,"%.2f\n",a);
	} if (argv[2][1]=='D'){
		double a = binary_double(argv[3]);
		fprintf(stdout,"%lf\n",a);
		}
	}

	
//INTEGER input format
if(argv[1][1]=='I'){
	int i;
	 // for wrong input size
        if(Atoi(argv[3])> 2147483647 || Atoi(argv[3])< -2147483648){
            fprintf(stderr,"ERROR: The input size is wrong.\n");
            return 1;
        }
    //input format errors
	if((argv[3][0] == '-') || (argv[3][0]>='0' && argv[3][0]<='9')){
	}else{
		fprintf(stderr,"ERROR:  Input format error at location 0.\n");
		return 1;
	}
    int j=0;
	while(argv[3][j+1]!='\0'){
		if(argv[3][j+1]>=48 && argv[3][j+1]<=57){
		}
		else{
			fprintf(stderr,"ERROR:  Input format error at location %d.\n",j+1);
			return 1;
		}
		j++;
	}
     //converting integer to double 
	if(argv[2][1]=='D'){
		fprintf(stderr,"ERROR: This conversion is not possible.\n");
		return 1;
	}
	 if(argv[2][1]=='F'){
		int a = int_float(argv[3]);
		fprintf(stdout,"%d.00\n",a);
	 }else if(argv[2][1]=='I'){
		 fprintf(stdout,"%s\n",argv[3]);
	 }else if(argv[2][1]=='B'){
		 int_binary(argv[3]);
		 for(i=31;i>=0;i--){
			 fprintf(stdout,"%d",binary[i]);
			}
			fprintf(stdout,"\n");
	}else if (argv[2][1]=='H'){
		int_hexa(argv[3]);
		for(i=0;i<8;i++){
			fprintf(stdout,"%c",hexa[i]);
			}
			fprintf(stdout,"\n");
		}
 }
	
//HEXADECIMAL input format
if(argv[1][1]=='H'){ 
	int j,i;
	int x = myStrlen(argv[3]);
	//input size error
	if(argv[2][1]!='D'){
		if(x<8){ 
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 1;
		}else if(x>8){
			fprintf(stderr,"ERROR:  This conversion is not possible.\n");
			return 1;
		}
	}else{
		if(x<16){ 
			fprintf(stderr,"ERROR: The input size is wrong.\n");
			return 1;
		}else if(x>16){
			fprintf(stderr,"ERROR:  This conversion is not possible.\n");
			return 1;
		}
	}
	//input format error
	for(j=0;j<x;j++){ 
		if(!((argv[3][j] >= '0' && argv[3][j] <= '9') || (argv[3][j] >= 'A' && argv[3][j] <= 'F'))){
			fprintf(stderr,"Error:  Input format error at location %d.\n",j);
			return 1;
		}
	}
			
	if(argv[2][1]=='H'){
	   printf("%s\n",argv[3]);
   }else if(argv[2][1]=='B'){
	   hexa_binary(argv[3]);
	   for(i=0;i<32;i++){
		printf("%d",hexbinary[i]);
		}
		printf("\n");
	}else if(argv[2][1]=='I'){ 
		 hexa_int(argv[3]);
	}else if(argv[2][1]=='F'){
		hexa_float(argv[3]);
	}else if (argv[2][1]=='D'){
		hexa_double(argv[3]);
		}
}
	
//FLOAT input format
if(argv[1][1]=='F'){
	int i=0;
	int count=0,j=0;
   //input format error
	while(argv[3][i]!='\0'){
		if(!((argv[3][i]>='0' && argv[3][i]<='9') || (argv[3][i]=='.' )|| (argv[3][i] == '-'))){
			fprintf(stderr,"ERROR: Input format error at location %d.\n",j);
			return 1;
		}
		i++;
	}
	//checking whether the no.of '.' is more than one
	while(argv[3][j]!='\0'){
		if(argv[3][j]=='.'){
			++count;
		}
		if(count>1){
			fprintf(stderr,"ERROR: Input format error at location %d.\n",j);
			return 1;
		}
		j++;
	}
	//converting float to double
	if(argv[2][1]=='D'){
		fprintf(stderr,"ERROR: This conversion is not possible.\n");
		return 1;
	}
	  if(argv[2][1]=='F'){
	    float x = Atof(argv[3]);
	    fprintf(stdout,"%.2f\n",x);
		}else if(argv[2][1]=='I'){
			fprintf(stderr,"WARNING: There is a possibility for a precision loss.\n");
			float_int(argv[3]);
		}else if(argv[2][1]=='B'){
			float_binary(argv[3]);
			for(i=0;i<32;i++){
			fprintf(stdout,"%d",floatbinary[i]);
		}
		}else if (argv[2][1]=='H'){
			float_hexa(argv[3]);
			for(i=0;i<8;i++){
			fprintf(stdout,"%d",hexa[i]);
		}
		fprintf(stdout,"\n");
		}
	}
	
//DOUBLE input format 
if(argv[1][1]=='D'){ 
	int i;
	int count=0,j=0;
	//input format error
	while(argv[3][i]!='\0'){
		if(!((argv[3][i]>='0' && argv[3][i]<='9') || (argv[3][i]=='.' )|| (argv[3][i] == '-'))){
			fprintf(stderr,"ERROR: Input format error at location %d.\n",j);
			return 1;
		}
		i++;
	}
	//checking whether the no.of '.' is more than one
	j=0;
	while(argv[3][j]!='\0'){
		if(argv[3][j]=='.'){
			++count;
		}else if(count>1){
			fprintf(stderr,"ERROR: Input format error at location %d.\n",j-1);
			return 1;
		}
		j++;
	}
      //converting double to float
		if(argv[2][1]=='F'){
			fprintf(stderr,"ERROR: This conversion is not possible.\n");
			return 1;
		}
		//converting double to integer
		if(argv[2][1]=='I'){
			fprintf(stderr,"ERROR: This conversion is not possible.\n");
			return 1;
		}
		if(argv[2][1]=='D'){
		 float x = Atof(argv[3]);
	     fprintf(stdout,"%.6f",x);
		}else if(argv[2][1]=='B'){
			double_binary(argv[3]);
			for(i=0;i<64;i++){
			fprintf(stdout,"%d",doublebinary[i]);
			}
			fprintf(stdout,"\n");
		}else if(argv[2][1]=='H'){
			double_hexa(argv[3]);
			for(i=0;i<16;i++){
			fprintf(stdout,"%d",hexa64[i]);
		}
		fprintf(stdout,"\n");
			}
	}
	return 0;
}

//function that converts string to integer
int Atoi(char *str){       
    
	int val = 0;
    int sign = 1;
    int j = 0,i;
    
    if (str[0] == '-'){    //to leave sign bit for negative numbers
        sign = -1; 
         j++;  
    }else
        sign = sign;
        j=j;
	for (i=j; str[i] != '\0'; i++){
		val = val*10 + str[i] - '0';
	}
	    val = val*sign;
	return val;
}

//function that converts strings to float
float Atof(char *str){
	int i=0,j,b,val=0,k=0,sign=1;
	float f_val=0.0,p=0.1,value;
    
	int a = myStrlen(str);
	int arr[a];
	//int arr1[a];
	
     if (str[0] == '-'){
        sign = -1; 
         k++;  
    }else{
        sign = sign;
        k=k;
       }   
	for (j=0;j<a;j++){
		arr[j]=0;
	}
    
	while(str[i]!='.'){
		int x = str[i]-'0' ;
		arr[i] = x;
		i++;
		}
		
    for (j=k;j<i; j++){
		val = val*10 + arr[j];
	}
        j=0;
        ++i;
        while(str[i]!='\0'){
            int q = str[i]-'0';
            arr[i]=q;
            i++;
            j++;
        }
    
       for(b=i-j;b<a;b++){
		f_val = f_val + p*arr[b];
		p=p/10;
		}
		
		value = val + f_val;
		value = value*sign;
   	return value;
}		


//function to find string length
int myStrlen(char *str){      
	int i;
	int count=0;
	for(i=0;str[i] != '\0' ;i++){
		count++;
		}
		return count;
	}

//My power function	
int power(int a , int b){      
		int i, num=1;
		for(i=0;i<b;i++){
		num = num*a;
		}
	return num;
}


// converting integer into floating point numbers 
int int_float(char *ch){                                                 
	int x=Atoi(ch);
	return x;
	}
		                                                                      
// converting floating point numbers into integers	
void float_int(char *ch){                                                
	 int i,a;
	 for(i=0;ch[i] != '.';i++){       //to get number befor the '.'
		 a=ch[i]-'0';
			 fprintf(stdout,"%d",a);
		 }
		fprintf(stdout,"\n");
}

//converting integer to binary
void int_binary(char *ch){                                                
	int x= Atoi(ch);
		  int i=1;
		  for(i=0;i<32;i++){
			  binary[i]=0;
			  }
			  i=0;
	   if(x>0){
			  while (x!=0){
			  int rem=x%2;
			  binary[i]= rem;
			  x=x/2;
			  i++;
			  }
			  
		  }
		if(x<0){
			if(x<0){      // to remove negative sign and get positive integers
			  x = x*(-1);
			 }
			  while (x!=0){
			  int rem=x%2;
			  binary[i]= rem;
			  x=x/2;
			  i++;
			  }
	for(i=0;i<32;i++){
		if(binary[i]==0){
			binary[i]=1;
		}else if(binary[i]==1){
			binary[i]=0;
			}
		}
	for(i=0;i<32;i++){
		if(binary[i]==1){
			binary[i]=0;
		}else if(binary[i]==0){
			binary[i]=1;   break;
			}
		}
	}
}

//converting binary to hexa
void binary_hexa(char *ch){       
	int i;
	int x[32];
	int a = myStrlen(ch);                             
		for(i=0;i<a;i++){
		if(ch[i]=='0'){
			x[i]=0;
			}else{
				x[i]=1;
				}
			}
			fprintf(stdout,"0x");
		int k,j;
		for(k=0,j=0 ; k<=28 && j<=8 ; k+=4,j++){
		   if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			  hexa[j]='0';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			   hexa[j]='1';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			   hexa[j]='2';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			   hexa[j]='3';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			   hexa[j]='4';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			   hexa[j]='5';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			   hexa[j]='6';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			   hexa[j]='7';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			   hexa[j]='8';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			  hexa[j]='9';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			  hexa[j]='A';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			  hexa[j]='B';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			  hexa[j]='C';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			  hexa[j]='D';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==0){
			  hexa[j]='E';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			  hexa[j]='F';
		  }
		  }
		  
   } 
                        
// converting hexadecimal to binary
void hexa_binary(char *ch){       
	int j,k;
		for (j=0,k=0 ; j<8 && k<=28 ; j++,k+=4){
		 switch (ch[j]) {
			 case '0':
				hexbinary[k]=0; hexbinary[k+1]=0;hexbinary[k+2]=0;hexbinary[k+3]=0;
				  break;
			case '1':
				hexbinary[k]=0; hexbinary[k+1]=0;hexbinary[k+2]=0;hexbinary[k+3]=1;
				 break;
			case '2':
				hexbinary[k]=0; hexbinary[k+1]=0;hexbinary[k+2]=1;hexbinary[k+3]=0;
				 break;
			case '3':
			    hexbinary[k]=0; hexbinary[k+1]=0;hexbinary[k+2]=1;hexbinary[k+3]=1;
				 break;
			case '4':    
			    hexbinary[k]=0; hexbinary[k+1]=1;hexbinary[k+2]=0;hexbinary[k+3]=0;
				 break;
			case '5':
				 hexbinary[k]=0; hexbinary[k+1]=1;hexbinary[k+2]=0;hexbinary[k+3]=1;
				 break;
			case '6':
				 hexbinary[k]=0; hexbinary[k+1]=1;hexbinary[k+2]=1;hexbinary[k+3]=0;
				 break;
			case '7':
				 hexbinary[k]=0; hexbinary[k+1]=1;hexbinary[k+2]=1;hexbinary[k+3]=1;
				 break;
			case '8':
				 hexbinary[k]=1; hexbinary[k+1]=0;hexbinary[k+2]=0;hexbinary[k+3]=0;
				 break;
			case '9':
				 hexbinary[k]=1; hexbinary[k+1]=0;hexbinary[k+2]=0;hexbinary[k+3]=1;
				 break;
			case 'A':
				 hexbinary[k]=1; hexbinary[k+1]=0;hexbinary[k+2]=1;hexbinary[k+3]=0;
				 break;
			case 'B':
				 hexbinary[k]=1; hexbinary[k+1]=0;hexbinary[k+2]=1;hexbinary[k+3]=1;
				 break;
			case 'C':
				 hexbinary[k]=1; hexbinary[k+1]=1;hexbinary[k+2]=0;hexbinary[k+3]=0;
				 break;
			case 'D':
				 hexbinary[k]=1; hexbinary[k+1]=1;hexbinary[k+2]=0;hexbinary[k+3]=1;
				 break;
			case 'E':
				 hexbinary[k]=1; hexbinary[k+1]=1;hexbinary[k+2]=1;hexbinary[k+3]=0;
				 break;
			case 'F':
				 hexbinary[k]=1; hexbinary[k+1]=1;hexbinary[k+2]=1;hexbinary[k+3]=1;
				 break;
			
			}
		}

	}

void int_hexa(char *ch){
	int i,j;
	char str[32];
	int_binary(ch);
	for(i=31,j=0;i>=0 && j<32;i--,j++){
		char a = binary[j] + '0';
		str[i] = a;
		}
		binary_hexa(str);
	}
	
int  binary_int(char *ch){	                                            //converting binary to integer      
     int i,j;
	   int number = 0;
	   int k=1;
	   if(ch[0]==1){
		for(i=31;i>=0;i--){
			if(ch[i]==0){
				ch[i]=1;
			}else if (ch[i]==1){
				ch[i]=0;       break;
				}
			}
		for(i=0;i<32;i++){
			if(ch[i]==0){
				ch[i]=1;
			}else if(ch[i]==1){
				ch[i]=0;
				}
			} 
			for(j=31;j>=0;j--){
		   if(ch[j]=='1'){
			   number = number+k;
		   }
		   k=k*2;
	   } 
	   number = number *(-1);
	   }
	   for(j=31;j>=0;j--){
		   if(ch[j]=='1'){
			   number = number+k;
		   }
		   k=k*2;
	   }
		return number;	  
	}

void hexa_int(char *ch){
	int i,j;
	char str[32];
	hexa_binary(ch);
	for(i=31,j=31;i>=0 && j>=0;i--,j--){
		char a = hexbinary[j] + '0';
		str[i] = a;
		}
		int num = binary_int(str);
		fprintf(stdout,"%d\n",num);
	}
	
float  binary_float(char *ch){
	int i,k=1,j,number=0,int_num=0;
	float float_num=0,number1,e=0.5;
	int arr[8];
	
	for(i=0;i<32;i++){
		int a = ch[i] - '0';
		binaryArr[i] = a;
		}
	
	//to get exponent
	for(i=1;i<=8;i++){
		int a = binaryArr[i];
		arr[i-1] = a;
		}
		for(j=7;j>=0;j--){
		   number = number+k*arr[j];
		   k=k*2;
	   }
	 int expo = number -127;
	if(expo>0){
		   k=1;
		//to get int part of the float number
		for(i=(8+expo);i>=9;i--){
			int_num = int_num + k*binaryArr[i];
			k=k*2; 
		}
			int_num = int_num + k;
		
		for(i=(9+expo);i<32;i++){
            float_num = float_num + e*binaryArr[i];
           e=e/2;
        } 
        number1 = int_num + float_num;
        if(binaryArr[0]==1){
			number1 = number1*(-1);
		}else if (binaryArr[0]==1){
			number1 = number1;
			}    
        //return number1;
	}else if(expo<0){
		   expo = expo * (-1);
		
		   int arr1[expo];
		   for(i=0;i<(expo-1);i++){
			   arr1[i]=0;
			   }
			   arr1[expo-1]=1;
			   
			e=0.5;
			
		for(i=0;i<=(expo-1);i++){
           float_num = float_num + e*arr1[i];
           e=e/2;
        }
   
        for(i=9;i<32;i++){
            float_num = float_num + e*binaryArr[i];
           e=e/2;
        }
           number1 = float_num;
        if(binaryArr[0]==1){
			number1 = number1*(-1);
		}else if (binaryArr[0]==0){
		    number1 = number1;
			}  
        //return float_num;
	} 
  return number1;
}
	
double binary_double(char *ch){
	int i,k=1,j,number=0,int_num=0;
	float e=0.5;
	double number1 ,float_num = 0;
	int arr[11];
	int binaryArr[64];
	for(i=0;i<64;i++){
		int a = ch[i] - '0';
		binaryArr[i] = a;
		}
	
	//to get exponent
	for(i=1;i<=11;i++){
		int a = binaryArr[i];
		arr[i-1] = a;
		}
		for(j=10;j>=0;j--){
		   number = number+k*arr[j];
		   k=k*2;
       }
	 int expo = number -1023;
	if(expo>0){
		   k=1;
		//to get int part of the float number
		for(i=(11+expo);i>=12;i--){
			int_num = int_num + k*binaryArr[i];
			k=k*2; 
			}
			int_num = int_num + k;
		
		for(i=(12+expo);i<64;i++){
            float_num = float_num + e*binaryArr[i];
           e=e/2;
        } 
        number1 = int_num + float_num; 
        if(binaryArr[0]==1){
			number1 = number1*(-1);
		}else if (binaryArr[0]==1){
			number1 = number1;
			}   
        //return number1;
	}else if(expo<0){
		   expo = expo * (-1);
		
		   int arr1[expo];
		   for(i=0;i<(expo-1);i++){
			   arr1[i]=0;
			   }
			   arr1[expo-1]=1;
			   
			e=0.5;
			
		for(i=0;i<=(expo-1);i++){
           float_num = float_num + e*arr1[i];
           e=e/2;
        }
   
        for(i=12;i<64;i++){
            float_num = float_num + e*binaryArr[i];
           e=e/2;
        }
        number1 = float_num;
        if(binaryArr[0]==1){
			number1 = number1*(-1);
		}else if (binaryArr[0]==0){
		    number1 = number1;
			}  
       // return float_num;
	} 
	return number1;
}

void hexa_float(char *ch){
	int i,j;
	char str[32];
	hexa_binary(ch);
	for(i=31,j=31;i>=0 && j>=0;i--,j--){
		char a = hexbinary[j] + '0';
		str[i] = a;
		}
		float a = binary_float(str);
		fprintf(stdout,"%.2f\n",a);
	}
//converting 64bit hexa number to binary	
void hexa64_binary(char *ch){       
	int j,k;
		for (j=0,k=0 ; j<16 && k<=60 ; j++,k+=4){
		 switch (ch[j]) {
			 case '0':
				hex64binary[k]=0; hex64binary[k+1]=0; hex64binary[k+2]=0; hex64binary[k+3]=0;
				  break;
			case '1':
				hex64binary[k]=0; hex64binary[k+1]=0; hex64binary[k+2]=0; hex64binary[k+3]=1;
				 break;
			case '2':
				hex64binary[k]=0; hex64binary[k+1]=0; hex64binary[k+2]=1; hex64binary[k+3]=0;
				 break;
			case '3':
			    hex64binary[k]=0; hex64binary[k+1]=0; hex64binary[k+2]=1; hex64binary[k+3]=1;
				 break;
			case '4':    
			    hex64binary[k]=0; hex64binary[k+1]=1; hex64binary[k+2]=0; hex64binary[k+3]=0;
				 break;
			case '5':
				 hex64binary[k]=0; hex64binary[k+1]=1; hex64binary[k+2]=0; hex64binary[k+3]=1;
				 break;
			case '6':
				 hex64binary[k]=0; hex64binary[k+1]=1; hex64binary[k+2]=1; hex64binary[k+3]=0;
				 break;
			case '7':
				 hex64binary[k]=0; hex64binary[k+1]=1; hex64binary[k+2]=1; hex64binary[k+3]=1;
				 break;
			case '8':
				 hex64binary[k]=1; hex64binary[k+1]=0; hex64binary[k+2]=0; hex64binary[k+3]=0;
				 break;
			case '9':
				 hex64binary[k]=1; hex64binary[k+1]=0; hex64binary[k+2]=0; hex64binary[k+3]=1;
				 break;
			case 'A':
				 hex64binary[k]=1; hex64binary[k+1]=0; hex64binary[k+2]=1; hex64binary[k+3]=0;
				 break;
			case 'B':
				 hex64binary[k]=1; hex64binary[k+1]=0; hex64binary[k+2]=1; hex64binary[k+3]=1;
				 break;
			case 'C':
				 hex64binary[k]=1; hex64binary[k+1]=1; hex64binary[k+2]=0; hex64binary[k+3]=0;
				 break;
			case 'D':
				 hex64binary[k]=1; hex64binary[k+1]=1; hex64binary[k+2]=0; hex64binary[k+3]=1;
				 break;
			case 'E':
				 hex64binary[k]=1; hex64binary[k+1]=1; hex64binary[k+2]=1; hex64binary[k+3]=0;
				 break;
			case 'F':
				 hex64binary[k]=1; hex64binary[k+1]=1; hex64binary[k+2]=1; hex64binary[k+3]=1;
				 break;
			
			}
		}

	}
//converting hexa to duble
void hexa_double(char *ch){
	int i,j;
	char str[64];
	hexa64_binary(ch);
	for(i=63,j=63;i>=0 && j>=0;i--,j--){
		char a = hex64binary[j] + '0';
		str[i] = a;
		}
		
		float a = binary_double(str);
		printf("%lf\n",a);
}

//converting float to binary
void float_binary(char *ch){
	int i,j;
	float a = Atof(ch);                          
	int x= a;
	float y = a-x;
    
	if(x<0){
		x = x*(-1);
		
	}else {
	   x=x;
    }
    int arr[32];
    for(i=0;i<32;i++){
		arr[i]=0;
		}
    i=0;
    while(x!=0){
	  int rem=x%2;
	  arr[i]= rem;
	  x=x/2;
	  i++;
      }
      int lenb = i;
    int arrb[lenb];
	for(j=0;j<lenb;j++){
		int p = arr[j];
		arrb[j] = p;
	}
	if(x==0){
		for(i=0;i<1;i++){
			arrb[i]=arr[i];
			}
		}
	int arr1[32];
	for(i=0;i<32;i++){
		arr1[i]=0;
		}
		
	i=0;
	while(y!=0.0){
	y = y*2;
	int q = y;
	arr1[i]=q;
	y = y-q;
	i++;	
	}
	int lenf =i;
	int arrf[lenf];
	for(j=0;j<lenf;j++){
	int q = arr1[j];
	arrf[j]=q;
	}
	int len_num = lenb+lenf;
	int arrnum[len_num];
	for(i=lenb-1,j=0;i>=0 && j<lenb;i--,j++){
		int q = arrb[i];
		arrnum[j] = q;
	}
	for(i=0,j=lenb;i<lenf && j<len_num;i++,j++){
		int q = arrf[i];
		arrnum[j] = q;
		}
	int expo = 127+lenb-1;
	int arrexpo[8];
	for(j=0;j<8;j++){
		arrexpo[j]=0;
	}
	int k=0;
	
    while(expo != 0){
        arrexpo[7-k] = expo%2;
        expo = expo/2;
        k++;
    }
   
    for(k=0;k<32;k++){
		floatbinary[k]=0;
	}
	for(k=1;k<9;k++){
		floatbinary[k] = arrexpo[k-1];
	}
	
	for(k=9,j=1 ; k<32 && j<len_num;k++,j++){
		floatbinary[k]=arrnum[j];
		}
		
	if(ch[0]=='-'){
		floatbinary[0]=1;
	}else{ 
	    floatbinary[0]=0;	
   }
   
}

//converting float to hexa
void float_hexa(char *ch){
	int i,j;
	char str[32];
	float_binary(ch);
	for(i=31,j=31;i>=0 && j>=0;i--,j--){
		char a = floatbinary[j] + '0';
		str[i] = a;
		}
		binary_hexa(str);
		
	}

//converting double to binary
void double_binary(char *ch){
	int i,j;
	float a = Atof(ch);
	int x= a;
	float y = a-x;
    
	if(x<0){
		x = x*(-1);
		
	}else {
	   x=x;
    }
    int arr[32];
    for(i=0;i<32;i++){
		arr[i]=0;
		}
    i=0;
    while(x!=0){
	  int rem=x%2;
	  arr[i]= rem;
	  x=x/2;
	  i++;
      }
      int lenb = i;
    int arrb[lenb];
	for(j=0;j<lenb;j++){
		int p = arr[j];
		arrb[j] = p;
	}
	if(x==0){
		for(i=0;i<1;i++){
			arrb[i]=arr[i];
			}
		}
	int arr1[32];
	for(i=0;i<32;i++){
		arr1[i]=0;
		}
		
	i=0;
	while(y!=0.0){
	y = y*2;
	int q = y;
	arr1[i]=q;
	y = y-q;
	i++;	
	}
	int lenf =i;
	int arrf[lenf];
	for(j=0;j<lenf;j++){
	int q = arr1[j];
	arrf[j]=q;
	}
	int len_num = lenb+lenf;
	int arrnum[len_num];
	for(i=lenb-1,j=0;i>=0 && j<lenb;i--,j++){
		int q = arrb[i];
		arrnum[j] = q;
	}
	for(i=0,j=lenb;i<lenf && j<len_num;i++,j++){
		int q = arrf[i];
		arrnum[j] = q;
		}
	int expo = 1023+lenb-1;
	int arrexpo[11];
	for(j=0;j<11;j++){
		arrexpo[j]=0;
	}
	int k=0;
	
    while(expo != 0){
        arrexpo[10-k] = expo%2;
        expo = expo/2;
        k++;
    }
   
    for(k=0;k<64;k++){
		doublebinary[k]=0;
	}
	for(k=1;k<12;k++){
		doublebinary[k] = arrexpo[k-1];
	}
	
	for(k=12,j=1 ; k<64 && j<len_num;k++,j++){
		doublebinary[k]=arrnum[j];
		}
		
	if(ch[0]=='-'){
		doublebinary[0]=1;
	}else{ 
	    doublebinary[0]=0;	
   }
   
}

//converting 64-bit binary to hexa
void binary64_hexa(char *ch){       
	int i;
	int x[64];
	int a = myStrlen(ch);                             
		for(i=0;i<a;i++){
		if(ch[i]=='0'){
			x[i]=0;
			}else{
				x[i]=1;
				}
			}
			fprintf(stdout,"0x");
		int k,j;
		for(k=0,j=0 ; k<=28 && j<=8 ; k+=4,j++){
		   if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			  hexa64[j]='0';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			   hexa64[j]='1';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			   hexa64[j]='2';
		  }if(x[k]==0 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			   hexa64[j]='3';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			   hexa64[j]='4';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			   hexa64[j]='5';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			   hexa64[j]='6';
		  }if(x[k]==0 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			   hexa64[j]='7';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==0){
			   hexa64[j]='8';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==0 && x[k+3]==1){
			  hexa64[j]='9';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==0){
			  hexa64[j]='A';
		  }if(x[k]==1 && x[k+1]==0 && x[k+2]==1 && x[k+3]==1){
			  hexa64[j]='B';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==0){
			  hexa64[j]='C';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==0 && x[k+3]==1){
			  hexa64[j]='D';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==0){
			  hexa64[j]='E';
		  }if(x[k]==1 && x[k+1]==1 && x[k+2]==1 && x[k+3]==1){
			  hexa64[j]='F';
		  }
		  }
   } 

void double_hexa(char *ch){
	int i,j;
	char str[64];
	double_binary(ch);
	for(i=63,j=63;i>=0 && j>=0;i--,j--){
		char a = doublebinary[j] + '0';
		str[i] = a;
		}
		binary64_hexa(str);
	}

