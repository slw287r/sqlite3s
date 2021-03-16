#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sqlite3.h>

static void error(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	vfprintf(stderr, format, ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

int is_sql3(const char *fn)
{
	int sql3 = 0;
	char line[17] = {0};
	FILE *fp = fopen(fn, "rb");
	if (!fp)
	{
		fprintf(stderr, "Error opening [%s]\n", fn);
		exit(1);
	}
	fread(line, sizeof(char), 16, fp);
	sql3 = (strncmp(line, "SQLite format 3", 16) == 0);
	fclose(fp);
	return sql3;
}

static int callback(void *data, int ncol, char **fields, char **cnames)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for (i = 0; i < ncol; ++i)
		printf("%s = %s\n", cnames[i], fields[i] ? fields[i] : "NULL");
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	sqlite3 *db;
	char *e = 0;
	int rc;
	char *sql0, *sql1, *sql2, *sql3, *sql4;
	const char *data = "Callback function called";
	rc = sqlite3_open("test.db", &db);
	if (rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		return 0;
	}
	else
		fprintf(stdout, "Opened database successfully\n");
	rc = sqlite3_key(db, "123456", 6);
	if (rc != SQLITE_OK) error("Error encrypt db\n");
	sql0 = "CREATE TABLE COMPANY (" \
		   "ID INT PRIMARY KEY NOT NULL," \
		   "NAME TEXT NOT NULL," \
		   "AGE INT NOT NULL," \
		   "ADDRESS CHAR(50)," \
		   "SALARY REAL );";
	sql1 = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
	sql2 = "SELECT * from COMPANY";
	sql3 = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
			"SELECT * from COMPANY";
	sql4 = "DELETE from COMPANY where ID=2; " \
			"SELECT * from COMPANY";
	rc = sqlite3_exec(db, sql0, callback, 0, &e);
	rc = sqlite3_exec(db, sql1, callback, 0, &e);
	rc = sqlite3_exec(db, sql2, callback, (void *)data, &e);
	//rc = sqlite3_exec(db, sql3, callback, (void *)data, &e);
	//rc = sqlite3_exec(db, sql4, callback, (void *)data, &e);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error: %s\n", e);
		sqlite3_free(e);
	}
	else
		fprintf(stdout, "Operation done successfully\n");
		//fprintf(stdout, "Record created successfully\n");
		//fprintf(stdout, "Table created successfully\n");
	sqlite3_close(db);
	return 0;
}
