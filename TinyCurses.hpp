/*TinyCurses by Bryan Strait. This library is copyrighted under the LGPLv3,*/
/*or (at your option) any later version.                                   */
/*For more information, see: http://www.gnu.org/copyleft/lgpl.html         */
/*Version 1.0a                                                             */

#ifndef TINYCURSES_H_DEFINED
#define TINYCURSES_H_DEFINED

#include "SDL.h"
#include "SDL_ttf.h"

/* Defining bool for C/C++ compatibility.*/
//#define bool char
//#define true 1
//#define false 0

/* These are the keyboard keys that are defined.*/
#define KEY_UP SDLK_UP
#define KEY_DOWN SDLK_DOWN
#define KEY_LEFT SDLK_LEFT
#define KEY_RIGHT SDLK_RIGHT
#define KEY_HOME SDLK_HOME
#define KEY_END SDLK_END
#define KEY_PAGEUP SDLK_PAGEUP
#define KEY_PAGEDOWN SDLK_PAGEDOWN
#define KEY_BACKSPACE SDLK_BACKSPACE
#define KEY_ESCAPE SDLK_ESCAPE
#define KEY_QUIT SDL_QUIT
#define KEY_INSERT SDLK_INSERT
#define KEY_SCROLL SDLK_SCROLLOCK
#define KEY_PAUSE SDLK_PAUSE
#define KEY_PRINT SDLK_PRINT
#define KEY_TAB SDLK_TAB
#define KEY_CAPSLOCK SDLK_CAPSLOCK
#define KEY_DELETE SDLK_DELETE
#define KEY_NUMLOCK SDLK_NUMLOCK

#define KEY_CTRLDOWN SDLK_RCTRL
#define KEY_CTRLUP SDLK_LCTRL
#define KEY_ALTDOWN SDLK_RALT
#define KEY_ALTUP SDLK_LALT
#define KEY_SHIFTDOWN SDLK_RSHIFT
#define KEY_SHIFTUP SDLK_LSHIFT

#define KEY_F1 SDLK_F1
#define KEY_F2 SDLK_F2
#define KEY_F3 SDLK_F3
#define KEY_F4 SDLK_F4
#define KEY_F5 SDLK_F5
#define KEY_F6 SDLK_F6
#define KEY_F7 SDLK_F7
#define KEY_F8 SDLK_F8
#define KEY_F9 SDLK_F9
#define KEY_F10 SDLK_F10
#define KEY_F11 SDLK_F11
#define KEY_F12 SDLK_F12

#define KEY_MOUSE1 1337
#define KEY_MOUSE2 1338
#define KEY_MOUSE3 1339
#define KEY_WHEELUP 1336
#define KEY_WHEELDOWN 1335

class TinyCurses
{
public:
/* These move the cursor and put things on the screen.*/
static int addch(int ch);
static int printw(const char *s, ...);
static int move(char x,char y);
static int refresh();
static int clear();
static int color(char r,char g,char b,char fr,char fg,char fb);
static int setcursor(bool c);

/* These move the cursor, print the character/text and move the cursor back*/
static int mvprintw(const char *s,int x,int y, ...);
static int mvaddch(int c,int x,int y);

/* These get input from the user*/
static int getch();
static char *getstr(char *s,int l);
static int getmouse(int *x,int *y,bool real);

static int initscr();
static void endwin();

/* These are extended versions of the functions above functions.*/
static int initscrext(int w,int h,bool real);
static int addchext(int ch,int x,int y,char r,char g,char b,char fr,char fg,char fb);
static int printwext(char *s,int x,int y,char r,char g,char b,char fr,char fg,char fb, ...);
static int getchext(int w);
static int clearext(int ch,char r,char g,char b,char fr,char fg,char fb);

/* These are advanced features.*/
static int setalpha(char a);
static int setlayer(char l);
static int setlayershown(char l,bool s);
static int changecolor(int x,int y,char r,char g,char b,char fr,char fg,char fb);
static int changech(int ch,int x,int y);
static int addcolor(int x,int y,int r,int g,int b,int fr,int fg,int fb);
static int setcaption(char *c);
static int setcursorlook(char r,char g,char b);
static int setfont(char *f,int pt);
static int clearlayer(int l);

/* These are tinycurse's "private" variables. Using them directly IS encouraged,*/
/* but be careful! Know what you're doing :)                                    */
private:
static int TC_X,TC_Y,TC_R,TC_G,TC_B,TC_FR,TC_FG,TC_FB,TC_A,TC_FA,TC_L,TC_W,TC_H,TC_XSpace,TC_YSpace, TC_MX, TC_MY;
static int TC_CR,TC_CG,TC_CB;
static bool TC_Show, TC_On, TC_Wait;
static TTF_Font *TC_Font;
static SDL_Surface *TC_Screen;
static bool TC_LayersShown[7];
static Uint32 TC_Layers[255][255][7][9];
static char *TC_FontName;
static int TC_FontSize;

/* This is an internally used function.*/
static int BOUND(int x,int min,int max);
};

#endif /* TINYCURSES_H_DEFINED */

