#include <stdio.h>
#include <stdlib.h>

//function prototypes
void Add();
void print();
void printall();
void delete();

//create a structure (create new data type)
typedef struct _{
	int batch;
	int regNo;
	char firstName[20];
	char lastName[20];
	float cGPA;
	struct _* next;
}student_t;

char reg_no[8];
student_t * head  = NULL;


int main(){
	int task;
	// create UI
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
			return 0;        //for quit
		}else if(task == 1){
			Add();      //call add function
		}else if(task == 2){
			printf("Enter the Registration number: ");     //to take registration no from user which want to print
			scanf("%s",reg_no);
			print();     // call print function
		}else if(task == 3){
		     printall();   //call printall function
		}else if(task == 4){
			printf("Enter the Registration number: ");          //to take registration no from user which want to delete
			scanf("%s",reg_no);
			delete();    //call delete function
		}
	}while(task!=0);
	return 0;
	}


//add function
void Add(){

	  student_t * current;
	   current = (student_t*)malloc(sizeof(student_t));  //allocate memory for current

	//take student data from user
	printf("Enter the batch(11/12/13/14): ");
	scanf("%d",&current->batch);
	printf("Enter the registeration number: ");
	scanf("%d",&current->regNo);
	printf("Enter the first name: ");
	scanf("%s",current->firstName);
	printf("Ente r the last name: ");
	scanf("%s",current->lastName);
	printf("Enter the GPA: ");
	scanf("%f",&current->cGPA);

	current->next = head;     //assign head value to next of current object
	head = current;            // assign current to head

}

void print(){

   student_t * current1;

   //take batch and E number seperately
	int yr = (reg_no[2]-48)*10 + (reg_no[3]-48);
	int e_no = (reg_no[5]-48)*100 + (reg_no[6]-48)*10 + (reg_no[7]-48);
	//print student record
	for(current1= head ; current1 != NULL ; current1 = current1->next){
	   if(current1->regNo == e_no && current1->batch == yr){
		   printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %f\n",current1->firstName,current1->lastName,current1->batch,current1->regNo,current1->cGPA);
	}
   }
}

//print All function
void printall(){
	student_t * current1;
	// printing all data
	for(current1=head ; current1!=NULL ; current1 = current1->next){
	 printf("The student %s %s (E/%.2d/%.3d) has a cumulative GPA of %f\n",current1->firstName,current1->lastName,current1->batch,current1->regNo,current1->cGPA);
	}
}


//delete function
void delete(){
	student_t * temp;      //creating student_t type teobject
	student_t * current1;


	//take batch and E no separately
	int yr = (reg_no[2]-48)*10 + (reg_no[3]-48);
	int e_no = (reg_no[5]-48)*100 + (reg_no[6]-48)*10 + (reg_no[7]-48);

	current1 = head;
	if(current1 -> regNo == e_no && current1 -> batch == yr){   // delete the first node
			temp = current1 -> next;
			free(current1);
			head = temp;
    }
    else{

            temp = head;
            current1 = head -> next;

            while(current1 -> regNo != e_no && current1 -> batch != yr){
                current1 = current1 -> next;
                temp = temp -> next;
            }
            if(current1 -> next == NULL){   // delete the last node
                temp -> next = NULL;
                free(current1);
                current1 = temp;
            }
            else{
                temp -> next = current1 -> next;   // delete a middle node
                free(current1);
                temp = current1;
            }

    }

}
