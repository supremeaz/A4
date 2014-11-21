#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char*  getPW(FILE* acc,char* username){
//Loop until eof, fgets each time. sscanf()to get username. clear buffer,strcmp
//Return NULL if username!=exist, else return the password string
	char* userInfo=malloc(200);//records the line for a user: username,password 
	char* waste=malloc(100);
	char* tempU=malloc(100);
	do{
		fgets(userInfo,200,acc);
		tempU=strtok(userInfo,",");
		printf("%s",tempU);
		if(strcmp(tempU,username)==0){
		//	printf("%s",strtok(userInfo,","));
			//return strtok(userInfo,",");//return the password
		}
		else waste=strtok(userInfo,",");//clear buffer
	}	
	while(!feof(acc));	//while 1.not end of file 2.line isn't null 3.line doesn't matc
	return NULL;
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
		free(tempPW);
	}
	else exit(EXIT_FAILURE);//still need error message-username not registered
	return strcmp(pw,password);
}
void verifySuccess(int result){
//Method takes in rsult of verification and act appropriately
	if(result==0){
		printf("The username and password matched!");
	}
	else printf("Your identification did not match, please try again");
}
int main(int argc, char* argv[]){
	//1-receive 2 strings from page
	//2-verify with verify method.
	//..
	/*-TESTS*/
	char *un1="username";
	char *pw1="password";
	int result=Verify(un1,pw1);//get result of verification
	verifySuccess(result);
	return 0;
}
