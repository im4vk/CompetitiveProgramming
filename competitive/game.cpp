// #include "headers.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string s[4]={"Pratyay","Gaurav","Vikas","Neelabjo"};
int b[4]={0,0,0,0};
struct room
{
    int bat;
    int ball;
    int chappal;
    int bottle;
};

class player
{
    public :
    int bat;
    int ball;
    int bottle;
    int chappal;
    int health;
    int bag;
    int position;
    int secret1,secret2,secret3;
    int code1,code2,code3,code4;
    room r[5];
    int battery;

    player()
    {
         bag=0;
         bat=0;
         ball=0;
         bottle=0;
         chappal=0;
         health=100;
         position=1; //hostel
         secret1=0;secret2=0;secret3=0;
         code1=0;code2=0;code3=0;code4=0;
         for(int i=0;i<5;i++)
         {
             r[i].ball=rand()%15;
             r[i].bat=rand()%5;
             r[i].bottle=rand()%10;
             r[i].chappal=rand()%10;
         }
         battery=0;
    }

    void others()
    {
      int j;
      cout<<"1. MAP 2. HEALTH 3.GAME TERMINAL 4.ACCESORIES 5. Drop"<<endl;
      cin>>j;
      if(j==1)
      {
        map();
      }
      if(j==2)
      {
        cout<<"HEALTH  "<<health<<endl;
      }
      if(j==3)
      {
        string CODE;
        cin>>CODE;
        if(CODE=="BAT")
        {
          if(bag+10<=100)
          {
            bat++;
          }
        }
        if(CODE=="BALL")
        {
          if(bag+2<=100)
          {
            ball++;
          }
        }
        if(CODE=="CHAPPAL")
        {
          if(bag+5<=100)
          {
            chappal++;
          }
        }
        if(CODE=="HEALTH")
        {
          health=100;
        }
      }
      if(j==4)
      {     bag1();
      }
      if(j==5)
      {
          drop();
      }
    }
    void initiate()
        {  health=100;
          cout<<"You have encountered a small zombie Viranchoid.Remember you dont own any weapons.Show your physical strength.";
          zombie(1);

          rooms();


            int temp=rand()%2+1;
            cout<<"OH NO!! SEEMS THAT ZOMBIES ARE APPROACHING YOU IN YOUR CORRIDOR.LOAD YOUR WEAPONS AS NOW ITS ACTION TIME........"<<endl;
            zombie(temp);
            travel();

            return;
        }

    void rooms()
    {
      cout<<"YOU MIGHT GET SOMETHING THAT WOULD HELP YOU FIGHT THE ZOMBOTS IN YOUR FRIENDS' ROOMS"<<endl;
      cout<<"Room no.      .       Friend's name"<<endl;
      cout<<"  1           .        HIMANSHU-BOT    "<<endl;
      cout<<"  2           .        PRABAL-BEE    "<<endl;
      cout<<"  3           .        KAJANIYOID"<<endl;
      cout<<"  4           .        ANSHDEEN"<<endl;
      cout<<"  5           .        APU_BOT"<<endl;
        for(int i=0;i<3;i++)
        {   cout<<"you want to see accesories in the bag  1.yes  2.no"<<endl;
            int m;
            cin>>m;
           if(m==1) bag1();
            int room_no;
            cout<<"WHICH ROOM(1,2,3,4,5) WOULD YOU PREFER TO GO IN?  "<<endl;
            cin>>room_no;

            if(room_no<=5 && room_no>=1)
            {
                cout<<"bat       "<<r[room_no-1].bat<<endl;
                cout<<"ball      "<<r[room_no-1].ball<<endl;
                cout<<"chappal   "<<r[room_no-1].chappal<<endl;
                cout<<"bottle    "<<r[room_no-1].bottle<<endl;

                int b,ba,ch,bo,d=1;
                while(d){


                cout<<"how many bat , bottle , chapple , bottle  you want to pick"<<endl;
                cin>>b>>ba>>ch>>bo;

                if(b>r[room_no-1].bat) {cout<<"there are only "<<r[room_no-1].bat<<" bats\n"; continue;}
                if(ba>r[room_no-1].ball) {cout<<"there are only "<<r[room_no-1].ball<<" balls\n"; continue;}
                if(ch>r[room_no-1].chappal) {cout<<"there are only "<<r[room_no-1].chappal<<" chappals\n"; continue;}
                if(bo>r[room_no-1].bottle) {cout<<"there are only "<<r[room_no-1].bottle<<" bottles\n"; continue;}

                if((10*(bat+b)+2*(ball+ba)+5*(chappal+ch)+8*(bottle+bo)>100))
                 {  cout<<"you can't pick this combination(bag has insufficient space available)"<<endl;
                   cout<<"your bag have only "<<(100-bag)<<" percent space"<<endl;}
                 else {d=0;  r[room_no-1].bat=r[room_no-1].bat-b;
                             r[room_no-1].ball=r[room_no-1].ball-ba;
                             r[room_no-1].chappal=r[room_no-1].chappal-ch;
                             r[room_no-1].bottle=r[room_no-1].bottle-bo;
                         bat=bat+b;
                         ball=ball+ba;
                         chappal=chappal+ch;
                         bottle=bottle+bo;
                         bag=10*bat+2*ball+5*chappal+8*bottle; }

                 }
             }

            else {cout<<"OH MAN!!!! CALM DOWN ,  WHEN YOU ARE TENSED YOU CANNOT MAKE RIGHT DECISIONS \n"
                        "        **       YOU MADE AN INVALID CHOICE          **                      \n"
                        "                   *    TRY AGAIN       *          "<<endl; i--;  }


        }

     }


    void zombie(int i)
    {
      if(health<=0)
    {
      cout<<"SORRY, YOUR HEALTH LEVEL IS ZERO . YOU LOOSE"<<endl;
      cout<<"GAME RESTARTING........."<<endl;
      initiate();
    }
       if(i<=0)
           {cout<<"THANK GOD!  NO ONE HERE. KEEP MOVING"<<endl; return;}
        int k;
        cout<<"THERE ARE "<<i<<" ZOMBIES REMAINING"<<endl;
        cout<<"FIGHT........."<<endl;
        cout<<"SELECT WEAPON ----- \n"
              "  YOU WEAPON SELECTION DECIDES YOUR FATE \n"
            "     1. bat  \n"
            "     2. ball  \n"
            "     3. chappal  \n"
            "     4. bottle  \n"
            "     5. no weapon .SHOW YOUR PHYSICAL STRENGTH\n"
            "     6.OTHERS"<<endl;
        cin>>k;
        switch(k)
        {
            case 1:
                 if(bat>0)
                { bat--;
                  zombie(i-3);
                }
                 else {cout<<"no bat "; zombie(i);}
                 break;
            case 2:
                if(ball>0)
                {ball--;
                zombie(i-1);
                }

                else {cout<<"no ball "; zombie(i);}
                break;
            case 3:
                if(chappal>0){
                chappal--;
                zombie(i-2);
                }
                else {cout<<"no chapal "; zombie(i);}
                break;
            case 4:
                if(bottle>0){
                bottle--;
                zombie(i-3);
                 }
                else {cout<<"no bottle "; zombie(i);}
                break;
            case 5:
                cout<<"no weapon ";
                health=health-30;


                if(health<=0)
                {
                  cout<<"YOU LOOSE"<<endl;
                  initiate();
                }
                else zombie(i-1);
                break;

            case 6:
            {others();zombie(i);}
            return;
        }
    }

    void drop()
    {   int i,n;
        cout<<"which weapon do you want to drop"<<endl;
        cout<<"1. bat  2. ball  3. chappal  4. bottle  5. none "<<endl;
        cin>>i;
        cout<<"how many weapons do you want to drop"<<endl;
        cin>>n;

        switch(i)
        {
            case 1:
                {
                    if(bat>=n) bat=bat-n;
                    else { cout<<"there are only "<<bat<<" bats"<<endl;
                           drop();}
                    break;
                }
            case 2:
                {
                    if(ball>=n) ball=ball-n;
                    else { cout<<"there are only "<<ball<<" balls"<<endl;
                           drop();}
                    break;
                }
            case 3:
                {
                    if(chappal>=n) chappal=chappal-n;
                    else { cout<<"there are only "<<chappal<<" chappals"<<endl;
                           drop();}
                    break;
                }
            case 4:
                {
                    if(bottle>=i) bottle=bottle-i;
                    else { cout<<"there are only "<<bottle<<" bottles"<<endl;
                           drop();}
                    break;
                }
            case 5:
                return;
        }

    }

    void map()
    {
      cout<<"      ------------------                                                                   -----------------"<<endl;
      cout<<"      |                |                                                                   |               |"<<endl;
      cout<<"      |                |-------------------------------------------------------------------|               |"<<endl;
      cout<<"      |      MINING    |-------------------------------------------------------------------|     MESS      |"<<endl;
      cout<<"      |                |                                                                   |               |"<<endl;
      cout<<"      |                |-----------------------------------                                |               |-----------------------------"<<endl;
      cout<<"      ------------------ -------------------------------   |                                -------------------------------------------   |"<<endl;
      cout<<"                       ||                                | |                                              | |                           | |"<<endl;
      cout<<"                       ||                                | |                                              | |                           | |"<<endl;
      cout<<"                       ||                                | |                                              | |                           | |"<<endl;
      cout<<"                       ||                                | |----------------------------------------------  |                           | |"<<endl;
      cout<<"                       ||                                -------------------------------------------------  |                           | |"<<endl;
      cout<<"                       ||                                                                                 | |                           | |"<<endl;
      cout<<"                       ||                                                                                 | |                           | |"<<endl;
      cout<<"                       ||                                                                                 | |                           | |"<<endl;
      cout<<"------------------     ||                            ------------------                               ------------------                | |"<<endl;
      cout<<"|                |     ||____________________________|                |                               |                |                | |"<<endl;
      cout<<"|                |     |_____________________________|                |                               |                |                | |"<<endl;
      cout<<"|     AC.BL.     |                                   |     ADMIN      |                               |      HOSTEL    |                | |"<<endl;
      cout<<"|                |                                   |                |                               |                |                | |"<<endl;
      cout<<"|                |                                   |                |                               |                |                | |"<<endl;
      cout<<"------------------                                   ------------------                               ------------------                | |"<<endl;
      cout<<"              | |                                                                                                                       | |"<<endl;
      cout<<"              | |                                                                                                                       | |"<<endl;
      cout<<"              |  -----------------------------------------------------------------------------------------------------------------------| |"<<endl;
      cout<<"              ----------------------------------------------------------------------------------------------------------------------------|"<<endl;;
        cout<<"DUE TO SECURITY REASONS HIDDEN PATHS ARE NOT SHOWN"<<endl;
    }
 void travel()     //secret hatana hai      rebuild
     {
         int i;
         switch(position)
         {
            case 1:
                {
                   if(secret1==0 && secret2==0)
                   {
                    cout<<"4 for mess 2 for mining  6. first floor  ";
                  }
                  if(secret1!=0 && secret2==0)
                  {
                    cout<<"4 for mess 2 for mining  6. first floor 3.for academic";
                  }
                    if(secret1!=0 && secret2!=0)
                    {
                      cout<<"4 for mess 2 for mining  6. first floor  3.for academic  5.for adminBlock ";
                    }
                  break;
                }
            case 2:
                {
                    cout<<"1. hostel  4. mess  5.  admin block";
                    break;
                }
            case 3:
                {
                  if(secret1==0 && secret2==0)
                  {
                   cout<<"4 for mess ";
                 }
                 if(secret1!=0 && secret2==0)
                 {
                   cout<<"4 for mess 1.hostel";

                 }
                   if(secret1!=0 && secret2!=0)
                   {
                     cout<<"4 for mess 1.hostel  5.for adminBlock ";

                   }
                  break;
                }
            case 4:
                {
                    cout<<"1. hostel   3. academic block  2. mining ";
                    break;
                }
            case 5:
                {
                    cout<<"2. mining";
                    break;
                }
            case 6:
                {
                    cout<<"1. ground floor  7.  second floor";
                    break;
                }
            case 7:
                {
                    cout<<"6. first floor  1.ground floor";
                    break;
                }
         }

         cout<<"choose path "<<endl;
         cin>>i;
         position=i;
         switch(i)
         {
            case 1: hostel(); break;
            case 2: mining(); break;
            case 3: academic(); break;
            case 4: mess(); break;
            case 5: admin(); break;
            case 6: firstfloor(); break;
            case 7: secondfloor(); break;
         }

     }

void bag1()
    {
        cout<<"bat      "<<bat<<endl;
        cout<<"ball     "<<ball<<endl;
        cout<<"chappal  "<<chappal<<endl;
        cout<<"bottle   "<<bottle<<endl;
        cout<<"bag is "<<(10*bat+2*ball+5*chappal+8*bottle)<<" percent full"<<endl;
    }

bool isPrime(int n)
{
  bool p=true;
  for(int i=1;i<n;i++)
  {
    if(n%i==0)
    {
      p=false;
      break;
    }
  }
  return p;
}
void hostel()
{
  int i;
  zombie(rand()%4);
  cout<<"PRESS 1 TO GO TO TO GO TO YOUR ROOM TO REVIVE ENERGY"<<endl;
  cin>>i;
  if(i)
  {
    health=100;
  }

  travel();

}

void academic()
{
  zombie(rand()%5);

  int i;
  cout<<"1.LH1 2.tut1";
  cin>>i;
  if(i==1)
  {
    cout<<"LOK PATI"<<endl;
    cout<<"                   4                                       1 \n";
    cout<<"                   /\\                                      /\\ \n";
    cout<<"                  /  \\                                    /  \\ \n";
    cout<<"                 /    \\                                  /    \\ \n";
    cout<<"                /      \\                                /      \\ \n";
    cout<<"               /   12   \\                              /   4    \\ \n";
    cout<<"              /          \\                            /          \\ \n";
    cout<<"             /            \\                          /            \\ \n";
    cout<<"          7  --------------  9                    1  --------------4 \n";


    cout<<"                                     2 \n";
    cout<<"                                    /\\ \n";
    cout<<"                                   /  \\ \n";
    cout<<"                                  /    \\ \n";
    cout<<"                                 /      \\ \n";
    cout<<"                                /   ?    \\ \n";
    cout<<"                               /          \\ \n";
    cout<<"                              /            \\ \n";
    cout<<"                           6  --------------  5 \n";

    cout<<"                 WHICH NUMBER REPLACES THE QUESTION MARK?                "<<endl;
    int n;
    cin>>n;
    if(n==9)
    {
      health=90;
    }
    else
    {
      health=health/2;
    }
  }
  if(i==2)
  {
    cout<<"DHANYA MAM"<<endl<<endl;
    cout<<"     |   2   |   3  |"<<endl;
    cout<<"     |   6   |   4  |"<<endl;
    cout<<"     |   8   |   12 |"<<endl;
    cout<<"     |   24  |   ?  |"<<endl;

        cout<<"WHICH NUMBER REPLACES THE QUESTION MARK?"<<endl;
        int ans;
        cin>>ans;
        if(ans==16)
        {
          health=100;
        }
        else
        {
          health=min(health+30ll,100ll);
        }
  }
  int k;
  cout<<"DO YOU WANT TO SHOUT FOR BHAIYA"<<endl;
  cout<<" 1.YES 0.NO"<<endl;
  cin>>k;
  int k1=rand()%2;
  if(k){
  if(k1)
  {
      code2=1;
      string s;
      int z;
      while(1)
      {   z=rand()%4;
          s=s[z];
          if(b[z]==0) {cout<<"HURRAY! WE FOUND "<<s<<" bhaiya as WELL AS ONE PART OT THE CODE "<<endl;
                       b[z]=1;
              travel();
              break;}
      }
  }
  else
  {
      zombie(rand()%4);
  }}
  else
  {
      travel();
  }
}

void admin()
{
  zombie(rand()%3);

  int i;
  cout<<"1.for change";
  cin>>i;
  if(i==1)
  {
    travel();
  }
  else
  {
    int j;
    cout<<"1 for director's cabin 2 for amaldev's cabin";
    cin>>j;
    if(j==1)
    {
      bool won=false;
      zombie(rand()%6);//835
      int n=rand()%3+1;
      if(n==1)
      {
      cout<<"4    -    -    -    -    8    -    -    -"<<endl;
      cout<<"-    8    -    6    7    -    2    5    -"<<endl;
      cout<<"-    -    -    -    -    3    -    -    1"<<endl;
      cout<<"-    -    3    9    -    6    5    -    -"<<endl;
      cout<<"-    -    8    2    -    4    1    3    -"<<endl;
      cout<<"-    4    -    3    8    7    -    2    9"<<endl;
      cout<<"9    1    -    -    -    -    7    -    2"<<endl;
      cout<<"-    3    -    7    -    -    -    1    -"<<endl;
      cout<<"7    -    -    1    6    -    4    -    -"<<endl;
      cout<<endl<<endl<<"THE FIRST THREE NUMBERS IN THE THIRD LINE IS THE KEY"<<endl;
      int kj;
      cin>>kj;
      if(kj==835)
      won=true;
    }
    if(n==2)
    {
    cout<<"2    -    -    -    -    4    -    5    -"<<endl;
    cout<<"-    6    -    7    -    -    9    5    2"<<endl;
    cout<<"7    -    -    -    -    -    4    -    -"<<endl;
    cout<<"-    -    4    6    -    -    -    -    8"<<endl;
    cout<<"-    5    9    -    8    -    6    4    3"<<endl;
    cout<<"-    7    -    4    3    5    -    2    -"<<endl;
    cout<<"6    8    -    5    -    -    -    -    -"<<endl;
    cout<<"-    -    -    1    7    -    8    3    -"<<endl;
    cout<<"-    1    7    -    -    8    2    6    -"<<endl;
    cout<<endl<<endl<<"THE FIRST THREE NUMBERS IN THE THIRD LINE IS THE KEY"<<endl;
    int kj;
    cin>>kj;
    if(kj==324)
    won=true;
  }
  if(n==3)
  {
  cout<<"-    8    -    -    3    -    4    -    5"<<endl;
  cout<<"-    -    9    2    -    -    3    -    6"<<endl;
  cout<<"3    -    4    -    -    6    7    -    9"<<endl;
  cout<<"-    6    8    -    5    -    -    -    -"<<endl;
  cout<<"9    4    -    6    8    -    -    3    2"<<endl;
  cout<<"-    -    -    7    -    -    -    6    -"<<endl;
  cout<<"4    1    -    -    -    2    -    5    -"<<endl;
  cout<<"-    -    5    -    6    4    -    7    1"<<endl;
  cout<<"-    3    -    1    -    -    -    -    -"<<endl;
  cout<<endl<<endl<<"THE FIRST THREE NUMBERS IN THE THIRD LINE IS THE KEY"<<endl;
  int kj;
  cin>>kj;
  if(kj==268)
  won=true;
}
      if(won)
      {
        health=100;
        battery=1;
        cout<<"YOU HAVE STOLEN BATTERY WITHOUT THE NOTICE OF ZOMBOTS"<<endl;
      }
      else
      {cout<<"WRONG ANSWER"<<endl;
        travel();

        }
    }
    if(j==2)
    {
      zombie(rand()%3);
    }
  }
  if(code1==1 && code2==1 && code3==1 && code4==1&& battery==1)
  {
    int i;
    cout<<"DO YOU TRUST AMALDEV AND AFTER MAKING SURE THAT NOTHING IS WRONG AROUND YOU WANT TO SUBMIT CODE 1.yes 0.no";
    cin>>i;
    if(i)
    cout<<"YOU WON THE GAME";
    initiate();
  }
  else
  {
    if(battery==1)
    {
      cout<<"AMALDEV: NOW I FEEL BETTER BUT GO QUICKLY GET ME THE CODES"<<endl;
      travel();
    }
    else
    {
      cout<<"AMALDEV sir needs batteries urgently as he Doesn't HAVE MUCH TIME LEFT . HURRY UP"<<endl;
      travel();
    }
  }
}

void mess()
{
  int i;
  cout<<"1.ice cream 2.chapati 3.chole bhature  4.drugs  5.others";
  cin>>i;
  if(i==1)
  {
    health=min(100ll,health+10ll);
  }
  if(i==2)
  {
    health=min(100ll,health+30ll);
  }
  if(i==3)
  {
    health=min(100ll,health+20ll);
  }
  if(i==4)
  {
    health=5;
    cout<<"your health is very low"<<endl;
    cout<<"HAVEN'T YOU HEARD- 'SAY NO TO DRUGS'"<<endl;
    cout<<"NOW REAP WHAT YOU HAVE SOWN"<<endl;
  }

  if(i==5)
  {
    others();
  }
  int r;
  cout<<"DO WANT TO SHOUT FOR BHAIYA 1.YES 0.NO"<<endl;
  cin>>r;
  int r1=rand()%2;
  if(r)
  {
      if(r1)
      {
          zombie(rand()%2);
          code3=1;
          string s;
          int z;
          while(1)
          {   z=rand()%4;
              s=s[z];
              if(b[z]==0) {cout<<"HURRAY! WE FOUND "<<s<<" bhaiya as WELL AS ONE PART OT THE CODE "<<endl;
                           b[z]=1;break;}
          }
      }
      else
      {
          zombie(rand()%4);
      }
  }
      travel();
}

void firstfloor()
{
  int i;
  cout<<"do you want to shout for bhaiya     0.no 1.yes";
  cin>>i;
  if(i)
  {
    zombie(rand()%4);
  }
  if(rand()%2)
  {
    code1=1;
    string s;
    int z;
    while(1)
    {   z=rand()%4;
        s=s[z];
        if(b[z]==0) {cout<<"HURRAY! WE FOUND "<<s<<" bhaiya as WELL AS ONE PART OT THE CODE "<<endl;
                   b[z]=1;break;}
    }
  }
  travel();
}
void secondfloor()
{
  int i;
  if(code1!=0){
  cout<<"do you want to shout for bhaiya     0.no 1.yes";
  cin>>i;
  if(i)
  {
    zombie(rand()%2);
  }
  if(rand()%2)
  {
    code1=1;
  }
  else zombie(rand()%2);
}
travel();
}
void mining()
{
  int i;
  cout<<"1.computer lab  2.ask special weapon from bhaiya hiding in security guard's cabin  3.change location "<<endl;
  cin>>i;
  if(i==1)
  {
    map();
    bag1();
  }
  if(i==2)
  {
    cout<<"TO GET IT SOLVE A RIDDLE FOR ME"<<endl;
    cout<<"            puzzle      \n "
          " A 3 digit number xyz (all digits different) is such that 3 X xyz = zzz \n"
          " Find the three digit number and enter it\n";


    int o;
    cin>>o;
    if(o==185)
    {
      cout<<"WELL DONE! YOU HAVE WON AN AXE AS WELL AS THE CODE"<<endl;
      code4=1;
      string s;
      int z;
      while(1)
      {   z=rand()%4;
          s=s[z];
          if(b[z]==0) {cout<<"HURRAY! WE FOUND "<<s<<" bhaiya as WELL AS ONE PART OT THE CODE "<<endl;
                       b[z]=1;break;}
      }
    }
    else
    {
      cout<<"YOU LOST 50 PERCENT OF YOUR HEALTH BUT ARE ABLE TO KILL VAIBHOID"<<endl;
      health=health/2;
      cout<<"TIME TO MOVE ON"<<endl;
    }

    cout<<"HERE COMES THE BIGGEST ZOMBOID VAIBHOID"<<endl;
    cout<<"HE is so furious that his roar has made infected Sudiptoid faint down to coma as the virus from his roar infects through head and sudiptoid has no hair for protection!!!";
    cout<<"DON'T CALL ME VAIBHOID , CALL ME BIG_SHOID"<<endl;
    cout<<"I CAN USE MY AXE TO KILL HIM";
    cout<<"VAIBHOID IS KILLED"<<endl;
    cout<<"TIME TO MOVE AHEAD"<<endl;

  }


  int v;
  cout<<"you have found a secret vault do you wish to open it 1. yes  2. continue to normal path"<<endl;
  cin>>v;
  if(v==1)
  {  int w;
     cout<<"here is the puzzle :  pq is a two digit prime number which comes at xy postion in the list of prime numbers starting from 2."<<endl;
     cout<<"the number qp is also a prime number and appears at yx position in the same list."<<endl;
     cout<<"Find out the number pq and enter it."<<endl;
     cin>>w;
     if(w==73)
     { cout<<"You have obtained the code some batteries and a path that takes you to Amaldev sir's cabin;"<<endl;
        cout<<"You reach Sir's cabin free him and retrieve all the student and faculty bots"<<endl;
        cout<<"---*** YOU WIN DUDE ***---"<<endl;     }
     else
     {  cout<<"wrong answer you are sent back again"<<endl;
        travel();
     }
  }
  else{travel();}
 }
};
int32_t main()
{
   srand(time(0));
   cout<<"*****************************************************************************************************************************************************"<<endl<<endl;

   cout<<"                                                             WELCOME TO THE PRESTIGIOUS ENGINEERING COLLEGE"<<endl<<endl;
   cout<<"                                                                THE INDIAN INSTITUTE OF BOT TECHNOLOGY"<<endl;
   cout<<"                                                                         PONDA,GOA-403401"<<endl<<endl;
   cout<<"******************************************************************************************************************************************************"<<endl;
     cout<<endl<<endl<<"HEY PLAYER!"<<endl;
     cout<<"Enter your details"<<endl;
     cout<<" NAME : ";
     string name;
     cin>>name;
     cout<<endl<<"The game zone is situated in the campus of IIT Goa consisting of the ADMIN,ACADEMIC,MINING blocks , the HOSTEL and MESS."<<endl;
     cout<<"The story overviews a hypothetical incident where a computer virus has affected majority of staff and student bots."<<endl;
     cout<<"You are the saviour and the only capable healthy bot to solve this issue."<<endl;
     cout<<"The culprit for this issue is most confused professor of IIT Goa: Hope you understand"<<endl;
     cout<<"You need to find 4 parts of code which are possesed by the organisers of pokethon(spread all over the campus) and take them to Amaldev sir"<<endl;
     cout<<"Amaldev sir is the only person with knowledge required to solve this issue and retain all the student and faculty bots"<<endl;
     cout<<"Weapons are BAT:(3 kills), BALL:(1 kill), CHAPPAL:(2 kills), BOTTLE:(3 kills)"<<endl<<"So, Suit up as the game begins now"<<endl;
     cout<<name<<"oid woke up realising that current is absent in it's hostel"<<endl;
     cout<<"OH MY GOD!!!! 19 missed calls from Amaldev sir . What could have possibly gone wrong."<<endl;
     cout<<"SHIT!! NO CURRENT .  Telephone is not working. I must go and see Sir in person...."<<endl;
     cout<<"Message:(Amaldev Sir)--The bots have been infected by a virus, my batteries have been damaged, Ive locked myself in my office in ADMIN Block"<<endl<<"Bring me part codes from Pratyay, Gaurav,Neelabjo and Vikas"<<endl;
     cout<<"YOU GET UP AND OPEN THE DOOR AND BOOM"<<endl;
     cout<<"All bots are RED and seem to be more aggressive . One starts running towards you with a curtain rod"<<endl;
     cout<<"You ,being terribly afraid run for you life towards the bathroom"<<endl;
     cout<<"Seeing through the window and being a smart bot you could easily make out that possibly in todays LOK PATI's lecture , he must have had passed on de-Morvies virus to all the students"<<endl;
     cout<<"You count yourself to be lucky having slept late at night therefore sleeping in your room while the lecture was going on"<<endl;
     cout<<"Being a social bot you are determined to help all your fellow friends and teachers by getting the antivirus POKIRA-antivirus"<<endl;
     cout<<"Escaping from ZOMBOTS(infected BOTS) is not that easy but with luck , hard-work and wishes of friend , teachers and parents you can make through it"<<endl;
     cout<<endl<<endl<<"                 #          BEST  OF  LUCK             # \n"
                         "                           game begins..........     "<<endl;

    player p1;
    p1.initiate();
    return 0;
}