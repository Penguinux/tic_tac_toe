
#include <iostream>
#include"board.h"
using namespace std;




int main() {
	board bo;
	bool wp=0,d=0,wc=0;
	char choice;
cout<<"---------TIC TAC TOE---------"<<endl<<endl;
cout<<"'x' or 'o'"<<endl;
while(choice!='x'&&choice!='o'){
cin>>choice;
if(choice!='x'&&choice!='o'){
	cout<<"wrong choice"<<endl;
}
else if(choice=='o'){
	bo.playersymb='o';
	bo.computersymb='x';
}
else if(choice=='x'){
	bo.playersymb='x';
		bo.computersymb='o';
}
}
cout<<"Determinate size of the board"<<endl;
cin>>bo.size;
cout<<"How many symbols in a row are necessary to win?"<<endl;
cin>>bo.howmany;

bo.make_b( bo.size);
bo.clear(bo.size, bo.b);
bo.write_b(bo.b,bo.size);
while((wp!=1)&&(d==0)&&(wc!=1)){



	cout<<"Player move"<<endl;
	bo.move_p(bo.b,bo.position,bo.playersymb,bo.size);
	bo.write_b(bo.b,bo.size);
	cout<<"Computer move"<<endl;
			bo.minimax(bo.b,bo.size,bo.howmany,bo.position[1],bo.position[0],bo.computersymb,bo.playersymb,0,-100000,100000,bo.positionc);
			bo.write_b(bo.b,bo.size);

if(bo.win(bo.b,bo.positionc[1],bo.positionc[0],bo.size,bo.howmany)){
	wc=1;
	cout<<"computer wins"<<endl;
}

else if(bo.win(bo.b,bo.position[1],bo.position[0],bo.size,bo.howmany)){
	wp=1;
	cout<<"player wins"<<endl;
}
else if(bo.draw(bo.size,bo.b)){
	d=1;
	cout<<"draw"<<endl;
}

}


cout<<'1';


	return 0;
};
