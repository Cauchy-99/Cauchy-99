#pragma once
#include <vector>
#include <string>
#include <map>
// 解析树状的数据
typedef std::multimap<std::string, std::string> Chapter;
class ZWReadTreeDataCls
{
public:
	ZWReadTreeDataCls();
	~ZWReadTreeDataCls();
public:
	//************************************
	// Method:    init 用于初始化数据，读取txt文本文件
	// FullName:  ZWReadTreeDataCls::init
	// Access:    public 
	// Returns:   void
	// Qualifier:
	//************************************
	void init();

	//************************************
	// Method:    ReadData 用于解析数据
	// FullName:  ZWReadTreeDataCls::ReadData
	// Access:    public 
	// Returns:   bool
	// Qualifier:
	//************************************
	bool ReadData();

	std::vector<std::string> m_Data; //保存了所有的数据
	Chapter m_chapter1;
	Chapter m_chapter2;
};