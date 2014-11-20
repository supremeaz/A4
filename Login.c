#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char*  getPW(FILE* acc,char* username){
//Loop until eof, fgets each time. sscanf()to get username. clear buffer,strcmp
//Return NULL if username!=exist, else return the password string
	char* t;
	return "";
}
int Verify(char* username, char* password){
//This method takes in username and password and verify them according to the .csv file
//finding name should be done by binary search
	FILE* accounts=fopen("./admins.csv","rt");
//need a function to read the textfile until the line with the given username, then return the password.
	//need to determine if username exists. If yes, return the line.
	//char* info=getUsr(accounts,username);//gets in a line user info
	
	char* pw;//Do not allow pw over 100 chars
	char* tempPW=getPW(accounts,username);
	if(tempPW!=NULL){//-the case the username is registered
		pw=malloc(100);
		strcpy(pw,tempPW);
		free(tempPW);
	}
	else exit(EXIT_FAILURE);//still need error message-username not registered
	return strcmp(pw,password);
}

int main(int argc, char* argv[]){
	//1-receive 2 strings from page
	//2-verify with verify method.
	//..


}
