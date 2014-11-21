#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char*  getPW(FILE* acc,char* username){
//Loop until eof, fgets each time. sscanf()to get username. clear buffer,strcmp
//Return NULL if username!=exist, else return the password string
	char* userInfo=malloc(200);//records the line for a user: username,password 
	//char* waste=malloc(100);
	char* tempU=malloc(100);
	char* tempP=malloc(100);
	char* pReturn=malloc(100);
	do{
		fgets(userInfo,200,acc);
		tempU=strtok(userInfo,",");
		tempP=strtok(NULL,",");
		tempP=strtok(tempP,"\n");//get rid of the \n at the end of password
		//printf("%d",strcmp(tempU,username));
	/*	if(strcmp(tempU,username)==0){
			strcpy(pReturn,tempP);
			break;
		}*/
	}	
	while(!feof(acc)&&strcmp(tempU,username)!=0);	//while 1.not end of file 2.line isn't null 3.line doesn't matc
	return tempP;
}
int Verify(char* username, char* password){
//This method takes in username and password and verify them according to the .csv file
//finding name should be done by binary search
	FILE* accounts=fopen("./admins.csv","rt");
//need a function to read the textfile until the line with the given username, then return the password.
	//need to determine if username exists. If yes, return the line.
	//char* info=getUsr(accounts,username);//gets in a line user info
	
	char* pw;//Do not allow pw over 100 chars
	char* tempPW=malloc(100);
	tempPW=getPW(accounts,username);
	if(tempPW!=NULL){//-the case the username is registered
		pw=malloc(100);
		strcpy(pw,tempPW);
	}
	else exit(EXIT_FAILURE);//still need error message-username not registered
	return strcmp(pw,password);
}
void verifySuccess(int result){
//Method takes in rsult of verification and act appropriately
	if(result==0){
		printf("The username and password matched!\n");
	}
	else printf("Your identification did not match, please try again\n");
}
int main(int argc, char* argv[]){
	//1-receive 2 strings from page
	//2-verify with verify method.
	//..
	/*-TESTS*/
	char *un1="username";
	char *pw1="password";
	char *un2="arthur";
	char *pw2="1zhao";
	int result=Verify(un2,pw2);//get result of verification
	verifySuccess(result);
	return 0;
}
