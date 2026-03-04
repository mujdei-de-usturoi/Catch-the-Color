//Copyright Gheorghe Stefan Augustin
#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <string.h>
#include <ctime>
#include <windows.h>

using namespace std;

bool is_main_menu=1,is_rules_page=0,is_started=0,is_exitted=0;
int current_level=1,timer=5000;

char colors_to_choose_from[10][8]= {"BLUE","RED","PINK","CYAN","LIME","GREY","ORANGE","PURPLE","YELLOW","WHITE"};
char color_to_find[8];

int i_guaranteed,j_guaranteed;

char options[11][11][8];

void rules_page();


//functia afiseaza pe ecranul grafic meniul principal
void main_menu()
{
    for(int i=1; i<=100; i++)
    {
        clearmouseclick(WM_LBUTTONDOWN);
    }
    clearviewport();
    setcolor(COLOR(255,255,255));
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,6);
    outtextxy(20,20,"Catch The Color");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
    outtextxy(20,90,"The intentionally chaotically");
    outtextxy(20,110,"designed timed color clicking game");

    setcolor(COLOR(35,35,255));
    for(int i=0; i<=10; i++)
    {
        rectangle(450+i,590-i,650-i,640+i);
    }
    outtextxy(510,605,"START");

    setcolor(COLOR(100,255,0));
    for(int i=0; i<=10; i++)
    {
        rectangle(250+i,390-i,450-i,440+i);
    }
    outtextxy(310,405,"RULES");

    setcolor(COLOR(246,24,24));
    for(int i=0; i<=10; i++)
    {
        rectangle(40+i,190-i,250-i,240+i);
    }
    outtextxy(117,205,"EXIT");

}

//functia afiseaza pe ecranul grafic pagina de reguli ale jocului
void rules_page()
{
    for(int i=1; i<=100; i++)
    {
        clearmouseclick(WM_LBUTTONDOWN);
    }
    clearviewport();
    setcolor(COLOR(255,255,255));
    settextstyle(GOTHIC_FONT,HORIZ_DIR,6);
    outtext("How to play:");
    settextstyle(GOTHIC_FONT,HORIZ_DIR,2);

    outtextxy(0,64,"When the game starts, a grid of colored shapes");
    outtextxy(0,88,"will be shown on screen along with a timer.");

    outtextxy(0,136,"You have to click on the indicated color before");
    outtextxy(0,160,"the timer runs out.");

    outtextxy(0,208,"As you progress through levels you will have less");
    outtextxy(0,232,"time to find the color");

    outtextxy(0,280,"Reach level 15 to win.Good luck!");
    for(int i=0; i<=10; i++)
    {
        rectangle(450+i,590-i,650-i,640+i);
    }
    outtextxy(510,605,"BACK");

}

//functia ruleaza ecranul de incarcare al jocului
void loading_screen()
{
    for(int i=1; i<=100; i++)
    {
        clearmouseclick(WM_LBUTTONDOWN);
    }
    setcolor(COLOR(0,255,255));
    setfillstyle(SOLID_FILL,COLOR(0,255,255));
    pieslice(350,350,0,120,50);
    delay(1000);
    setcolor(COLOR(255,240,31));
    setfillstyle(SOLID_FILL,COLOR(255,240,31));
    pieslice(350,350,120,240,100);
    delay(1000);
    setcolor(COLOR(255,0,144));
    setfillstyle(SOLID_FILL,COLOR(255,0,144));
    pieslice(350,350,240,360,150);
    delay(1000);
}

//functia transforma numarul nivelului curent intr-un sir de caractere
//pentru a fi adaugat la sirul destinat numarului nivelului curent
void int_to_char(int current_level,char level_value[3])
{
    if(current_level<10)
    {
        level_value[0]=current_level+48;
        level_value[1]='\0';
    }
    else
    {
        level_value[0]=current_level/10+48;
        level_value[1]=current_level%10+48;
        level_value[2]='\0';
    }
}

//functia pregateste scheletul nivelului (gridul si texte standard)
void prepare_game()
{
    for(int i=1; i<=100; i++)
    {
        clearmouseclick(WM_LBUTTONDOWN);
    }
    setcolor(COLOR(255,255,255));
    char level_text[9],level_value[3];
    strcpy(level_text,"Level ");
    int_to_char(current_level,level_value);
    strcat(level_text,level_value);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(5,1,level_text);
    setlinestyle(SOLID_LINE,0,1);
    line(0,200,700,200);
    for(int i=0; i<=700; i+=70)
    {
        line(i,200,i,700);
    }
    line(699,200,699,700);
    for(int i=200; i<=700; i+=50)
    {
        line(0,i,700,i);
    }
    line(0,699,700,699);
    settextstyle(BOLD_FONT,HORIZ_DIR,10);
    outtextxy(0,16,"FIND:");
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    outtextxy(5,140,"REMAINING TIME:");

}

//functia plaseaza o forma de o anumita culoare in grid
void fill_table(char color_to_put[8],int shape,int x,int y)
{
    setcolor(COLOR(22,22,29));
    setfillstyle(SOLID_FILL,COLOR(22,22,29));
    bar(70*x-70+3,200+y*50-50+2,70*x-70+2+66,200+y*50-50+2+46);


    //"BLUE","RED","PINK","CYAN","LIME","GREY","ORANGE","PURPLE","YELLOW","WHITE"
    if(strstr(color_to_put,"BLUE"))
    {
        setcolor(COLOR(35,35,255));
        setfillstyle(SOLID_FILL,COLOR(35,35,255));
    }
    if(strstr(color_to_put,"RED"))
    {
        setcolor(COLOR(246,24,24));
        setfillstyle(SOLID_FILL,COLOR(246,24,24));
    }
    if(strstr(color_to_put,"PINK"))
    {
        setcolor(COLOR(255,0,144));
        setfillstyle(SOLID_FILL,COLOR(255,0,144));
    }
    if(strstr(color_to_put,"CYAN"))
    {
        setcolor(COLOR(0,255,255));
        setfillstyle(SOLID_FILL,COLOR(0,255,255));
    }
    if(strstr(color_to_put,"LIME"))
    {
        setcolor(COLOR(137,243,54));
        setfillstyle(SOLID_FILL,COLOR(137,243,54));
    }
    if(strstr(color_to_put,"GREY"))
    {
        setcolor(COLOR(123,123,125));
        setfillstyle(SOLID_FILL,COLOR(123,123,125));
    }
    if(strstr(color_to_put,"ORANGE"))
    {
        setcolor(COLOR(255,153,28));
        setfillstyle(SOLID_FILL,COLOR(255,153,28));
    }
    if(strstr(color_to_put,"PURPLE"))
    {
        setcolor(COLOR(138,0,196));
        setfillstyle(SOLID_FILL,COLOR(138,0,196));
    }
    if(strstr(color_to_put,"YELLOW"))
    {
        setcolor(COLOR(255,240,31));
        setfillstyle(SOLID_FILL,COLOR(255,240,31));
    }
    if(strstr(color_to_put,"WHITE"))
    {
        setcolor(COLOR(255,255,255));
        setfillstyle(SOLID_FILL,COLOR(255,255,255));
    }
    switch(shape)
    {
    case 0:
    {
        bar(70*x-70+3,200+y*50-50+2,70*x-70+2+66,200+y*50-50+2+46);
        break;
    }
    case 1:
    {
        fillellipse(70*x-70+35,200+y*50-25,23,23);
        break;
    }
    case 2:
    {
        fillellipse(70*x-70+35,200+y*50-25,31,11);
        break;
    }
    }
}

//functia decide si plaseaza culorile si formele din grid, asiguranduse ca exista cel putin
//o varianta corecta
void setup_game()
{
    strcpy(color_to_find,colors_to_choose_from[rand() % 10]);
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    setcolor(COLOR(22,22,29));
    setfillstyle(SOLID_FILL,COLOR(22,22,29));
    bar(360,58,700,100);
    setcolor(COLOR(255,255,255));
    outtextxy(360,58,color_to_find);
    i_guaranteed=rand() % 11;
    j_guaranteed=rand() % 11;
    if(i_guaranteed==0)
    {
        i_guaranteed=1;
    }
    if(j_guaranteed==0)
    {
        j_guaranteed=1;
    }
    for(int i=1; i<=10; i++)
    {
        for(int j=1; j<=10; j++)
        {
            strcpy(options[i][j],colors_to_choose_from[rand() % 10]);
            fill_table(options[i][j],rand() % 3,i,j);
        }
    }
    strcpy(options[i_guaranteed][j_guaranteed],color_to_find);
    fill_table(options[i_guaranteed][j_guaranteed],rand() % 3,i_guaranteed,j_guaranteed);
}

//functia verifica daca culoarea corecta a fost apasata
bool verify_color(int x, int y)
{
    if(strstr(options[x/70+1][(y-200)/50+1],color_to_find))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//functia afiseaza pe ecranul grafic ecranul pentru esec
void fail()
{
    clearviewport();
    settextstyle(BOLD_FONT,HORIZ_DIR,6);
    setcolor(COLOR(246,24,24));
    outtextxy(185,210,"You failed!");
    loading_screen();

}

//functia afiseaza timerul actualizat
void show_update_timer()
{
    timer-=10;
    char timer_text[5];
    timer_text[0]=timer/1000+48;
    timer_text[1]='.';
    timer_text[2]=timer/100%10+48;
    timer_text[3]=timer/10%10+48;
    timer_text[4]='\0';
    settextstyle(BOLD_FONT,HORIZ_DIR,5);
    setcolor(COLOR(255,255,255));
    outtextxy(470,149,timer_text);
}

//functia afiseaza pe ecranul grafic ecranul pentru castigarea jocului
void win_page()
{
    setbkcolor(COLOR(229,184,11));
    clearviewport();
    settextstyle(SCRIPT_FONT,VERT_DIR,10);
    setcolor(COLOR(255-229,225-184,255-11));
    outtextxy(300,700,"YOU WIN");
    settextstyle(SCRIPT_FONT,HORIZ_DIR,1);
    outtextxy(200,342,"Press anywhere to return to main menu");
    outtextxy(200,342,"Press anywhere to return to main menu");
    outtextxy(200,342,"Press anywhere to return to main menu");
    while(ismouseclick(WM_LBUTTONDOWN)==0)
    {
        ;
    }
    clearmouseclick(WM_LBUTTONDOWN);
}

int main()
{
    FreeConsole();
    initwindow(700,700,"Catch The Color");
    bool goto_mainmenu=0;

mainmenu:

    setbkcolor(COLOR(22,22,29));
    main_menu();
    timer=5000;
    goto_mainmenu=0;
    is_exitted=0;
    is_started=0;
    is_main_menu=1;
    is_rules_page=0;
    current_level=1;
    while(is_exitted==0 && is_started==0)
    {
        int x_clk=-1,y_clk=-1;
        if(ismouseclick(WM_LBUTTONDOWN)==1)
        {
            clearmouseclick(WM_LBUTTONDOWN);
            x_clk=mousex();
            y_clk=mousey();
        }

        if(is_main_menu==1)
        {

            if (x_clk>=40 && x_clk<=250 && y_clk>=180 && y_clk<=250)
            {
                is_exitted=1;
            }
            if (x_clk>=250 && x_clk<=450 && y_clk>=380 && y_clk<=450)
            {
                is_main_menu=0;
                is_rules_page=1;
                rules_page();
            }
            if (x_clk>=450 && x_clk<=650 && y_clk>=580 && y_clk<=650)
            {
                is_started=1;
            }
        }
        if(is_rules_page==1)
        {
            if(x_clk>=450 && x_clk<=650 && y_clk>=580 && y_clk<=650)
            {
                is_rules_page=0;
                is_main_menu=1;
                main_menu();
            }
        }

    }
    if(is_started==1 && current_level!=16)
    {
        clearviewport();
        loading_screen();
continue_game:
        prepare_game();
        bool choice=0;
        while(current_level!=16)
        {
            setup_game();
            bool color_chosen=0;
            while(color_chosen!=1)
            {
                int x_clk=-1,y_clk=-1;
                delay(10);
                show_update_timer();
                if(timer==0)
                {
                    color_chosen=1;
                    choice=0;
                }
                if(ismouseclick(WM_LBUTTONDOWN)==1)
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    x_clk=mousex();
                    y_clk=mousey();
                }
                if(y_clk>200)
                {
                    color_chosen=1;
                    choice=verify_color(x_clk,y_clk);
                }
            }
            if(choice==1)
            {
                current_level++;
                if(current_level<=5)
                {
                    timer=5000;
                }
                if(current_level>5 && current_level<=10)
                {
                    timer=2500;
                }
                if(current_level>10)
                {
                    timer=1250;
                }
                goto continue_game;
            }
            else
            {
                fail();
                current_level=16;
                goto_mainmenu=1;
            }
        }
    }
    if(goto_mainmenu==1 && is_exitted==0)
    {
        goto mainmenu;
    }
    if(is_exitted==0)
    {
        win_page();
    }
    if(is_exitted==0)
    {
        goto mainmenu;
    }
}
