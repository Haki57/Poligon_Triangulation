//
// Created by User on 20.09.2019.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

vector<pair<pair<long long, long long>, bool>> arr;


void error() {
    cout << "\n";
    cout << ">>>>> Вы ввели неправильный формат данных.\nПовторите попытку, следуюя моим инструкциям, указанным выше.\n\n";
    cout << ">>>>> You entered an incorrect data format.\nTry again, following my instructions above.\n";
}


bool trav(long long x1, long long y1, long long x3, long long y3, long long x2, long long y2, long long x4, long long y4) {
    long long A1 = (x3 - x1) * (y4 - y1) - (y3 - y1) * (x4 - x1);
    long long A2 = (x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1);
    long long B1 = (x4 - x2) * (y1 - y2) - (x1 - x2) * (y4 - y2);
    long long B2 = (x4 - x2) * (y3 - y2) - (x3 - x2) * (y4 - y2);
    long long C1 = (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
    long long C2 = (x1 - x3) * (y4 - y3) - (x4 - x3) * (y1 - y3);

    if (((A1 <= 0 && 0 <= A2) || (A2 <= 0 && 0 <= A1)) && ((B1 <= 0 && 0 <= B2) || (B2 <= 0 && 0 <= B1)) && ((C1 <= 0 && 0 <= C2) || (C2 <= 0 && 0 <= C1))) {
        if (A1 == 0 && A2 == 0 && B1 == 0 && B2 == 0 && C1 == 0 && C2 == 0) {
            if (!(fmin(fmax(x1, x3), fmax(x2, x4)) < fmax(fmin(x1, x3), fmin(x2, x4))) &&
                !(fmin(fmax(y1, y3), fmax(y2, y4)) < fmax(fmin(y1, y3), fmin(y2, y4))))
                return true;
            else
                return false;
        } else
            return true;
    } else
        return false;

}


bool check(long long one, long long two, long long tree, long long j) {
    long double s_norm = 0, s = 0;
    s_norm += arr[one].first.second * arr[two].first.first - arr[two].first.second * arr[one].first.first;
    s_norm += arr[two].first.second * arr[tree].first.first - arr[tree].first.second * arr[two].first.first;
    s_norm += arr[tree].first.second * arr[one].first.first - arr[one].first.second * arr[tree].first.first;
    s_norm = abs(s_norm);
    long long a = arr[j].first.first;
    long long b = arr[j].first.second;
    s += abs(arr[one].first.second * arr[two].first.first - arr[two].first.second * arr[one].first.first + arr[two].first.second * a - b * arr[two].first.first + b * arr[one].first.first - arr[one].first.second * a);
    s += abs(arr[two].first.second * arr[tree].first.first - arr[tree].first.second * arr[two].first.first + arr[tree].first.second * a - b * arr[tree].first.first + b * arr[two].first.first - arr[two].first.second * a);
    s += abs(arr[tree].first.second * arr[one].first.first - arr[one].first.second * arr[tree].first.first + arr[one].first.second * a - b * arr[one].first.first + b * arr[tree].first.first - arr[tree].first.second * a);

    if (s == s_norm) {
        return true;
    } else
        return false;

}


void start() {
    cout << ">>>>>Выберите вормат ввода. Если вы хотите вводить с консоли напишите 'c', без кавычек; если же вы хотите вводить из файла, то напишите 'f', без кавычек.\n\n";
    cout << ">>>>>Select input entry. If you want to type from the console, write 'c', without the quotes; If you want to type from a file, write 'f', without quotes.\n\n";
    cout << ">>>>>Введите количество вершин вашего многоугольника. Затем введите координаты его вершин в порядке обхода по часовой стрелке.\n";
    cout << "\n";
    cout << ">>>>>Write the number of vertices of your polygon. Then enter the coordinates of it's vertices in the order of the clockwise traversal.\n";
    cout << "\n";
}


long long stint(string s) {
    long long dec = 1;
    long long ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        ans += dec * (s[i] - 48);
        dec *= 10;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    while (true) {
        start();
        string tipe;
        string output;
        //ifstream in("input.txt");
        ifstream in;
        //in.open("/Users/Andrey/Desktop/infa/КРУЖКИ/57/10 class/Proj3/input.txt");
        //in.open("input.txt");
        long long n = 0;
///////////////////////........finding tipe 1 .....................
        while (true) {
            cin >> tipe;
            if (tipe == "f")
                break;
            else if (tipe != "c") {
                error();
                continue;
            }
            break;
        }
///////////////////////........finding n ..........................
        while (true) {
            string s;
            string s2;
            n = 0;
            if (tipe == "c") {
                cin >> s;
            } else {
                in >> s;
            }
            int k = 0;
            while (k < s.size()) {
                if (isdigit(s[k]))
                    k++;
                else
                    break;
            }
            if (k != s.size()) {
                error();
                continue;
            }
            if (s.size() > 4) {
                error();
                continue;
            }
            n = stint(s);
            break;
        }
///////////////////////........finding tipe n dots .....................
        while (true) {
            int i = 0;
            if (tipe == "c") {
                i = 0;
                string lit;
                while (i < n && cin >> lit) {
                    if (arr.size() > 0 && lit == "m") {
                        arr.pop_back();
                        continue;
                    }
                    long long x, y;
                    int j = 0;
                    while (j < lit.size()) {
                        if (isdigit(lit[j])) {
                            j++;
                            continue;
                        }
                        break;
                    }
                    if (j != lit.size()) {
                        error();
                        continue;
                    }
                    x = stint(lit);

                    cin >> lit;
                    j = 0;
                    while (j < lit.size()) {
                        if (isdigit(lit[j])) {
                            j++;
                            continue;
                        }
                        break;
                    }
                    if (j != lit.size()) {
                        error();
                        continue;
                    }
                    y = stint(lit);
                    arr.push_back({{x, y}, false});
                    i++;
                }
            }
            if (tipe == "f") {
                string lit;
                i = 0;
                while (i < n && in >> lit) {
                    long long x, y;
                    int j = 0;
                    while (j < lit.size()) {
                        if (isdigit(lit[j])) {
                            j++;
                            continue;
                        }
                        break;
                    }
                    if (j != lit.size()) {
                        error();
                        continue;
                    }
                    x = stint(lit);

                    in >> lit;
                    j = 0;
                    while (j < lit.size()) {
                        if (isdigit(lit[j])) {
                            j++;

                            continue;
                        }
                        break;
                    }
                    if (j != lit.size()) {
                        error();
                        continue;
                    }
                    y = stint(lit);
                    arr.push_back({{x, y}, false});
                    i++;
                }
            }
            if (i == n)
                break;
        }
///////////////////////........finding tipe 2 .....................
        while(true) {
            if (tipe == "c")
                cin >> output;
            else
                in >> output;
            if(output != "c" && output != "f") {
                error();
                continue;
            }
            break;
        }
///////////////////////////////////////////////////////////////////
        if (n < 3) {
            cout << ">>>>>Вы ввели не многоугольник (в нём слишком мало вершин). Количество вершин многоугольника должно быть больше либо равно 3.\n";
            cout << "\n";
            cout << ">>>>>You did not enter a polygon (there are too few vertices in it). The number of vertices of a polygon must be greater than or equal to 3.\n";
            start();
            continue;
        }
        if (n == 3){
            cout << "ваш многоугольник является треугольником\n";
            cout << "Your polygon is a triangle\n";
            return 0;
        }
        bool flag = true;
        for (int j = 2; j < n - 1; j++) {
            if (trav(arr[0].first.first, arr[0].first.second, arr[1].first.first, arr[1].first.second, arr[j].first.first, arr[j].first.second, arr[j + 1].first.first, arr[j + 1].first.second)) {
                flag = false;
                break;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 2; j < n - 1; j++) {
                if (trav(arr[i].first.first, arr[i].first.second, arr[i + 1].first.first, arr[i + 1].first.second, arr[j].first.first, arr[j].first.second, arr[j + 1].first.first, arr[j + 1].first.second)) {
                    cout << i << " " << j << "\n";
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if(!flag) {
            cout << "Ваш многоугольник имеет самопересечения. Введите другой многоугольник, соответствующий условию.\n";
            cout << "Your polygon has self-intersections. Enter another polygon that matches the condition.\n";
            continue;
        }
        vector<pair< pair<long long, long long>, pair<long long, long long>> > ans;
        long long one = 0, two = 1, tree = 2;
        bool bil = true;
        long long cnt = n;
        int num = 0;
        while (cnt > 3) {
            if (!bil && !(one == 0 && two == 1 && tree == 2 && num < 1)) {
                one = two;
                two = tree;
                int i = tree + 1;
                while (i != tree) {
                    if (i == n)
                        i = 0;
                    if (!arr[i].second)
                        break;
                    i--;
                }
                tree = i;
            }
            bil = false;
            if (!arr[one].second && !arr[two].second && !arr[tree].second) {
                long long eps = (arr[tree].first.first - arr[two].first.first) * (arr[one].first.second - arr[two].first.second) - (arr[tree].first.second - arr[two].first.second) * (arr[one].first.first - arr[two].first.first);
                if (eps < 0) {
                    bool flag = true;
                    for (int j = 0; j < n; j++) {
                        if (!arr[j].second && j != one && j != two && j != tree) {
                            if (check(one, two, tree, j)) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag){
                        ans.push_back({arr[one].first, arr[tree].first});
                        arr[two].second = true;
                        cnt--;
                        if (cnt <= 3)
                            continue;
                        two = one;
                        int i = one - 1;
                        while (i != one) {
                            if (i == -1)
                                i = n - 1;
                            if (!arr[i].second)
                                break;
                            i--;
                        }
                        one = i;
                        bil = true;
                    }
                }
                num++;
            }
        }
        if (output == "f"){
            ofstream out("output.txt");
            for (int i = 0; i < ans.size(); i++) {
                out << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
            }
        } else {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
            }
        }
        in.close();
    }
}
