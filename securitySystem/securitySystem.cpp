#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;
 
int main(){
	int a,i=0;
	string txt, old, password1, password2, pass, name, password0, age, user, word,word1;
	string creds[2], cp[2];
	cout<<"      Security Seystem     "<<endl;
	cout<<" .........................."<<endl<<endl;
	cout<<"|       1. Register        |"<<endl;
	cout<<"|       2. Login           |"<<endl;
	cout<<"|       3. Change pasword  |"<<endl;
	cout<<"|.......4. End program.....|"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice:-\n";
		cin>>a;
		switch(a){
			
			case 1:{
				cout<<"......................................\n\n";
				cout<<"|............Register..................|\n\n";
				cout<<"|......................................|\n\n";
				cout<<"Please enter the username:-\n";
				cin>>name;
				cout<<"Please enter the password:-\n";
				cin>>password0;
				cout<<"Please enter your age:-\n";
				cin>>age;
				
				ofstream of1;
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"Registration successfull."<<endl;
				}
				break;
			}
			case 2:{
				i=0;
				cout<<"......................................\n\n";
				cout<<"|............Register..................|\n\n";
				cout<<"|......................................|\n\n";
				ifstream of2;
				of2.open("file.txt");
				cout<<"Please enter the username:-\n";
				cin>>user;
				cout<<"Please enter the password:-\n";
				cin>>pass;
				if(of2.is_open()){
					while(!of2.eof()) {
						while(getline(of2, txt)) {
							istringstream iss(txt);
							iss>>word;
							creds[i]=word;
							i++;
						}
						if(user==creds[0] && pass==creds[1]) {
							cout<<"----log in successful---\n\n\n";
							cout<<"  Details: "<<endl;
							cout<<"UserName: "+ name<<endl;
							cout<<"Password: "+pass<<endl;
							cout<<"Age:"+ age<<endl;
						}else{
							cout<<"\n\n\n";
							cout<<"Incorrect Creddentials"<<endl;
							cout<<"|      1. Press 2 to login                |"<<endl;
							cout<<"|      2. Press 3 to Change the password  |"<<endl;
							break;
						}
						
						
 					}
				}
			}
				break;
				case 3:{
					i=0;
					ifstream of0;
					of0.open("file.txt");
					cout<<"Enter the old password.\n";
					cin>>old;
					if(of0.is_open()){
						while(of0.is_eof()){
							while(getline(of0, text)){
								istringstream iss(text);
								iss>>word1;
								cp[i]=word1;
								i++;
							}
							if(old==cp[1]){
								of0.close();
								ofstream of1;
								if(of1.is_open()){
									cout<<"Enter your new password:-\n";
									cin>>password1;
									cout<<"Enter you password again:-\n";
									cin>>password2;
									if(password1==password2){
										of1.<<cp[0]<<"\n";
										of1<<password1;
										cout<<"Password changed successfully.\n";
									}else{
										of1<<cp[0]<<"\n";
										of1<<old;
										cout<<"Passwoed do not match.\n";
									}
								}
							}else{
								cout<<"Please enter a valid password:-\n";
								break;
							}
						}
					}
					
					cout<<"...................Change password................\n";
					
					ifstream
					
					break;
				}
				case 4:{
					cout<<"..............Thank you !................\n";
					break;
				}
				default:
					cout<<"Enter a valid choice.\n";
			}
		}
	}while(a!=4);
	
	
	return 0;
}

