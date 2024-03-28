#include<bits/stdc++.h>
using namespace std;
struct T{
	float x[100];
	bool nhan;
};
//---------------------------------
int n=14;//sample cua training
int m=1; //sample cua test
int feature=4;//cot cua test and train
//---------------------------------
		T a[100];
		T b[100];
void nhap(){
		ifstream ip("training_set.txt");//dia chi file training dataset
		
		for(int i=0;i<n;i++){
			ip>>a[i].x[0]>>a[i].x[1]>>a[i].x[2]>>a[i].x[3]>>a[i].nhan;
		}
		ip.close();
		
		ifstream ip1("test_set.txt");
		for(int i=0;i<m;i++){
			ip1>>b[i].x[0]>>b[i].x[1]>>b[i].x[2]>>b[i].x[3];
		}
		ip1.close();
}
main(){
    
	nhap();
	
	float yes,no;
	int county,countn;
	int demYes[100],demNo[100];
	
	for(int i=0;i<feature;i++){
			demYes[i]=demNo[i]=0;
	}
		
	for(int k=0;k<m;k++){
			
			yes=1;no=1;
			
			county=0;countn=0;
		for(int i=0;i<n;i++)	//duyet data training
		{
			for(int j=0;j<feature;j++)	//duyet thuoc tinh
			{
				if(a[i].x[j]==b[k].x[j] && a[i].nhan==1) demYes[j]++;	//dem yes
				if(a[i].x[j]==b[k].x[j] && a[i].nhan==0) demNo[j]++;	//dem no
			}
			if(a[i].nhan==1) county++;
			else countn++;
		}
		
		for(int i=0;i<feature;i++)
		{
			cout<<demYes[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<feature;i++)
		{
			cout<<demNo[i]<<" ";
		}
		cout<<endl;
		for(int i=0;i<feature;i++)
		yes*=((float)(demYes[i])/(float)(county));
		for(int i=0;i<feature;i++)
		no*=((float)(demNo[i])/(float)(countn));
		
		cout<<fixed<<setprecision(3)<<"xac suat khi label yes: "<<yes<<endl;
		cout<<fixed<<setprecision(3)<<"xac suat khi label no: "<<no<<endl;
		b[k].nhan=0;
		if(yes>no) b[k].nhan=1;
		cout<<"nhan cua dataset "<<k<<" la: "<<b[k].nhan<<endl;
		
	}
}
