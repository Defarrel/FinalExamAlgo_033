#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

class node {
public:
	int nim;
	string Nama;
	int thn;
	node* next;
	node* prev;
};
class DoubleLinkedList {
private:
	
	node* START;
public:
	DoubleLinkedList();
	bool search(int rollNo, node** previous, node** current);
	bool listEmpty();
	void tambahMahasiswa();
	void tampilkanSemuaMahasiswa();
	void algorithmacariMahasiswaByNIM();
	void algorithmaSortByTahunMasuk();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}
void DoubleLinkedList::tambahMahasiswa(){
		int nim;
		string Nama;
		int thn;
		cout << "NIM: " << endl;
		cin >> nim;
		cout << "Nama: " << endl;
		cin >> Nama;
		cout << "Jurusan: " << endl;
		int jurusan;
		cin >> jurusan;
		cout << "Tahun Masuk: " << endl;
		cin >> thn;

		node* newNode = new node();
		newNode->nim;
		newNode->Nama;
		newNode->thn;

		if (START == NULL || nim <= START->thn) {
			if (START != NULL && nim== START->thn) {
				cout << "\nDuplicate number not allowed" << endl;
				return;
			}
			newNode->next = START;
			if (START != NULL)
				START->prev - newNode;
			newNode->prev = NULL;
			START = newNode;
			return;
		}
		node* current = START;
		while (current->next != NULL && nim > current->next->thn)
			current = current->next;
		if (current->next != NULL && nim == current->next->thn) {
			cout << "\nDuplicate roll number not allowed: " << endl;
			return;
		}
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != NULL)
			current->next->prev = newNode;
		current->next = newNode;

	}



bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}
void DoubleLinkedList::tampilkanSemuaMahasiswa() {
	if(listEmpty())
		cout << "\nList is Empty" << endl;
	else{
		cout << "\nPilihan:  " << endl;
	node* currentNode = START;
	while (currentNode != NULL) {
		cout << currentNode->thn << " " << currentNode->Nama<< endl;
		currentNode = currentNode->next;
	}
}
}
bool DoubleLinkedList::search(int rollno, node** previous, node** current) {
	*previous = *current = START;
	while (*current != NULL && rollno != (*current)->nim) {
		*previous = *current;
		*current = (*current)->next;
	}
	return(*current != NULL);
}

void algorithmacariMahasiswaByNIM() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;

	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nPilihan: ";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << curr->nim << endl;
		
	}
}
void algorithmaSortByTahunMasuk() {
	return;
}
int main() {
	DoubleLinkedList obj;
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			obj.tambahMahasiswa();
			break;
		case 2:
			obj.tampilkanSemuaMahasiswa();
			break;
		case 3:
			obj.algorithmacariMahasiswaByNIM();
			break;
		case 4:
			obj.algorithmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

//2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? (10 Poin)
//3. Jelaskan perbedaan mendasar antara algorithma stack dan queue!(15 Poin)
//4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack ? (15 poin)
//5. Perhatikan gambar berikut : (20 Poin)
//a.Seberapa banyak kedalaman yang dimiliki struktur tersebut ?
//b.Bagaimana cara membaca struktur pohon di atas ? (Pilih salah satu metode yaitu
	//Inorder, Preorder atau Postorder Traversal)

//Jawab

//2. Double linked list 
//3. Stack adalah algoritma dengan menyimpan data secara bertummpuk dan akses stack hanya bisa diambil dari atas dan hanya dapat mengurangi/push atau pop
//	 sedangkan queue adalah algoritma yang menyimpan element secara antrian dimana elmenent disimpan disatu ujung dan dihapus dari ujung antrian belakang.
//4. Saat kita membutuhkan daftar undo untuk aplikasi atau sistem.
//5. a. (5).
//	 b. (preorder) Pohon diatas memiliki root 25 karena preorder maka anak pertama ny adalah 20 kemudian 10, 5, dan 1 setelah mencapai node paling bawah
//		maka pohon akan kembali ke root terakhir dari node terakhir dan membaca anak 8 dan seterusnya sampai node habis dan kembali ke root awal.