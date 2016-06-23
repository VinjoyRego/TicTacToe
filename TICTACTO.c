# include<stdio.h>
# include<string.h>
# include<conio.h>
# include <cstdlib>
#define WINDOWS 1

char brd[9],p1[50],p2[50];
 
void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

void login()
{
 clrscr();
 printf("\n\n\n\n\t\t\tTIC-TAC-TOE\n");
 printf("\n\n\tA game in the liesure period to play....\n");
 printf("\n\tEnjoy the product...");
 printf("\n\n\n\t\t\tPress any key..");
 getch();
}

void logout()
{
 clrscr();
 printf("\n\n\n\n\n\n\n\t\t\t\tThank you....");
 printf("\n\n\n\n\t\tProgram by\t::- VINJOY REGO");
 printf("\n\n\n\n\n\n\t\t\tPress any key..");
 getch();
}

void dispbrd()
{
 printf("\n\n\n\t");
 printf("%c\t%c\t%c\n\t%c\t%c\t%c\n\t%c\t%c\t%c\n\n",brd[0],brd[1],brd[2],brd[3],brd[4],brd[5],brd[6],brd[7],brd[8]);
}

int player()
{
  int pos;
  printf("%s your turn:\n",p1);
  printf("Enter the position you want to enter:");
  scanf("%d",&pos);
  if(brd[pos-1]!='X' && brd[pos-1]!='O' && pos>0 && pos<=9)
   {
     brd[pos-1]='X';
   }
  else
   {
    clrscr();
    dispbrd();
    printf("Wrong position:\n");
    player();
   }
  clrscr();
  dispbrd();
/* Checks for win */
  if((brd[0]=='X' && brd[1]=='X' && brd[2]=='X')
     || (brd[3]=='X' && brd[4]=='X' && brd[5]=='X')
     || (brd[6]=='X' && brd[7]=='X' && brd[8]=='X')
     || (brd[0]=='X' && brd[4]=='X' && brd[8]=='X')
     || (brd[0]=='X' && brd[3]=='X' && brd[6]=='X')
     || (brd[1]=='X' && brd[4]=='X' && brd[7]=='X')
     || (brd[2]=='X' && brd[5]=='X' && brd[8]=='X')
     || (brd[2]=='X' && brd[4]=='X' && brd[6]=='X'))
  {
    printf("\n\t\t# TIC-TAC-TOE #\n");
    printf("$ $ $ $ $ $ %s You won the game...$ $ $ $ $ $",p1);
    return(1);
  }
  return(0);
}

int player2()
{
  int pos;
  printf("%s your turn:\n",p2);
  printf("Enter the position you want to enter:");
  scanf("%d",&pos);
  if(brd[pos-1]!='X' && brd[pos-1]!='O' && pos>0 && pos<=9)
   {
     brd[pos-1]='O';
   }
  else
   {
    clrscr();
    dispbrd();
    printf("Wrong position:\n");
    player();
   }
  clrscr();
  dispbrd();
/* Checks for win */
  if((brd[0]=='O' && brd[1]=='O' && brd[2]=='O')
     || (brd[3]=='O' && brd[4]=='\0' && brd[5]=='O')
     || (brd[6]=='O' && brd[7]=='O' && brd[8]=='O')
     || (brd[0]=='O' && brd[4]=='O' && brd[8]=='O')
     || (brd[0]=='O' && brd[3]=='O' && brd[6]=='O')
     || (brd[1]=='O' && brd[4]=='O' && brd[7]=='O')
     || (brd[2]=='O' && brd[5]=='O' && brd[8]=='O')
     || (brd[2]=='O' && brd[4]=='O' && brd[6]=='O'))
  {
    printf("\n\t\t# TIC-TAC-TOE #\n");
    printf("$ $ $ $ $ $ %s You won the game...$ $ $ $ $ $",p2);
    return(1);
  }
  return(0);
}

int comp()
{
 int pos=-1,i;
 clrscr();
/* finds wether any next move has wining chance. if so then assigns it */
 if(brd[0]=='O')
 {
  if(brd[1]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[2]=='O' && (brd[1]!='X' && brd[1]!='O'))
   pos=1;
  else if(brd[3]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[6]=='O' && (brd[3]!='X' && brd[3]!='O'))
   pos=3;
  else if(brd[4]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[1]=='O' && pos==-1)
 {
  if(brd[0]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[2]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
  else if(brd[4]=='O' && (brd[7]!='X' && brd[7]!='O'))
   pos=7;
  else if(brd[7]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[2]=='O' && pos==-1)
 {
  if(brd[1]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
  else if(brd[0]=='O' && (brd[1]!='X' && brd[1]!='O'))
   pos=1;
  else if(brd[5]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[5]!='X' && brd[5]!='O'))
   pos=5;
  else if(brd[4]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[6]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[3]=='O' && pos==-1)
 {
  if(brd[0]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[6]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
  else if(brd[4]=='O' && (brd[5]!='X' && brd[5]!='O'))
   pos=5;
  else if(brd[5]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[4]=='O' && pos==-1)
 {
  if(brd[1]=='O' && (brd[7]!='X' && brd[7]!='O'))
   pos=7;
  else if(brd[7]=='O' && (brd[1]!='X' && brd[1]!='O'))
   pos=1;
  else if(brd[5]=='O' && (brd[3]!='X' && brd[3]!='O'))
   pos=3;
  else if(brd[3]=='O' && (brd[5]!='X' && brd[5]!='O'))
   pos=5;
  else if(brd[2]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[6]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[0]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
 }
 if(brd[5]=='O' && pos==-1)
 {
  if(brd[2]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[4]=='O' && (brd[3]!='X' && brd[3]!='O'))
   pos=3;
  else if(brd[3]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[6]=='O' && pos==-1)
 {
  if(brd[3]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
  else if(brd[0]=='O' && (brd[3]!='X' && brd[3]!='O'))
   pos=3;
  else if(brd[4]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[2]=='O' && (brd[3]!='X' && brd[3]!='O'))
   pos=3;
  else if(brd[7]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[7]!='X' && brd[7]!='O'))
   pos=7;
 }
 if(brd[7]=='O' && pos==-1)
 {
  if(brd[6]=='O' && (brd[8]!='X' && brd[8]!='O'))
   pos=8;
  else if(brd[8]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[4]=='O' && (brd[1]!='X' && brd[1]!='O'))
   pos=1;
  else if(brd[1]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
 }
 if(brd[8]=='O' && pos==-1)
 {
  if(brd[0]=='O' && (brd[4]!='X' && brd[4]!='O'))
   pos=4;
  else if(brd[4]=='O' && (brd[0]!='X' && brd[0]!='O'))
   pos=0;
  else if(brd[5]=='O' && (brd[2]!='X' && brd[2]!='O'))
   pos=2;
  else if(brd[2]=='O' && (brd[5]!='X' && brd[5]!='O'))
   pos=5;
  else if(brd[7]=='O' && (brd[6]!='X' && brd[6]!='O'))
   pos=6;
  else if(brd[6]=='O' && (brd[7]!='X' && brd[7]!='O'))
   pos=7;
 }
 if(pos>-1)
 {
   brd[pos]='O';
   dispbrd();
   printf("\n\t\t# TIC-TAC-TOE #\n");
   printf("$ $ $ $ $ $ You Lost the Game...$ $ $ $ $ $");
   printf("\n\t**** Computer Wins ****");
   return(1);
 }
 else
 {
 /* finds which psition has winning move for opponent if so blocks it */
  if(brd[0]=='X')
  {
   if(brd[1]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[2]=='X' && (brd[1]!='X' && brd[1]!='O'))
    pos=1;
   else if(brd[3]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[6]=='X' && (brd[3]!='X' && brd[3]!='O'))
    pos=3;
   else if(brd[4]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[1]=='X' && pos==-1)
  {
   if(brd[0]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[2]=='X' && (brd[0]!='X' && brd[0]!='O'))
    pos=0;
   else if(brd[4]=='X' && (brd[7]!='X' && brd[7]!='O'))
    pos=7;
   else if(brd[7]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[2]=='X' && pos==-1)
  {
   if(brd[1]=='X' && (brd[0]!='X' && brd[0]!='O'))
    pos=0;
   else if(brd[0]=='X' && (brd[1]!='X' && brd[1]!='O'))
    pos=1;
   else if(brd[5]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[5]!='X' && brd[5]!='O'))
    pos=5;
   else if(brd[4]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[6]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[3]=='X' && pos==-1)
  {
   if(brd[0]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[6]=='X' && (brd[0]!='X' && brd[0]!='O'))
    pos=0;
   else if(brd[4]=='X' && (brd[5]!='X' && brd[5]!='O'))
    pos=5;
   else if(brd[5]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[4]=='X' && pos==-1)
  {
   if(brd[1]=='X' && (brd[7]!='X' && brd[7]!='O'))
    pos=7;
   else if(brd[7]=='X' && (brd[1]!='X' && brd[1]!='O'))
    pos=1;
   else if(brd[5]=='X' && (brd[3]!='X' && brd[3]!='O'))
    pos=3;
   else if(brd[3]=='X' && (brd[5]!='X' && brd[5]!='O'))
    pos=5;
   else if(brd[2]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[6]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[0]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[0]!='X' && brd[0]!='O'))
    pos=0;
  }
  if(brd[5]=='X' && pos==-1)
  {
   if(brd[2]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[4]=='X' && (brd[3]!='X' && brd[3]!='O'))
    pos=3;
   else if(brd[3]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[6]=='X' && pos==-1)
  {
   if(brd[3]=='X')
    pos=0;
   else if(brd[0]=='X' && (brd[3]!='X' && brd[3]!='O'))
    pos=3;
   else if(brd[4]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[2]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
   else if(brd[7]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[7]!='X' && brd[7]!='O'))
    pos=7;
  }
  if(brd[7]=='X' && pos==-1)
  {
   if(brd[6]=='X' && (brd[8]!='X' && brd[8]!='O'))
    pos=8;
   else if(brd[8]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[4]=='X' && (brd[1]!='X' && brd[1]!='O'))
    pos=1;
   else if(brd[1]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
  }
  if(brd[8]=='X' && pos==-1)
  {
   if(brd[0]=='X' && (brd[4]!='X' && brd[4]!='O'))
    pos=4;
   else if(brd[4]=='X' && (brd[0]!='X' && brd[0]!='O'))
    pos=0;
   else if(brd[5]=='X' && (brd[2]!='X' && brd[2]!='O'))
    pos=2;
   else if(brd[2]=='X' && (brd[5]!='X' && brd[5]!='O'))
    pos=5;
   else if(brd[7]=='X' && (brd[6]!='X' && brd[6]!='O'))
    pos=6;
   else if(brd[6]=='X' && (brd[7]!='X' && brd[7]!='O'))
    pos=7;
  }
 /* finds better postion if there is no winning chance for both */
  if(pos==-1)
  {
   if(brd[0]=='O')
   {
    if((brd[4]=='O' || brd[7]=='O') && (brd[1]!='X' && brd[1]!='O'))
     pos=1;
    else if((brd[5]=='O' || brd[8]=='O') && (brd[2]!='X' && brd[2]!='O'))
     pos=2;
   }
   else if(brd[1]=='O')
   {
    if((brd[5]=='O' || brd[8]=='O') && (brd[2]!='X' && brd[2]!='O'))
     pos=2;
    else if((brd[3]=='O' || brd[6]=='O') && (brd[0]!='X' && brd[0]!='O'))
     pos=0;
   }
   else if(brd[2]=='O')
   {
    if((brd[3]=='O' || brd[6]=='O') && (brd[0]!='X' && brd[0]!='O'))
     pos=0;
    else if((brd[4]=='O' || brd[7]=='O') && (brd[1]!='X' && brd[1]!='O'))
     pos=1;
   }
   else if(brd[3]=='O')
   {
    if((brd[1]=='O' || brd[7]=='O') && (brd[4]!='X' && brd[4]!='O'))
     pos=4;
    else if((brd[2]=='O' || brd[8]=='O') && (brd[5]!='X' && brd[5]!='O'))
     pos=5;
   }
   else if(brd[4]=='O')
   {
    if((brd[0]=='O' || brd[6]=='O') && (brd[3]!='X' && brd[3]!='O'))
     pos=3;
    else if((brd[2]=='O' || brd[8]=='O') && (brd[5]!='X' && brd[5]!='O'))
     pos=5;
   }
   else if(brd[5]=='O')
   {
    if((brd[0]=='O' || brd[6]=='O') && (brd[3]!='X' && brd[3]!='O'))
     pos=3;
    else if((brd[1]=='O' || brd[7]=='O') && (brd[4]!='X' && brd[4]!='O'))
     pos=4;
   }
   else if(brd[6]=='O')
   {
    if((brd[1]=='O' || brd[4]=='O') && (brd[7]!='X' && brd[7]!='O'))
     pos=7;
    else if((brd[2]=='O' || brd[5]=='O') && (brd[8]!='X' && brd[8]!='O'))
     pos=8;
   }
   else if(brd[7]=='O')
   {
    if((brd[0]=='O' || brd[3]=='O') && (brd[6]!='X' && brd[6]!='O'))
     pos=6;
    else if((brd[2]=='O' || brd[5]=='O') && (brd[8]!='X' && brd[8]!='O'))
     pos=8;
   }
   else if(brd[8]=='O')
   {
    if((brd[0]=='O' || brd[3]=='O') && (brd[6]!='X' && brd[6]!='O'))
     pos=6;
    else if((brd[1]=='O' || brd[4]=='O') && (brd[7]!='X' && brd[7]!='O'))
     pos=7;
   }
  }
 /* just finds any postion anf assigns it */
  if(pos==-1)
  {
   for(i=0;i<=8;i++)
   {
    if(brd[i]!='X' && brd[i]!='O')
    {
     pos=i;
     break;
    }
   }
  }
  brd[pos]='O';
  dispbrd();
 }
 return(0);
}


void pcgame()
{
 int cnt=0,flag=0;
 clrscr();
 printf("Enter player name:");
 scanf("%s",p1);
 clrscr();
 dispbrd();
 while(cnt<9)
 {
   if(cnt%2==0)
    flag=player();
   else
    flag=comp();
   cnt++;
   if(flag==1)
     return;
   clrscr();
   dispbrd();
 }
 printf("\n\n!!!!!  Good try .... Game is drawn !!!!!");
}

void p1p2game()
{
 int cnt=0,flag=0;
 clrscr();
 printf("Enter player1 name:");
 scanf("%s",p1);
 printf("Enter player2 name:");
 scanf("%s",p2);
 clrscr();
 dispbrd();
 while(cnt<9)
 {
   if(cnt%2==0)
    flag=player();
   else
    flag=player2();
   cnt++;
   if(flag==1)
     return;
   clrscr();
   dispbrd();
 }
 printf("\n\n!!!!!  Good try .... Game is drawn !!!!!");
}

main()
{
 char ch='\0';
 int i,type;
 login();
 do
 {
  clrscr();
  for(i=0;i<9;i++)
    brd[i]=48+i+1;
label:printf("1.One player game\n\n2.Two player game\n\n");
  printf("Enter your choice:");
  scanf("%d",&type);
  if(type==1)
    pcgame();
  else if(type==2)
    p1p2game();
  else
  {
    clrscr();
    printf("Wrong choice:\n\n");
    goto label;
  }
  printf("\n\n\n\nDo you want to play again ? ? ? (y/n)");
  ch=getch();
 }while(ch=='Y' || ch=='y');
 logout();
}