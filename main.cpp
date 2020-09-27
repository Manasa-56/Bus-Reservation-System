#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX 10
static int p=0;
class resSystem{
private: 
        char busn[MAX],driver[MAX],arrival[MAX],depart[MAX],from[MAX],to[MAX],seat[8][4][MAX];
public:
        void install();
        void allotment();
        void empty();
        void show();
        void avail();
        void position(int l);
        
}bus[MAX];

void vline(char ch){
    for(int i=50;i>0;i--)
    cout<<ch;
} 
void resSystem::install(){
    cout<<"\nEnter bus no.: ";
    cin>>bus[p].busn;
    cout<<"\nEnter driver name: ";
    cin>>bus[p].driver;
    cout<<"\nEnter arrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nEnter departure time: ";
    cin>>bus[p].depart;
    cout<<"\nFrom where: ";
    cin>>bus[p].from;
    cout<<"\nTo where: ";
    cin>>bus[p].to;
    bus[p].empty();
    p++;
}
void resSystem::allotment(){
    int seat;
    char number[5];
    top:
    cout<<"\nEnter Bus No.: ";
    cin>>number;
    int n;
    for(n=0;n<p;n++){
        if(strcmp(bus[n].busn,number)==0)
        break;
    }
    while(n<=p){
        cout<<"\nEnter Seat No.: ";
        cin>>seat;
        if(seat>32)
        cout<<"\nThere are only 32 seats in this bus.";
        else{
                if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0){
                cout<<"\nEnter passenger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;
                }
                else
                cout<<"\nThe seat no. is already reserved.";
            }
    }
    if(n>p){
        cout<<"\nEnter correct bus no.";
        goto top;            
    }
}
void resSystem::empty(){
    for(int i=0;i<8;i++){
        for(int j=0;j<4;j++){
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}
void resSystem::show(){
    int n;
    char number[5],choice='Y';
        cout<<"\nEnter Bus No.: ";
        cin>>number;
        for(n=0;n<=p;n++){
        if(strcmp(bus[n].busn,number)==0)
        break;
    }
        while(n<=p){
        cout<<"\n";
        vline('*');
        cout<<"\nBus No.: "<<bus[n].busn;
        cout<<"\nDriver Name: "<<bus[n].driver;
        cout<<"\nArrival Time: "<<bus[n].arrival;
        cout<<"\nDeparture Time: "<<bus[n].depart;
        cout<<"\nFrom: "<<bus[n].from;
        cout<<"\nTo: "<<bus[n].to;
        vline('*');
        cout<<"\n";
        bus[0].position(n);
        int a=1;
        for(int i=0;i<8;i++){
            for(int j=0;j<4;j++){
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                cout<<"\nThe seat no."<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
    cout<<"\nPlease try again & enter correct bus number!!";
}
void resSystem::avail(){
    for(int n=0;n<p;n++){
        cout<<"\n";
        vline('*');
        cout<<"\nBus No.: "<<bus[n].busn;
        cout<<"\nDriver Name: "<<bus[n].driver;
        cout<<"\nArrival Time: "<<bus[n].arrival;
        cout<<"\nDeparture Time: "<<bus[n].depart;
        cout<<"\nFrom: "<<bus[n].from;
        cout<<"\nTo: "<<bus[n].to<<"\n";
        vline('*');
        cout<<"\n";
    }
}
void resSystem::position(int l){
    int s=0;
    int p=0;
    for(int i=0;i<8;i++){
        cout<<"\n";
        for(int j=0;j<4;j++){
        s++;
        if(strcmp(bus[l].seat[i][j],"Empty")==0){
            cout.width(5);
            cout.fill(' ');
            cout<<s<<".";
            cout.width(10);
            cout.fill(' ');
            cout<<bus[l].seat[i][j];
            p++;
        }
        else{
            cout.width(5);
            cout.fill(' ');
            cout<<s<<".";
            cout.width(10);
            cout.fill(' ');
            cout<<bus[l].seat[i][j];  
        }
      }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in bus no. "<<bus[l].busn;
}

int main()
{
    int choice;
    do{
        cout<<"\nMenu";
        cout<<"\n1.Install";
        cout<<"\n2.Reservation";
        cout<<"\n3.Show";
        cout<<"\n4.Buses Available";
        cout<<"\n5.Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:bus[p].install();
                   break;
            case 2:bus[p].allotment();
                   break;
            case 3:bus[p].show();
                   break;
            case 4:bus[p].avail();
                   break;
            case 5:cout<<"Thank You For Choosing Us!!\nHappy Journey<3";
                   break;       
        }
    }while(choice!=5);
    return 0;
}
