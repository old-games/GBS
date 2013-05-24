#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "24";
	static const char MONTH[] = "05";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.05";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const int MAJOR = 1;
	static const int MINOR = 1;
	static const int BUILD = 2;
	static const int REVISION = 51;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 468;
	#define RC_FILEVERSION 1,1,2,51
	#define RC_FILEVERSION_STRING "1, 1, 2, 51\0"
	static const char FULLVERSION_STRING[] = "1.1.2.51";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 8;
}
#endif //VERSION_H
