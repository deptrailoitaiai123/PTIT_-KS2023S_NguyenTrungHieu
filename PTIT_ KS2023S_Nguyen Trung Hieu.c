#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
struct CD{
	int id;
	char name[50];
	float duration;
	char content[50];
	bool status;
	
};
	struct CD cdList[100];
	int  	cdCurrent=2;
void printfCDList(){
	printf("danh sach CD \n");
	printf("%d.   %s %fp    %s    %s   \n","id","ten phim","thoi luong","noi dung ","trang thai");
		for(int i=0;i<cdCurrent;i++){
			printf("    %d.     %s      %fp      %s       %s   \n",cdList[i].id, cdList[i].name, cdList[i].duration, cdList[i].content, cdList[i].status ? "online" : "offline");
    }		
}
void addNewCD() {
	struct CD newCD;
    printf("nhap thong tin CD moi\n");
    printf("ten ");
    scanf("%s", newCD.name);
    printf("thoi luong ");
    scanf("%f", &newCD.duration);
    printf("noi dung ");
    scanf("%s", newCD.content);
    newCD.status = true;
    newCD.id = cdCurrent + 1;   
    cdList[cdCurrent] = newCD;
    cdCurrent++;
    printf("da them cd moi\n");
    
}
void updateCD() {
    char targetName[50];
    printf("nhap ten CD muon cap nhat \n ");
    scanf("%s", targetName);

    int index = -1;
    for (int i = 0; i < cdCurrent; i++) {
        if (strcmp(cdList[i].name, targetName) == 0) {
            index = i;
            break;
        }
}

    if (index != -1) {
        printf("nhap thong tin moi cho CD\n");
        printf("ten ");
        scanf("%s", cdList[index].name);
        printf("thoi luong ");
        scanf("%f", &cdList[index].duration);
        printf("noi dung  ");
        scanf("%s", cdList[index].content);
        
}
	else {
        printf("khong  tim thay CD\n");
    }
}
void deleteCD() {
    char targetName[50];
    printf("nhap ten cd muon xoa ");
    scanf("%s", targetName);
    int index = -1;
    for (int i = 0; i < cdCurrent; i++) {
        if (strcmp(cdList[i].name, targetName) == 0) {
            index = i;
            break;
    }
}

    if (index != -1) {
        
        for (int i = index; i < cdCurrent - 1; i++) {
            cdList[i] = cdList[i + 1];
    }
        cdCurrent--;
        printf("da xoa cd\n");
} else {
        printf("khong tim thay cd\n");
   }
}
void sortCDList() {
    for (int i = 1; i < cdCurrent; i++) {
        struct CD key = cdList[i];
        int j = i - 1;

        while (j >= 0 && cdList[j].duration > key.duration) {
            cdList[j + 1] = cdList[j];
            j = j - 1;
    }

        cdList[j + 1] = key;
    }

    printf("da sap xep phim thoi thoi luong tang dan\n");
}
int main(){
    cdList[0] = (struct CD){1, "ho", 90, "nguyen", true};
    cdList[1] = (struct CD){2, "dem", 20, "trung ", false};
    int choice;
    printf("***************MENU***********\n");
    printf("1. in toan bo danh sach CD co trong hang\n");
    printf("2. them cd va nhap thong tin\n");
    printf("3. cap nhat thong tin cho cd\n");
    printf("4. xoa cd\n");
    printf("5. sap xep phim theo thoi luong\n");
    printf("6. thoat\n");
    do {
    
    
    	
   	printf("MOI NHAP YEU CAU!!!\n ");
	scanf("%d", &choice);
        switch (choice) {
            case 1:
                printfCDList();
                break;
            case 2:
                addNewCD();
                break;
            case 3:
                updateCD();
                break;
            case 4:
                deleteCD();
                break;
            case 5:
                sortCDList();
                break;
            case 6:
            	exit(0);
            default:
                printf("vui long chon lai \n");
                }
} while (1 == 1);
    


}



	
