/*
 字符串大小比较，可以用strcmp
 也可以用string，直接< > 来比较
 */
#include<iostream>
#include<cstring>
using namespace std;


int main()
{
    char stu_in[15],stu_out[15],stu[15];
    char sign_in[10] = "23:59:59";
    char sign_out[10] = "00:00:00";
    char tmp_in[10],tmp_out[10];
    int num,i;
    
    cin>>num;
    for(i=0; i<num; i++)
    {
        cin>>stu>>tmp_in>>tmp_out;
        if(strcmp(tmp_in,sign_in) <= 0)
        {
            strcpy(stu_in,stu);
            strcpy(sign_in,tmp_in);
        }
        if(strcmp(tmp_out, sign_out) >= 0)
        {
            strcpy(stu_out,stu);
            strcpy(sign_out,tmp_out);
        }
    }
    cout<<stu_in<<" "<<stu_out<<endl;
    return 0;
}