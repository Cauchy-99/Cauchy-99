#include "ZWReadTreeDataCls.h"

#include <iostream>

ZWReadTreeDataCls::ZWReadTreeDataCls()
{
	m_Data.reserve(50);
}

ZWReadTreeDataCls::~ZWReadTreeDataCls()
{

}

void ZWReadTreeDataCls::init()
{

}

bool ZWReadTreeDataCls::ReadData()
{
	// 拆分数据，每一行按都好拆分数据
	std::vector<std::vector<std::string>> lst_date;
	lst_date.push_back({ "整机", "9","卷绕", "901","方形动力卷绕机", "90101","方形动力卷绕机" });
	lst_date.push_back({ "整机", "9","卷绕", "901","圆柱动力卷绕机", "90102","圆柱动力卷绕机" });
	lst_date.push_back({ "整机", "9","叠片", "902","折叠式热复合叠片机", "90201","折叠式热复合叠片机" });
	lst_date.push_back({ "整机", "9","叠片", "902","堆叠式热复合叠片机", "90202","堆叠式热复合叠片机" });
	lst_date.push_back({ "整机", "9","激光", "903","激光极耳成型机", "90301","激光极耳成型机" });
	lst_date.push_back({ "整机", "9","激光", "903","激光清洗机", "90302","激光清洗机" });
	lst_date.push_back({ "3D整机单元", "7","卷绕3D整机单元", "701","方形动力卷绕机3D整机单元", "70101","方形动力卷绕机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","卷绕3D整机单元", "701","圆柱动力卷绕机3D整机单元", "70102","圆柱动力卷绕机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","一体机3D整机单元", "706","激光切卷绕一体机3D整机单元", "70601","激光切卷绕一体机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","一体机3D整机单元", "706","焊接卷绕一体机3D整机单元", "70602","焊接卷绕一体机3D整机单元" });
	lst_date.push_back({ "组件", "5","收放卷组件", "501", "50100","收放卷组件" });
	lst_date.push_back({ "组件", "5","机械手组件", "502", "50200","机械手组件" });
	lst_date.push_back({ "组件", "5","卷绕头组件", "503", "50300","卷绕头组件" });
	lst_date.push_back({ "组件", "5","张力组件", "504", "50400","张力组件" });

	for (auto it = lst_date.begin(); it != lst_date.end(); it++)
	{
		m_chapter1.insert(std::make_pair((*it)[0], (*it)[2])); // 将第0个数据和第3个数据保存在章节1中
		m_chapter2.insert(std::make_pair((*it)[2], (*it)[4])); // 将第3个数据和第5个数据保存在章节2中
	}

	//展示章节1数据
	while (true) {
		int a;
		std::cout << "需要读取的章节：输入 1 2" << std::endl;
		std::cin >> a;
		if (a==1)
		{
			std::string test;
			std::cout << "输入章节名：" << std::endl;
			std::cin >> test;
			std::cout << "There are " << m_chapter1.count(test) << " elements with key " << test << ":";
			for (auto it1 = m_chapter1.equal_range(test).first; it1 != m_chapter1.equal_range(test).second; ++it1)
				std::cout << ' ' << (*it1).second;
			std::cout << '\n';
		}else if (a==2)
		{
			std::string test;
			std::cout << "输入章节名：" << std::endl;
			std::cin >> test;
			std::cout << "There are " << m_chapter2.count(test) << " elements with key " << test << ":";
			for (auto it1 = m_chapter2.equal_range(test).first; it1 != m_chapter2.equal_range(test).second; ++it1)
				std::cout << ' ' << (*it1).second;
			std::cout << '\n';
		}
		else {
			std::cout << "无效章节" << std::endl;
			continue;
		}

		char b;
		std::cout << "Esc: 退出，其他: 继续" << std::endl;
		std::cin >> b;
		if (b==27)
		{
			break;
		}

	}
	return true;
}
