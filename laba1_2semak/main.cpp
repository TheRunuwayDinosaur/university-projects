#include <bits/stdc++.h>
#include <windows.h>
#define all(x) begin(x),end(x)
#define isz(x) (int)x.size()
using namespace std;

long long N_op = 2;
class Queue{
private:
    vector <int> q; // 1
    vector <int> q_sorted; // 1
public:
    void push(int value){ // 1
        q.push_back(value); // 1
        N_op += 1;
    }
    int size_(){ // 1
        N_op += 1;
        return isz(q); // 1
    }
    int get(int pos){ // худший случай - n
        if (pos > 0 && pos - 1 >= size_()){ // 1
            N_op += 1;
            return -1; // 1;
        }
        reverse(all(q)); // (size / 2) - свапов, значит size значений, которые изменились ~ n
        N_op += size_() / 2;
        // разворачиваю очередь для удобства работы с ней
        vector <int> temp; // 1
        N_op += 1;
        // временная очередь
        int result = 0; // 1
        N_op += 1;
        int temp_size = size_(); // 1
        N_op += 1;
        for (int i = temp_size - 1;i > temp_size - pos;i--){ // (temp_size) - pos - 1 ~ (n - pos - 1) ~ n
            temp.push_back(q.back()); // 1
            N_op += 1;
            // добавляю во временную очередь последний(первый) элемент основной очереди
            q.pop_back(); // 1
            N_op += 1;
            // удаляю из основной очереди последний(первый) элемент
            N_op += 1;
        }
        result = q.back(); // 1
        N_op += 1;
        // запоминаю элемент, который лежит в нужной нам позиции
        temp_size = size_(); // 1
        N_op += 1;
        for (int i = 0;i < temp_size;i++){ // temp_size - 1 ~ (n - 1) ~ n
            temp.push_back(q.back()); // 1
            N_op += 1;
            // дополняю до конца нашу временную очередь
            q.pop_back(); // 1
            N_op += 1;
            // удаляю до конца основную очередь
            N_op += 1;
        }
        temp_size = isz(temp); // 1
        N_op += 1;
        reverse(all(temp)); // (size / 2) свапов ~ n / 2
        N_op += size_() / 2;
        // разворачиваю нашу временную очередь, для удобства работы с ней
        for (int i = 0;i < temp_size;i++){ // temp_size - 1 ~ n - 1 ~ n
            q.push_back(temp.back()); // 1
            N_op += 1;
            // добавляю в конец основной очереди
            temp.pop_back(); // 1
            N_op += 1;
            // удаляю из конца(начала) временной очереди
            N_op += 1;
        }
        N_op += 1;
        return result; // 1
    }
    void pop(int pos){ // худший случай - n
        if (pos == 0 || pos - 1 >= size_()){ // 1
            N_op += 1;
            std::cout << "Некорректная позиция!!!\n"; // 1
            return; // 1
        }
        reverse(all(q)); // size / 2 свапов ~ n / 2
        N_op += size_() / 2;
        // разворавичаю очередь для удобства работы с ней
        vector <int> temp; // 1
        N_op += 1;
        // временная очередь
        int temp_size = size_(); // 1
        N_op += 1;
        for (int i = temp_size - 1;i > temp_size - pos;i--){ // (temp_size - pos - 1) ~ (n - pos - 1) ~ n
            temp.push_back(q.back()); // 1
            N_op += 1;
            // добавляю во временную очередь последний(первый) элемент основной очереди
            q.pop_back(); // 1
            N_op += 1;
            // удаляю из основной очереди последний(первый) элемент
            N_op += 1;
        }
        q.pop_back(); // 1
        N_op += 1;
        // удаляю элемент, который стоит в нужной нам позиции
        temp_size = size_(); // 1
        N_op += 1;
        for (int i = 0;i < temp_size;i++){ // temp_size - 1 ~ n - 1 ~ n
            temp.push_back(q.back()); // 1
            N_op += 1;
            // заполняю до конца нашу временную очередь
            q.pop_back(); // 1
            N_op += 1;
            // удаляю до конца нашу основную очередь
            N_op += 1;
        }
        temp_size = isz(temp); // 1
        N_op += temp_size;
        reverse(all(temp)); // size / 2 свапов ~ n / 2
        N_op += temp_size / 2;
        // разворачиваю временную очередь, для удобства работы с ней
        for (int i = 0;i < temp_size;i++){ // temp_size - 1 ~ n
            q.push_back(temp.back()); // 1
            N_op += 1;
            // достаём из конца(начала) временной очереди
            temp.pop_back(); // 1
            N_op += 1;
            // удаляем из конца(начала) временной очереди
            N_op += 1;
        }
    }
    void set(int pos,int value){ // худший случай - n
        if (pos == 0 || pos - 1 >= size_()){ // 1
            N_op += 1;
            std::cout << "Некорректная позиция!!!\n"; // 1
            return; // 1
        }
        pop(pos); // n
        N_op += size_();
        // вызываю метод pop
        vector <int> temp; // 1
        N_op += 1;
        // временная очередь
        reverse(all(q)); // (size / 2) свапов ~ n / 2
        N_op += size_() / 2;
        // разворачиваю основную очередь для удобства работы с ней
        int temp_size = size_(); // 1
        N_op += 1;
        for (int i = temp_size - 1;i > temp_size - pos;i--){ // (temp_size - pos - 1) ~ n - pos - 1 ~ n
            temp.push_back(q.back()); // 1
            N_op += 1;
            // добавляю во временную очередь последний(первый) элемент основной очереди
            q.pop_back(); // 1
            N_op += 1;
            // удаляю последний(первый) элемент основной очереди
            N_op += 1;
        }
        temp.push_back(value); // 1
        N_op += 1;
        // добавляю новое значение на позицию, которую запросили
        temp_size = isz(temp); // 1
        N_op += 1;
        for (int i = 0;i < temp_size;i++){ // temp_size - 1 ~ n - 1 ~ n
            q.push_back(temp.back()); // 1
            N_op += 1;
             // берём последний(первый) элемент временной очереди и добавляем в основную
            temp.pop_back(); // 1
            N_op += 1;
            // удаляем последний(первый) элемент временной очереди
            N_op += 1;
        }
        reverse(all(q)); // (size / 2) свапов ~ n / 2
        N_op += size_() / 2;
        // разворачиваем очередь обратно, чтобы она стала в нормальном виде
    }
    void print_all_queue(){ // худший случай - n
        if (size_() == 0){ // 1
            N_op += 1;
            std::cout << "Очередь пустая!!!\n"; // 1
            return; // 1
        }
        for (int i : q){ //  n
            N_op += 1;
            std::cout << i << ' '; // 1
        }
        N_op += 1;
        std::cout << "\n"; // 1
    }
    void init_count_sort(int max_value){
        N_op += max_value;
        q_sorted.resize(max_value + 1); // ~ max_value
    }
    void uppdate_sort(int value){ // худший случай - n
        reverse(all(q_sorted)); // n / 2
        N_op += isz(q_sorted) / 2;
        vector <int> temp_q_sorted; // 1
        N_op += 1;
        int pos = isz(q_sorted) - value; // 1
        N_op += 1;
        while(isz(q_sorted) - 1 != pos){ // n
            temp_q_sorted.push_back(q_sorted.back()); // 1
            N_op += 1;
            q_sorted.pop_back(); // 1
            N_op += 1;
            N_op += 1;
        }
        int cur = q_sorted.back(); // 1
        N_op += 1;
        cur++; // 1
        N_op += 1;
        q_sorted.pop_back(); // 1
        N_op += 1;
        q_sorted.push_back(cur); // 1
        N_op += 1;
        while (isz(temp_q_sorted) > 0){ // - n
            q_sorted.push_back(temp_q_sorted.back()); // 1
            N_op += 1;
            temp_q_sorted.pop_back(); // 1
            N_op += 1;
            N_op += 1;
        }
        reverse(all(q_sorted)); // size / 2 свапов ~ n / 2
        N_op += isz(q_sorted) / 2;
    }
    void print_all_sorted_queue(){ // ~ n
        for (int i = 0;i < isz(q_sorted);i++){ // ~ n
            while(q_sorted[i] > 0){
                N_op += 1;
                std::cout << i + 1 << ' ';
                q_sorted[i]--;
            }
            N_op += 1;
        }
    }
    ~Queue(){ // n
        N_op += size_();
        q.clear(); // n
    }
};
int main(){
    long long time_left = GetTickCount();
    system("chcp 1251");
    Queue q; // 1
    N_op += 1;
    srand(2000); // 1
    N_op += 1;
    int n; // 1
    N_op += 1;
    std::cin >> n; // 1
    N_op += 1;
    for (int i = 0;i < n;i++){ // n
        int x = rand() % 100000;
        while(x == 0){
            x = rand() % 10;
        }
        q.push(x); // 1
        N_op += 1;
    }
    std::cout << "Не посорченная очередь:\n"; // 1
    N_op += 1;
    q.print_all_queue(); // n
    N_op += n;
    int maxs_element = q.get(1); // n
    N_op += n;
    for (int i = 0;i < q.size_();i++){ // n^2
        if (q.get(i + 1) > maxs_element){ // n
            maxs_element = q.get(i + 1); // n
            N_op += n;
        }
        N_op += 1;
    }
    q.init_count_sort(maxs_element); // max_element в худшем случае - 33001
    N_op += 33001;
    for (int i = 0;i < q.size_();i++){ // n
        q.uppdate_sort(q.get(i + 1)); // n^2
        N_op += 1;
        N_op += n;
    }
    std::cout << "Посорченная очередь:\n"; // 1
    N_op += 1;
    q.print_all_sorted_queue(); // n
    N_op += n;
    long long time_right = GetTickCount();
    N_op += 1;
    std::cout << "\n" << "time - " << (time_right - time_left) / 1000.;
    N_op += 1;
    std::cout << "\nN_op = " << N_op << "\n";
}
