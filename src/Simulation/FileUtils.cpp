#include "FileUtils.h"
#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <stdlib.h>
#include <list>

using namespace std;

void FileUtils::fixTrailingSlash(string& pathStr){
	if (pathStr.back() != '/'){
		pathStr += '/';
	}
}

bool FileUtils::endsWith(const string & str, const string & suffix){
	if (suffix.size() > str.size()) return false;
	return equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}


vector<string> FileUtils::getSortedFileNamesListBySuffix(const string & path, const string & suffix){
	list<string> fileNamesList;
	vector<string> fileNamesVec;
	DIR * dir = opendir(path.c_str());
	if (dir == NULL){
		return fileNamesVec;
	}
	struct dirent *dp;
	while ((dp = readdir(dir)) != NULL){
		if (endsWith(string(dp->d_name), suffix)){
			fileNamesList.emplace_back(dp->d_name);
		}
	}
	closedir(dir);
	fileNamesList.sort();
	fileNamesVec.reserve(fileNamesList.size());
	fileNamesVec.insert(fileNamesVec.end(),fileNamesList.begin(),fileNamesList.end());
	return fileNamesVec;
}

string FileUtils::getFileNameFromPath(const std::string& filePath)
{
	int found = filePath.find_last_of("/");
	if (found < 0){
		return filePath;
	}
	return filePath.substr(found+1);
}

const string FileUtils::getFileNameNoExt(const std::string& filePath)
{
	string fileName = getFileNameFromPath(filePath);
	int found = fileName.find_last_of(".");
	if  (found < 0){
		return fileName;
	}
	return fileName.substr(0, found);
}

string FileUtils::getFullPath(const std::string& path){
	char *fullPath = realpath(path.c_str(), NULL);
	if (fullPath == NULL){
		return path;
	}
	string fullPathStr(fullPath);
	free(fullPath);
	return fullPathStr;
}

bool FileUtils::createDirectoryIfNotExists(const string& dirPath)
{
  string cmd = "mkdir -p " + dirPath;
  int ret = system(cmd.c_str());
  if (ret == -1)
  {
    return false;
  }
  return true;
}

bool FileUtils::removeDir(const string& dirPath)
{
  string cmd = "rm -rf " + dirPath;
  int ret = system(cmd.c_str());
  if (ret == -1)
  {
    return false;
  }
  return true;
}
