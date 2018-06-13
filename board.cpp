#include"board.h"
#include <iostream>
using namespace std;


void board::make_b(int size){
		b=new char*[size];
		for(int i=0;i<size;i++){
			b[i]=new char[size];
		}
	}

void board::clear( int size,char **arr){
	for(int y=0;y<size;y++){
		for(int x=0;x<size;x++){
		arr[y][x]=' ';
		}
	}
}

bool board::draw(int size, char **arr){


		for(int y=0;y<size;y++){
					for(int x=0;x<size;x++){
					if(arr[y][x]==' '){
						return 0;

					}

						}
		}

			return 1;


}



	void board::write_b(char **arr, int size){
		for(int y=0;y<size;y++){
			if(y==0){
								for(int i=0;i<size;i++){
									cout<<' '<<i<<' ';
									if((i+1)%size!=0) cout<<' ';
									if(i==size-1){
										cout<<endl;}
								}
							}
			for(int x=0;x<size;x++){

				cout<<' '<<arr[y][x]<<' ';
				if((x+1)%size!=0) cout<<'|';
				if(x==size-1){
					cout<<' '<<y;
				}
			}
			cout<<endl;
			if((y+1)!=size){
			for(int i=0;i<size;i++){
				if((i+1)!=size){
				cout<<"---+";
				}
				else{
					cout<<"---";
				}
			}
			}
			cout<<endl;
		}
	}
	bool board::win(char **arr, int posx, int posy, int size, int howmany){
		int counter=0,x=0,y=0;
		char symbol=arr[posy][posx];
		if(symbol==' '){
			return 0;
		}
		for( x=posx-howmany+1;x<=posx+howmany;x++ ){
			if(counter==howmany){
							return 1;
						}

			else if(x<0||x>size-1){
				counter=0;
			}
			else if(arr[posy][x]==symbol){
				counter++;
			}
			else{
				counter=0;
			}
		}
		counter=0;
		for(y=posy-howmany+1;y<=posy+howmany;y++ ){

					if(counter==howmany){
						return 1;
					}
					else if(y<0||y>size-1){
										counter=0;
									}
					else if(arr[y][posx]==symbol){
					counter++;
					}
					else{
						counter=0;
					}
				}
		counter=0;
		x=posx+howmany-1;
		for(y=posy-howmany+1;y<=posy+howmany;y++ ){

							if(counter==howmany){
								return 1;
							}
							else if(y<0||y>size-1||x<0||x>size-1){
												counter=0;
											}
							else if(arr[y][x]==symbol){

								counter++;
							}
							else{
								counter=0;
							}

							x--;
						}
		counter=0;
		x=posx-howmany+1;
		for(y=posy-howmany+1;y<=posy+howmany;y++ ){


							if(counter==howmany){
								return 1;
							}
							else if(y<0||y>size-1||x<0||x>size-1){
												counter=0;
											}
							else if(arr[y][x]==symbol){
								counter++;
							}
							else{
								counter=0;
							}
							x++;
						}

		return 0;
	}

int board::minimax(char **arr,int size, int howmany,int posx,int posy,char cs,char ps,int level,int alpha,int beta,int *pos){

	int m=0,mx=0,i=0,j=0;
	if(win(arr,posx,posy,size,howmany)){
		if(cs!=ps){

			return 1;
		}
		else {


			return -1;
		}
	}
	if(draw(size,arr)){
		return 0;
	}
	if(cs==ps){
		mx=-10;
	}
	else{
		mx=10;

	}

if(level>(size+howmany)){
	return -1;
}
	for(int y=0;y<size;y++)
		for(int x=0;x<size;x++)
			if(arr[y][x]==' '){
				arr[y][x]=cs;

				if(cs!=ps){

					m=minimax(arr,size,howmany,x,y,ps,ps,level+1,alpha,beta,pos);
				}
				else{
					if(ps=='o'){


					m=minimax(arr,size,howmany,x,y,'x',ps,level+1,alpha,beta,pos);}
					if(ps=='x'){
						m=minimax(arr,size,howmany,x,y,'o',ps,level+1,alpha,beta,pos);}


				}


				arr[y][x]=' ';
				if(((cs!=ps)&&(m<mx))){

					mx=m;
					beta=min(beta,mx);
					i=y;
					j=x;
				}
				else if ((cs==ps)&&(m>mx)){
					mx=m;
					alpha=max(alpha,mx);

										i=y;
										j=x;
				}


				if(alpha>=beta){
						return mx;
					}

	}

	if(level==0){
		arr[i][j]=cs;
		pos[0]=i;
		pos[1]=j;
	}

	return mx;
}
void board::move_p(char **arr,int *pos, char ps, int size){
	int x=0,y=0;
	bool good=0;
	while(good!=1){
	cout<<"x: ";
	cin>>x;
	cout<<"y: ";
	cin>>y;
	if(x<size&&x>=0&&y<size&&y>=0){
		if(arr[y][x]==' '){
			good=1;
		}
		else{
				cout<<"wrong move"<<endl;
			}
	}
	else{
		cout<<"wrong move"<<endl;
	}
	}
	arr[y][x]=ps;
	pos[0]=y;
	pos[1]=x;

}



