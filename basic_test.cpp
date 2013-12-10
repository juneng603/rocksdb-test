#include <cassert>
#include <rocksdb/db.h>
#include <rocksdb/statistics.h>

int main() {
    rocksdb::DB* db;
    rocksdb::Options options;
    options.create_if_missing = true;
    options.statistics = rocksdb::CreateDBStatistics();
    rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/rocks.db", &db);
    assert(status.ok());
    return 0;
}
