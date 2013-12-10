#include <cassert>
#include <iostream>
#include <thread>
#include <rocksdb/db.h>
#include <rocksdb/statistics.h>

using namespace std;
using namespace rocksdb;

void put_test(DB* db, Options options) {
    const string value = "value";
    for (int i = 0; i < 100; i++) {
        db->Put(WriteOptions(), to_string(i), to_string(i*i));
    }
}

void print_result(DB* db) {
    const string key = "key";
    string value;
    for (int i = 0; i < 100; i++) {
        Status status = db->Get(ReadOptions(), to_string(i), &value);
        cout << value << endl;
    }
}

int main() {
    int thread_count = 1;
    DB* db;
    Options options;
    options.create_if_missing = true;
    options.statistics = CreateDBStatistics();
    Status status = DB::Open(options, "/tmp/rocks.db", &db);
    thread t1(put_test, db, options);
    t1.join();

    print_result(db);

    return 0;
}
