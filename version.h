#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "03";
	static const char MONTH[] = "03";
	static const char YEAR[] = "2011";
	static const char UBUNTU_VERSION_STYLE[] = "11.03";
	
	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";
	
	//Standard Version Type
	static const int MAJOR = 1;
	static const int MINOR = 1;
	static const int BUILD = 1;
	static const int REVISION = 50;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 467;
	#define RC_FILEVERSION 1,1,0,47
	#define RC_FILEVERSION_STRING "1, 1, 0, 47\0"
	static const char FULLVERSION_STRING[] = "1.1.0.47";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 7;
	

}
#endif //VERSION_H
