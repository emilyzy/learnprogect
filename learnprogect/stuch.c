#include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 struct stu 
{ int num;
 char name[20];
 char kind[20];
 int lhours; 
int rhours;
 int crdit; 
int score;
 int term;
 }
s[1000],t;

int input(struct stu s[]);
 int openfile(struct stu s[]);
 void output(struct stu s[],int n);
 int seqsearch1(struct stu s[],int n,int search_score);
 int seqsearch2(struct stu s[],int n,char search_name[]);
 void seqinsert(struct stu s[],int *len);
 void seqdelete(struct stu s[],int *len);
 void revise(struct stu s[],int n);
 void sort(struct stu s[],int n);
 void save(struct stu s[],int n);
 void main()
 {
    int sel,choice;
 int n,*len=&n,i;
 int search_score;
 char search_name[20];
 char message[]={ "***********************************************" "******欢迎使用选课系统************\n" "本系统是一个学生选课系统，您可以在本系统中实现\n" "课程信息的输入，浏览，查找，存入，删除，修改，\n" "排序，保存等操作******************************\n"};
 char menu[]={ "88888888888888888888888888888888888888888888888888\n" " *1.输入课程信息 \n" " *2.浏览课程信息 \n" " *3.查找课程信息 \n" " *4.插入课程信息 \n" " *5.删除课程信息 \n" " *6.修改课程信息 \n" " *7.课程信息排序 \n" " *8.存盘 \n" " *9.退出 \n" "88888888888888888888888888888888888888888888888888\n"};
 printf("%s",message); 
do { printf("%s",menu);
 printf("请在1--9中选择\n"); 
scanf("%d",&sel);
 switch(sel)
 {
 case 1: printf("1---键盘输入\n"); 
printf("2---文件载入\n");
 printf("请选择1或2\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: n=input(s);
 break; 
case 2: n=openfile(s);
 break;
 }
 break;
 case 2: output(s,n);
 break;
 case 3:
 do {
 printf("1----------按照学分查找------\n");
 printf("2----------按照课程名查找----\n");
 printf("0----------返回上一级菜单----\n");
 printf("请选择\n");
 scanf("%d",&choice); 
switch(choice)
 {
 case 1: printf("请输入学分\n");
 scanf("%d",&search_score);
 i=seqsearch1(s,n,search_score);
 if(i==-1)
printf("无此学分相应课程");
 else { printf("8888888888888");
 printf("i=%d",i); printf("查找课程为:\n");
 printf("课程编号%d\n",s[i].num);
 printf("课程名称%20s\n",s[i].name);
 printf("课程性质%20s\n",s[i].kind);
 printf("总学时%d\n",s[i].lhours);
 printf("授课学时%d\n",s[i].rhours);
 printf("实验或上机学时%d\n",s[i].crdit);
 printf("学分%d\n",s[i].score); 
printf("开课学期%d\n",s[i].term);
 printf("--------\n");
 }
 break;
 case 2: printf("请输入课程名\n");
 scanf("%s",search_name);
 i=seqsearch2(s,n,search_name);
 if(i==-1) printf("无此课程\n");
 else { printf("8888888888\n"); 
printf("查找的课程为"); 
printf("课程编号%d\n",s[i].num);
 printf("课程名称%20s\n",s[i].name);
 printf("课程性质%20s\n",s[i].kind);
 printf("总学时%d\n",s[i].lhours);
 printf("授课学时%d\n",s[i].rhours);
 printf("实验或上机学时%d\n",s[i].crdit);
 printf("学分%d\n",s[i].score);
 printf("开课学期%d\n",s[i].term);
 }
 break;
 case 9: break;
 }
 }
while(choice!=0);
 case 4: seqinsert(s,len);
 break;
 case 5: seqdelete(s,len);
 break;
 case 6: revise(s,n);
 break;
 case 7: sort(s,n);
 break;
 case 8: save(s,n);
 break;
 case 9:exit(1);
 }
 }
while(sel!=0);
 }
 void save(struct stu s[],int n)/*保存模块*/ 
{
 int i;
 FILE *fp1;
 fp1=fopen("d:\\课程系统表.txt","w");
 if(fp1==NULL) printf("保存不成功\n");
 else
 {
 for(i=0;i<n;i++) fprintf(fp1,"%d%20s%10d%d%d%d%d",s[i].num,s[i].name,s[i].kind,s[i].lhours,s[i].rhours,s[i].crdit,s[i].score,s[i].term); fclose(fp1);
 printf("成功保存\n");
 }
 }
 /*输出模块*/
 void output( struct stu s[],int n)
 {
 int i; printf(" 选修课程信息表 \n ");
 printf("\n ");
 for(i=0;i<=n-1;i++) 
{
printf("课程编号%d\n",s[i].num);
 printf("课程名称%20s\n",s[i].name);
 printf("课程性质%20s\n",s[i].kind);
 printf("总学时%d\n",s[i].lhours);
 printf("授课学时%d\n",s[i].rhours);
 printf("实验或上机学时%d\n",s[i].crdit);
 printf("学分%d\n",s[i].score);
 printf("开课学期%d\n",s[i].term);
 }
 }
 /*学分查询模块*/ 
int seqsearch1( struct stu s[],int n,int search_score)
 {
 int i=0;
 for(i=0;i<=n-1;i++)
 if(s[i].score==search_score)
 return i; 
}
 /*课程名查询模块*/
 int seqsearch2( struct stu s[],int n,char search_name[]) 
{
 int i=0;
 for(i=0;i<=n-1;i++)
 if(strcmp(s[i].name,search_name)==0)
return i; 
}
 /*修改模块*/
 void revise( struct stu s[],int n) 
{
 int k,choice;
 char kname[20];
 do
 {
 printf("1**********按课程名称修改*******\n");
 printf("0***********返回上级菜单 ***********\n"); 
printf("请输入选择\n");
 scanf("%d",&choice); 
switch(choice) 
{
 case 1: printf("请输入要修改的课程名称\n");
 scanf("%s",&kname);
 k=seqsearch2(s,n,kname);
 if(k==-1) printf("修改无效\n");
 else{ printf("课程编号");
 scanf("%d",&s[k].num);
 printf("课程名称"); 
scanf("%20s",&s[k].name);
 printf("课程性质");
 scanf("%20s",&s[k].kind);
 printf("总学时");
 scanf("%d",&s[k].lhours);
 printf("授课学时");
 scanf("%d",&s[k].rhours);
 printf("实验或上机学时");
 scanf("%d",&s[k].crdit);
 printf("学分");
 scanf("%d",&s[k].score);
 printf("开课学期");
 scanf("%d",&s[k].term);
 printf("修改成功!\n");
 }
 break;
 case 0: break; 
}
 }
while(choice!=0);
 }
 /*删除模块*/
 void seqdelete( struct stu s[],int *len)
 {
 int j,delete_score,k,choice;
 char delete_name[20];
 if(*len==0) printf("数组以空");
 else
 {
 do {
 printf("1*********按课程名删除*****\n");
 printf("0*********返回上级菜单*****\n");
 printf("请输入选择\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: printf("请输入删除课程的课程名：");
 scanf("%s",delete_name);
 k=seqsearch2(s,*len,delete_name);
 if(k==-1) printf("无效的删除位置\n");
 else { for(j=k+1;j<=*len-1;j++) s[j-1]=s[j];
 (*len)--; printf("删除成功");
 }
 break;
 case 0: break;
 }
 }
while(choice!=0); 
}
 
}
 /*输入模块*/ 
int input( struct stu s[])
 {
 int i=0,n=0;
 printf("输入课程编号(为-1时结束)");
 scanf("%d",&s[i].num);
 while(s[i].num!=-1)
 {
 printf("课程编号");
 scanf("%d",&s[i].num);
 printf("课程名称");
 scanf("%20s",&s[i].name);
 printf("课程性质"); 
scanf("%20s",&s[i].kind);
 printf("总学时"); 
scanf("%d",&s[i].lhours);
 printf("授课学时");
 scanf("%d",&s[i].rhours);
 printf("实验或上机学时");
 scanf("%d",&s[i].crdit);
 printf("学分");
 scanf("%d",&s[i].score);
 printf("开课学期");
 scanf("%d",&s[i].term);
 i++;
 n++;
 printf("输入课程编号(为-1时结束)");
 scanf("%d",&s[i].num);
 }
 return n;
 }
 /*排序模块*/
 void sort( struct stu s[],int n)
 {
 int i,j,k;
 for(i=0;i<n-1;i++)
 {
 k=i;
 for(j=i+1;j<n;j++) if(strcmp(s[k].name,s[j].name)>0)
k=j;
 if(i!=k) { t=s[k]; s[k]=s[i]; s[i]=t; }
 }
 }
 /*插入模块*/
 void seqinsert( struct stu s[],int *len)
 {
 int j,k,choice;
 int insert_num;
 char insert_name[10];
 char insert_kind[20];
 int insert_ltime;
 int insert_stime;
 int insert_sjtime;
 int insert_score;
 int insert_term; struct stu cr ;
 /*新数组*/
 if(*len==1000-1)
 printf("数组已满！");
 else 
{ 
do{ printf("1**********按课程名称插入*******\n");
 printf("0***********返回上级菜单 ***********\n");
 printf("请输入选择\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: printf("请输入插入位置(插入某课程名之前)\n"); 
scanf("%s",&insert_name);
 k=seqsearch2(s,*len,insert_name);
 if(k==-1) printf("位置无效、\n");
 else{
 printf("课程编号");
 scanf("%d",&cr.num);
 printf("课程名称");
 scanf("%20s",&cr.name);
 printf("课程性质");
 scanf("%20s",&cr.kind);
 printf("总学时");
 scanf("%d",&cr.lhours);
 printf("授课学时");
 scanf("%d",&cr.rhours);
 printf("实验或上机学时");
 scanf("%d",&cr.crdit);
 printf("学分");
 scanf("%d",&cr.score);
 printf("开课学期");
 scanf("%d",&cr.term);
 for(j=*len-1;j>=k;j--)
 s[j+1]=s[j];
 s[k]=cr;
 (*len)++;
 printf("插入成功\n");
 }
 break;
 case 0: break;
 }
 }
while(choice!=0);
 }
 } 
/*载入模块*/
 int openfile(struct stu s[] )
 {
 int i=0;
 FILE *fp2; 
fp2=fopen("d:\\课程系统表.txt","r");
 /*打开D盘"课程系统表"文件*/
 if(fp2==NULL)
 {
 printf("找不到文件\n"); 
return 0; 
}
 else
 {
 while(!feof(fp2))
 {
 fscanf(fp2,"%d%s%s%d%d%d%d%d"); 
i++; 
}
 fclose(fp2); 
printf("数据写入\n");
 return i; 
}
 }

