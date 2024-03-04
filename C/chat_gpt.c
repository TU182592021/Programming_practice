#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // 最大連絡先数

struct Contact
{
    char name[50];
    char phone[20];
};

struct Contact contacts[MAX_CONTACTS]; // 連絡先を格納する配列
int numContacts = 0;                   // 現在の連絡先数

// 新しい連絡先を追加する関数
void addContact()
{
    struct Contact newContact;
    printf("名前を入力してください: ");
    scanf("%s", newContact.name);
    printf("電話番号を入力してください: ");
    scanf("%s", newContact.phone);
    contacts[numContacts] = newContact;
    numContacts++;
}

// 指定された連絡先を削除する関数
void deleteContact()
{
    int index;
    printf("削除する連絡先の番号を入力してください (1-%d): ", numContacts);
    scanf("%d", &index);
    if (index < 1 || index > numContacts)
    {
        printf("無効な番号です\n");
        return;
    }
    index--;
    for (int i = index; i < numContacts - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }
    numContacts--;
}

// すべての連絡先を表示する関数
void displayContacts()
{
    printf("連絡先一覧:\n");
    for (int i = 0; i < numContacts; i++)
    {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

// メイン関数
int main()
{
    int choice;
    while (1)
    {
        printf("\n電話帳\n");
        printf("1. 連絡先を追加する\n");
        printf("2. 連絡先を削除する\n");
        printf("3. すべての連絡先を表示する\n");
        printf("4. 終了する\n");
        printf("選択してください: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            deleteContact();
            break;
        case 3:
            displayContacts();
            break;
        case 4:
            exit(0);
        default:
            printf("無効な選択です\n");
        }
    }
    return 0;
}
