#include<iostream>
#include<fstream>
using namespace std;
class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
};
void shopping::menu(){
	again:
	int choice;
	string email;
	string password;
	cout<<"\t\t\t\t\t........................................\n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t       Supermarket Main menu            \n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t                                        \n";
	cout<<"\t\t\t\t\t........................................\n";
	cout<<"\t\t\t| 1)  Admistrator |\n";
	cout<<"\t\t\t|                 |\n";
	cout<<"\t\t\t| 2)  Buyer       |\n";
	cout<<"\t\t\t|                 |\n";
	cout<<"\t\t\t| 2)  Exit        |\n";
	cout<<"\t\t\t|                 |\n";
	cout<<"\n\t\t\t\t Please select!\n";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"\t\t\t Please login \n";
			cout<<"Enter Email \n";
			cin>>email;
			cout<<"Enter password \n";
			cin>>password;
			if(email=="rafi@gmail.com" && password=="1234"){
				administrator();
			}else{
				cout<<"Invalid user name or password!\n";
			}
			break;
			case 2:
				{
				buyer();	
				}
				break;
			case 3:
				{
					exit(0);
				}
				break;
			default:
				{
					cout<<"Please select from the given options\n";
				}
	}
	goto again;
}
void shopping::buyer(){
	again:
	int choice;
	cout<<"\t\t\t   Buyer      \n";
	cout<<"................    \n";
	cout<<"                    \n";
	cout<<"\t\t\t 1)Buy product\n";
	cout<<"                    \n";
	cout<<"\t\t\t 2) Go Back   \n";
	cout<<"\t\t\t Enter your choice:\n";
	cin>>choice;
	switch(choice){
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid choice.\n";
	}
	goto again;
}
void shopping::administrator(){
	again:
	int choice;
	cout<<"\n\n\n\t\t\t\t Administrator menu\n";
	cout<<"\n\t\t\t |....1) Add the product....|\n";
	cout<<"\n\t\t\t |                          |\n";
	cout<<"\n\t\t\t |....2) Modify the product.|\n";
	cout<<"\n\t\t\t |                          |\n";
	cout<<"\n\t\t\t |....3) Delete the product.|\n";
	cout<<"\n\t\t\t |                          |\n";
	cout<<"\n\t\t\t |....4) Back to Main menu  |\n";
	cout<<"\n\n Please enter your choice\n";
	cin>>choice;
	switch(choice){
		case 1:
			add();
			break;
	    case 2:
			edit();
			break;
		case 3:	
	        rem();
	        break;
	    case 4:
	    	menu();
	    	break;
	    default:
	    	cout<<"invalid choice!\n";
		 
	}
	goto again;

}
void shopping::add(){
	again:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Add new product\n";
	cout<<"\n\n\t product code the product.\n";
	cin>>pcode;
	cout<<"\n\t Name of the product.\n";
	cin>>pname;
	cout<<"\n\n\t Price of the product.\n";
	cin>>price;
	cout<<"\n\n\t Discount on product.\n";
	cin>>dis;
	data.open("database.txt,ios::in");
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		}else{
			data>>c>>n>>p>>d;
			while(!data.eof()){
				if(c==pcode){
					token++;
				}
				cin>>c>>n>>p>>d;
			}
			data.close();
	
		if(token==1){
			goto again;
		}else{
			data.open("database.txt",ios::app|ios::out);
		    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		    data.close();
		}
	}
		cout<<"\n\n\t\t Record inseted.\n";
}
void shopping::edit(){
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float d;
	float p;
	string n;
	cout<<"\n\t\t\t Modify the  record.\n";
	cout<<"\n\t\t Product code :\n";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\nFile doesn't exist!.\n";
	}else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\n\t\t Product new code:\n";
				cin>>c;
				cout<<"\n\n\t\t Name of the product :\n";
				cin>>n;
				cout<<"\n\t\t\t Price:\n";
				cin>>p;
				cout<<"\n\t\t\t Discoutnt:\n";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<" "<<"\n";
				cout<<"\n\n\t\t Record edited.\n";
				
			}else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0){
			cout<<"\n\n\t Record not found.\n";
		}
	}
}
void shopping::rem(){
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product.\n";
	cout<<"Enter the product code :\n";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\t\t file doesn't exist\n";
	}else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey){
				cout<<"\n\n\t Prduct deleted successfully.\n";
				token++;
			}else{
				data1<<" "<<pcode<<" "<<pname<<""<<price<<" "<<dis<<"\n";		
	     	}
	     	data.clear();
	     	data1.close();
	     	remove("database.txt");
	     	rename("database.txt","database.txt");
	     	if(token==0){
	     		cout<<"\n\n Record not found.\n";
			 }
		}
	}
}
void shopping::list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|...........................................................\n";
	cout<<"ProdutNo\t\tName\t\t Proce\n";
	cout<<"\n\n|...........................................................\n";
	data>>pcode>>pname>>price>>dis;
	while(data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}
void shopping::receipt(){
	again:
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	cout<<"\n\n\t\t Receipt.\n";
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n Empty database\n";
	}else{
		data.close();
		list();
		cout<<"\n ...........................................\n";
		cout<<"\n                                            \n";
		cout<<"\n         Please place the order             \n";
		cout<<"\n                                            \n";
		cout<<"\n ...........................................\n";
		do{
			cout<<"\n\n Enter product code:\n";
			cin>>arrc[c];
			cout<<"\n\nEnter the quantity:\n";
			cin>>arrq[c];
			for(int i=0;i<c;i++){
				if(arrc[c]==arrc[i]){
					cout<<"\n\n Duplicate product code. Please try again.\n";
					goto again;
				}
			}
			c++;
			cout<<"\n\n Do you wanna buy another product?if yes press y else no\n";
			cin>>choice;
		}
		while(choice=='y');
		cout<<"\n\n\t\t ..............................Reciept ............................\n";
		cout<<"\n\nProduct No\t Product name \t product quantity\t price\tAmount\tAmount with discount\n";
		for(int i=0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof()){
				if(pcode==arrc[i]){
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<price<<"\t"<<amount<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
		
	}
	cout<<"\n\n...................................................\n";
	cout<<"\n total amount :"<<total;
	
}
int main(){
	shopping s;
	s.menu();
	
}
