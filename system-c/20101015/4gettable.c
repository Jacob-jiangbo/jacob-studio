#include<stdio.h> 
#include<stdlib.h> 
#include"sqlite3.h" 
#include<string.h> 

int main(int argc, char **argv) 
{ 
	sqlite3 *db; 
	char *zErr; 
	int rc,i; 
	char *sql; 
	char **result; 
	int nrows, ncols; 

	/* Connect to database, etc. */ 
	rc = sqlite3_open("test.db", &db); 
	sql = "select * from episodes;"; 
	rc = sqlite3_get_table(db, sql, &result, &nrows, &ncols, &zErr); 
	/* Do something with data */ 
	printf("rows=%d,cols=%d\n",nrows,ncols); 
	for (i=0;i<=nrows;i++) 
	printf("%-5s%-20s%-5s\n",result[3*i],result[3*i+1],result[3*i+2]); 
	/* Free memory */ 
	sqlite3_free_table(result); 
}

