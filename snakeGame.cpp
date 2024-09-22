#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<iostream>
using namespace std;

const int width=80;
const int height =20;

int x,y;
int fruitcordX, fruitcordY;
int playerscore;
int snakeTailX[100],snakeTailY[100];
int snakeTailLen;
enum snakeDirection{ STOP=0, LEFT, RIGHT, UP, DOWN};
snakeDirection sDir;

bool isGameOver;

void GameInit(){
    isGameOver= false;
    sDir= STOP;
    x=width/2;
    y=height/2;
    fruitcordX=rand()%width;
    fruitcordY=rand()%height;
    playerscore=0;
}

void GameRender(string playername){
    system("cls");
    for(int i=0; i<width+2; i++)
    cout<<"-";
    cout<<endl;

    for(int i=0; i<height; i++){
        for(int j=0; j<=width; j++){
            if(j==0||j==width)
            cout<<"|";
            if(i==y && j==x)
            cout<<"O";
            else if(i== fruitcordY && j==fruitcordX)
            cout<<"#";
            else{bool prTail=false;
            for(int k=0; k<snakeTailLen; k++){
                if(snakeTailX[k]==j && snakeTailY[k]==i){
                    cout<<"0";
                    prTail=true;
                }
            }
            if(!prTail)
            cout<<" ";
            
        }
    }
    cout<<endl;
}

for(int i=0; i<width + 2; i++)
    cout<<"-";
    cout<<endl;

    cout<<playername<<" 's Score: "<<playerscore<<endl;


}

void UpdateGame(){
    int prevX=snakeTailX[0];
    int prevY=snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0]=x;
    snakeTailY[0]=y;

    for(int i=1; i<snakeTailLen; i++){
        prev2X=snakeTailX[i];
        prev2Y=snakeTailY[i];
        snakeTailX[i]=prevX;
        snakeTailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(sDir){
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
    }
    if(x>=width || x<0 || y>=height || y<0)
    isGameOver=true;

    for(int i=0; i<snakeTailLen; i++){
        if(snakeTailX[i]==x && snakeTailY[i]==y)
        isGameOver= true;
    }

    if(x==fruitcordX && y==fruitcordY){
        playerscore +=10;
        fruitcordX= rand()%width;
        fruitcordY=rand()%height;
        snakeTailLen++;
    }
}

int setDifficulty(){
    int dfc, choice;
    cout<< "\nSET DIFFICULTY\n1: Easy\n2: Medium\n3: hard "
            "\nNOTE: if not chosen or pressed any other "
            "key, the difficulty will be automatically set "
            "to medium\nChoose difficulty level: "; 
            cin>>choice;
            switch(choice){
                case '1':
                dfc=50;
                break;

                case '2':
                dfc=100;
                break;

                case '3':
                dfc=150;
                break;

                default:
                dfc=100;
            }
            return dfc;
}

void userInput(){
    if(_kbhit()){

        switch(getch()){
            case 'a':
            sDir=LEFT;
            break;
            case 'd':
            sDir=RIGHT;
            break;
            case 'w':
            sDir=UP;
            break;
            case 's':
            sDir=DOWN;
            break;
            case 'x':
            isGameOver=true;
            break;
        }

    }
}
int main(){
    string playerName;
    cout<<"enter your name :";
    cin>>playerName;
    int dfc=setDifficulty();

    GameInit();
    while(!isGameOver){
        GameRender(playerName);
        userInput();
        UpdateGame();
        Sleep(dfc);

    }
    return 0;
}