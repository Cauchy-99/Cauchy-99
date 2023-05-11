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
		std::cout << node->title << std::endl;
		for (auto child : node->children) // ����ÿ���Ӽ�
		{
			PrintNode(child);
		}
	}
}

void HowToReadText::Run()
{
	std::vector<std::vector<std::string>> lst_date;
	lst_date.push_back({ "����", "9","����", "901","���ζ������ƻ�", "90101","���ζ������ƻ�" });
	lst_date.push_back({ "����", "9","����", "901","Բ���������ƻ�", "90102","Բ���������ƻ�" });
	lst_date.push_back({ "����", "9","��Ƭ", "902","�۵�ʽ�ȸ��ϵ�Ƭ��", "90201","�۵�ʽ�ȸ��ϵ�Ƭ��" });
	lst_date.push_back({ "����", "9","��Ƭ", "902","�ѵ�ʽ�ȸ��ϵ�Ƭ��", "90202","�ѵ�ʽ�ȸ��ϵ�Ƭ��" });
	lst_date.push_back({ "����", "9","����", "903","���⼫�����ͻ�", "90301","���⼫�����ͻ�" });
	lst_date.push_back({ "����", "9","����", "903","������ϴ��", "90302","������ϴ��" });
	lst_date.push_back({ "3D������Ԫ", "7","����3D������Ԫ", "701","���ζ������ƻ�3D������Ԫ", "70101","���ζ������ƻ�3D������Ԫ" });
	lst_date.push_back({ "3D������Ԫ", "7","����3D������Ԫ", "701","Բ���������ƻ�3D������Ԫ", "70102","Բ���������ƻ�3D������Ԫ" });
	lst_date.push_back({ "3D������Ԫ", "7","һ���3D������Ԫ", "706","�����о���һ���3D������Ԫ", "70601","�����о���һ���3D������Ԫ" });
	lst_date.push_back({ "3D������Ԫ", "7","һ���3D������Ԫ", "706","���Ӿ���һ���3D������Ԫ", "70602","���Ӿ���һ���3D������Ԫ" });
	lst_date.push_back({ "���", "5","�շž����", "501", "50100","�շž����" });
	lst_date.push_back({ "���", "5","��е�����", "502", "50200","��е�����" });
	lst_date.push_back({ "���", "5","����ͷ���", "503", "50300","����ͷ���" });
	lst_date.push_back({ "���", "5","�������", "504", "50400","�������" });

	SJDBuildCatalogCls* pClass = new SJDBuildCatalogCls();
	if (!!pClass)
	{
		std::vector<std::string> path;
		path.reserve(5); // ��ʼ�� capacity �����ٲ���Ҫ�Ŀ��ٿռ�
		for (auto data : lst_date)
		{
			// �����һ�½�
			path.clear(); // clear ֻ��������ݣ�����ı� capacity
			pClass->insertChapter(path, data[0], data[1]); // path ��֤�˽ṹ��·������ȷ�ԣ�data[1]�ǵ�һ�½� data[1]�ǵ�һ�½ڵ����ݡ��ڲ������˲��ظ�����½�

			// ����ڶ��½�
			path.push_back(data[0]); //ȷ�����ڵ�
			pClass->insertChapter(path, data[2], data[3]);

			// ��������½�
			path.push_back(data[2]);
			pClass->insertChapter(path, data[4], data[5]);
		}
	}
	
	// ��ʾ
	std::cout << "================= Ŀ¼ =====================" << std::endl;
	if (!!pClass->root)
	{
		PrintNode(pClass->root);
	}

}

bool HowToReadText::Calculate()
{

	return true;
}
