// BSIT 1-2
// headers/ preprocessors
#include <TOOLBOX.h>


// global/ external declarations, prototypes
void screen_1();
void screen_2();
void screen_3();
void screen_4();
char press;
void clear_input_buffer(); // clearing ram input for less lag
char option = ' ';
void option2();
void print_pattern(int dividend);


void enter();
void clearFile();
void Reader();

int pageNum;

bool out = true;
char yesnt = ' ';
main()
{

    // this is the main function

    screen_1();
    option2();
}
void enter()
{

    gotoxy(58, 28);
    yesnt = tolower(getche());
    if (yesnt == 'y')
    {
        clearFile();
        hline(37, 21, 129, ' ');
        printxy(67, 37, "File Cleared!!!");
    }
    else if (yesnt == 'n')
    {

        hline(37, 21, 129, ' ');
        printxy(60, 37, "Option Cancelled! Choose again.");
        //
    }
}
void option2()
{

    while (out)
    {
        gotoxy(58, 28);
        option = tolower(getchar());

        if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == '\r')
        {

            if (option == 'a')
            {
                pushColor(14); // Highlight color
                gotoxy(33, 18);
                putchar(16);
                printxy(35, 18, "A) Create a new file");
                hline(37, 21, 129, ' ');
                printxy(52, 37, "Warning this will clear current file! Continue?[y/n]");
                enter();
            }
            else
            {
                pushColor(7); // Default color
                gotoxy(33, 18);
                putchar(' ');
                printxy(35, 18, "A) Create a new file");
                // hline(37, 21, 129, ' ');
            }

            gotoxy(35, 20);

            if (option == 'b')
            {
                pushColor(14); // Highlight color
                gotoxy(33, 20);
                putchar(16);
                printxy(35, 20, "B) Add a record");
                gotoxy(33, 22);
                putchar(' ');
                pushColor(7); // Default color
                printxy(35, 22, "C) Browse");
                pushColor(7); // Default color
                gotoxy(33, 24);
                putchar(' ');
                //                printxy(35, 24, "D) Close");
                // hline(37, 21, 129, ' ');
                screen_2();
            }
            else
            {
                pushColor(7); // Default color
                gotoxy(33, 20);
                putchar(' ');
                printxy(35, 20, "B) Add a record");
                // hline(37, 21, 129, ' ');
            }

            gotoxy(35, 22);

            if (option == 'c')
            {
                pushColor(14); // Highlight color
                gotoxy(33, 22);
                putchar(16);
                printxy(35, 22, "C) Browse");
                // hline(37, 21, 129, ' ');
                screen_3();

                // option2();
            }
            else
            {
                pushColor(7); // Default color
                printxy(35, 22, "C) Browse");
                gotoxy(33, 22);
                putchar(' ');

                // hline(37, 21, 129, ' ');
            }

            gotoxy(35, 24);

            if (option == 'd')
            {
                pushColor(14); // Highlight color
                gotoxy(33, 24);
                putchar(16);
                printxy(35, 24, "D) Close");
                // hline(37, 21, 129, ' ');
                screen_4();
                out = false;
            }
            else
            {
                pushColor(7); // Default color
                gotoxy(33, 24);
                putchar(' ');
                //                printxy(35, 24, "D) Close");
                // hline(37, 21, 129, ' ');
            }
        }
        else
        {
            // printxy(67, 37, "Invalid selection");
        }
    }
}
// Functions
void clearFile()
{
    getch();
    FILE *file = fopen("July-Justine.txt", "w");
    fprintf(file, "%c", ' ');
    fclose(file);
}
void screen_1()
{

    line1(20, 2, 130, 35); // Main Box
    line1(21, 3, 129, 34);

    // error box
    line1(20, 36, 130, 38);
    // printxy(63, 37, "Reserve for error Message");

    line1(22, 4, 128, 8); // Head Box

    printxy(56, 5, "Polytechnic University of the Phils.");
    printxy(66, 6, "San Juan Campus");
    printxy(67, 7, "San Juan City");

    // Left Box & Right Box
    line1(22, 9, 74, 33);
    line1(75, 9, 128, 33);

    // Menu Box
    line1(27, 10, 69, 12);
    printxy(44, 11, "Main Menu");

    // Menu Choices

    printxy(35, 18, "A) Create a new file"); // new txt file
    printxy(35, 20, "B) Add a record");
    printxy(35, 22, "C) Browse");
    printxy(35, 24, "D) Close");

    pushColor(14);
    printxy(40, 28, "Select an option: ");
    pushColor(14);

    // Right Box
    printxy(97, 19, "Programmed");
    printxy(101, 20, "By:");
    printxy(91, 22, "Justine Lloyd Bautista");
}
int count = 0;

char studNum[50];
char Ln[20];
char Fn[20];
char Mi[2];
char course;
void input()
{

    gotoxy(85, 16);
    scanf("%s", studNum); // Limit the input to avoid buffer overflow

    // last name
    pushColor(7); // Set color to yellow
    printxy(83, 15, "Student number");
    gotoxy(80, 15);
    putchar(' ');
    pushColor(14); // Set color to yellow
    printxy(83, 17, "Last name");
    gotoxy(80, 17);
    putchar(16);

    gotoxy(85, 18);
    scanf("%s", Ln); // Limit the input to avoid buffer overflow

    // firstname
    pushColor(7); // Set color to yellow
    printxy(83, 17, "Last name");
    gotoxy(80, 17);
    putchar(' ');
    pushColor(14); // Set color to yellow
    printxy(83, 19, "First name");
    gotoxy(80, 19);
    putchar(16);

    gotoxy(85, 20);
    // gets(firstname);
    scanf("%s", Fn); // Limit the input to avoid buffer overflow

    pushColor(7); // Set color to yellow
    printxy(83, 19, "First name");
    gotoxy(80, 19);
    putchar(' ');
    pushColor(14); // Set color to yellow
    printxy(83, 21, "M.I");
    gotoxy(80, 21);
    putchar(16);

    gotoxy(85, 22);
    scanf("%s", Mi);

    // Program Code
    pushColor(7); // Set color to white
    printxy(83, 21, "M.I");
    gotoxy(80, 21);
    putchar(' ');
    pushColor(14); // Set color to yellow
    printxy(83, 23, "Program Code");
    gotoxy(80, 23);
    putchar(16);
    gotoxy(85, 24);
    scanf("\n");
    scanf("%c", &course);
    pushColor(7);
    printxy(83, 23, "Program Code");
    gotoxy(80, 23);
    putchar(' ');

    pushColor(7);
    printxy(62, 37, "Press Enter key to continue...");
    getch();
    hline(37, 21, 129, ' ');
    gotoxy(58, 28);
    putchar(' ');

    FILE *file = fopen("July-Justine.txt", "a");

    // Write the inputs to the file

    fprintf(file, "%s %s %s %s %c\n",studNum, Ln, Fn, Mi, course);

    // Close the file

    fclose(file);

    // option2();
}



struct copy{
	char studNumCpy[50];
char LnCpy[20];
char FnCpy[20];
char MiCpy[2];
char courseCpy;	
}copy[10];



void screen_2()
{
    hline(37, 21, 129, ' ');
    pushColor(7);
    clearportion(76, 10, 127, 32);
    printxy(83, 15, "Student number");
    printxy(83, 17, "Last name");
    printxy(83, 19, "First name");
    printxy(83, 21, "M.I");
    printxy(83, 23, "Program Code");

    pushColor(14); // Set color to yellow
    printxy(83, 15, "Student number");
    gotoxy(80, 15);
    putchar(16);

    pushColor(14); // Set color to yellow
    printxy(83, 15, "Student number");
    gotoxy(80, 15);
    putchar(16);

    hline(16, 85, 100, ' ');
    hline(18, 85, 100, ' ');
    hline(20, 85, 100, ' ');
    hline(22, 85, 100, ' ');
    hline(24, 85, 100, ' ');

    input();
}
FILE *files;
  int start = 0;
    int end = 2;
    
     int i = 0;
    char line[100];
    int lineCount = 0;
    int maxDiv = 0;
    int Division[20];
   int page = 1;
   int countery;
void screen_3()
{
    pushColor(7);
    system("cls");

        printxy(54, 5, "Polytechnic University of the Philippines");
        printxy(66, 6, "San Juan Campus");
        printxy(67, 7, "San Juan City");
        pushColor(14);
        printxy(32, 10, "#");
        printxy(40, 10, "Student #");
        printxy(67, 10, "Student name");
        printxy(100, 10, "Program");
        pushColor(7);
        hline(11, 20, 130, '=');
        printxy(25, 8, "Page: ");
        gotoxy(32, 8);
    	 printf( "%d", page);

    // read

    printxy(62, 34, "Press Enter key to continue...");




int strcSize = sizeof(copy)/  sizeof(copy[0]);


print_pattern(i);
//printf("%d\n", Division[0]);
//printf("%d\n",  Division[1]);
//printf("%d\n",  Division[2]);
//printf("%d\n",  Division[3]);
   
//  }
	
//    screen_1();
files = fopen("July-Justine.txt", "r");

    while (fscanf(files, "%s %s %s %s %c\n",studNum, Ln, Fn, Mi, &course) != EOF)
    {

   strcpy(copy[i].studNumCpy, studNum);
   strcpy(copy[i].LnCpy,Ln);
   strcpy(copy[i].FnCpy, Fn);
   strcpy(copy[i].MiCpy, Mi);
   copy[i].courseCpy = course;
   i++;
   
    }
  fclose(files);
  bool valid = true;
 
    while(end <= 10){
  int y;  
	
	
		
	
    for(int x = start; x<=end; x++){
    	
	
    	gotoxy(32,12+y);
				printf("%d", x+1);

				gotoxy(40,12+y);
				printf("%s", copy[x].studNumCpy);
				
				gotoxy(63,12+y);
        printf("%s, ", copy[x].LnCpy);
        printf("%s", copy[x].FnCpy);
          printf(" %s.\t", copy[x].MiCpy);
    
    
     gotoxy(100,12+y);
        copy[x].courseCpy = toupper(copy[x].courseCpy);
        if (copy[x].courseCpy == 'A')
        {

            printf("Accounting");
        }
        else if (copy[x].courseCpy == 'B')
        {

            printf("Business");
        }
        else if (copy[x].courseCpy == 'C')
        {

            printf("Computer");
        }
        else
        {
            printf("Other courses");
        }
        y++;
         
  }
			getch();
		
			y =0;
			if(start <= 9){
				
				start += 3;
    	end += 3;
			}else{
					start += 1;
    	end += 1;
			}
    
    	 clearportion(20,12 ,130, 20 );
    	
    	 page++;
    	  gotoxy(32, 8);
    	 printf( "%d", page);
    	 
    
    	 
		}
  
    
    
}




void print_pattern(int dividend) {
    int remainder = dividend % 3;
    int count = 0;
    int set = dividend / 3;
    int sum = 3;
		int z;
    while (count < set) {
        
        Division[z] = sum;

        count++;
z++;
    }

    if (remainder > 0) {
         Division[z] = remainder;

z++;
    }
}



void Reader(){
	
	
	
	 
    
}
void screen_4()
{

    clearportion(76, 10, 127, 32);

    gotoxy(93, 17);
    ColoredText(COLOR_YELLOW, "SESSION CLOSING...");

    line1(85, 18, 117, 20);
    for (int x = 86; x <= 116; x++)
    {
        pushColor(14); // Set color to yellow
        box(86, 19, x, 19, 177);
        Sleep(5);
    }
    for (int x = 86; x <= 116; x++)
    {
        pushColor(14); // Set color to yellow
        box(86, 19, x, 19, 178);
    }

    printxy(93, 17, " SESSION CLOSED      ");
    pushColor(7); // Set color to white
    printxy(93, 24, "   MULA SA'YO,       ");
    printxy(93, 25, " PARA SA BAYAN.       ");

    gotoxy(58, 28);
    putchar(' ');
  
    out = false;
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Discard characters until newline or end of file
    }
}


/*Logic
Upon readinf I will copy the data to a struct and i wall basethe printing base on struct index 0-9 of each data
0-2 , 3-5 ,6-8, and 9


*/
