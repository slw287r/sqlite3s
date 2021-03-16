# sqlite3s
sqlite3 lib with secure support for old computers.

---

For brandnew computers please try the latest solution provided by wxSQLite3:

* Download SQLite 3.35 from [source](https://www.sqlite.org/2021/sqlite-autoconf-3350100.tar.gz)
```
wget https://www.sqlite.org/2021/sqlite-autoconf-3350100.tar.gz
tar -xf sqlite-autoconf-3350100.tar.gz 
```

* Download wxSQLite3 (based on SQLite 3.35.0)
```
wget https://github.com/utelle/wxsqlite3/archive/v4.6.5.tar.gz
tar -xf v4.6.5.tar.gz
```

* Replace sqlite3 with wxSQLite3 and install

```
cp v4.6.5/src/sqlite3mc_amalgamation.c sqlite-autoconf-3350100/sqlite3.c
cp v4.6.5/src/sqlite3mc_amalgamation.h sqlite-autoconf-3350100/sqlite3.h
cd sqlite-autoconf-3350100
./configure && make && make install
```

## Reference

[sqlite3-secure](https://github.com/luweimy/sqlite3-secure.git)
