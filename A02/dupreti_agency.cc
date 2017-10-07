#include <stdio.h>
#include <string>
#include <iostream>
#include "dupreti_player.h"
#include "dupreti_team.h"

using namespace std;

static Players arr[50];
static int player_count;
static int team_count;
static string team_names[30];

void add_team(struct Teams **pointer_to_head)
{	
	string strvar;
	
	cout<<endl<< "Adding team : ";
	struct Teams* new_team = (struct Teams*) malloc(sizeof(struct Teams));
	
	cout<<endl<<"Enter the name of Team : "<<endl;
	cin.ignore();
	getline(cin,strvar);
	new_team->team_name = strvar;
	team_names[team_count] = strvar;
	cout<<"Enter the city of the Team : "<<endl;
	cin.ignore();
	getline(cin,strvar);
	new_team->city = strvar;
	cout<<"Enter the name of stadium : "<<endl;
	cin.ignore();
	getline(cin,strvar);
	new_team->stadium = strvar;
	
	new_team->next_team = (*pointer_to_head);
	(*pointer_to_head) = new_team;
	
	cout<<new_team->team_name<<" created."<<endl;
}

struct PlayerNode * createPlayerNode(int i, string s)
{
	struct PlayerNode* new_player_node = (struct PlayerNode*) malloc(sizeof(struct PlayerNode));
	new_player_node->player_index = i;
	new_player_node->player_name = s;
	
	return new_player_node;
}

void deleteList(struct Teams** pointer_to_head)
{
   struct Teams* current = *pointer_to_head;
   struct Teams* next;
   struct PlayerNode * current_player_node;
   struct PlayerNode * pnext_player_node;
 
   while (current != NULL) 
   {	
       next = current->next_team;
       current_player_node = current->next_player_node;
       while(current_player_node != NULL)
       {  pnext_player_node = current_player_node->next_node;
       	  free(current_player_node);
       	  current_player_node = pnext_player_node;
       }
       free(current);
       current = next;
   }
   *pointer_to_head = NULL;
}

int add_player(struct Players *A)
{
  
    cout<<endl<<"Running program ....";
    string temp;
	int temp2;
	float temp3;
	cout<<"Creating Player..."<<endl;
	cout<<"Enter Player name : "<<endl;
	cin.ignore();
	getline(cin,temp);
	A->player_name = temp; 
	
	bool flag = 1;
	cout<<"Enter Player team : "<<endl;
	getline(cin,temp);
	for(int i=0; i<30; i++)
		{  if (team_names[i] == temp) { cout<<"Team names exists .."<<endl ;flag = 0; break; }
		   else { continue; }
		}
	if (flag == 1) {cout<<"The provided team is not yet created, please create team first."<<endl;
					cout<<"Returning to main menu..."<<endl;
					return 0;}	
	A->player_team = temp;
	
	flag = 1;
	while(flag){
	cout<<"Enter Unique ID : "<<endl;
	cin>>temp2;
	for(int i=0; i<50; i++)
		{  if (arr[i].unique_id == temp2) { cout<<"Not Unique ID, please enter another."<<endl; flag = 0; break; }
		   else { continue; }
		}
	if (flag == 0) { flag = 1;}
	else { flag = 0; }			}
	A->unique_id = temp2;
	
	cin.ignore();
	flag = 1;
	while(flag){
	cout<<"Enter Phone number (Don't use special characters -,#,% .. ): "<<endl;
	cin>>temp;
	for(int i=0; i<50; i++)
		{  if (arr[i].unique_phone_number == temp) { cout<<"Not unique phone number, please enter another."<<endl; flag = 0; break; }
		   else { continue; }
		}
	if (flag == 0) { flag = 1;}
	else { flag = 0; }			}
	A->unique_phone_number = temp;
	
	cout<<"Enter Position : "<<endl;
	cin>>temp;
	A->position = temp;
	cout<<"Enter Address : "<<endl;
	cin>>temp;
	A->address = temp;
	cout<<"Enter Salary : "<<endl;
	cin>>temp3;
	A->salary = temp3;
  
    player_count++;
    cout<<"Player created."<<endl;
    return 1;
  
}

void find_player(int count)
{
	int found = 0;
	char par;
	string input_str;
	int input_num;
	cout<<"Which parameter do you want to use for finding player(Enter 1,2 or 3): "<<endl<<"1. Name"<<endl<<"2. ID Number"<<endl<<"3. Phone Number"<<endl;
	cin>>par;
	switch(par){
    case '1':
      cout << "Enter name : ";
      cin.ignore();
      getline(cin,input_str);
      for (int i = 0; i < count; i++)
	  { if (arr[i].player_name.find(input_str) != std::string::npos) { cout<< " Found : Index - " << i << " Name : " << arr[i].player_name<<" Team : "<<arr[i].player_team<<endl; found++;} }
      break;
    case '2':
      cout << "Enter unique ID : ";
      cin >> input_num;
      for (int i = 0; i < count; i++)
	  { if (arr[i].unique_id == input_num) { cout<< "Found : Index - " << i << " Name : " << arr[i].player_name<<endl; found++; break; } }
      break;
    case '3':
      cout << "Enter phone number : ";
      cin >> input_str;
      for (int i = 0; i < count; i++)
	  { if (arr[i].unique_phone_number == input_str) { cout<< "Found : Index - " << i << " Name : " << arr[i].player_name<<endl; found++; break; } }
      break;
    default:
      cout << "INVALID INPUT!!, Please provide 1,2 or 3" << "\n";
	}
	if (found == 0) { cout<< "No matches found!! ";}

}

int display_team(string name)
{	
	bool flag = 1;
	for(int i=0; i<30; i++)
		{  if (team_names[i] == name) { cout<<"Team names exists .."<<endl ;flag = 0; break; }
		   else { continue; }
		}
	if (flag == 1) {cout<<"The provided team is not yet created, please create team first."<<endl;
					cout<<"Returning to main menu..."<<endl;
					return 0;}	
  	
  	for(int i = 0; i< player_count; i++){
		if (arr[i].player_team == name)
		{ cout<<"Player Found : "<<arr[i].player_name<<" | Team : "<<name<<endl;	}
										}  
	return 1;
}

int players_to_team(struct Teams **pointer_to_head)
{	
	struct Teams *current_team;
	current_team = *pointer_to_head;
	string name;
	string s;
	struct PlayerNode * prev;
  	struct PlayerNode * next;
  	struct PlayerNode * current_node;
  	
	for (int j=0; j<team_count; j++)
	{
		name = current_team->team_name;
		for(int i = 0; i < player_count; i++)
		{
			if (arr[i].player_team == name)
				{ 	cout<<"Pointers Linking..."<<endl;
				  	s = arr[i].player_name;
		  			prev = createPlayerNode(i,s); //a
		  			next = current_team->next_player_node;
		  			current_team->next_player_node = prev;
		  			prev->next_node = next;	
		  			current_team->team_player_count++;
		  			cout<<current_team->next_player_node->player_index<<" | "<<arr[i].player_name<<" | "<<current_team->team_name<<endl;
				}
		}
		cout<<"Printing Generated Player Linked List for Team "<<current_team->team_name<<" : "<<endl;
		current_node = current_team->next_player_node;
		for (int i=0;i<current_team->team_player_count; i++)
		{
			cout<<"Index : "<<current_node->player_index<<" | Name : "<<current_node->player_name<<" | Team : "<<current_team->team_name<<endl;
			current_node = current_node->next_node;
		}
		cout<<"Number of players in team : "<<current_team->team_player_count<<endl;
		
		current_team = current_team->next_team;
	}
	
 	return 0;
  }


void update(struct Teams **pointer_to_head)
{
	struct Teams *current_team;
	current_team = *pointer_to_head;
	struct PlayerNode * temp;
  	struct PlayerNode * current_node;
  	while(current_team != NULL)
	{
		current_node = current_team->next_player_node;
		for (int i=0;i<current_team->team_player_count; i++)
		{   temp = current_node->next_node;
			free(current_node);
			current_node = temp;
		}
		current_team->team_player_count = 0 ;
		current_team = current_team->next_team;
	}		
}  

void printplayerArray()
{ for(int i = 0; i<player_count;i++)
	{
		cout<<"Index : "<<i<<" | Player: "<<arr[i].player_name<<" | ID : "<<arr[i].unique_id<<" | Phone : "<<arr[i].unique_phone_number<<" | Team: "<<arr[i].player_team<<endl;
	}
}

void swap(struct Players *A, struct Players *B)
{
	struct Players C = *A;
	*A = *B;
	*B = C;
}

void sortPlayers()
{   char par;
	cout<<"Which parameter do you want to use for sorting players(Enter 1,2 or 3): "<<endl<<"1. Name"<<endl<<"2. ID Number"<<endl<<"3. Phone Number"<<endl;
	cin>>par;
	switch(par){
    case '1':
      cout<<"SORTED BY NAME : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_name>arr[j+1].player_name){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();		
      break;
    case '2':
      cout<<"SORTED BY ID : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_id<arr[j+1].unique_id){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
      break;
    case '3':
      cout<<"SORTED BY PHONE : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_phone_number<arr[j+1].unique_phone_number){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
      break;
    default:
      cout << "INVALID INPUT!!, Please provide 1,2 or 3" << "\n";
	}
}

void sortPlayersbyTeam()
{   char par;
    for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_team>arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
	cout<<"Which parameter do you want to use for sorting players(Enter 1,2 or 3): "<<endl<<"1. Name"<<endl<<"2. ID Number"<<endl<<"3. Phone Number"<<endl;
	cin>>par;
	
	switch(par){
    case '1':
      cout<<"SORTED TEAMWISE BY NAME : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_name>arr[j+1].player_name && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();		
      break;
    case '2':
      cout<<"SORTED TEAMWISE BY ID : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_id<arr[j+1].unique_id && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
      break;
    case '3':
      cout<<"SORTED TEAMWISE BY PHONE : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_phone_number<arr[j+1].unique_phone_number && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
      break;
    default:
      cout << "INVALID INPUT!!, Please provide 1,2 or 3" << "\n";
	}
}

void add_team_test1(struct Teams **pointer_to_head)
{	
	string strvar;
	strvar = "Yankees";
	cout<<endl<< "Adding team : ";
	struct Teams* new_team = (struct Teams*) malloc(sizeof(struct Teams));
	
	new_team->team_name = strvar;
	team_names[team_count] = strvar;
	strvar = "New York";
	new_team->city = strvar;
	strvar = "Yankee Stadium";
	new_team->stadium = strvar;
	
	new_team->next_team = (*pointer_to_head);
	(*pointer_to_head) = new_team;
	
	cout<<new_team->team_name<<" created."<<endl;
}

void add_team_test2(struct Teams **pointer_to_head)
{	
	string strvar;
	strvar = "San Diego Padres";
	cout<<endl<< "Adding team : ";
	struct Teams* new_team = (struct Teams*) malloc(sizeof(struct Teams));
	
	new_team->team_name = strvar;
	team_names[team_count] = strvar;
	strvar = "San Diego";
	new_team->city = strvar;
	strvar = "Petco Park";
	new_team->stadium = strvar;
	
	new_team->next_team = (*pointer_to_head);
	(*pointer_to_head) = new_team;
	
	cout<<new_team->team_name<<" created."<<endl;
}

int add_player_test1(struct Players *A)
{   string temp;
	int temp2;
	float temp3;
	cout<<"Creating Player..."<<endl;
	temp = "Devin Upreti";
	A->player_name = temp; 
	temp = "Yankees";
	A->player_team = temp;
	temp2 = 1;
	A->unique_id = temp2;
	
	temp = "8126922128";
	A->unique_phone_number = temp;
	temp = "Pitcher";
	A->position = temp;
	temp = "Syracuse, NY";
	A->address = temp;
	temp3 = 1000.101;
	A->salary = temp3;
    player_count++;
    cout<<"Player created -> Devin"<<endl;
    return 1; 
}

int add_player_test2(struct Players *A)
{   string temp;
	int temp2;
	float temp3;
	cout<<"Creating Player..."<<endl;
	temp = "Wil Myers";
	A->player_name = temp; 
	temp = "San Diego Padres";
	A->player_team = temp;
	temp2 = 2;
	A->unique_id = temp2;
	
	temp = "9126927864";
	A->unique_phone_number = temp;
	temp = "Infielder";
	A->position = temp;
	temp = "San Diego, CA";
	A->address = temp;
	temp3 = 2200.101;
	A->salary = temp3;
    player_count++;
    cout<<"Player created -> Wil"<<endl;
    return 1; 
}

int add_player_test3(struct Players *A)
{   string temp;
	int temp2;
	float temp3;
	cout<<"Creating Player..."<<endl;
	temp = "Austin Hedges";
	A->player_name = temp; 
	temp = "San Diego Padres";
	A->player_team = temp;
	temp2 = 3;
	A->unique_id = temp2;
	
	temp = "9174387864";
	A->unique_phone_number = temp;
	temp = "Catcher";
	A->position = temp;
	temp = "San Diego, CA";
	A->address = temp;
	temp3 = 2800.11;
	A->salary = temp3;
    player_count++;
    cout<<"Player created -> Austin"<<endl;
    return 1; 
}

void sortPlayers_test()
{     cout<<"SORTED BY NAME : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_name>arr[j+1].player_name){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();		
      cout<<"SORTED BY ID : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_id<arr[j+1].unique_id){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
      cout<<"SORTED BY PHONE : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_phone_number<arr[j+1].unique_phone_number){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
}

void sortPlayersbyTeam_test()
{ 
    for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_team>arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
	 cout<<"SORTED TEAMWISE BY NAME : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].player_name>arr[j+1].player_name && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();		
      cout<<"SORTED TEAMWISE BY ID : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_id<arr[j+1].unique_id && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
    cout<<"SORTED TEAMWISE BY PHONE : "<<endl;
      for (int i = 0; i < player_count; i++)
	  	{ 	for (int j =0; j< player_count-i-1; j++)
	  			{ if(arr[j].unique_phone_number<arr[j+1].unique_phone_number && arr[j].player_team == arr[j+1].player_team){ swap(arr[j],arr[j+1]); }
	  			}
         }
       printplayerArray();
     
}

int players_to_team_test(struct Teams **pointer_to_head)
{	
	struct Teams *current_team;
	current_team = *pointer_to_head;
	string name;
	string s;
	struct PlayerNode * prev;
  	struct PlayerNode * next;
  	struct PlayerNode * current_node;
  	
	for (int j=0; j<team_count; j++)
	{
		name = current_team->team_name;
		for(int i = 0; i < player_count; i++)
		{
			if (arr[i].player_team == name)
				{ 	cout<<"Pointers Linking..."<<endl;
				  	s = arr[i].player_name;
		  			prev = createPlayerNode(i,s); //a
		  			next = current_team->next_player_node;
		  			current_team->next_player_node = prev;
		  			prev->next_node = next;	
		  			current_team->team_player_count++;
		  			cout<<current_team->next_player_node->player_index<<" | "<<arr[i].player_name<<" | "<<current_team->team_name<<endl;
				}
		}
		cout<<endl<<endl;
		cout<<"Printing Generated Player Linked List for Team "<<current_team->team_name<<" : "<<endl;
		current_node = current_team->next_player_node;
		for (int i=0;i<current_team->team_player_count; i++)
		{
			cout<<"Index : "<<current_node->player_index<<" | Name : "<<current_node->player_name<<" | Team : "<<current_team->team_name<<endl;
			current_node = current_node->next_node;
		}
		cout<<"Number of players in team : "<<current_team->team_player_count<<endl;
		current_team = current_team->next_team;
	}
	
 	return 0;
  }



void test()
{ struct Players *A;
  A = arr;
  int a;
  struct Teams * head;

  add_team_test1(&head);
  team_count++;
  add_team_test2(&head);
  team_count++;
  a = add_player_test1(A);
  if (a ==1 ){A++;}
  a = add_player_test2(A);
  if (a ==1 ){A++;}
  a = add_player_test3(A);
  if (a ==1 ){A++;}
  cout<<endl<<"Displaying Teams : "<<endl;
  cout<<endl<<endl;
  display_team("San Diego Padres");
  cout<<endl<<endl;
  display_team("Yankees");
  cout<<endl<<endl;
  cout<<endl<<"Generating Player Linked List from Teams..."<<endl;
  players_to_team_test(&head);
  cout<<endl<<endl;
  sortPlayers_test();
  cout<<"Team Linked List modified, generate Team Linked List to see new."<<endl;
  cout<<endl<<endl;
  sortPlayersbyTeam_test();
  cout<<"Team Linked List modified, generate Team Linked List to see new."<<endl;
  cout<<"Printing array of Players : "<<endl;
  cout<<endl<<endl;
  printplayerArray();
  
  cout<<endl<<endl;
  cout<<"Player Count: "<<player_count<<endl;
  cout<<"Team Count: "<<team_count<<endl;
  cout<<"EXITING PROGRAM...."<<endl;
  deleteList(&head);
  cout<<"List Deleted"<<endl;
  
  
}

int main()
{ 
  struct Players *A;
  A = arr;

  struct Teams * head;
  
  int a;
  bool flag = 1;
  char x;
  string y;
  do{
  
  cout<<"Options(Press 1 or 2 or 3....) : "<<endl<<"1. Add Team"<<endl<<"2. Add Players"<<endl<<"3. Display Team Players"<<endl<<"4. Find Player"<<endl;
  cout<<"5. Generate Player Linked List from Teams"<<endl<<"6. Sort All Players"<<endl<<"7. Sort Players by Team"<<endl<<"8. Print all players."<<endl<<"9. Run Test Function."<<endl<<"0. Exit"<<endl;
  cin>>x;
  
  switch(x){
  	
  	case '1':
      add_team(&head);
      team_count++;
      cout<<head->team_name<<" in Linked List ^.^ "<<endl;
      break;
    case '2':
      a = add_player(A);
      if (a ==1 ){A++;} 
      break;
    case '3':
      cout<<"Enter the team name : "<<endl;
      cin.ignore();
      getline(cin, y);
      display_team(y);
      break;
    case '4':
      find_player(player_count);
      break;
    case '5':
      players_to_team(&head);
      break;
    case '6':
      sortPlayers();
      update(&head);
      cout<<"Team Linked List modified, generate Team Linked List to see new."<<endl;
      break;
    case '7':
      sortPlayersbyTeam();
      update(&head);
      cout<<"Team Linked List modified, generate Team Linked List to see new."<<endl;
      break;    
    case '8':
      printplayerArray();
      break;
    case '9':
      test();
      break;   
    case '0':
      flag = 0;
      break;
    default:
      cout << "INVALID INPUT!!, Please provide 1,2 or 3" << "\n";
	}
	cin.clear();
	cin.ignore();
	
	cout<<endl<<"Do you want to perform another operation (Y or N)? Pressing N will exit program.";
  	cin>>y;
  
  	if( y== "Y" || y == "y")
  	{  }
  	else if ( y== "N" || y == "n" )
  	{	flag = 0; }
  	else
  	{ cout<<endl<< "Not valid input"<<endl; }
	
	cin.clear();
	cin.ignore();
	
  } while(flag);
  
  cout<<endl<<endl;
  cout<<"Player Count: "<<player_count<<endl;
  cout<<"Team Count: "<<team_count<<endl;
  
  deleteList(&head);
  cout<<"List Deleted"<<endl;
  
  
  return 0;
}
