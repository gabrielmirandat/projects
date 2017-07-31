#!/usr/bin/python
import sys
import os.path

def main(filename):
    nameHpp = "./include/" + filename + ".hpp"
    nameCpp = "./src/" + filename + ".cpp"

###################################
# Checking and Creating Files
##################################
    if(os.path.exists(nameHpp)):
        print("ERROR! " + nameHpp + " already exists!")
        return
    elif (os.path.exists(nameCpp)):
        print("ERROR! " + nameCpp + " already exists!")
        return

    arqHpp = open(nameHpp, 'w')
    arqCpp = open(nameCpp, 'w')
    arqInclude = open("include/includeMapBehavior.hpp", 'w')
    arqCMake = open("CMakeLists.txt", 'w')
###################################
# Opening Templates
##################################
    tempHpp = open("./templates/tempBehaviorClass.hpp", 'r')
    tempHppString = tempHpp.read();
    tempCpp = open("./templates/tempBehaviorClass.cpp", 'r')
    tempCppString = tempCpp.read();
    tempInclude = open("./templates/tempincludeMapBehavior.hpp", 'r')
    tempIncludeString = tempInclude.read();
    tempCMake = open("./templates/tempCMakeLists.txt", 'r')
    tempCMakeString = tempCMake.read();

###################################
# Replacing and Filling Templates
##################################
    hppString = tempHppString.replace("tempBehaviorClass",filename)
    cppString = tempCppString.replace("tempBehaviorClass",filename)

###################################
# Saving files
##################################
    arqHpp.write(hppString)
    arqHpp.close()
    arqCpp.write(cppString)
    arqCpp.close()

#########################################
# Updating includeMapBehavior and CMake
########################################

    listIncludes = []
    for file in os.listdir("./include"):
        if file != "includeMapBehavior.hpp":
            listIncludes.append("#include <" + file + ">")

    includeString = tempIncludeString.replace("++tempincludeMapBehavior++", ("\n".join(listIncludes)))

    listCMake = []
    for file in os.listdir("./src"):
        listCMake.append("  \"src/" + file + "\"")

    CMakeString = tempCMakeString.replace("++tempCMakeLists++",("\n".join(listCMake)))

###################################
# Saving files
##################################
    arqInclude.write(includeString)
    arqInclude.close()
    arqCMake.write(CMakeString)
    arqCMake.close()

if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1])
    else:
        print("Error! Usage: " + sys.argv[0] + " className")
