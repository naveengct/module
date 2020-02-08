#include<stdio.h>
struct bank{
  int id;
  float bal;
}b[10];
count_b=0;
count_g=0;
count_p=0;
struct card{
   int no;
   int id;
   int pin;
   float bal;
   char st;
}c[20];

struct purchase{
 int no;
 int cn;
 float amt;
}p[100];
void bank()
{
  printf("Enter the ID: ");
  scanf("%d",&b[count_b].id);
  printf("Enter the Amount: ");
  scanf("%f",&b[count_b].bal);
  count_b++;
//  dis_b();
}

void dis_b()
{
printf("ID  BALANCE\n");
for(int i=0;i<count_b;i++)
 printf("%d %f\n",b[i].id,b[i].bal);
}

void dis_p()
{
printf("TNO  CNO AMOUNT\n  ");
for(int i=0;i<count_p;i++)
 printf("%d    %d      %f\n",p[i].no,p[i].cn,p[i].amt);
}
void dis_g()
{
printf("CNO ID BALANCE STATUS\n");
for(int i=0;i<count_g;i++)
 printf("%d %d %d %f %c\n",c[i].no,c[i].id,c[i].pin,c[i].bal,c[i].st);
}

void create()
{
  printf("Enter your Customer ID: ");
  scanf("%d",&c[count_g].id);
  printf("Enter your Customer PIN: ");
  scanf("%d",&c[count_g].pin);
  printf("Enter your Customer Balance: ");
  scanf("%f",&c[count_g].bal);
  c[count_g].no=count_g+1;
  for(int i=0;i<count_b;i++)
   if(b[i].id==c[count_g].id)
      b[i].bal=b[i].bal-c[count_g].bal;
   c[count_g].st='Y';
  count_g++;
 // dis_g();
}

void topup()
{
  int n;
  float f;
  printf("Enter your Card ID: ");
  scanf("%d",&n);
   printf("Enter amount: ");
  scanf("%f",&f);
  for(int i=0;i<count_g;i++)
    if(c[i].no==n)
      {
      c[i].bal=c[i].bal+f;
       for(int j=0;j<count_b;j++)
      if(b[j].id==c[i].id)
      b[j].bal=b[j].bal-f;
      }
      // dis_g();
}

void close()
{
     int n,m;
  printf("Enter your Card ID: ");
  scanf("%d",&n);
   printf("Enter PIN ");
  scanf("%d",&m);
   for(int i=0;i<count_g;i++)
   if(c[i].no==n && c[i].pin==m)
   {
   for(int j=0;j<count_b;j++)
      if(b[j].id==c[i].id)
      b[j].bal=b[j].bal+c[i].bal;
       c[i].st='N';
     c[i].bal=0; 
   }
   //  dis_g();
      // dis_b();
}

void pur()
{
  int n,m;
  float f;
  printf("Enter your Card ID: ");
  scanf("%d",&n);
   printf("Enter PIN ");
  scanf("%d",&m);
   printf("Enter amount: ");
  scanf("%f",&f);
   for(int i=0;i<count_g;i++)
   if(c[i].no==n && c[i].pin==m)
   {
   c[i].bal=c[i].bal-f;
   p[count_p].cn=n;
      p[count_p].amt=f;
         p[count_p].no=count_p+1;
         count_p++;
   }
   // dis_g();
}
void main()
{
 int n,t,k=1;
 while(k)
 {
  printf("1.Acc 2.Gift 3.bank detail 4.card detail 5.purchase detail 6.exit\n");
  scanf("%d",&n);
  switch(n){
   case 1:
   bank();
   break;
   case 2:
   {
   printf("1.Card create 2.Top up 3.close 4.purchase 5.Exit\n");
  scanf("%d",&t);
  switch(t)
  {
          case 1:
          create();
          break;
          case 2:
          topup();
          break;
           case 3:
          close();
          break;
          case 4:
          pur();
          break;
  }
   }
   break;
   case 3:
   dis_b();
   break;
   case 4:
   dis_g();
   break;
   case 5:
   dis_p();
   break;
   case 6:
   k=0;
   
  } 
 }

}
