#include <stdio.h>
#include <string.h>

// tydef = reserved keyword that gives an exisiting a "nickname"

//typedef char user[25];

typedef struct{
	char name[25];
	char password[12];
	int id;
}User, Username;


int main(){
	
	//user user1 = "Bro";
	
	// struct User user2 = {
	//	"Bru",
	// 	"password123",
	// 	432525
	// };
	
	User user3 = {
		"Bri",
		"Password245",
		4325256
	};
	
	Username user4 = {
		"Bra",
		"passwordf54",
		8244214
	};
	
	return 0;
};
