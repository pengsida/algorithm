//
//  temp.c
//  introduction_to_algorithm
//
//  Created by pengsida on 2016/11/19.
//  Copyright © 2016年 pengsida. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define n 1000

void fq(char b[]); //统计频率

void to_low(char *a)
{
    while(*a != '\0')
    {
        if(*a > 'A' && *a < 'Z')
            *a = *a - 'A' + 'a';
        a++;
    }
}
//
//int main()
//{
//    char a[n],b[n],c,*p,*pa;
//    int sen=0;
//    int i = 0;
//    printf("------------------词频统计工具-------------------\n");
//    printf("功能：\n");
//    printf("         1.去除多余的空白;\n");
//    printf("         2.统计一段文字中句子的长度，统计每个单词出现的频率;\n");
//    printf("         3.按照词频的大小顺序输出。\n");
//    printf("-------------------------------------------------\n");
//    while(1)
//    {
//        printf("请输入一段英文文字，长度不要超过1000：\n");
//        
//        for(i = 0; i < n; ++i)
//        {
//            a[i] = '\0';
//            b[i] = '\0';
//        }
//        
//        gets(a);
////        strlwr(a);
//        to_low(a);
//        {
//            for(p=b,pa=a;*pa;pa++)
//            {
//                *p=*pa;
//                *(p+1)=*(pa+1);
//                if((*p)!=' ')
//                    p++;  //不是空格的指针往右走
//                else if((*(p+1))!=' '&&(*(p+1))!=','&&(*(p+1))!='.'&&(*(p+1))!='!'&&(*(p+1))!=';'&&(*(p+1))!='?'\
//                        &&(*(p-1))!=','&&(*(p-1))!='.'&&(*(p-1))!='!'&&(*(p-1))!=';'&&(*(p-1))!='?')
//                    p++;
//            }
//            //是单独的空格指针也往右走(并且不在标点符号周围）
//            *p='\0';
//        }
//        printf("%s\n",b);
//        
//        {for(pa=a;*pa;pa++)
//            if(*pa==','||*pa=='.'||*pa=='!'||*pa=='?'||*pa==';')  sen++;}//数句子数量
//        
//        {
//            fq(b);
//            
//        }
//        
//        
//        printf("句子数：%d\n",sen);
//        sen=0;
//        printf("\n是否继续? [Y/N] \n");
//        while((c = getchar()) != '\n')
//            if(c=='N'||c=='n')
//                return 0;
//    }
//    return 0;
//}
//



void fq(char b[])
{
    int i=0,j=0,k=0,w=0,z,c[n];
    char a[n][20];
    char *p;
    int *q;
    int word=0;
    int temp;
    char t[20];
    int len = 0;
    for(z=0;z<n;z++)
        c[z]=0;
    for(z=0;z<n;z++)
        if(b[z]==','||b[z]=='.'||b[z]=='!'||b[z]=='?'||b[z]==';')
            b[z]=' ';
    for(p=b,q=c;*p;p++)
    {
        if(*p==' ');
        else {
            while(*p!=' '&&*p!='\0')
            {
                a[i][j]=*p;
                j++;
                p++;
            }//把单词读到a[i]中
            a[i][j]='\0';
            i++;
            q++;//为了第一次。。
            j=0;
            for(w=0;w<i-1;w++)
            {
                if(strcmp(a[w],a[i-1])==0)
                {
                    c[w]++;
                    k++;
                    i--;
                    q--;
                }
            }
            if(k==0)
            {
                (*(q-1))++;
            }
        }
    }
    len = i;
    for(i=len;i > 0;i--)
        for(j=0;j<i;j++)
            if(c[j]<c[i]) 
            {
                temp=c[j];
                c[j]=c[i];
                c[i]=temp;
                strcpy(t,a[j]);
                strcpy(a[j],a[i]);
                strcpy(a[i],t);
            }
    for(i=0;i<len;i++)
    {
        word+=c[i];
        printf("%s  %d\n",a[i],c[i]);
    }
    printf("单词数：%d",word);
    memset(a,0,n*20);
}





