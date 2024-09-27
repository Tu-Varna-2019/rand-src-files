#include<iostream>
#include<string>
using namespace std;

class CPerson {
	string name,egn,gender;
public:
	
		CPerson(const string& nname,const string& eegn,const string& ggender) : name(nname),egn(eegn),gender(ggender) {}
		CPerson() { name="N/A";egn="unknown";gender="unknown";}
		CPerson(const CPerson& pers) : name(pers.name),egn(pers.egn),gender(pers.gender){}
	ostream& Output(ostream& os)const;
};

ostream& CPerson::Output(ostream& os) const { // DM 
	os<<"\nName: "<<name<<"\nEgn: "<<egn<<"\nGender: "<<gender;
	return os;
}


class CAdress {
	string street,pcode,town;
public:
	void SetStreet( const string& str) { street=str;}
	const string& GetStreet() const { return street;}
	const string& GetPCode() const { return pcode;}
	const string& GetTown() const { return town;}

	CAdress() : street("STUDENTSKA #1"),pcode("9040"),town("Varna") {}

	CAdress(const string& st,const string& pc,const string& to="Varna") : street(st),pcode(pc),town(to) {}
	CAdress(const CAdress& obj) : street(obj.street),pcode(obj.pcode),town(obj.town) {}//copy constructor
	ostream& Output(ostream& os)const;
};

ostream& CAdress::Output(ostream& os)const {
	os<<"\nStreet: "<<street<<endl<<"Postal code: "<<pcode<<endl<<"Town: "<<town<<endl;
		return os;
}

class CStudent:public CPerson {

	CPerson info;
	string fn;
	CAdress addr;
public:
	

	CStudent(const string& name,const string& egn,const string& gend,const string& ffn,const CAdress& adr): info(CPerson(name,egn,gend)),fn(ffn),addr(adr){}//with facility num

	CStudent(const string& name,const string& egn,const string& gend,const CAdress& adr): CPerson(name,egn,gend),addr(adr){}//without facility num
	
	CStudent(const CStudent& st) :info(st.info), fn("8888"),addr(st.addr){}
	CStudent() : CPerson() , fn("8888") {}
	ostream& Output(ostream& os) const {
		
		info.Output(cout); //DM Cperson output
		cout<<"\nFacility number: "<<fn;
		addr.Output(cout);
		return os;
	}

};




int main() 
{
	CAdress addr1,addr2("Ivan Vazov1","1234","Sofia"),
	addr3("Vl.Varnenchik48","9000"),addr4(addr2);
	cout<<"Adress 1: \n";addr1.Output(cout);
	cout<<"------------------------------\n\nAdress 2: \n";
	addr2.Output(cout);
	cout<<"-------------------------------\n\nAdress 3: \n";
	addr3.Output(cout);
	cout<<"--------------------------------\n\nAdress 4: \n";
	addr4.Output(cout);

	CStudent ivan("Ivan","male","0041234","19621212",addr2),pesho(ivan);
	cout<<"---------------------------------\n\nIvan info: \n";ivan.Output(cout);
	cout<<"---------------------------------\n\nPesho info: \n";pesho.Output(cout);
	cout<<endl;system("pause");
	return 0;
}