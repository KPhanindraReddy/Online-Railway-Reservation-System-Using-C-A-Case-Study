#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
char name[50];
int train_num;
int num_of_seats;
} pd;

void reservation (void);
void viewdetails (void);
void cancel (void);
void printticket (char name[], int, int, float);
void specifictrain (int);
float charge (int, int);
void login ();

int

main ()
{
system ("cls");
printf
("\t\t================================================
=\n");
printf ("\t\t| |\n");
printf ("\t\t| ----------------------------- |\n");
printf ("\t\t| TRAIN TICKET RERS. SYSTEM |\n");
printf ("\t\t| ----------------------------- |\n");

printf (" \n Press any key to continue:");
getch ();
system ("cls");
login ();
int menu_choice, choice_return;
start:
system ("cls");
printf ("\n=================================\n");
printf (" TRAIN RESERVATION SYSTEM");
printf ("\n=================================");
printf ("\n1>> Reserve A Ticket");
printf ("\n------------------------");
printf ("\n2>> View All Available Trains");
printf ("\n------------------------");

printf ("\n3>> Cancel Reservation");
printf ("\n------------------------");
printf ("\n4>> Exit");
printf ("\n------------------------");
printf ("\n\n-->");
scanf ("%d", &menu_choice);
switch (menu_choice)
{
case 1:
reservation (); //Fucntion still not added
break;
case 2:
viewdetails ();
printf ("\n\nPress any key to go to Main Menu..");
getch ();
break;
case 3:
cancel ();
//function not added. code has been removed due to some
errors
break;
case 4:
return (0);
default:

printf ("\nInvalid choice");
}
goto start;
return (0);
}

void
viewdetails (void)
{
system ("cls");
printf
("-----------------------------------------------------------------------------");
printf
("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
printf
("-----------------------------------------------------------------------------");
printf ("\n1001\tRed Lines Express\tkadapa to
vijayawada\tRs.5000\t9am");
printf ("\n1002\tRed Lines Express\tbangalore to
tirupati\tRs.5000\t12pm");
printf
("\n1003\tLA City Express\t\tvisakhapatnam to
hyderabad\t\tRs.4500\t8am");
printf

("\n1004\tLA City Express\t\tbangalore to
hyderabad\t\tRs.4500\t11am");
printf ("\n1005\tIron City Express\tkerala to
visakhapatnam\tRs.4000\t7am");
printf ("\n1006\tIron City Express\tbangalore to
chennai\tRs.4000\t9.30am");
printf ("\n1007\tKeystone Express\tgujarat to
maharashtra\tRs.3500\t1pm");
printf ("\n1008\tKeystone Express\tguntur to
nagpur\tRs.3500\t4pm");
printf ("\n1009\tMeteor Express\t\tkolkata to
bangalore\tRs.6000\t3.35pm");
printf ("\n1009\tMeteor Express\t\tbangalore to
delhi\tRs.6000\t4.15pm");

}

void
reservation (void)
{
char confirm;
int i = 0;
float charges;
pd passdetails;

FILE *fp;
fp = fopen ("seats_reserved.txt", "a");
system ("cls");

printf ("\nEnter Your Name:> ");
fflush (stdin);
gets (passdetails.name);
//error here have to take input of the name
printf ("\nEnter Number of seats:> ");
scanf ("%d", &passdetails.num_of_seats);
printf ("\n\n>>Press Enter To View Available Trains<< ");
getch ();
system ("cls");
viewdetails ();
printf ("\n\nEnter train number:> ");
start1:
scanf ("%d", &passdetails.train_num);
if (passdetails.train_num >= 1001 && passdetails.train_num <=
1010)
{
charges = charge (passdetails.train_num,
passdetails.num_of_seats);
printticket (passdetails.name, passdetails.num_of_seats,

passdetails.train_num, charges);

}

else
{
printf ("\nInvalid train Number! Enter again--> ");
goto start1;
}

printf ("\n\nConfirm Ticket (y/n):>");
start:
scanf (" %c", &confirm);
if (confirm == 'y')
{
fprintf (fp, "%s\t\t%d\t\t%d\t\t%.2f\n", &passdetails.name,
passdetails.num_of_seats, passdetails.train_num,
charges);
printf ("==================");
printf ("\n Reservation Done\n");
printf ("==================");
printf ("\nPress any key to go back to Main menu");
}
else
{
if (confirm == 'n')
{
printf

("\nReservation Not Done!\nPress any key to go back to
Main menu!");
}
else
{
printf ("\nInvalid choice entered! Enter again-----> ");
goto start;
}
}
fclose (fp);
getch ();
}

/*********************************************CHARGE(
)*************************************************/

float
charge (int train_num, int num_of_seats)
{
if (train_num == 1001)
{
return (5000.0 * num_of_seats);
}
if (train_num == 1002)
{

return (5000.0 * num_of_seats);
}
if (train_num == 1003)
{
return (4500.0 * num_of_seats);
}
if (train_num == 1004)
{
return (4500.0 * num_of_seats);
}
if (train_num == 1005)
{
return (4000.0 * num_of_seats);
}
if (train_num == 1006)
{
return (4000.0 * num_of_seats);
}
if (train_num == 1007)
{
return (3500.0 * num_of_seats);
}
if (train_num == 1008)
{

return (3500.0 * num_of_seats);
}
if (train_num == 1009)
{
return (6000.0 * num_of_seats);
}
if (train_num == 1010)
{
return (6000.0 * num_of_seats);
}
}

/*********************************************PRINTTIC
KET()*************************************************
/

void
printticket (char name[], int num_of_seats, int train_num, float
charges)
{
system ("cls");
printf ("-------------------\n");
printf ("\tTICKET\n");
printf ("-------------------\n\n");

printf ("Name:\t\t\t%s", name);
printf ("\nNumber Of Seats:\t%d", num_of_seats);
printf ("\nTrain Number:\t\t%d", train_num);
specifictrain (train_num);
printf ("\nCharges:\t\t%.2f", charges);
}

/*********************************************SPECIFIC
TRAIN()***********************************************
**/

void
specifictrain (int train_num)
{

if (train_num == 1001)
{
printf ("\nTrain:\t\t\tRed Lines Express");
printf ("\nDestination:\t\tkadapa to vijayawada");
printf ("\nDeparture:\t\t9am ");
}
if (train_num == 1002)
{
printf ("\nTrain:\t\t\tRed Lines Express");
printf ("\nDestination:\t\tbangalore to tirupati");

printf ("\nDeparture:\t\t12pm");
}
if (train_num == 1003)
{
printf ("\nTrain:\t\t\tLA City Express");
printf ("\nDestination:\t\tvisakhapatnam to hyderabad");
printf ("\nDeparture:\t\t8am");
}
if (train_num == 1004)
{
printf ("\nTrain:\t\t\tLA City Express");
printf ("\nDestination:\t\tbangalore to hyderabad");
printf ("\nDeparture:\t\t11am ");
}
if (train_num == 1005)
{
printf ("\nTrain:\t\t\tIron City Express");
printf ("\nDestination:\t\t kerala to visakhapatnam");
printf ("\nDeparture:\t\t7am");
}
if (train_num == 1006)
{
printf ("\ntrain:\t\t\tIron City Express");
printf ("\nDestination:\t\t bangalore to chennai");

printf ("\nDeparture:\t\t9.30am ");
}
if (train_num == 1007)
{
printf ("\ntrain:\t\t\tKeystone Express");
printf ("\nDestination:\t\tgujarat to maharashtra");
printf ("\nDeparture:\t\t1pm ");
}
if (train_num == 1008)
{
printf ("\ntrain:\t\t\tKeystone Express");
printf ("\n Destination:\t\tguntur to nagpur");
printf ("\nDeparture:\t\t4pm ");
}
if (train_num == 1009)
{
printf ("\ntrain:\t\t\tMeteor Express");
printf ("\nDestination:\t\tkolkata to bangalore");
printf ("\nDeparture:\t\t3.35pm ");
}
if (train_num == 1010)
{
printf ("\ntrain:\t\t\tMeteor Express");
printf ("\nDestination:\t\tbangalore to delhi ");

printf ("\nDeparture:\t\t1.15 ");
}
}

void
login ()
{
int a = 0, i = 0;
char uname[10], c = ' ';
char pword[10], code[10];
char user[10] = "user";
char pass[10] = "pass";
do
{

printf
("\n ======================= LOGIN FORM
=======================\n ");
printf (" \n ENTER USERNAME:-");
scanf ("%s", &uname);
printf (" \n ENTER PASSWORD:-");
while (i < 10)
{
pword[i] = getch ();

c = pword[i];
if (c == 13)
break;
else
printf ("*");
i++;
}
pword[i] = '\0';

i = 0;

if (strcmp (uname, "user") == 0 && strcmp (pword, "pass") ==
0)
{
printf
(" \n\n\n WELCOME TO OUR SYSTEM !! YOUR LOGIN
IS SUCCESSFUL");
printf ("\n\n\n\t\t\t\tPress any key to continue...");
getch ();
break;
}
else
{
printf ("\n SORRY !!!! LOGIN IS UNSUCESSFUL");
a++;

getch ();
system ("cls");
}
}
while (a <= 2);
if (a > 2)
{
printf
("\nSorry you have entered the wrong username and
password for four times!!!");

getch ();

}
system ("cls");
}

void
cancel (void)
{
system ("cls");
int trainnum;
printf ("-----------------------\n");

printf ("Enter the train number: \n");
printf ("-----------------------\n");
fflush (stdin);
scanf ("%i", &trainnum);
printf ("\n\nCancelled");
getch ();
}