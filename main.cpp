
#include<bits/stdc++.h>
using namespace std;
stack<char>stack1;
stack<int>stack2;


int main()
{
       char str[500];
       int m,n;
       char filename[] ="input.txt";
       //char filename[] ="input1.txt";
       //char filename[] ="input2.txt";
      // char filename[] ="input3.txt";
       FILE *file = fopen ( filename, "r" );
       FILE *fp2 = fopen("output.txt","a");


       if(file != NULL)
       {

           while(fgets(str,sizeof str,file)!=NULL)
           {

               int p = -1;

               char postfix[500],array[500],pop;

               int flag = 0;;
               int x1,y1,value,h,l;


               l=strlen(str);

               if(str[1]=='=' && l==4)
               {
                    int flag2=0;
                    for(int i=0; i<=l; i++)
                    {


                        if(str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='(' && str[i]!='/')
                        {
                            flag2=1;
                        }
                    }


                if(flag2==0);
                {
                    array[0]=str[2];
                    n=atoi(array);

                }
            }
            int count=0;
            for(int i=0; i<l; i++)
            {
                if(str[i+1]!='=')
                {
                    if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='(' || str[i]=='/'))
                    {

                        count=1;
                    }
                }
            }
            if(count!=0)
            {
                for(int i=0; i<=l; i++)
                {

                    if(str[i+1]=='=')
                    {

                        if(str[i]=='x' && l!=3)
                        {
                            flag=1;
                        }
                        if(str[i]=='z' && l!=3)
                        {
                            flag=2;
                        }
                    }
                    else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='(' || str[i]=='/')
                    {

                            stack1.push(str[i]);
                    }

                    else if(str[i]==')')
                    {
                        while(!stack1.empty())
                        {

                            pop=stack1.top();
                            stack1.pop();
                            if(pop!='(')
                            {
                                p=p+1;
                                postfix[p]=pop;
                            }
                        }

                    }
                     else if(i==l)
                    {

                        while(!stack1.empty())
                        {
                            pop=stack1.top();
                            stack1.pop();
                            if(pop!='(')
                            {
                                p=p+1;
                                postfix[p]=pop;
                            }
                        }
                    }
                    else
                    {
                        p=p+1;
                        postfix[p]=str[i];

                    }
                }
                while(!stack1.empty())
                {

                        stack1.pop();
                }

                for(int i=0; i<=p; i++)
                {
                    if(postfix[i]!='+' && postfix[i]!='-' && postfix[i]!='*' && postfix[i]!='/')
                    {

                        if(postfix[i]=='x')
                        {
                            // printf("insert x %d\n",x);
                            stack2.push(m);

                        }
                        else if(postfix[i]=='y')
                        {
                            stack2.push(n);
                        }
                        else if(postfix[i]=='1' ||postfix[i]=='2' || postfix[i]=='3'|| postfix[i]=='4' || postfix[i]=='5'
                                || postfix[i]=='6' || postfix[i]=='7' || postfix[i]=='8' || postfix[i]=='9'  )
                        {


                            h=postfix[i]-'0';
                            stack2.push(h);
                        }
                    }
                        else
                       {
                                if(postfix[i]=='+' && postfix[i+1]=='+')
                                {
                                    printf("Syntax Error\n");
                                    return 0;
                                }
                                 if(postfix[i]=='*' && postfix[i+1]=='*')
                                {
                                    printf("Syntax Error\n");
                                    return 0;
                                }

                                else if(postfix[i]=='+')
                                {
                                    x1=stack2.top();
                                    stack2.pop();
                                    y1=stack2.top();
                                    stack2.pop();
                                    value=x1+y1;
                                    stack2.push(value);

                                }
                                else if(postfix[i]=='*')
                                {
                                    x1=stack2.top();
                                    stack2.pop();
                                    y1=stack2.top();
                                    stack2.pop();
                                    value=x1*y1;
                                    stack2.push(value);

                                }

                            }

                    }
                    while(!stack2.empty())
                    {
                            stack2.pop();
                    }

                }
                if(count==0)
                {

                    fprintf(fp2,"%s",str);


                }
                else if(flag==1)
                {
                    m=value;
                    fprintf(fp2,"x=%d\n",value);
                }
                 else if(flag==2)
                {
                    fprintf(fp2,"z=%d\n",value);
                }


                else
                {

                    fprintf(fp2,"%d\n",value);

                }


           }
       }

    }
