#include "HowToReadText.h"
#include "SJDBuildCatalogCls.h"

HowToReadText::HowToReadText()
{

}

HowToReadText::~HowToReadText()
{

}

void PrintNode(TreeNode* node) {
	if (!!node)
	{
		std::cout << node->node.title << " + " << node->node.content << std::endl;
		for (auto first : node->children) // 遍历每个子级
		{
			// 输出第一章
			std::cout << "\t" << first->node.title << " + " << first->node.content << std::endl;
			for (auto second : first->children)
			{
				// 输出第二章
				std::cout << "\t\t" << second->node.title << " + " << second->node.content << std::endl;
				for (auto third : second->children)
				{
					// 输出第三章
					std::cout << "\t\t\t" << third->node.title << " + " << third->node.content << std::endl;
				}
			}
			std::cout << std::endl;
		}
	}
}

void HowToReadText::Run()
{
	std::vector<std::vector<std::string>> lst_date;
	lst_date.push_back({ "整机", "9","卷绕", "901","方形动力卷绕机", "90101","方形动力卷绕机" });
	lst_date.push_back({ "整机", "8","卷绕", "901","圆柱动力卷绕机", "90102","圆柱动力卷绕机" });
	lst_date.push_back({ "整机", "9","叠片", "902","折叠式热复合叠片机", "90201","折叠式热复合叠片机" });
	lst_date.push_back({ "整机", "8","叠片", "902","堆叠式热复合叠片机", "90202","堆叠式热复合叠片机" });
	lst_date.push_back({ "整机", "9","激光", "903","激光极耳成型机", "90301","激光极耳成型机" });
	lst_date.push_back({ "整机", "9","激光", "903","激光清洗机", "90302","激光清洗机" });
	lst_date.push_back({ "3D整机单元", "7","卷绕3D整机单元", "701","方形动力卷绕机3D整机单元", "70101","方形动力卷绕机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","卷绕3D整机单元", "701","圆柱动力卷绕机3D整机单元", "70102","圆柱动力卷绕机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","一体机3D整机单元", "706","激光切卷绕一体机3D整机单元", "70601","激光切卷绕一体机3D整机单元" });
	lst_date.push_back({ "3D整机单元", "7","一体机3D整机单元", "706","焊接卷绕一体机3D整机单元", "70602","焊接卷绕一体机3D整机单元" });
	lst_date.push_back({ "组件", "5","收放卷组件", "501", "50100","收放卷组件" });
	lst_date.push_back({ "组件", "5","机械手组件", "502", "50200","机械手组件" });
	lst_date.push_back({ "组件", "4","卷绕头组件", "503", "50300","卷绕头组件" });
	lst_date.push_back({ "组件", "4","张力组件", "504", "50400","张力组件" });

	SJDBuildCatalogCls* pClass = new SJDBuildCatalogCls();
	if (!!pClass)
	{
		Node node;
		std::vector<Node> path;
		path.reserve(5); // 初始化 capacity ，减少不必要的开辟空间
		for (auto data : lst_date)
		{
			// 插入第一章节
			path.clear(); // clear 只会清除数据，不会改变 capacity
			node.Set(data[0], data[1]);
			pClass->insertChapter(path, node); // path 保证了结构树路径的正确性，data[1]是第一章节 data[1]是第一章节的内容。内部设置了不重复添加章节

			// 插入第二章节
			path.push_back(node); //确定父节点
			node.Set(data[2], data[3]);
			pClass->insertChapter(path, node);

			// 插入第三章节
			path.push_back(node);
			node.Set(data[4], data[5]);
			pClass->insertChapter(path, node);
		}
	}
	
	// 显示
	std::cout << "================= 目录 =====================" << std::endl;
	if (!!pClass->root)
	{
		PrintNode(pClass->root);
	}

}

bool HowToReadText::Calculate()
{

	return true;
}
