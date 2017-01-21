#include <stdio.h>
#define PASSWORD "1234567"
int verify_password (char *password){
  int authenticated;
  char buffer[8];  // add local buff to be overflowed
  authenticated=strcmp(password,PASSWORD);
  strcpy(buffer,password);  //over flowed here!  
  return authenticated;
}

main()
{
  int valid_flag=0;
  char password[1024];
  while(1){
    printf("please input password:\t");
    scanf("%s",password);
    valid_flag = verify_password(password);
    if(valid_flag){
      printf("incorrect password!\n\n");
    }
    else{
      printf("Congratulation! You have passed the verification!\n");
      break;
    }
  }
  printf("%d\n",valid_flag);
}
