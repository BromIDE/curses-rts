/*************************************************************************/
/*******************placeholder*******************************************/
/*************************************************************************/

#include <menu.h>
#include <stdio.h>
#include <ncurses.h>

char *choices[] = {
  "Begin",
  "Exit",
};

int main() {
  /*data*/
  ITEM **my_items;
  int c;
  MENU *my_menu;
  int n_choices, i;
  ITEM *cur_item;
  
  initscr();
  raw();
  keypad(stdscr,TRUE);
  noecho();
  
  n_choices = ARRAY_SIZE(choices);
  my_items= (ITEM **)calloc(n_choices + 1, sizeof(item*));
  
  for(i = 0; i<n_choices; ++i)
  	my_items[i] = new_item(choices[i], choices[i]);
  my_items[n_choices] = (ITEM *)NULL;
  
  my_menu = new_menu((ITEM **)my_items);
  mvprintw(lines - 2, 0, "ESC to Exit");
  post_menu(my_menu);
  refresh();
  
  while ((c = getch()) != KEY_ESCAPE)
  { switch(c)
  	{	case KEY_DOWN:
  			menu_driver(my_menu, REQ_DOWN_ITTEM);
  				break;
  			case KEY_UP:
  				menu_driver(my_menu, REQ_UP_ITEM);
  				break;
  	}
  }
  
  
  
  }
