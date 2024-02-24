#include <stdio.h>
#include <string.h>

void pc1(char *key, char *newkey){
  int permtable[56] = {57, 49, 41, 33, 25, 17, 9,
                        1, 58, 50, 42, 34, 26, 18,
                        10, 2, 59, 51, 43, 35, 27,
                        19, 11, 3, 60, 52, 44, 36,
                        63, 55, 47, 39, 31, 23, 15,
                        7, 62, 54, 46, 38, 30, 22,
                        14, 6, 61, 53, 45, 37, 29,
                        21, 13, 5, 28, 20, 12, 4};
  int i;
  for(i=0;i<56;i++){
    newkey[i] = key[permtable[i]-1];
  }
}

void left_shift(char *src, char *dst, int num, int len){
  strncpy(dst, src+num, len-num);
  strncat(dst, src, num);
}

void pc2(char *c, char *d, char *key){
  int permtable[56] = {14, 17, 11, 24, 1, 5,
                        3, 28, 15, 6, 21, 10,
                        23, 19, 12, 4, 26, 8,
                        16, 7, 27, 20, 13, 2,
                        41, 52, 31, 37, 47, 55,
                        30, 40, 51, 45, 33, 48,
                        44, 49, 39, 56, 34, 53,
                        46, 42, 50, 36, 29, 32};
  int i;
  for(i=0;i<48;i++){
    if (permtable[i] <= 28) {
      key[i] = c[permtable[i]-1];
    }
    else {
      key[i] = d[permtable[i]-29];
    }
  }
}

int main(){
  char ciphertext[] = "1100101011101101101000100110010101011111101101110011100001110011";
  char key[] = "0100110001001111010101100100010101000011010100110100111001000100";
  
  char key_perm[57];
  pc1(key, key_perm);
  
  char c[17][29];
  char d[17][29];
  strncpy(c[0], key_perm, 28);
  strncpy(d[0], key_perm + 28, 28);

  int i;
  int shiftnum[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
  char key_round[16][49];
  for(i=1;i<17;i++){
    left_shift(c[i-1], c[i], shiftnum[i], 28);
    pc2(c[i], d[i], key_round[i-1]);
  }
  return 0;
}
