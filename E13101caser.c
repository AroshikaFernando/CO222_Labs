#include <stdio.h>
#include <stdlib.h>

//prototyping functions
int rotateright(int ch);
int rotateleft(int ch);
int encode(int ch,int shift);

int main(){
	
	int shift;
	int ch=0;
	char text[200];             //declaring array size of 200
	printf("Enter shift: ");
	scanf("%d",&shift);
	printf("Enter text: \n");
	int i=0;
	while(ch!= -1){
		ch= getchar();
		text[i]=ch;         //get ASCII value of the charater into array text
		i++;
	}
	printf("\nHere is the encoded text: ");
	int a =i-1;
	for(i=0;i<a;i++){
	if((text[i]>='A' && text[i]<='Z') || (text[i]>='a' && text[i]<='z')){       //checking charachters within this range(only letters)
		if(shift != 0){
			text[i]=encode(text[i],shift);              //calling encode function
			}
		}
		printf("%c",text[i]);                           //printing text
}
	printf("\n");
	return 0;
	}
	
// creating rotateright function	
int rotateright(int ch){
	if((ch>=65&& ch<90) || (ch>=97 && ch<122)){       //checking   letters without 'A' and 'a'
		ch = ch+1;
	}else if(ch==90){                                 //checking character 'A'
		ch='A';
	}else{
		ch='a';                                       //checking character 'a'
		}
	return ch;
}

//creating rotateleft function
int rotateleft(int ch){
	if((ch>65&& ch<=90) || (ch>97 && ch<=122)){       //checking letters without 'Z' and 'z'
		ch = ch-1;
	}else if(ch==65){                                 //checking character 'Z'
		ch='Z';
	}else{
		ch='z';                                       //checking character 'z'
		}
	return ch;
	}
	
//creating encode function	
int encode(int ch,int shift){
	int i=0;
	if(shift>0){                                     //checking only positive shift numbers
	for(i=0;i<shift;i++){
		ch=rotateright(ch);                          //calling rotateright function
		}
	}else{
	  for(i=0;i>shift;i--){                          //checking negative shift numbers
		ch=rotateleft(ch);                           //calling rotateleft function
		}
	}
	return ch;
}
