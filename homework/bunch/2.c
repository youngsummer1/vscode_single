// 串替换

// 不调用库函数，自己实现字符串替换操作，函数原型为：

// int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr);
// 参数说明:

// in， 原始字符串，保持不变
// out, 存放替换结果的字符串
// outlen，out空间的大小
// oldstr，要替换的旧字符串
// newstr，替换成的新字符串
// 函数返回成功替换的次数，即有多少个子串被成功替换
// 在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
// 原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
// 如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。此时函数应该返回 2, out指向的串为 "aaabbb333333c"
// 再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "b"，newstr 为 "123456"，进行替换后所得的串长度为14，与结束符一共占 15 个字节，超过outlen的10字节，此时不进行替换，函数应该返回 0。
#include<stdio.h>
#include<stdlib.h>
// #include<string.h>

int strlength(const char *ch){
    int i;
    for(i=0;ch[i]!='\0';i++);
    return i;
}
void GetNext(const char* oldstr,int next[]){
    int j,k;
    j=0,k=-1;
    next[0]=-1;
    while(j<strlength(oldstr)-1){
        if(k==-1||oldstr[j]==oldstr[k]){
            j++;
            k++;
            next[j]=k;
        }
        else{
            k=next[k];
        }
    }
}
int KMPIndex(const char *in,const char* oldstr){
    int next[30],i=0,j=0;
    GetNext(oldstr,next);
    while(i<strlength(in)&&j<strlength(oldstr)){
        if(j==-1||in[i]==oldstr[j]){
            i++;j++;
        }
        else j=next[j];
    }
    if(oldstr[j]=='\0')return i-j;
    else return(-1);
}


// int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr){
//     if(outlen<0&&strlength(in)<0&&strlength(in)+1>outlen&&strlength(oldstr)<strlength(in))return 0;
//     out=(char*)in;
//     char temp[40];
//     strcpy(temp,out);
//     int num=0,position,i,j;
//     int distance=strlength(newstr)-strlength(oldstr);
//     position=KMPIndex(in,oldstr);

//     while(strlength(out)+1+distance<=outlen&&position>=0){
//         num++;
//         int len=strlength(out);

//         if(distance>=0){
//             for(i=len+distance;i>=position+strlength(newstr);i--){
//                 out[i]=out[i-distance];
//             }
//             for(i=position,j=0;i<position+strlength(newstr);i++,j++){
//                 out[i]=newstr[j];
//             }
//         }
//         else{
//             for(i=position,j=0;j<strlength(newstr);i++,j++){
//                 out[i]=newstr[j];
//             }
//             for(i=position+strlength(newstr);i<=len+distance;i++){
//                 out[i]=out[i-distance];
//             }
//         }
//         position=KMPIndex(out,oldstr);
//     }
//     return num;

// }
char *mycpy(char *dst,const char *src){
    char* ret =dst;
    while(*dst++=*src++);//dst复制到\0时退出
    *dst='\0';
    return ret;
}
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr){
    if(outlen<0&&strlength(in)<0&&strlength(in)+1>outlen&&strlength(oldstr)<strlength(in))return 0;
    // out=(char*)in;
    char temp[40];
    // out=(char*)malloc(50);

    mycpy(temp,in);
    int num=0,position,i,j;
    int distance=strlength(newstr)-strlength(oldstr);
    position=KMPIndex(in,oldstr);

    while(strlength(temp)+1+distance<=outlen&&position>=0){
        num++;
        int len=strlength(temp);

        if(distance>=0){
            for(i=len+distance;i>=position+strlength(newstr);i--){
                temp[i]=temp[i-distance];
            }
            for(i=position,j=0;i<position+strlength(newstr);i++,j++){
                temp[i]=newstr[j];
            }
        }
        else{
            for(i=position,j=0;j<strlength(newstr);i++,j++){
                temp[i]=newstr[j];
            }
            for(i=position+strlength(newstr);i<=len+distance;i++){
                temp[i]=temp[i-distance];
            }
        }
        position=KMPIndex(temp,oldstr);

    }
    // char *temp1="";
    // mycpy(out,temp);
    // out=temp1;
    char* ret =out;
    for(int i=0;temp[i]!='\0';i++){
        *ret++=temp[i];
    }
    *ret='\0';
    printf("out=%s\n",out);
    return num;

}
int main(){
    const char* in="abcdefg";
    char *out;
    char temp[20];
    out=(char*)malloc(50);
    int outlen=20,num=0;
    const char *oldstr="fg",*newstr="123";
    mycpy(temp,in);
    mycpy(out,temp);

    num=str_replace(in,out,outlen,oldstr,newstr);
    // printf("num=%d",num);
    // printf("len=%d",strlength(ch));
    
    // int len=strlength(out);
    // int distance=strlength(newstr)-strlength(oldstr);
    // int position=KMPIndex(in,oldstr);

    // for(int i=len+distance;i>=position+strlength(newstr);i--){
    //             out[i]=out[i-distance];
    //         }
    // int j;
    // for(int i=0;in[i]!='\0';i++)temp[i]=in[i];
    // for(int i=position,j=0;j<strlength(newstr);i++,j++){
    //     temp[i]=newstr[j];
    // }
    // out=temp;
    // for(int i;in[i]!='\0';i++)out[i]=in[i];
    // out[0]='a';
    // out[1]='b';
    printf("num=%d\n",num);
    printf("out=%s\n",out);
    printf("temp=%s\n",temp);
    printf("len_temp=%d\n",strlength(temp));

    printf("in=%s",in);
    return 0;
}
// int main(){
//     char temp[]="abcdefg";
//     const char *oldstr="cd";
//     int position=KMPIndex(temp,oldstr);

//     return 0;
// }

int get_len(const char* s)
{
    int i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}
int str_replace2(const char* in, char* out, int outlen, const char* oldstr, const char* newstr)
{
    int count_times = 0;
    int i;
    int j = 0;
    int k;
    int flag = 0;
    for (i = 0; outlen > 1 && in[i] != 0; i++) {
        if (in[i] != oldstr[0]) {
            out[j] = in[i];
            j++;
            outlen--;
            continue;
        } else {
            flag = 0;
            for (k = 0; oldstr[k] != 0; k++) {
                if (in[k + i] != oldstr[k]) {
                    break;
                } else {
                    if (k == (get_len(oldstr) - 1)) {
                        if (outlen > get_len(newstr)) {
                            i += k;
                            flag = 1;
                        }
                    }
                }
            }
            if (flag == 1) {
                count_times++;
                for (k = 0; newstr[k] != 0; k++) {
                    out[j] = newstr[k];
                    j++;
                    outlen--;
                }
            } else {
                out[j] = in[i];
                j++;
                outlen--;
            }
        }
    }
    out[j] = 0;
    return count_times;
}
