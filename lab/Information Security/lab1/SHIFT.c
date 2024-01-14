#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//随机值
short SHIFT_KeyGen (){
    short key;
    srand(time(0));
    //范围限定在3-6
    key = (short) (rand() % 4)+3;
    return key;
}

int SHIFT_Encrypt(short key, char* plaintext, int plength, char* ciphertext, int* clength){
    int i = 0, j = 0, temp = 0;
    //key为矩阵每行的列数
    int m = plength / key; //矩阵的行数
    int n = (key - plength % key) % key; //矩阵填满的列数
    //先把填满的列输进去
    for(i = 0; i < key - n; i++)
    {   
        //此处i为列，j为行
        //当矩阵是满的时候
        if(n == 0)
            for(j = 0 ; j < m ; j++) 
                ciphertext[ temp++ ] = plaintext[j * key +i];
        //矩阵没满时，m因为向下取整，所以要+1
        else
            for(j = 0 ; j < m + 1; j++) 
                ciphertext[ temp++ ] = plaintext[j * key +i];
    }
    //再把没填满的列输进去
    for(i = key - n; i < key; i++){
        for(j = 0; j < m; j++)
            ciphertext[ temp++ ] = plaintext[j * key +i];
    }
    //给字符串最后一个赋'\0'
    ciphertext[temp] = '\0';
    //计算字符串长度
    *clength = strlen(ciphertext);

}


int SHIFT_Decrypt(short key, char* ciphertext, int clength, char* plaintext, int* plength){
    int i = 0, j = 0, temp = 0;
    //key为矩阵每行的个数
    int m = clength / key; //矩阵的行数
    int n = (key - clength % key) % key; //矩阵填不满的列数
    //先把填满的列输进去
    for(i = 0; i < key - n; i++)
    {   
        //此处i为列，j为行
        //当矩阵是满的时候
        if(n == 0)
            for(j = 0 ; j < m ; j++) 
                plaintext[j * key +i] = ciphertext[ temp++ ];
        //矩阵没满时，m因为向下取整，所以要+1
        else
            for(j = 0 ; j < m + 1; j++) 
                plaintext[j * key +i] = ciphertext[ temp++ ];
    }
    //再把没填满的列输进去
    for(i = key - n; i < key; i++){
        for(j = 0; j < m; j++)
            plaintext[j * key +i] = ciphertext[ temp++ ];
    }
    //给字符串最后一个赋'\0'
    plaintext[temp] = '\0';
    //计算字符串长度
    *plength = strlen(plaintext);
}

//用于测试
int main(){
    short key = SHIFT_KeyGen();
    char plaintext[40] ,ciphertext[40];
    int clength[2] ,plength[2];
    //先给出key，后面好输入
    printf("本次加密的key为: %d\n",key);

    printf("请输入明文：");
    scanf("%s", plaintext);
    printf("请输入明文的长度：");
    scanf("%d", &plength);

    
    SHIFT_Encrypt(key ,plaintext ,plength[0] ,ciphertext ,clength);
    printf("加密后的密文为：%s\n",ciphertext);

    SHIFT_Decrypt(key ,ciphertext ,clength[0] ,plaintext ,plength);
    printf("密文还原的结果为：%s\n",plaintext);
    

    return 0;
}