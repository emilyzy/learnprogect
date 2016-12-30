//猜数游戏
#include<stdio.h>
//#include<conio.h>


int main()
{
    int i=3,password=0,key,answer;
    //加密语句
   while(password!=123456)
    {
    	if(i>0)
    	{
	    	printf("you will have %d change to play this game!\nplease input your password:\n",i);
	    	scanf("%d",&password);
    		i--;
    	}else
        	{
    	    	puts("sorry,you will not to play it!");
        		return;
        	}      	
    }
    // clrscr();//清屏函数
    system("clear");
     puts("wilcome to this game!\n");	
              srand((unsigned)time(0));/*随机数发生器初始化函数*/
     key=1+rand()%100;
     printf("the game is begining,please tell me your answer:\n");
  do {	
       	scanf("%d",&answer);
       	if(answer<=0||answer>=100)
       	printf("please input the number who is between 1 to 100\n");
           else
       	{
           	if(answer<key)
           	printf("smaller!\nplease try another one:\n");
           	if(answer>key)
           	printf("bigger!\nplease try another one:\n");
       	}

   }while (answer!=key);
   	printf("you are right ! the key is %d\n",key);
   	return(0);
  }
