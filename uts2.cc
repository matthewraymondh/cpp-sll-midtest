#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int nilai1, nilai2;
    string target;
    TNode *next;
};

TNode *head, *tail, *bantu, *bantu2, *baru, *del, *sebelum;

void init()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if(tail == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int countTNode(){
    bantu = head;
    int jumlah = 0;
    while(bantu != NULL){
        jumlah++;
        bantu  = bantu ->next;
    }
    return jumlah;
}

void insertDepan(int nilai1, int nilai2, string target)
{
    baru = new TNode;
    baru->nilai1 = nilai1;
    baru->nilai2 = nilai2;
    baru->target = target;
    if(isEmpty() == 1){
        head=tail=baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
    cout << "Data inputted successfully\n";

}

void insertBelakang(int nilai1, int nilai2, string target)
{
    baru = new TNode;
    baru->nilai1 = nilai1;
    baru->nilai2 = nilai2;
    baru->target = target;
    if(isEmpty() == 1){
        head=tail=baru;
        tail->next = NULL;
    }
    else{
        baru->next = NULL;
        tail->next = baru;
        tail = baru;
    }
    cout << "Data inputted successfully\n";
}

void insertSebelum(int nilai1, int nilai2, string target, int posisi)
{
    if(posisi<1 || posisi>countTNode()){
        cout << "position out of reach" << endl;
    }
    else if(posisi==1){
        cout << "position not in the middle" << endl;
    }
    else{
        baru = new TNode();
        baru->nilai1 = nilai1;
        baru->nilai2 = nilai2;
        baru->target = target;

        bantu = head;
        int nomor=1;
        while(nomor<posisi-1){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    cout << "Data inserted successfully\n";
}

void insertSetelah(int nilai1, int nilai2, string target, int posisi)
{
    if(posisi<1 || posisi>countTNode()){
        cout << "position out of reach" << endl;
    }
    else if(posisi==1){
        cout << "position not in the middle" << endl;
    }
    else{
        baru = new TNode();
        baru->nilai1 = nilai1;
        baru->nilai2 = nilai2;
        baru->target = target;

        bantu = head;
        int nomor=1;
        while(nomor<posisi){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    cout << "Data inserted\n";
}


void hapusDepan()
{
    if(isEmpty() == 0){
        if(head != tail){
            del = head;
            head = head->next;
            delete del;
        }
        else{
            head = tail = NULL;
        }
        cout << "Data deleted\n";
    }
    else{
        cout << "Data still empty\n";
    }
}

void hapusTertentu(int cari1, int cari2, string cari3)
{
    if (isEmpty() == 0)
    {
        bantu = head;
        while (bantu->nilai1 != cari1 && bantu->nilai2 != cari2 && bantu->target != cari3)
        {
            bantu2 = bantu;
            bantu = bantu->next;
        }
        if (bantu->nilai1 == cari1 && bantu->nilai2 == cari2 && bantu->target == cari3)
        {
            if (bantu == head)
            {
                del = head;
                head = head->next;
                delete del;
            }
            else if (bantu == tail)
            {
                del = tail;
                tail = bantu2;
                tail->next = NULL;
                delete del;
            }
            else
            {
                bantu2->next = bantu->next;
                delete bantu;
            }
            cout << "Data deleted successfully" << endl;
        }
        else
        {
            cout << "Data not found" << endl;
        }
    }
    else
    {
        cout << "Data still empty" << endl;
    }
}

void hapusBelakang()
{
    if(isEmpty() == 0){
        if(head != tail){
            del = tail;
            bantu = head;
            while(bantu->next!=tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete del;
        }
        else{
            head = tail = NULL;
        }
        cout << "Data deleted\n";
    }
    else{
        cout << "Data still empty\n";
    }
}

void cariData(int cari1, int cari2, string cari3)
{
    int node = 1;
    if (isEmpty() == 0)
    {
        bantu = head;
        while (bantu->nilai1 != cari1 && bantu->nilai2 != cari2 && bantu->target != cari3)
        {
            bantu = bantu->next;
            node++;
        }
        if (bantu->nilai1 == cari1 && bantu->nilai2 == cari2 && bantu->target == cari3)
        {
            cout << "Data found at node-" << node << endl;
        }
        else
        {
            cout << "Data not found" << endl;
        }
    }
    else
    {
        cout << "Data still empty" << endl;
    }
}

void tampilData()
{
    bantu = head;
    if (isEmpty() == 0)
    {
        int angka = 1;
        while (bantu != NULL)
        {
            cout << angka << ". " << bantu->nilai1 << " " << bantu->nilai2 << " " << bantu->target << "\n";
            bantu = bantu->next;
            angka++;
        }
    }
    else
    {
        cout << "Data is empty" << endl;
    }
}



int main()
{
    int pilih, nilai1, nilai2, posisi;
    string target;
    do
    {
        system("cls");
        tampilData();
        cout << "\n";
        cout << " =============================" << endl;
        cout << " =  MATTHEW RAYMOND HARTONO  =" << endl;
        cout << " =      A11.2021.13275       =" << endl;
        cout << " =============================" << endl;
        cout << " = 1. Input Front            =" << endl;
        cout << " = 2. Input End              =" << endl;
        cout << " = 3. Input before node x    =" << endl;
        cout << " = 4. Input after note x     =" << endl;
        cout << " = 5. Delete Front           =" << endl;
        cout << " = 6. Delete selected data   =" << endl;
        cout << " = 7. Delete End             =" << endl;
        cout << " = 8. Search Data            =" << endl;
        cout << " = 9. Show Data              =" << endl;
        cout << " = 10. Exit                  =" << endl;
        cout << " =============================" << endl;
        cout << " Select Menu (1-10) : ";
        cin >> pilih;
        switch (pilih)
        {
            case 1:
                cout << "Input Value 1 : ";
                cin >> nilai1;
                cout << "Input Value 2 : ";
                cin >> nilai2;
                cout << "Masukkan target : ";
                cin >> target;
                insertDepan(nilai1, nilai2, target);
                getch();
                break;
            case 2:
                cout << "Input Value 1 : ";
                cin >> nilai1;
                cout << "Input Value 2 : ";
                cin >> nilai2;
                cout << "Masukkan target : ";
                cin >> target;
                insertBelakang(nilai1, nilai2, target);
                getch();
                break;
            case 3:
                cout << "Input Value 1 : ";
                cin >> nilai1;
                cout << "Input Value 2 : ";
                cin >> nilai2;
                cout << "Input target : ";
                cin >> target;
                cout << "Input Value before node : ";
                cin >> posisi;
                insertSebelum(nilai1, nilai2, target, posisi);
                getch();
                break;
            case 4:
                cout << "Input Value 1 : ";
                cin >> nilai1;
                cout << "Input Value 2 : ";
                cin >> nilai2;
                cout << "Input target : ";
                cin >> target;
                cout << "Input Value after node : ";
                cin >> posisi;
                insertSetelah(nilai1, nilai2, target, posisi);
                getch();
                break;
            case 5:
                hapusDepan();
                getch();
                break;
            case 6:
                cout << "Input Value 1 to delete : ";
                cin >> nilai1;
                cout << "Input Value 2 to delete : ";
                cin >> nilai2;
                cout << "Input target that will be deleted : ";
                cin >> target;
                hapusTertentu(nilai1, nilai2, target);
                getch();
                break;
            case 7:
                hapusBelakang();
                getch();
                break;
            case 8:
                cout << "Input Value 1 to search : ";
                cin >> nilai1;
                cout << "Input Value 2 to search : ";
                cin >> nilai2;
                cout << "Input target to search : ";
                cin >> target;
                cariData(nilai1, nilai2, target);
                getch();
                break;
            case 9:
                tampilData();
                getch();
                break;
            case 10:
                cout << "===============" << endl;
                cout << "=  Thank you  =" << endl;
                cout << "===============" << endl;
                break;
            default:
                cout << "No choice selected" << endl;
        }

    } while (pilih != 10);

    return 0;
}