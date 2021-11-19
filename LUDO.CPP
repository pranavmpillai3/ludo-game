#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<stdio.h>

	const int  TRUE = 1;

	class player;

	void display_player(player* ,player *,player *,player *);

	void draw_with_save(player * , player * , player * , player * );

	class ludo_interface
	{

	int small_box_color;   //for row columns
	int box_color;    //box color for seperate columns
	int line_color;    //line color for drawing rectangle
	int circle_color;   //circle color for filling color inside 4 small
			//boxes
	public:

	ludo_interface()
	{

	line_color = WHITE;
	circle_color = WHITE;

	}
	void intialise_graph();   //to intialise graphic system

	void draw_rect();         //to complete all interfaces in
				//which game has to be played
	void finish()
	{
	closegraph();
	}

	};


	void ludo_interface::intialise_graph()
	{
	int driver = VGA,mode = VGAHI;

	initgraph(&driver,&mode,"c://turboc3//bgi");

	}

	void ludo_interface::draw_rect()

	{

	setbkcolor(BLACK);   	//background color setted
	     //MAIN RECTANGLE
/*************drawing rectangle**********/
				//main rectangle inside which game is played
	setcolor(line_color);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(0,0,480,480);
/****************************************/


/************ main margins ********/

			//drawing lines inside box inorder to draw small box

	 // uppermost lines

	line(180,0,180,480);
	line(300,0,300,480);
	line(220,0,220,180);
	line(260,0,260,180);

	//leftmost  lines

	line(0,180,180,180);
	line(0,220,180,220);
	line(0,260,180,260);
	line(0,300,180,300);

	//bottomlevel  lines

	line(180,300,180,480);
	line(220,300,220,480);
	line(260,300,260,480);
	line(300,300,300,480);

	//right most lines

	line(300,180,480,180);
	line(300,220,480,220);
	line(300,260,480,260);
	line(300,300,480,300);

	//drawing rectangle on middle of bix box to display ludo

	rectangle(180,180,300,300);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
	outtextxy(210,210,"ludo");

  /******* drawing small lines inorder to make
	  player's coin movement path******/

	  setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	  //drawing lines on topmost

     line(180,30,300,30);
     line(180,60,300,60);
     line(180,90,300,90);
     line(180,120,300,120);
     line(180,150,300,150);

	 //drawing lines on leftmost

     line(30,180,30,300);
     line(60,180,60,300);
     line(90,180,90,300);
     line(120,180,120,300);
     line(150,180,150,300);

	//drawing lines on bottommost

     line(180,330,300,330);
     line(180,360,300,360);
     line(180,390,300,390);
     line(180,420,300,420);
     line(180,450,300,450);

	//drawing lines on right most

     line(330,180,330,300);
     line(360,180,360,300);
     line(390,180,390,300);
     line(420,180,420,300);
     line(450,180,450,300);

   /***********filling colors on 4 small boxes on each corner*************/
				      //players intial resting area
	//filling left botton box with yellow color
	small_box_color = YELLOW;
	setfillstyle(SOLID_FILL,small_box_color);
	floodfill(90,390,line_color);

	//filling left top box with red color
	small_box_color = RED;
	setfillstyle(SOLID_FILL,small_box_color);
	floodfill(90,90,line_color);

	//filling right top box with green color
	small_box_color = GREEN;
	setfillstyle(SOLID_FILL,small_box_color);
	floodfill(390,90,line_color);

	//filling right bottom box with green color
	small_box_color = BLUE;
	setfillstyle(SOLID_FILL,small_box_color);
	floodfill(390,390,line_color);

/*********drawing circles inside the small red box**************/
			    //area where each coins of player lies

	setfillstyle(SOLID_FILL,circle_color);
				//setted filling adjustments
	circle(50,50,20);        //1st circle
	floodfill(50,50,line_color);

	circle(130,50,20);       //2nd circle
	floodfill(130,50,line_color);

	circle(50,130,20);       //3rd circle
	floodfill(50,130,line_color);

	circle(130,130,20);        //4th circle
	floodfill(130,130,line_color);

/********drawing circles inside the small green box************/
			 //area where each coins of player lies

	circle(350,50,20);    //1st circle
	floodfill(350,50,line_color);

	circle(430,50,20);	//2nd circle
	floodfill(430,50,line_color);

	circle(350,130,20);	//3rd circle
	floodfill(350,130,line_color);

	circle(430,130,20);	//4th circle
	floodfill(430,130,line_color);

/*******drawing circles inside the small yellow box*******/
			  //area where each coins of player lies

	circle(50,350,20);	//1st circle
	floodfill(50,350,line_color);

	circle(130,350,20);	//2nd circle
	floodfill(130,350,line_color);

	circle(50,430,20);	//3rd circle
	floodfill(50,430,line_color);

	circle(130,430,20);	//4th circle
	floodfill(130,430,line_color);

/******drawing circles inside the small blue box**********/
				//area where each coins of player lies

	circle(350,350,20);	//1st circle
	floodfill(350,350,line_color);

	circle(430,350,20);	//2nd circle
	floodfill(430,350,line_color);

	circle(350,430,20);	//3rd circle
	floodfill(350,430,line_color);

	circle(430,430,20);	//4th circle
	floodfill(430,430,line_color);

/**** filling the room box of each associated small colored boxes...**/
	     int x,y;         //ultimate movement boxes of each player
   //	for blue box
	    x = 315,y = 240;
	small_box_color = BLUE;
	setfillstyle(SOLID_FILL,small_box_color);
	for(int i=1; i<=5; i++,x=x+30)
	{
	floodfill(x,y,line_color);
	}

   //   for yellow box
	x = 240;y = 315;
	small_box_color = YELLOW;
	setfillstyle(SOLID_FILL,small_box_color);
	for(i=1; i<=5; i++,y=y+30)
	{
	floodfill(x,y,line_color);
	}

   //	for red box
	x = 165;y = 240;
	small_box_color = RED;
	setfillstyle(SOLID_FILL,small_box_color);
	for(i=1; i<=5; i++,x=x-30)
	{
	floodfill(x,y,line_color);
	}

   //  for green box
	x = 240;y = 165;
	small_box_color = GREEN;
	setfillstyle(SOLID_FILL,small_box_color);
	for(i=1; i<=5; i++,y=y-30)
	{
	floodfill(x,y,line_color);
	}

	/******** setting of safe points on board*******************/

	/******bottom layer**********/

	line(180,420,220,450);      //beside the box
	line(220,420,180,450);

	line(260,390,300,420);
	line(300,390,260,420);     //on other side

	/*******left layer*********/

	line(30,180,60,220);
	line(60,180,30,220);		//beside the box

	line(60,260,90,300);
	line(90,260,60,300);		//on other side

	/*******top layer**********/

	line(260,30,300,60);
	line(300,30,260,60);			//beside the box

	line(180,60,220,90);
	line(220,60,180,90);             // on other side

	/******right layer *********/

	line(420,300,450,260);
	line(420,260,450,300);		 //beside the box

	line(390,220,420,180);
	line(390,180,420,220);			//on other side




/*******	drawing rectangle for control box	***/

	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	rectangle(490,0,640,480);
	setcolor(WHITE);
	settextstyle(GOTHIC_FONT,HORIZ_DIR,3);
	outtextxy(510,10,"control box");

    //*******all control's inside the box

	//	for dice
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	outtextxy(500,60,"DICE :");
	setlinestyle(SOLID_LINE,0,NORM_WIDTH);
	rectangle(560,50,600,70);

	//for throw box

	rectangle(500,80,600,100);
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(550,90,WHITE);
	outtextxy(530,90,"throw");
/************partition for name****************/
		//------------------------------//
	line(490,110,640,110);
	      //displaying name

	line(560,110,560,190);

	line(490,190,640,190);


	outtextxy(500,120,"player ");  //playername

	//-----------------------------------//

/************status of coin***************/

	outtextxy(500,140,"coin1 ");
	outtextxy(500,150,"coin2 ");
	outtextxy(500,160,"coin3 ");
	outtextxy(500,170,"coin4 ");

/************box for coin selection**********/

	//selecting with a mouse
	outtextxy(520,190,"select coin..");

	//rectangle has been setted
		//for each coin selection //
		//making 4 box for each coin
	rectangle(495,200,635,240);
	line(530,200,530,240);
	line(565,200,565,240);
	line(600,200,600,240);



/***********************************************/

/************for status reporting column***********/

	line(490,250,640,250);

	//status
	outtextxy(540,260,"status");


      }

     // structure includes features needed by coins


	struct coins
	{
	int xco,yco;	//to save coordinates of each coins
			//for current position

	int coin_color;	//to save color of coin

	int *add;	//to save location of coin into memory

	int status;     //if 0 not entered the board
			//if return 1 if coin enters in board
			//if 2 is released after play

	int movednum;	//how many columns have been moved
			//by the coin to identify each coin moves 57
			//small boxes to release
	int freepos;    //if in freeposition return 1 else 0
			//freeposition helps to escape from crossing of
			//coin by another players coin
	int xmov,ymov;    //direction changer variable while moving

	};


	class player

	{

	coins coin1,coin2,coin3,coin4; //each 4 coins

	coins *choosen;         //temperory pointer to change coin

			//for saving each coin
	char name[10];             //to save name of player

	int count;	//to get the value when dice is throwed
	int finish_player;	//return 1 if player had finished playing
				//else return 0
	int select;		//coin selection by user

	int player_color;	//to identify player color

	int xco1,yco1;

	public:

	player()
	{
	coin1.status = coin2.status = coin3.status = coin4.status = 0;
	coin1.movednum = coin2.movednum = coin3.movednum = coin4.movednum = 0;

	}

	player(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,
					int color,int xchanger,int ychanger)
	{

	player_color = color;
	coin1.xmov = coin2.xmov = coin3.xmov = coin4.xmov = xchanger;
	coin1.ymov = coin2.ymov = coin3.ymov = coin4.ymov = ychanger;

	coin1.xco = x1;
	coin1.yco = y1;

	coin1.xco = x2;
	coin1.yco = y2;

	coin1.xco = x3;
	coin1.yco = y3;

	coin1.xco = x4;
	coin1.yco = y4;

	coin1.coin_color = coin2.coin_color = coin3.coin_color =
				coin4.coin_color = color;

	coin1.status = coin2.status = coin3.status = coin4.status = 0;

	coin1.movednum = coin2.movednum = coin3.movednum =
						  coin4.movednum = 0;


	}

	void read_player_name()
	{
	settextstyle(SMALL_FONT,HORIZ_DIR,3);
	cout<<"enter the player name\n";
	gets(name);

	}

	void display_player_name()
	{
	setcolor(WHITE);             //display name when player changes

	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	outtextxy(580,120,name);
	}

	friend void display_player(player* ,player* ,player* ,player *);


	void dicethrow();	//for throwing dice for each player

	void display_coin_status();     //for displaying status of
					//coin on control box

	int selection_list();		//to check whether
					//any coin is available for moving

	void movement();	//for movement of each player's coin

	int boarder_check();	//to deviate if boarder is present
	int final_check();	//to check if particular column reaches
	void freearea();	//detect whether a coin is in free area

	void cross_coin();	//crossing of another players coin
	void finish_coin();

	void reintialise();

	friend void draw_with_save(player *, player *, player * ,player *);

	};

	void player::dicethrow()
	{

	setcolor(WHITE);
	int cx,dx;
	cx = dx = 0;
	union REGS regs;
	regs.x.ax = 1;
	int86(0x33,&regs,&regs);       //setted the mouse cursor

	while(TRUE)               //exit loop only after mouse click occurs
	{

	randomize();

	regs.x.ax = 5;
	regs.x.bx = 0;
	int86(0x33,&regs,&regs);      // to detect if mouse click occurs

	if(regs.x.bx)
	{
	cx = regs.x.cx;
	dx = regs.x.dx;
	}


	if((cx >= 500 && cx <= 600)&&
				(dx >= 80 && dx <= 100))
	{
			       //if click is correct then
	sound(30);  delay(1000);      //sound generates
	sound(40);  delay(1000);
	sound(50);  delay(1000);
	nosound();

	count = random(7);

	if(count == 0)
	{
	count++;
	}

	switch(count)
	{
	case 1:outtextxy(580,60,"1");
		break;
	case 2:outtextxy(580,60,"2");
		break;
	case 3:outtextxy(580,60,"3");
		break;
	case 4:outtextxy(580,60,"4");
		break;
	case 5:outtextxy(580,60,"5");
		break;
	case 6:outtextxy(580,60,"6");
	}

	return;

	}          //if finishes
	else continue;

	}     //loop finishes

	}

      void player::display_coin_status()
      {
	setcolor(WHITE);

	//test for coin1
      if(coin1.status == 0)
      {
      outtextxy(600,140,"NOT");
      }
      else if(coin1.status == 1)
      {
      outtextxy(600,140,"IN");
      }
      else if(coin1.status == 2)
      {
      outtextxy(600,140,"FIN");
      }

      //test for coin2

      if(coin2.status == 0)
      {
      outtextxy(600,150,"NOT");
      }
      else if(coin2.status == 1)
      {
      outtextxy(600,150,"IN");
      }
      else if(coin2.status == 2)
      {
      outtextxy(600,150,"FIN");
      }

      //test for coin3

      if(coin3.status == 0)
      {
      outtextxy(600,160,"NOT");
      }
      else if(coin3.status == 1)
      {
      outtextxy(600,160,"IN");
      }
      else if(coin3.status == 2)
      {
      outtextxy(600,160,"FIN");
      }

      //test for coin4

      if(coin4.status == 0)
      {
      outtextxy(600,170,"NOT");
      }
      else if(coin4.status == 1)
      {
      outtextxy(600,170,"IN");
      }
      else if(coin4.status == 2)
      {
      outtextxy(600,170,"FIN");
      }

      }

      int player::selection_list()
      {

      int avai1,avai2,avai3,avai4 = 0;
      //display greenly if 1st coin is available
		//else would print in red

       if(count == 1 && (coin1.status != 2 ))
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(512,220,WHITE);
       avai1 = 1;
       }
       else if(count !=1 && (coin1.status != 0) && (coin1.status != 2) &&
		coin1.movednum + count <= 57)
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(512,220,WHITE);
       avai1 = 1;
       }
       else
       {
       setfillstyle(SOLID_FILL,RED);
       floodfill(512,220,WHITE);
       avai1 = 0;
       }

       //display greenly if 2nd coin is available
		//else would print in red

       if(count == 1 && (coin2.status != 2 ))
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(547,220,WHITE);
       avai2 = 1;
       }
       else if(count !=1 && (coin2.status != 0) && (coin2.status != 2) &&
		coin2.movednum + count <= 57)
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(547,220,WHITE);
       avai2 = 1;
       }
       else
       {
       setfillstyle(SOLID_FILL,RED);
       floodfill(547,220,WHITE);
       avai2 = 0;
       }


       //display greenly if 3rd coin is available
		//else would print in red

       if(count == 1 && (coin3.status != 2 ))
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(582,220,WHITE);
       avai3 = 1;
       }
       else if(count !=1 && (coin3.status != 0) && (coin3.status != 2) &&
		coin3.movednum + count <= 57)
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(582,220,WHITE);
       avai3 = 1;
       }
       else
       {
       setfillstyle(SOLID_FILL,RED);
       floodfill(582,220,WHITE);
       avai3 = 0;
       }

       //display greenly if 4th coin is available
		//else would print in red

       if(count == 1 && (coin4.status != 2 ))
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(617,220,WHITE);
       avai4 = 1;
       }
       else if(count !=1 && (coin4.status != 0) && (coin4.status != 2) &&
		coin4.movednum + count <= 57)
       {
       setfillstyle(SOLID_FILL,GREEN);
       floodfill(617,220,WHITE);
       avai4 = 1;
       }
       else
       {
       setfillstyle(SOLID_FILL,RED);
       floodfill(617,220,WHITE);
       avai4 = 0;
       }



      //	display coin number on each column

	outtextxy(512,220,"1");
	outtextxy(547,220,"2");
	outtextxy(582,220,"3");
	outtextxy(617,220,"4");
	union REGS regs;
	int cx,dx;

	while(TRUE)
	{
	regs.x.ax = 5;
	int86(0x33,&regs,&regs);
	if(regs.x.bx)
	{
	cx = regs.x.cx;
	dx = regs.x.dx;
	}
	if(((cx >= 495 && cx <= 530) && (dx >= 200 && dx <=240) &&
						avai1 == 1))
	{
	select = 1; break;
	}
	else if(((cx >= 530 && cx <= 565) && (dx >= 200 && dx <=240) &&
							avai2 == 1))
	{
	select = 2;  break;
	}
	else if(((cx >= 565 && cx <= 600) && (dx >= 200 && dx <=240) &&
							avai3 == 1))
	{
	select = 3;   break;
	}
	else if(((cx >= 600 && cx <= 635) && (dx >= 200 && dx <=240) &&
							avai4 == 1))
	{
	select = 4;   break;
	}


	if(avai1 != 1 && avai2 != 1 && avai3 != 1 && avai4 != 1)
	{
	break;
	}
	}
	if(avai1 == 1 || avai2 == 1 || avai3 == 1 || avai4 == 1)
	return 1;
	else
	return 0;
	}


     void player::movement()
     {

     if(select == 1)
     {
     choosen = &coin1;
     }
     else if(select == 2)
     {
     choosen = &coin2;
     }
     else if(select == 3)
     {
     choosen = &coin3;
     }
     else if(select == 4)
     {
     choosen = &coin4;
     }

		 //checking if coin is enter for first time
		 //   in board
     if( count == 1 && ( choosen -> status == 0))

	{

     if( player_color == YELLOW)
     {

     if( select == 1 )
     {
     choosen -> xco = 193; choosen -> yco = 428;

     putimage(43,343, choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen ->yco,choosen ->add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 2)
     {
     choosen -> xco = 193; choosen ->yco = 428;

     putimage(123,343,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen ->yco,choosen ->add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 3)
     {
     choosen -> xco = 193; choosen -> yco = 428;

     putimage(43,423,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen ->yco,choosen ->add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 4)
     {
     choosen -> xco = 193; choosen -> yco = 428;

     putimage(123,423,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen ->yco,choosen ->add,XOR_PUT);;
     choosen -> status = 1;
     choosen -> movednum++;
     }
     }
     else if(player_color == RED)
     {

     if(select == 1)
     {
     choosen -> xco = 38; choosen -> yco = 193;

     putimage(43,43,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 2)
     {
     choosen -> xco = 38; choosen -> yco = 193;

     putimage(123,43,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 3)
     {
     choosen -> xco = 38; choosen -> yco = 193;

     putimage(43,123,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 4)
     {
     choosen -> xco = 38; choosen -> yco = 193;

     putimage(123,123,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     }
     else if(player_color == GREEN)
     {

     if(select == 1)
     {
     choosen -> xco = 273; choosen -> yco = 38;

     putimage(343,43,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 2)
     {
     choosen -> xco = 273; choosen -> yco = 38;

     putimage(423,43,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 3)
     {
     choosen -> xco = 273; choosen -> yco = 38;

     putimage(343,123,choosen ->add,XOR_PUT);
     putimage(coin3.xco,coin3.yco,coin3.add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 4)
     {
     choosen -> xco = 273; choosen -> yco = 38;

     putimage(423,123,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen ->add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     }
     else if(player_color == BLUE)
     {

     if(select == 1)
     {
     choosen -> xco = 428; choosen -> yco = 273;

     putimage(343,343,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 2)
     {
     choosen -> xco = 428; choosen -> yco = 273;

     putimage(423,343,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 3)
     {
     choosen -> xco = 428; choosen -> yco = 273;

     putimage(343,423,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     else if(select == 4)
     {
     choosen -> xco = 428; choosen -> yco = 273;

     putimage(423,423,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     choosen -> status = 1;
     choosen -> movednum++;
     }
     }
     }
     else if((choosen -> status != 2 || choosen -> status != 2 || choosen -> status != 2 ||
		choosen -> status != 2))
     {
       int mover = 1; //setted the column wise incrementing of coin


     while(mover <= count)
     {

     int ret = player::boarder_check();
     int ret1 = player::final_check();
     if(ret == 0 && ret1 == 0)
     {
     xco1 = choosen -> xco;
     yco1 = choosen -> yco;
     choosen -> xco = choosen -> xco + choosen -> xmov;
     choosen -> yco = choosen -> yco + choosen -> ymov;
     putimage(xco1,yco1,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     sound(100);
     delay(500);
     nosound();
     player::freearea();
     choosen -> movednum++;
     }
     else
     {
     putimage(xco1,yco1,choosen -> add,XOR_PUT);
     putimage(choosen -> xco,choosen -> yco,choosen -> add,XOR_PUT);
     sound(100);
     delay(500);
     nosound();
     player::freearea();
     choosen->movednum++;
     }

     mover++;

     }
     }
     else
     {
     return;
     }

     }

     int player::boarder_check()
     {

     if( choosen -> xco == 193 && choosen -> yco == 308)
     {
     xco1 = choosen -> xco;
     yco1 = choosen -> yco;
     choosen -> xco = 158;
     choosen -> yco = 273;
     choosen -> xmov = -30;
     choosen -> ymov = 0;
     return 1;
     }
     else if(choosen->xco == 8 && choosen->yco == 273)
     {
     choosen->xmov = 0;
     choosen->ymov = -40;
     }
     else if(choosen->xco == 8 && choosen->yco == 193)
     {
     choosen->xmov = +30;
     choosen->ymov =0;
     }
     else if(choosen->xco == 158 && choosen->yco == 193)
     {
     xco1 = choosen->xco;
     yco1 = choosen->yco;
     choosen->xco = 193;
     choosen->yco = 158;
     choosen->xmov = 0;
     choosen->ymov = -30;
     return 1;

     }
     else if(choosen -> xco == 193 && choosen -> yco == 8)
     {
     choosen -> xmov = -40;
     choosen -> ymov = 0;
     }
     else if(choosen -> xco == 273 && choosen -> yco == 8)
     {
     choosen -> xmov = 0;
     choosen -> ymov = 30;
     }
     else if(choosen -> xco == 273 && choosen -> yco == 158)
     {
     xco1 = choosen -> xco;
     yco1 = choosen -> yco;
     choosen -> xco = 308;
     choosen -> yco = 193;
     choosen -> xmov = 30;
     choosen -> ymov = 0;
     return 1;
     }
     else if(choosen->xco == 458 && choosen->yco == 193)
     {
     choosen -> xmov = 0;
     choosen -> ymov = 40;
     }
     else if(choosen -> xco == 458 && choosen -> yco == 273)
     {
     choosen -> xmov = -30;
     choosen -> ymov = 0;
     }
     else if(choosen -> xco == 308 && choosen -> yco == 273)
     {
     xco1 = choosen -> xco;
     yco1 = choosen -> yco;
     choosen -> xco = 273;
     choosen -> yco = 307;
     choosen -> xmov = 0;
     choosen -> ymov = 30;
     return 1;
     }
     else if(choosen -> xco == 273 && choosen -> yco == 458)
     {
     choosen -> xmov = -40;
     choosen -> ymov = 0;
     }
     else if(choosen -> xco == 193 && choosen -> yco == 458)
     {
     choosen -> xmov = 0;
     choosen -> ymov = -30;
     }
      return 0;


     }

     int player::final_check()
     {

      if(player_color == YELLOW)
      {
      if((choosen->xco == 233 && choosen->yco == 458) && choosen -> movednum == 51)
      {
      xco1 = choosen->xco;
      yco1 = choosen->yco;
      choosen->xmov = 0;
      choosen->ymov = -30;
      return 1;
      }
      else return 0;
      }
      else if(player_color == RED)
      {
      if((choosen -> xco == 8 && choosen -> yco == 233 ) && choosen -> movednum == 51 )
      {
      xco1 = choosen -> xco;
      yco1 = choosen -> yco;
      choosen -> xmov = 30;
      choosen -> ymov = 0;
      return 1;
      }
      else return 0;
      }
      else if(player_color == GREEN)
      {
      if((choosen -> xco == 233 && choosen -> yco == 8 )  && choosen -> movednum == 51 )
      {
      xco1 = choosen -> xco;
      yco1 = choosen -> yco;
      choosen -> xmov = 0;
      choosen -> ymov = 30;
      return 1;
      }
      else return 0;
      }
      else if(player_color == BLUE)
      {
      if((choosen -> xco == 458 && choosen -> yco == 233 ) && choosen -> movednum == 51)
      {
      xco1 = choosen -> xco;
      yco1 = choosen -> yco;
      choosen -> xmov = -30;
      choosen -> ymov = 0;
      return 1;
      }
      else return 0;
      }
      }


      void player::freearea()
      {
      if((choosen -> xco == 193 && choosen -> yco == 428)    ||
	 (choosen -> xco == 273 && choosen -> yco == 398)    ||
	 (choosen -> xco == 38  && choosen -> yco == 193)    ||
	 (choosen -> xco == 68  && choosen -> yco == 273)    ||
	 (choosen -> xco == 193 && choosen -> yco == 68 )    ||
	 (choosen -> xco == 273 && choosen -> yco == 38 )    ||
	 (choosen -> xco == 398 && choosen -> yco == 193)    ||
	 (choosen -> xco == 428 && choosen -> yco == 273))

      {

      choosen -> freepos = 1;

      }
      else
      {
      choosen -> freepos = 0;
      }

      }

     void player::reintialise()
     {

     setfillstyle(SOLID_FILL,BLACK);

     bar(561,51,599,69);    //clearing the dice column

     bar(561,111,638,189);  //clearing the name and coin status

     bar(496,201,529,239);
     bar(531,201,564,239);
     bar(566,201,599,239);
     bar(601,201,634,239);



     }


     void main()
     {

     ludo_interface ludo;
     int play_changer = 1;  //player changer in main
     int noplay;

     //intialising with argument passing for the first time

     player yellow_player(50,350,130,350,50,430,130,430,YELLOW,0,-30);
     player red_player(50,50,130,50,50,130,130,130,RED,30,0);
     player green_player(350,50,430,50,350,130,430,130,GREEN,0,30);
     player blue_player(350,350,430,350,350,430,430,430,BLUE,-30,0);

     //reading player names

     yellow_player.read_player_name();
     red_player.read_player_name();
     green_player.read_player_name();
     blue_player.read_player_name();

     //		intialising graphic system

		ludo.intialise_graph();
		ludo.draw_rect();

     draw_with_save(&yellow_player,&red_player,&green_player,&blue_player);

     display_player(&yellow_player,&red_player,&green_player,&blue_player);


     //		playing begins

		while(TRUE)
		{
		if(play_changer == 1)
		{
		yellow_player.display_player_name();
		yellow_player.dicethrow();
		yellow_player.display_coin_status();
		noplay = yellow_player.selection_list();
		if(noplay == 1)
		{
		yellow_player.movement();
		delay(7000);
		yellow_player.reintialise();
		}
		else
		{
		delay(2000);
		yellow_player.reintialise();
		}
		}
		else if(play_changer == 2)
		{
		red_player.display_player_name();
		red_player.dicethrow();
		red_player.display_coin_status();
		noplay = red_player.selection_list();
		if(noplay == 1)
		{
		red_player.movement();
		delay(7000);
		red_player.reintialise();
		}
		else
		{
		delay(2000);
		red_player.reintialise();
		}

		}
		else if(play_changer == 3)
		{
		green_player.display_player_name();
		green_player.dicethrow();
		green_player.display_coin_status();
		noplay = green_player.selection_list();
		if(noplay == 1)
		{
		green_player.movement();
		delay(7000);
		green_player.reintialise();
		}
		else
		{
		delay(2000);
		green_player.reintialise();
		}
		}
		else if(play_changer == 4)
		{
		blue_player.display_player_name();
		blue_player.dicethrow();
		blue_player.display_coin_status();
		noplay = blue_player.selection_list();
		if(noplay == 1)
		{
		blue_player.movement();
		delay(7000);
		blue_player.reintialise();
		}
		else
		{
		delay(2000);
		blue_player.reintialise();
		}
		}
		play_changer++;
		if(play_changer == 5)
		{
		play_changer = 1;
		}
		}
		getch();
		ludo.finish();

		}

	void draw_with_save(player * yp,player *rp,player *gp,player *bp)
	{

	 int coin_area1,coin_area2,coin_area3,coin_area4;
	setcolor(BLACK);


	setfillstyle(SOLID_FILL,YELLOW);
	//yellow coin
	     //1st coin drawing

	rectangle(43,343,57,357);
	floodfill(50,350,BLACK);
	outtextxy(50,350,"1");

	//2nd coin drawing
       rectangle(123,343,137,357);
       floodfill(130,350,BLACK);
       outtextxy(130,350,"2");

       //3rd coin drawing
       rectangle(43,423,57,437);
       floodfill(50,430,BLACK);
       outtextxy(50,430,"3");

       //4th coin drawing
       rectangle(123,423,137,437);
       floodfill(130,430,BLACK);
       outtextxy(130,430,"4");

      // for saving position of yellow coin into memory
			   //1st  coin memory area calculation
       coin_area1 = imagesize(43,343,57,357);
       yp -> coin1.add = (int*)malloc(coin_area1);



			//2nd coin  calculation
       coin_area2 = imagesize(123,343,137,357);
       yp -> coin2.add = (int*)malloc(coin_area2);



			//3rd coin calculation
       coin_area3 = imagesize(43,423,57,437);
       yp -> coin3.add = (int*)malloc(coin_area3);



			//4th coin calculation
       coin_area4 = imagesize(123,423,137,437);
       yp -> coin2.add = (int*)malloc(coin_area4);



       //saving

       getimage(43,343,57,357,yp -> coin1.add);

       getimage(123,343,137,357,yp -> coin2.add);

       getimage(43,423,57,437,yp -> coin3.add);

       getimage(123,423,137,437,yp -> coin4.add);


     // for saving postion of red coin into memory

	setfillstyle(SOLID_FILL,RED);
	//red coin drawing
		//1st coin  drawing
      rectangle(43,43,57,57);
      floodfill(50,50,BLACK);
      outtextxy(50,50,"1");

      //2nd coin  drawing
      rectangle(123,43,137,57);
      floodfill(130,50,BLACK);
      outtextxy(130,50,"2");

      //3rd coin drawing
      rectangle(43,123,57,137);
      floodfill(50,130,BLACK);
      outtextxy(50,130,"3");

      //4th coin drawing
      rectangle(123,123,137,137);
      floodfill(130,130,BLACK);
      outtextxy(130,130,"4");


			   //1st  coin calculation
     coin_area1 = imagesize(43,43,57,57);
     rp -> coin1.add = (int*)malloc(coin_area1);



			//2nd coin calculation
     coin_area2 = imagesize(123,43,137,57);
     rp -> coin2.add = (int*)malloc(coin_area2);



			//3rd coin calculation
     coin_area3 = imagesize(43,123,57,137);
     rp -> coin3.add = (int*)malloc(coin_area3);


			//4th coin calculation
     coin_area4 = imagesize(123,123,137,137);
     rp -> coin4.add = (int*)malloc(coin_area4);



     //saving

     getimage(43,43,57,57,rp -> coin1.add);

     getimage(123,43,137,57,rp -> coin2.add);

     getimage(43,123,57,137,rp -> coin3.add);

     getimage(123,123,137,137,rp -> coin4.add);


	// for drawing postion of green coin into memory
      //green coin
      setfillstyle(SOLID_FILL,GREEN);

		//1st coin drawing
      rectangle(343,43,357,57);
      floodfill(350,50,BLACK);
      outtextxy(350,50,"1");

      //2nd coin drawing
      rectangle(423,43,437,57);
      floodfill(430,50,BLACK);
      outtextxy(430,50,"2");

      //3rd coin drawing
      rectangle(343,123,357,137);
      floodfill(350,130,BLACK);
      outtextxy(350,130,"3");

       //4th coin drawing
      rectangle(423,123,437,137);
      floodfill(430,130,BLACK);
      outtextxy(430,130,"4");


			   //1st  coin calculation
     coin_area1 = imagesize(343,43,357,57);
     gp -> coin1.add = (int*)malloc(coin_area1);



			//2nd coin  calculation
     coin_area2 = imagesize(423,43,437,57);
     gp -> coin2.add = (int*)malloc(coin_area2);



			//3rd coin calculation
     coin_area3 = imagesize(343,123,357,137);
     gp -> coin3.add = (int*)malloc(coin_area3);



			//4th coin calculation
     coin_area4 = imagesize(423,123,437,137);
     gp -> coin4.add = (int*)malloc(coin_area4);



     //saving

     getimage(343,43,357,57,gp -> coin1.add);

     getimage(423,43,437,57,gp -> coin2.add);

     getimage(343,123,357,137,gp -> coin3.add);

     getimage(423,123,437,137,gp -> coin4.add);


      // for drawing position of blue coin into memory
      //blue coin
      setfillstyle(SOLID_FILL,BLUE);
		//1st coin drawing
      rectangle(343,343,357,357);
      floodfill(350,350,BLACK);
      outtextxy(350,350,"1");

       //2nd coin drawing
      rectangle(423,343,437,357);
      floodfill(430,350,BLACK);
      outtextxy(430,350,"2");

       //3rd coin drawing
      rectangle(343,423,357,437);
      floodfill(350,430,BLACK);
      outtextxy(350,430,"3");


      //4th coin drawing
      rectangle(423,423,437,437);
      floodfill(430,430,BLACK);
      outtextxy(430,430,"4");


			   //1st  coin  calculation
     coin_area1 = imagesize(343,343,357,357);
     bp -> coin1.add = (int*)malloc(coin_area1);



			//2nd coin calculation
     coin_area2 = imagesize(423,337,437,357);
     bp -> coin2.add = (int*)malloc(coin_area2);



			//3rd coin calculation
     coin_area3 = imagesize(343,423,357,437);
     bp -> coin3.add = (int*)malloc(coin_area3);



			//4th coin calculation
     coin_area4 = imagesize(423,423,437,437);
     bp -> coin4.add = (int*)malloc(coin_area4);



     //saving

     getimage(343,343,357,357,bp -> coin1.add);

     getimage(423,343,437,357,bp -> coin2.add);

     getimage(343,423,357,437,bp -> coin3.add);

     getimage(423,423,437,437,bp -> coin4.add);



     }

     void display_player(player * yp ,player * rp,player * gp, player * bp)
	{

	setcolor(WHITE);

	settextstyle(GOTHIC_FONT,HORIZ_DIR,2);


	outtextxy(5,305,yp -> name);
	outtextxy(5,5,rp -> name);
	outtextxy(305,5,gp -> name);
	outtextxy(305,305,bp -> name);

	}

















