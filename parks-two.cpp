#include<bits/stdc++.h>
using namespace std;
#define e endl
const int M=8,N=6;
struct park {
	char event='.'; //# , _ ;
	string number, vaqt;
} PARKS[N][M];
void openParks();       //start uchun .
void switchMenu(int x); // menyu tanlanganda .
void errShow(string s="KECHRASIZ QAYTA URNAB KO'RING");  //xatolik uchun .
void addAuto();     //add auto 
void deletAuto();  //delete auto 
void clearConsole(int t);  // clear console 
void closeParks();  //close parks 
void printPark(); //print parks 
void createParks(); // create parks 
void infoAuto(); //info auto 

int main(){
	 createParks();
	 openParks();//start program
	 exit: return 0;
}

void  openParks(){
    int x;
    cout<<"___________________________________________"<<e;
    cout<<"_________________OPEN PARKS________________"<<e;
    cout<<"___________________________________________"<<e;
    cout<<e<<e<<"MENU:"<<e<<e;
	cout<<"ADD AUTO    (1)"<<e;
	cout<<"DELETE AUTO (2)"<<e;
	cout<<"INFO   AUTO (3)"<<e;
	cout<<"CLOSE PARKS (4)"<<e<<e;
	printPark();
	cout<<e<<e<<"choose menu: ";
	cin>>x;
	switchMenu(x);
}

void clearConsole(int t){
	time_t S=time(0),F=time(0);
	while(S+t>=F) F=time(0); 	//while t minuit ....
	system("cls");         //clear console
	openParks();     //get menu 
}

void switchMenu(int x){	
	switch(x){
		case 1: addAuto();   break;
		case 2: deletAuto(); break;
		case 3: infoAuto();   break;
		case 4: closeParks();   break;
		default: errShow();
	}
}

void errShow(string s){
	cout<<"--------------------------------"<<e;
    cout<<s<<e;
    clearConsole(3);
}

void addAuto(){
     int row,col;
	 system("cls");
	 printPark();
	 cout<<e<<e<<"Line add row,col: ";
	 cin>>row>>col;
	 row--; col--;
	 if(row%2==0 &&  row>=0 && row<=N && col>=0 && col<=M){
	 	  if(PARKS[row][col].event=='#'){
		    errShow("Bu yer mashina bor og'ayini.");
		    }
	   	 else{
		     string num ;
		     cout<<"Mashina raqamni kirting:";
		     cin>>num; 
		     PARKS[row][col].event='#';
		     PARKS[row][col].number=num;
		     time_t seconds;
             time(&seconds);
             stringstream ss;
             ss << seconds;
             PARKS[row][col].vaqt=ss.str();
		     clearConsole(2);
	    	}
    	}
	 else {
	      errShow("Bu yer yo'lak.");
	 }
}

void deletAuto(){
     int row,col;
	 system("cls");
	 printPark();
	 cout<<e<<e<<"Line delete row,col: ";
	 cin>>row>>col;
	 row--; col--;
	 if(row%2==0 &&  row>=0 && row<=N && col>=0 && col<=M){
	 	   PARKS[row][col].event='.'; 
		   errShow("Bu yerdan mashina olip tashlandi.");
		   } else {
	       errShow("Bu yer yo'lak.");
	 }
}

void closeParks(){
   system("cls");
}

void createParks(){
	  for(int i=1;i<N;i+=2)
	  for(int j=0;j<M;j++)  PARKS[i][j].event='_';
}

void printPark(){
   	 cout<<" ";
   	 for(int j=0;j<M;j++) cout<<" "<<j+1;
	 for(int i=0;i<N;i++){
	  cout<<e<<i+1<<" ";
	  for(int j=0;j<M;j++)
	 	 cout<<PARKS[i][j].event<<" ";
	 }
}

void infoAuto(){
	 int row,col;
	 system("cls");
	 printPark();
	 cout<<e<<e<<"Line info row,col: ";
	 cin>>row>>col;
	 row--; col--;
	 if(row%2==0 &&  row>=0 && row<=N && col>=0 && col<=M && PARKS[row][col].event=='#'){
		      system("cls");
		      cout<<"Row,Col: "<<row+1<<" "<<col+1<<e;
		      cout<<"Number auto: "<<PARKS[row][col].number<<e;
		      cout<<"Add auto time: "<<PARKS[row][col].vaqt<<e;
		      clearConsole(10);
			  return ;
		}	 
	errShow("Bu yer mashina bor og'ayini.");	
}




