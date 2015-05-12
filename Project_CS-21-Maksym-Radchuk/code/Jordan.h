#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

class Jordan{
	private:
	    int NEQ, N1;
		float A[50][50];
	public:
		Jordan(){
			NEQ=1;
			N1=1;
			for (int i=0;i<=NEQ;i++){
				for(int j=0;j<=N1;j++){
					A[i][j]=0;
				}
			}
		}
     	void setJordan(){
		cout<<"Ââåä³òü ê³ëüê³ñòü ð³âíÿíü : ";
	    cin>>NEQ;
	    N1=NEQ+1;
	    	if(N1>50){
		cout<<"*** ÐÎÇÌ²Ð ÂÕ²ÄÍÎ¯ ÌÀÒÐÈÖ² "<<NEQ<<" ÏÅÐÅÂÈÙÓª ";
		cout<<"ÄÎÏÓÑÒÈÌÈÉ ÐÎÇÌ²Ð ÌÀÒÐÈÖ² ***"<<endl;
		exit(0);
	}
	   	cout<<"Ââåä³òü âõ³äíó ìàòðèöþ : "<<endl;
	     for(int i=1;i<=NEQ;i++){
		   for(int j=1;j<=N1;j++){
			cin>>A[i][j];
	         	}
        	}
		}
		void doCalculate(){
			int N, j, i;
			float D,D1;
			for(N=1;N<=NEQ;N++){
				if(A[N][N]==0){
					cout<<endl<<"*** ÍÓËÜÎÂÈÉ ÅËÅÌÅÍÒ Ç'ßÂËßªÒÜÑß ÏÎ Ä²ÀÃÎÍÀË² ";
					cout<<N<<" Ï²Ä ×ÀÑ ÂÈÊÎÍÀÍÍß ***"<<endl;
					exit(0);
				}
				D=(1/A[N][N]);
				for(j=1;j<=N1;j++){
					A[N][j]=D*A[N][j];
				}
				for(i=1;i<=NEQ;i++){
					if(i==N){
						i=i+1;
					}
					D1=A[i][N];
					for(j=1;j<=N1;j++){
						A[i][j]=A[i][j]-D1*A[N][j];
					}
				}
					A[N][N]=1;
				}
				cout<<endl<<"ÂÈÂ²Ä"<<endl<<endl;
     	for(i=1;i<=NEQ;i++){
		    for(j=1;j<=N1;j++){
			    cout<<setprecision(2)<<setw(5)<<A[i][j];
	    	}
	    	cout<<endl;
       	}
	}
};
