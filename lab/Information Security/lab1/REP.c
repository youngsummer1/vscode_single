#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

short REP_KeyGen(){
    short key;
    //重置种子
    srand(time(0));
    //将随机值key限制在0~25
    key = (short) (rand() % 26);
    return key;
}

int REP_Encrypt(short key, char*plaintext, int plength, char* ciphertext, int *clength){
    int i =0;
    char temp;
    for(i = 0; i < plength ; i++){
        //temp记录当前正在加密的字符
        temp = *(plaintext + i);

        //大写字母和小写字母分开处理
        //处理大写字母
        if(temp >= 'A' && temp <= 'Z')
            *(ciphertext + i) = (temp - 'A' + key) % 26 + 'A';

        //处理小写字母
        if(temp >= 'a' && temp <= 'z')
            *(ciphertext + i) = (temp - 'a' + key) % 26 + 'a';
    }
    //为字符串结尾赋'\0'
    *(ciphertext + i) = '\0';
    //为clength赋值为字符串的长度
    *clength = strlen(ciphertext);
}

int REP_Decrypt(short key, char*ciphertext, int clength, char* plaintext, int *plength){
    int i =0;
    char temp;
    for(i = 0; i < clength ; i++){
        //temp记录当前正在加密的字符
        temp = *(ciphertext + i);
        if(temp >= 'A' && temp <= 'Z')
            *(plaintext + i) = (temp - 'A' - key + 26) % 26 + 'A';
        if(temp >= 'a' && temp <= 'z')
            *(plaintext + i) = (temp - 'a' - key + 26) % 26 + 'a';
    }
    //为字符串结尾赋'\0'
    *(plaintext + i) = '\0';
    //为plength赋值为字符串的长度
    *plength = strlen(plaintext);

}

//以下为对代码的测试
int main(){
    short key = REP_KeyGen();
    char plaintext[20];
    char ciphertext[20];
    int clength[2] , plength[2];
 
    printf("请输入明文：");
    scanf("%s", plaintext);
    printf("请输入明文的长度：");
    scanf("%d", &plength);
    
    REP_Encrypt(key, plaintext,plength[0] ,ciphertext,clength);
    printf("本次加密的key为：%d\n",key);
    printf("加密后的密文为：%s\n",ciphertext);

    REP_Decrypt(key,ciphertext,clength[0] ,plaintext,plength);
    printf("密文还原的结果为：%s\n",plaintext);
    
    return 0;
}
