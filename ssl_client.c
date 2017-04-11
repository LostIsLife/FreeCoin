/* OpenSSL headers */
 
#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
 

bool get_args(int argc, char** argv)
{
	char basic_error[40] = "Arguments given were not as expected: ",
			 usage[45] = "Usage: program hostname port verbose(0: No)";
	if (argc > 3 || argc < 1)
	{
		printf("%s Received either too many arguments or too little. %s\n",basic_error, usage);
		exit(1);
	}

	//Verify hostname

	//Verify Port, if none given, choose one

	//Verify verbose
	return !( atoi(argv[2]) == 0);
}


//--------------------------- 
//--------------------------- 
//--------------------------- 
//--------------------------- 

int main(int argc, char** argv)
{	
	bool verbose = get_args(argc, argv);

	SSL_load_error_strings();
	ERR_load_BIO_strings();
	OpenSSL_add_all_algorithms();

	BIO* bio;

	bio = BIO_new_connect( "127.0.0.1:20001");
	
	//Handle an error here
	if (bio == NULL || BIO_do_connect(bio) <= 0)
	{
		printf("An error has occured while creating the connection\n");
	}


	BIO_free_all(bio);

	return 0;
}
