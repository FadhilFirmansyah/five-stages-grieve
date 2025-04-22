#include <iostream>
#include <vector>
#include <random>

using namespace std;

bool isActionArnoumai();
void actionArnoumai();
bool isActionThymous();
void actionThymous();
bool isActionProsfora();
void actionProsfora();

int main() {
    vector<string> items = {"Pedang"};
    vector<string> items_pool = {"Armor", "Koin Emas Kuno", "Elixir", "Melati Putih"};

    cout << "SELAMAT DATANG DI EARTH ODYSSEY" << endl << endl;
    cout << "Icarus merupakan seoarang petualang dan anak tunggal, Ibunya yang membesarkan seorang diri jatuh sakit yang tidak diketahui dan kondisi yang semakin waktu semakin parah" << endl;
    cout << "Konon cerita terdapat tumbuhan Melati yang memiliki inti sari dari kehidupan alam di puncak gunung, Icarus gegas berangkat tuk mengambil tumbuhan tersebut" << endl;

    if (isActionArnoumai()) {
        actionArnoumai();
    } else {
        cout << endl << "Tepat masuk ke rumah Icarus mendapati Ibunya sedang memasak makanan favoritnya dengan kondisi Ibu yang memprihatinkan" << endl;
        cout << "FIN" << endl;
    }

    cout << "Tiba Icarus pada kaki gunung yang akan didaki untuk mengambil tumbuhan yang ia butuhkan saat ini" << endl;

    if (isActionThymous()) {
        actionThymous();
    } else {
        cout << endl << "Gegas Icarus sampai rumah, ia melihat Ibu nya sedang menghangatkan tungku api agar malam hari terasa hangat" << endl;
        cout << "FIN" << endl;
    }

    cout << "Di tengah perjalanan Icarus menemui seorang kakek pengelana bernama Prosforá yang menawarkan Icarus koin aneh" << endl;


    return 0;
}

bool isActionArnoumai() {
    cout << endl << "Pada perjalanan awal Icarus menemui raksasa bernama Arnoúmai yang menghalangi perjalanan menuju puncak gunung" << endl;

    char is_fight = 'y';

    cout << "[input (y/n)] Melawan Arnoúmai atau Pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

bool isActionThymous() {
    cout << endl << "Dengan kelengahan Icarus suatu monster ras mimic bernama Thymós meniru perawakan Icarus, Ia menghadapi Thymós untuk mempercepat waktu" << endl;

    char is_fight = 'y';

    cout << "[input (y/n)] Melawan Thymós atau Pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

bool isActionProsfora() {
    cout << endl << "\"Tiada nyawa yang bisa digantikan oleh nilai materi, ambilah koin ini untuk menolak takdir yang sudah pasti\" ucap Prosforá pada Icarus" << endl;

    char is_fight = 'y';

    cout << "[input (y/n)] Terima pemberian Prosforá atau pulang?: ";
    cin >> is_fight;

    return is_fight == 'y';
}

void actionArnoumai() {
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
            cout << "Pilihan tidak dikenali! Icarus ragu dan kehilangan kesempatan..." << endl;
        }

        int arnoumai_move = enemy_choice(gen);
        if (arnoumai_move == 0) {
            cout << "Arnoúmai menyerang!" << endl;
            if (!is_defending) {
                hp_icarus--;
                cout << "Serangan mengenai Icarus!" << endl << endl;
            } else {
                cout << "Icarus berhasil menahan serangan" << endl;
            }
        } else {
            cout << "Arnoúmai lengah..." << endl << endl;
        }
    }

    is_win = hp_arnoumai <= 0;

    cout << endl;
    if (is_win) {
        cout << "Icarus berhasil mengalahkan Arnoúmai dan melanjutkan perjalanan" << endl;
    } else {
        cout << "Icarus tumbang dalam pertarungan..." << endl;
    }
}

void actionThymous() {
    char is_action = 'y';
    bool is_win = false;
    int hp_icarus = 6;
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
            cout << "Pilihan tidak dikenali! Icarus ragu dan kehilangan kesempatan..." << endl;
        }

        int thymous_move = enemy_choice(gen);
        if (thymous_move == 0) {
            cout << "Thymós menyerang!" << endl;
            if (!is_defending) {
                hp_icarus--;
                cout << "Serangan mengenai Icarus!" << endl << endl;
            } else {
                cout << "Icarus berhasil menahan serangan" << endl;
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

void actionProsfora() {

}
