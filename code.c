#include <stdio.h>

void Add();
void print();
void printall();
void delete();


typedef struct _ {
	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;
}student_t;

student_t student_record[1000];
int count = 0;
char reg_no[8];
int r_no;

int main(){
	int task;
	
	do{
		printf("---------------------------------------------\n");
		printf("A VOLATILE STUDENT RECORD MAINTAINANCE SYSTEM\n");
		printf("---------------------------------------------\n");
		printf("0. Quit\n");
		printf("1. Insert a Student Record\n");
		printf("2. Print a Student Record\n");
		printf("3. print all Student Record\n");
		printf("4. Delete a Student Record\n");

	
	scanf("%d",&task);
		if(task == 0){
			//return 0;
		}else if(task == 1){
			Add();
		}else if(task == 2){
			printf("Enter the Registration number: ");
			scanf("%s",reg_no);
			print();
		}else if(task == 3){
		    printall();
		}else if(task == 4){
			delete();
		}
	}while(task!=0);
	return 0;
	}
	
void Add(){
	student_t student;
	
	printf("Enter the batch(11/12/13/14): ");
	scanf("%d",&student.batch);
	printf("Enter the registeration number: ");
	scanf("%d",&student.regNo);
	printf("Enter the first name: ");
	scanf("%s",student.firstName);
	printf("Enter the last name: ");
	scanf("%s",student.lastName);
	printf("Enter the GPA: ");
	scanf("%f",&student.cGPA);
	
	student_record[count] = student;
	count++;
	}
	
void print(){
	int j;
	int yr = (reg_no[2]-48)*10 + (reg_no[3]-48);
	int e_no = (reg_no[5]-48)*100 + (reg_no[6]-48)*10 + (reg_no[7]-48);

for(j=0;j<count;j++){
	   if(student_record[j].regNo == e_no && student_record[j].batch == yr){
		   printf("The student %s %s (E/%d/%d) has a cumulative GPA of %f",student_record[j].firstName,student_record[j].lastName,student_record[j].batch,student_record[j].regNo,student_record[j].cGPA);
			
	}
}
}

void printall(){
	int j;
for(j=0;j<count;j++){
	 printf("The student %s %s (E/%d/%d) has a cumulative GPA of %f\n",student_record[j].firstName,student_record[j].lastName,student_record[j].batch,student_record[j].regNo,student_record[j].cGPA);
	}
	}
	
void delete(){
	int j;
	printf("Enter the Registration number: ");
	scanf("%s",reg_no);
	int yr = (reg_no[2]-48)*10 + (reg_no[3]-48);
	int e_no = (reg_no[5]-48)*100 + (reg_no[6]-48)*10 + (reg_no[7]-48);

	for(j=0;j<count;j++){
		if(student_record[j].regNo == e_no && student_record[j].batch == yr){
			student_record[j] = student_record[j+1];
			}
		}
		count = count -1;
	}
