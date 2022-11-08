#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termio.h>
#include <string.h>

int getch(void) {

int ch;

struct termios buf;

struct termios save;

tcgetattr(0, &save);

buf = save;

buf.c_lflag &= ~(ICANON | ECHO);

buf.c_cc[VMIN] = 1;

buf.c_cc[VTIME] = 0;

tcsetattr(0, TCSAFLUSH, &buf);

ch=getchar();

tcsetattr(0, TCSAFLUSH, &save);

return ch;

}

void printHuman(int fail){
switch (fail){
   case 0:printf("------------------------+\n"
"                        \n"
"                       \n"
"                        \n");break;
   
   
   
   case 1:printf("------------------------+\n"
"                        O\n"
"                       \n"
"                        \n");break;
   case 2:printf("------------------------+\n"
"                        O\n"
"                       / \n"
"                        \n");break;
   case 3:printf("------------------------+\n"
"                        O\n"
"                       /|\n"
"                        \n");break;
   case 4:printf("------------------------+\n"
"                        O\n"
"                       /|\\\n"
"                        \n");break;
   case 5:printf("------------------------+\n"
"                        O\n"
"                       /|\\\n"
"                        /\n");break;
   default:printf("------------------------+\n"
"                        O\n"
"                       /|\\\n"
"                        /\\\n");break;
}
}


struct word{
char *eng;
char *kor;
};

int main(void){
srand(time(NULL));
struct word words[7][10]={
{{"resident","거주자."},{"subcomponent","하위 구성 요소"},{"affinity","친화력"},{"inspector","검사관"},{"maiden","처녀의"},{"maize","옥수수"},{"diving","다이빙"},{"list","목록."},{"wildlife","야생 생물"},{"scale","규모."}}
,{{"dud","똥을 누다"},{"precipitation","강수량"},{"ceiling","천장."},{"celsius","섭씨"},{"dining","식사"},{"miscommunication","잘못된 의사소통"},{"porpoise","돌고래를 잡다"},{"customer","고객."},{"finding","찾기"},{"junker","고물상"}}
,{{"fibrosis","섬유증"},{"presume","추정하다"},{"polyp","폴립"},{"anagram","아나그램"},{"spiral","나선형의"},{"grace","우아함"},{"skylight","천창"},{"sandbar","모래톱"},{"ambassador","대사"},{"listing","상장"}}
,{{"cesspool","오물장"},{"organizing","조직 중인"},{"canteen","통조림"},{"sentiment","감정"},{"dump truck","덤프트럭"},{"needle","바늘로 찌르다"},{"blackfish","흑어"},{"pouch","파우치"},{"handball","핸드볼"},{"difficulty","어려움"}}
,{{"refusal","거절"},{"cat","고양이"},{"whole","전체"},{"merit","공로를 세우다"},{"repair","수리"},{"accountability","설명 책임"},{"chop","도려내다"},{"panties","팬티"},{"inbox","받은 편지함."},{"someplace","어디선가"}}
,{{"exception","예외."},{"commercial","상업의"},{"college","대학."},{"hygienic","위생적인"},{"osprey","먹잇감을 주다"},{"twig","잔가지"},{"rheumatism","류머티즘"},{"flugelhorn","플루겔혼"},{"willow","버드나무"},{"slot","슬롯을 달다"}}
,{{"edible","먹을 수 있는"},{"volume","용량"},{"mistake","실수"},{"description","묘사"},{"moth","나방"},{"widow","과부"},{"sweat","땀"},{"deposition","퇴적"},{"serval","서벌의"},{"irrigation","관개"}}

};
   
   int menu;
while (1){
system("clear");
printf(">>영어 단어 암기 프로그램<<\n1. 플래시 카드     2. 게임     3. 프로그램 종료\n\n번호를 선택하세요: ");
scanf("%d",&menu);
getchar();

//플래시 카드
if(menu==1){
   int day,printOption;
printf("학습 일차:");
scanf("%d",&day);
printf("출력 방식(수동모드:1,자동모드:2):");
scanf("%d",&printOption);
getchar();

int randArr[10];//랜덤인덱스 생성
for (int i=0;i<10;i++){
randArr[i]=rand()%10;
for (int j=0;j<i;j++)
   if (randArr[i]==randArr[j]) {i--;break;}

}

if (printOption==2){//자동모드
int cnt=0,index;

system("clear");
while(cnt<10){
printf(">>영어 단어 암기 프로그램: 플래시카드<<\n\n\n\n");
index=randArr[cnt];
printf("%s\n",words[day-1][index].eng);
sleep(1);
system("clear");
printf(">>영어 단어 암기 프로그램: 플래시카드<<\n\n\n\n");
printf("%s\n",words[day-1][index].kor);
sleep(1);
system("clear");
cnt++;
}
sleep(1);
}



else if (printOption==1){//수동모드
system("clear");
printf(">>영어 단어 암기 프로그램: 플래시카드<<\n\n\n\n");
int cnt=0;
while (cnt<20){
if (getchar()=='\n'){
if (cnt%2){ 
   system("clear");
printf(">>영어 단어 암기 프로그램: 플래시카드<<\n\n\n\n");
   printf("%s",words[day-1][randArr[cnt/2]].kor);
   }
else {
system("clear");
printf(">>영어 단어 암기 프로그램: 플래시카드<<\n\n\n\n");
printf("%s",words[day-1][randArr[cnt/2]].eng);
}
cnt++;
}
}
getchar();
}//수동모드
}//플래시카드


//게임
else if (menu==2){
int day,cnt=1,fail=0;
printf("학습 일차:");
scanf("%d",&day);
getchar();//개행삭제
struct word randWord=words[day-1][rand()%10];
char tmp[100]="",guess;

while (1){
system("clear");
printf(">>영어 단어 암기 프로그램: 게임<<");
printf("\n(힌트) %s\n\n",randWord.kor);
printHuman(fail);

for(int i=0;i<strlen(randWord.eng);i++){
if (tmp[i]) printf("%c ",tmp[i]);
else printf("_ ");
}

printf("\n%d번째 시도:",cnt);
scanf("%c",&guess);
getchar();//개행삭제

int ack=0;//다 돌아서 문자 있는지 체크
for (int i=0;i<strlen(randWord.eng);i++)
if (randWord.eng[i]==guess) {
   tmp[i]=guess;
   ack=1;
}
if (!ack) 
   fail++;



if (!(strcmp(randWord.eng,tmp))){
printf("############################\n"
      "#####Congratulations!#######\n"
      "############################\n");
//getchar();//엔터치면 메인으로
sleep(1);
break;
}

if (fail==6) {
   printf("#####################\n"
         "######실패##########\n"
         "###################\n");
   sleep(1);
   break;
}
cnt++;

}

}//게임



//종료
else if (menu==3){
system("clear");
return 0;
}

}


return 0;
}