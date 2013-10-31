#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{

	//Date Version Types
	static const char DATE[] = "01";
	static const char MONTH[] = "11";
	static const char YEAR[] = "2013";
	static const char UBUNTU_VERSION_STYLE[] = "13.11";

	//Software Status
	static const char STATUS[] = "Release";
	static const char STATUS_SHORT[] = "r";

	//Standard Version Type
	static const int MAJOR = 1;
	static const int MINOR = 2;
	static const int BUILD = 1;
	static const int REVISION = 60;

	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 468;
	#define RC_FILEVERSION 1,1,2,51
	#define RC_FILEVERSION_STRING "1, 1, 2, 52\0"
	static const char FULLVERSION_STRING[] = "1.2.1.60";

	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 8;
}
#endif //VERSION_H
