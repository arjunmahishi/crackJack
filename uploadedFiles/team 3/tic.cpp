#include<iostream>
using namespace std;

char board[10][10]={'\0'},uc,cc;
int c,filled=0;

int checkwin(){
    
    if(board[1][1]!='\0'){
       if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]){
           if(board[0][0]==cc) {
               return 1;
       }
       else{
           return 2;

       } 
       
    }
       if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]){
           if(board[1][1]==cc) {
               
               return 1;
       }
       else{
           return 2;

       } 
       
    }
    
       if(board[0][1]==board[1][1]&&board[1][1]==board[2][1]){
           if(board[1][1]==cc) {
               
               return 1;
       }
       else{
           return 2;

       } 
       
    }
    
       if(board[1][0]==board[1][1]&&board[1][1]==board[1][2]){
           if(board[1][1]==cc) {
               
               return 1;
       }
       else{
                          return 2;

       } 
       
    }
    
    
    
    
    
}

    if(board[0][0]!='\0'){
        
    
       if(board[0][1]==board[0][0]&&board[0][0]==board[0][2]){
           if(board[0][0]==cc) {
               
               return 1;
       }
       else{
                          return 2;

       } 
       
    }
    
       if(board[1][0]==board[0][0]&&board[0][0]==board[2][0]){
           if(board[0][0]==cc) {
               
               return 1;
       }
       else{
                          return 2;

       } 
       
    }
    

    }
    if(board[2][2]!='\0'){
        
    
       if(board[0][2]==board[2][2]&&board[1][2]==board[2][2]){
           if(board[2][2]==cc) {
               
               return 1;
       }
       else{
                          return 2;

       } 
       
    }
       if(board[2][0]==board[2][2]&&board[2][1]==board[2][2]){
           if(board[2][2]==cc) {
               
               return 1;
       }
       else{
                          return 2;

       } 
       
    }
    
    
    

    }
    
    
    


    return 0;
}
void display(){
cout<<"\n";
for(int i=0;i<3;i++){

for(int j=0;j<3;j++){

if(board[i][j])
cout<<board[i][j]<<" ";
else cout<<"- ";
}
cout<<"\n";
}
cout<<"\n****************************************************************\n";
}
void randmove(){
    for(int i=0;i<3;i++){

for(int j=0;j<3;j++){

if(board[i][j]=='\0') 
 {
    board[i][j]=cc;
    return;
}

}
}
    
}

int nextwinmove(){
    
            for(int i=0;i<=2;i++){
                
                for(int j=0;j<=2;j++){
                    if(board[i][j]=='\0'){
                        board[i][j]=cc;
                        if(checkwin()==1){
                            return 0;
                            
                        }
                        board[i][j]='\0';
                        
                        board[i][j]=uc;
                        if(checkwin()==2){
                            board[i][j]=cc;
                            return 0;
                            
                        }
                        board[i][j]='\0';
                        
                        
                    }
                }
            }
            
            randmove();

}
void makemove(){
    
    if(filled==0) {
        
        board[1][1]=cc;
        display();
    }
    else if(board[1][1]=='\0'){
        board[1][1]=cc;
        display();
    }
    else{
        
        nextwinmove();
        display();
    }
    
}
void computermove(){
        cout<<"************************Computer Turn***************************\n";
makemove();
    
}

void computemove(){
        cout<<"************************Computer Turn***************************\n";

    cout<<"Enter X,Y positions to fill ( 0 based index): ";
    int x,y;
    
    while(1){
            cin>>x>>y;

        if(board[x][y]=='\0'&&x>=0&&x<=2&&y>=0&&y<=2){
            board[x][y]=cc;
            display();
            break;
        }
        else  cout<<"Enter Valid Move\n\n";
        
    }
    
}


void usermove(){
    
    cout<<"************************Your Turn*******************************\nEnter X,Y positions to fill : ";
    int x,y;
    
    while(1){
            cin>>x>>y;

        if(board[x][y]=='\0'&&x>=0&&x<=2&&y>=0&&y<=2){
            board[x][y]=uc;
            display();
            break;
        }
        else  cout<<"Enter Valid Move\n\n";
        
    }
    
}


void toggle(){
    
    if(c==0) c=1;
    else if(c==1) c=0;
}
int main(){
char ch;int fl;
cout<<"Enter first player name (User/Computer)- press u for user c for computer \n";
cin>>ch;
cout<<"Choose Your(user) Coin:(X,O)? : ";
cin>>uc;
if(uc=='X' || uc=='x') uc='X',cc='O';
else if(uc=='o'||uc=='O'||uc=='0') uc='0',cc='X';
else {
        cout<<"make correct choice.bye";
    return 0;
}
if(ch=='c' || ch=='C') c=1;
else if(ch=='u' || ch=='U') c=0;
else{
    cout<<"make correct choice.bye";
    return 0;
}
cout<<"\n**********************Initial Board state**********************\n";

display();
while(filled<9){
if(c){
    computermove();
} 
else{
    
    usermove();
}
 
 filled++;
 fl=checkwin();
 if(fl) {
     if(fl==1)   cout<<"#######COMPUTER WINS#############"<<endl;
     else
     if(fl==2)   cout<<"#######USER WINS#############"<<endl;
     
     return 0;
     
 }
 toggle();
}

cout<<"Match Draw"<<endl;
return 0;
}