#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pengarang {
public:
	Pengarang(const string nama) : namaPengarang(nama) {}

	string getNamaPengarang() const {
		return namaPengarang;
	}

private:
	string namaPengarang;
};

class Penerbit {
public:
	Penerbit(const string nama) : namaPenerbit(nama) {}

	string getNamaPenerbit() const {
		return namaPenerbit;
	}

	void tambahPengarang(const Pengarang pengarang) {
		pengarangPenerbit.push_back(pengarang);
	}
	vector<Pengarang> getPengarangPenerbit() const {
		return pengarangPenerbit;
	}

private:
	string namaPenerbit;
	vector<Pengarang> pengarangPenerbit;
};
class Buku {
public:
	Buku(const string judul, const Pengarang pengarang) : judulBuku(judul), pengarangBuku(pengarang) {}

	string getJudulBuku() const {
		return judulBuku;
	}

	Pengarang getPengarangBuku() const {
		return pengarangBuku;
	}

private:
	string judulBuku;
	Pengarang pengarangBuku;
};

int main() {

	Penerbit GamaPress("Gama Press");
	Penerbit IntanPariwara("Intan Pariwara");

	Pengarang Giga("Giga");
	Pengarang Joko("Joko");
	Pengarang Lia("Lia");
	Pengarang Asroni("Asroni");

	GamaPress.tambahPengarang(Joko);
	GamaPress.tambahPengarang(Lia);
	GamaPress.tambahPengarang(Giga);
	IntanPariwara.tambahPengarang(Asroni);
	IntanPariwara.tambahPengarang(Giga);

	Buku bukuA("Fisika", Joko);
	Buku bukuB("Algoritma", Joko);
	Buku bukuC("BasisData", Lia);
	Buku bukuD("Dasar Pemrograman", Asroni);
	Buku bukuE("Matematika", Giga);
	Buku bukuF("Multimedia 1", Giga);

	cout << "Daftar pengarang pada penerbit \"Gama Press\":\n";
	for (const auto pengarang : GamaPress.getPengarangPenerbit()) {
		cout << pengarang.getNamaPengarang() << "\n";
	}
	cout << "" << endl;
	cout << "Daftar pengarang pada penerbit \"Intan Pariwara\":\n";
	for (const auto pengarang : IntanPariwara.getPengarangPenerbit()) {
		cout << pengarang.getNamaPengarang() << "\n";
	}
	cout << "" << endl;
	cout << "Daftar penerbit yang diikuti \"Giga\":\n";
	for (const auto penerbit : { GamaPress, IntanPariwara }) {
		for (const auto pengarang : penerbit.getPengarangPenerbit()) {
			if (pengarang.getNamaPengarang() == "Giga") {
				cout << penerbit.getNamaPenerbit() << "\n";
				break;
			}
		}
	}
	cout << "" << endl;
	cout << "Daftar buku yang dikarang \"Joko\":\n";
	for (const auto buku : { bukuA, bukuB }) {
		if (buku.getPengarangBuku().getNamaPengarang() == "Joko") {
			cout << buku.getJudulBuku() << "\n";
		}
	}
	cout << "" << endl;
	cout << "Daftar buku yang dikarang \"Lia\":\n";
	for (const auto buku : { bukuC }) {
		if (buku.getPengarangBuku().getNamaPengarang() == "Lia") {
			cout << buku.getJudulBuku() << "\n";
		}
	}
	cout << "" << endl;
	cout << "Daftar buku yang dikarang \"Asroni\":\n";
	for (const auto buku : { bukuD }) {
		if (buku.getPengarangBuku().getNamaPengarang() == "Asroni") {
			cout << buku.getJudulBuku() << "\n";
		}
	}
	cout << "" << endl;
	cout << "Daftar buku yang dikarang \"Giga\":\n";
	for (const auto buku : { bukuE, bukuF }) {
		if (buku.getPengarangBuku().getNamaPengarang() == "Giga") {
			cout << buku.getJudulBuku() << "\n";
		}
	}

	return 0;
}
