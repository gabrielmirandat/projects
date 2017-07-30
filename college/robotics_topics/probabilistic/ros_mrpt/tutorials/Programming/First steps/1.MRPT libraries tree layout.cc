Para cada módulo mrpt-<name>

MRPT
	libs: C++ libraries
		name
			src
				precomp_hdr.cpp (This file must only contain a: #include <mrpt/name.h> )
				registerAllClasses.cpp (optional: used to register all CSerializable objects so they can be de-serialized without knowing their type in advance)
				(the rest of source files)
			include
				mrpt
					name
						link_pragmas.h
						(the rest of include files)
					name.h (this will be the precompiled header: #include <mrpt/name.h> )
				CMakeLists.txt

				