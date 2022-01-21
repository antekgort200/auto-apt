#include<ncurses.h>
#include <string.h>
#include<iostream>
using namespace std;

int main(){

	initscr();
	noecho();
	cbreak();

	

	string choices[3] = {"A","B","C"};
	int choice;
	int highlight = 0;

	while(1){
		WINDOW *win = newwin(23,20,0,0);
	box(win,0,0);
	refresh();
	wrefresh(win);
	keypad(win,true);
		clear();
		for(int i =0;i<3;i++){
			if(i==highlight){
				
				mvwprintw(win,i+1,1,choices[i].c_str());
				
			}
		}
		mvwprintw(win,5,1,"===============");
		mvwprintw(win,6,1,"A-update");
		mvwprintw(win,7,1,"B-install");
		mvwprintw(win,8,1,"C-remove");
		move(8,1);
		choice = wgetch(win);
		
		switch(choice){
			case KEY_UP:
				highlight--;
				if(highlight == -1){
					highlight = 2;
				}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == 3){
					highlight =0;
				}
				break;
			default:
				break;
		}
			if(choice == 10){
				if(highlight == 0){
					system("sudo apt update");
					clear();}
				else if(highlight == 1){
					char com[] = "sudo apt install ";
					clear();
					char mesg[] = "name package/program: ";
					char str[80];
 					mvprintw(0,0,mesg);
					getstr(str);
					strcat(com, str);
					system(com);
					getch();
					
				}
				else{
					char com[] = "sudo apt-get remove ";
					clear();
					char mesg[] = "name package/program: ";
					char str[80];
					mvprintw(0,0,mesg);
					getstr(str);
					strcat(com,str);
					endwin();
					system(com);
					
				}				
			}
			}
		
	

	getch();
	endwin();
	return 0;
}
//end