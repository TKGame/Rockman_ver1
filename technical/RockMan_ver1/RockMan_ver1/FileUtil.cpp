#include "FileUtil.h"

CFileUtil* CFileUtil::instance = NULL;

CFileUtil::CFileUtil()
{

}
CFileUtil* CFileUtil::GetInstance()
{
	if (instance == NULL)
	{
		instance = new CFileUtil();
		return instance;
	}
	else
		return instance;
}
std::vector<std::string> CFileUtil::LoadFromFile(const std::string& filePath)
{
	ifstream* reader = new ifstream(filePath);
	std::string item;
	std::vector<std::string> result;
	if (reader->is_open())
	{
		while (!reader->eof())
		{
			getline(*reader, item);  //lay dong trong file -> chuoi string
			result.push_back(item);
		}
		reader->close();
	}
	return result;
}
//std::hash_map<int, std::string> CFileUtil::LoadFromFile(const std::string& filePath)
//{
//	hash_map<int, std::string> hashMap;
//	if(filePath.length() > 0)
//	{
//
//	}
//	return hashMap;
//}

std::vector<std::string> CFileUtil::Split(const std::string& value, char delim)
{
	std::vector<std::string> result;
	if (value.length() > 0) //Neu gia tri truyen vao khac null thi tien hanh cat
	{
		std::stringstream  values(value);
		std::string item;
		while (std::getline(values, item, delim))
		{
			if (item.length() > 0)
			{
				result.push_back(item);
			}
		}
	}
	return result;
}

CFileUtil::~CFileUtil()
{

}