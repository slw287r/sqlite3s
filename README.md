# sqlite3s
sqlite3 lib with secure support for old computers.

---

For brandnew computers please try the latest solution provided by wxSQLite3:

Updates on Nov 2024:

* Download SQLite 3.47 from [source](https://www.sqlite.org/2024/sqlite-autoconf-3470000.tar.gz)
```
curl https://www.sqlite.org/2024/sqlite-autoconf-3470000.tar.gz > sqlite-autoconf-3470000.tar.gz
tar -xf sqlite-autoconf-3470000.tar.gz
```

* Download wxSQLite3 (based on SQLite 3.35.0)
```
curl https://github.com/utelle/wxsqlite3/archive/refs/tags/v4.9.12.tar.gz > wxsqlite3-4.9.12.tar.gz
tar -xf wxsqlite3-4.9.12.tar.gz
```

* Replace sqlite3 with wxSQLite3 and install

```
cp wxsqlite3-4.9.12/src/sqlite3mc_amalgamation.c sqlite-autoconf-3470000/sqlite3.c
cp wxsqlite3-4.9.12/src/sqlite3mc_amalgamation.h sqlite-autoconf-3470000/sqlite3.h 
cd sqlite-autoconf-3470000
```

## For arm64 macOS (M1-M4), update the following flags
```
LDFLAGS = -L/usr/local/lib -framework Security -framework Foundation
./configure && make && make install
```


> * Download SQLite 3.35 from [source](https://www.sqlite.org/2021/sqlite-autoconf-3350100.tar.gz)
> ```
> wget https://www.sqlite.org/2021/sqlite-autoconf-3350100.tar.gz
> tar -xf sqlite-autoconf-3350100.tar.gz 
> ```
> 
> * Download wxSQLite3 (based on SQLite 3.35.0)
> ```
> wget https://github.com/utelle/wxsqlite3/archive/v4.6.5.tar.gz
> tar -xf v4.6.5.tar.gz
> ```
> 
> * Replace sqlite3 with wxSQLite3 and install
> 
> ```
> cp wxsqlite3-4.6.5/src/sqlite3mc_amalgamation.c sqlite-autoconf-3350100/sqlite3.c
> cp wxsqlite3-4.6.5/src/sqlite3mc_amalgamation.h sqlite-autoconf-3350100/sqlite3.h 
> cd sqlite-autoconf-3350100
> ./configure && make && make install
> ```


## Reference

[sqlite3-secure](https://github.com/luweimy/sqlite3-secure.git)
