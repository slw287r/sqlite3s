CC=gcc
PREFIX:=/usr/local
TARGET=lib/libsqlite3.a
TARGET_DIR = $(dir ${TARGET})
SOURCE=src/sqlite3secure.c
OBJECT=src/sqlite3secure.o
TEST=test/test
CFLAGS= -Isrc -Llib
LDFLAGS=-lpthread -ldl

$(TARGET): $(OBJECT)
	test -d $(TARGET_DIR) || mkdir -p $(TARGET_DIR)
	ar rs $@ $<

$(OBJECT): $(SOURCE)
	$(CC) -c -o $@ $< -DSQLITE_WITHOUT_ZONEMALLOC

install: $(TARGET)
	test -d $(PREFIX)/lib || mkdir -p $(PREFIX)/lib
	cp $(TARGET) $(PREFIX)/lib
	test -d $(PREFIX)/include || mkdir -p $(PREFIX)/include
	cp src/sqlite3.h src/sqlite3ext.h $(PREFIX)/include

test: test/test.c $(TARGET)
	$(CC) $(CFLAGS) -o test/test $^ $(LDFLAGS)
	cd $(dir ${TEST}) && ./test && cd ..

clean:
	rm -rf $(OBJECT) $(TARGET) $(test) $(dir ${TEST})test.db
