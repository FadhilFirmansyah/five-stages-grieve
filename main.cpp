#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool isActionArnoumai();
void actionArnoumai(vector<string>& items, vector<string>& items_pool, string& picked_item);
bool isActionThymous();
void actionThymous(int extra_hp);
bool isActionProsfora();
void actionProsfora();
bool isActionKatathlipsi();
void actionKatathlipsi(vector<string>& items, string& picked_item, int extra_hp);

int main() {
    bool final_action = 'y';
    vector<string> items = {"Pedang"};
    vector<string> items_pool = {"Armor", "Koin Emas Kuno"};
    string picked_item = "";

    cout << "SELAMAT DATANG DI EARTH ODYSSEY" << endl << endl;
    cout << "Icarus merupakan seoarang petualang dan anak tunggal, Ibunya yang membesarkan seorang diri jatuh sakit yang tidak diketahui dan kondisi yang semakin waktu semakin parah" << endl;
    cout << "Konon cerita terdapat tumbuhan Melati yang memiliki inti sari dari kehidupan alam di puncak gunung, Icarus gegas berangkat tuk mengambil tumbuhan tersebut" << endl;

    if (isActionArnoumai()) {
        actionArnoumai(items, items_pool, picked_item);
    } else {
        cout << endl << "Tepat masuk ke rumah Icarus mendapati Ibunya sedang memasak makanan favoritnya dengan kondisi Ibu yang memprihatinkan" << endl;
        cout << "FIN" << endl;
    }

    cout << "Tiba Icarus pada kaki gunung yang akan didaki untuk mengambil tumbuhan yang ia butuhkan saat ini" << endl;

    int extra_hp = (picked_item == "Armor") ? 1 : 0;

    if (isActionThymous()) {
        actionThymous(extra_hp);
    } else {
        cout << endl << "Gegas Icarus sampai rumah, ia melihat Ibu nya sedang menghangatkan tungku api agar malam hari terasa hangat" << endl;
        cout << "FIN" << endl;
    }

    cout << "Di tengah perjalanan Icarus menemui seorang kakek pengelana bernama Prosforá yang menawarkan Icarus koin aneh" << endl;

    if (isActionProsfora()) {
        picked_item = "Koin Emas Kuno";
        items.push_back(picked_item);
        cout << "Icarus menerima item: " << picked_item << endl;
    } else {
        cout << endl << "Icarus dengan cepat menuruni gunung menuju rumah dan melihat Ibu nya yang sakit terbaring di kasur sedang ter tidur lelap" << endl;
        cout << "FIN" << endl;
    }

    cout << endl << "Kebingungan yang mengisi kepala Icarus membuat bertanya kepada dirinya sendiri apakah perbuatan yang ia lakukan sejauh ini benar atau apa...." << endl;
    cout << "Hingga akhirnya tiba pada puncak gunung yang selama perjalanan ini berlangsung...." << endl;
    cout << "Namun siapa sangka bahwasannya terdapat sosok malaikat pencabut nyawa yang serupa dengan mendiang ayah Icarus yang bernama Katáthlipsi" << endl;

    if (isActionKatathlipsi()) {
        actionKatathlipsi(items, picked_item, extra_hp);
    } else {
        cout << endl << "Icarus tiba ke rumah dan melihat satu-satu nya pembawa kehidupan Icarus pada dunia telah tiada dan memeluk Ibu nya serta tangis tiada henti silir berganti" << endl;
        cout << "FIN" << endl;
    }

    cout << "Tepat di depan mata terdapat tumbuhan Melati Putih yang menjadi pusat kehidupan alam sekitar" << endl;
    cout << "Disinilah moral beban Icarus diuji dengan mengkorbankan apa yang semestinya ada atau melawan waktu yang terus berputar" << endl;
    cout << endl << "[input (y/n)] MENGAMBIL MELATI ATAU MEMBIARKAN APA YANG SUDAH PASTI: ";
    cin >> final_action;

    if (final_action == 'y') {
        cout << "Icarus melakukan perjalanan pulang dengan seiring ia berjalan melihat tumbuhan mati satu per satu" << endl << "untuk menyembuhkan sakit seorang malaikat yang membawa kehangatan pertama kali Icarus menghirup udara pada dunia" << endl;
    }else {
        cout << "Icarus terus meneteskan air mata selama perjalanan hingga tiba ke rumah ia memeluk erat hangat Ibu yang sudah tiada" << endl;
    }

    return 0;
}

bool isActionArnoumai() {
    cout << "Pada perjalanan awal Icarus menemui raksasa bernama Arnoúmai yang menghalangi perjalanan menuju puncak gunung" << endl;
    char is_fight = 'y';

    cout << "[input (y/n)] Melawan Arnoúmai atau Pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

void actionArnoumai(vector<string>& items, vector<string>& items_pool, string& picked_item) {
    char is_action = 'y';
    bool is_win = false;
    int hp_icarus = 5;
    int hp_arnoumai = 5;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> enemy_choice(0, 1);

    cout << endl << "Pertarungan dimulai!" << endl;

    while (hp_icarus > 0 && hp_arnoumai > 0) {
        cout << "Arnoúmai: ";
        for (int i = 0; i < hp_arnoumai; ++i) cout << "♥ ";
        cout << endl << "Icarus  : ";
        for (int i = 0; i < hp_icarus; ++i) cout << "♥ ";
        cout << endl << "---------------------" << endl;

        cout << "[input (1/2)] Serang / Berlindung?: ";
        cin >> is_action;
        bool is_defending = (is_action == '2');

        if (is_action == '1') {
            cout << endl << "Icarus menyerang!" << endl;
            hp_arnoumai--;
        } else if (is_defending) {
            cout << endl << "Icarus bersiap untuk berlindung..." << endl;
        } else {
            cout << endl << "Pilihan tidak dikenali! Icarus ragu dan kehilangan kesempatan..." << endl;
        }

        int move = enemy_choice(gen);
        if (move == 0) {
            cout << "Arnoúmai menyerang!" << endl;
            if (!is_defending) {
                hp_icarus--;
                cout << "Serangan mengenai Icarus!" << endl << endl;
            } else {
                cout << "Icarus berhasil menahan serangan" << endl << endl;
            }
        } else {
            cout << "Arnoúmai lengah..." << endl << endl;
        }
    }

    is_win = hp_arnoumai <= 0;

    cout << endl;
    if (is_win) {
        char take_item = 'n';
        cout << "Pertempuran dimenangkan Icarus dengan menumbangkan Arnoúmai" << endl;
        cout << "Arnoúmai menjatuhkan Armor. Apakah Icarus ingin mengambilnya? (y/n): ";
        cin >> take_item;

        if (take_item == 'y') {
            picked_item = "Armor";
            items.push_back(picked_item);
            cout << "Icarus mengambil item: " << picked_item << endl << endl;
        } else {
            cout << "Icarus memilih untuk tidak mengambil apa pun." << endl << endl;
        }

    } else {
        cout << "Icarus tumbang dalam pertarungan..." << endl;
    }

    cout << "Icarus berhasil mengalahkan Arnoúmai dan melanjutkan perjalanan" << endl;
}

bool isActionThymous() {
    cout << "Dengan kelengahan Icarus suatu monster ras mimic bernama Thymós meniru perawakan Icarus, Ia menghadapi Thymós untuk mempercepat waktu" << endl;
    char is_fight = 'y';

    cout << "[input (y/n)] Melawan Thymós atau Pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

void actionThymous(int extra_hp) {
    char is_action = 'y';
    bool is_win = false;
    int hp_icarus = 5 + extra_hp;
    int hp_thymous = 4;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> enemy_choice(0, 1);

    cout << endl << "Pertarungan dimulai!" << endl;

    while (hp_icarus > 0 && hp_thymous > 0) {
        cout << "Thymós : ";
        for (int i = 0; i < hp_thymous; ++i) cout << "♥ ";
        cout << endl << "Icarus : ";
        for (int i = 0; i < hp_icarus; ++i) cout << "♥ ";
        cout << endl << "---------------------" << endl;

        cout << "[input (1/2)] Serang / Berlindung?: ";
        cin >> is_action;
        bool is_defending = (is_action == '2');

        if (is_action == '1') {
            cout << endl << "Icarus menyerang!" << endl;
            hp_thymous--;
        } else if (is_defending) {
            cout << endl << "Icarus bersiap untuk berlindung..." << endl;
        } else {
            cout << endl << "Pilihan tidak dikenali! Icarus ragu dan kehilangan kesempatan..." << endl;
        }

        int move = enemy_choice(gen);
        if (move == 0) {
            cout << "Thymós menyerang!" << endl;
            if (!is_defending) {
                hp_icarus--;
                cout << "Serangan mengenai Icarus!" << endl << endl;
            } else {
                cout << "Icarus berhasil menahan serangan" << endl << endl;
            }
        } else {
            cout << "Thymós lengah..." << endl << endl;
        }
    }

    is_win = hp_thymous <= 0;

    cout << endl;
    if (is_win) {
        cout << "Perlawanan dimenangkan Icarus dan hasil perlawanan yang telah dilalui selama ini kekuatan Icarus bertambah kuat dari sebelumnya" << endl;
    } else {
        cout << "Icarus tumbang dalam pertarungan..." << endl;
    }
}

bool isActionProsfora() {
    cout << "\"Tiada nyawa yang bisa digantikan oleh nilai materi, ambilah koin ini untuk menolak takdir yang sudah pasti\" ucap Prosforá pada Icarus" << endl;
    char is_fight = 'y';
    cout << "[input (y/n)] Terima pemberian Prosforá atau pulang?: ";
    cin >> is_fight;
    return is_fight == 'y';
}

bool isActionKatathlipsi() {
    char is_fight = 'y';

    cout << "[input (y/n)] Melawan Katáthlipsi atau Pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

void actionKatathlipsi(vector<string>& items, string& picked_item, int extra_hp) {
    char is_action = 'y';
    bool is_win = false;
    bool revived = false;
    int hp_icarus = 5 + extra_hp;
    int hp_katathlipsi = 25;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> enemy_choice(0, 1);

    cout << endl;

    while (hp_icarus > 0 && hp_katathlipsi > 0) {
        cout << "Katáthlipsi : ";
        for (int i = 0; i < hp_katathlipsi; ++i) cout << "♥ ";
        cout << endl << "Icarus      : ";
        for (int i = 0; i < hp_icarus; ++i) cout << "♥ ";
        cout << endl << "---------------------" << endl;

        cout << "[input (1/2)] Serang / Berlindung?: ";
        cin >> is_action;
        bool is_defending = (is_action == '2');

        if (is_action == '1') {
            cout << endl << "Icarus menyerang Katáthlipsi!" << endl;
            hp_katathlipsi -= 2;
        } else if (is_defending) {
            cout << endl << "Icarus bersiap untuk berlindung..." << endl;
        } else {
            cout << endl << "Pilihan tidak dikenali! Icarus ragu dan kehilangan kesempatan..." << endl;
        }

        int move = enemy_choice(gen);
        if (move == 0) {
            cout << "Katáthlipsi menyerang!" << endl;
            if (!is_defending) {
                hp_icarus--;
                cout << "Serangan mengenai Icarus!" << endl << endl;
            } else {
                cout << "Icarus berhasil menahan serangan" << endl << endl;
            }
        } else {
            cout << "Katáthlipsi lengah..." << endl << endl;
        }

        if (hp_icarus <= 0 && !revived && find(items.begin(), items.end(), "Koin Emas Kuno") != items.end()) {
            char use_coin;
            cout << "Icarus tumbang... Namun Koin Emas Kuno mulai bersinar terang." << endl;
            cout << "Gunakan Koin Emas Kuno untuk hidup kembali? (y/n): ";
            cin >> use_coin;

            if (use_coin == 'y') {
                hp_icarus = 5 + extra_hp;
                revived = true;
                cout << "Kekuatan misterius membawa Icarus kembali hidup! Pertarungan berlanjut..." << endl;

                items.erase(remove(items.begin(), items.end(), "Koin Emas Kuno"), items.end());
            } else {
                break;
            }
        }
    }

    cout << endl;

    is_win = hp_katathlipsi <= 0;

    if (is_win) {
        cout << "Icarus berhasil mengalahkan Katáthlipsi dan menuntuskan tugas akhir yang ia perjuangkan sejauh ini...." << endl;
    } else {
        cout << "Icarus gagal dalam perjuangannya dan tidak mampu menyelamatkan ibunya..." << endl;
    }
}
