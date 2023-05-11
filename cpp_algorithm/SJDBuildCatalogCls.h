#pragma once

#include <iostream>
#include <string>
#include <vector>

// TODO: 
// 1.添加获取父级节点
// 2.目前访问某一个节点，需要全路径，待优化
// 3.

struct Node
{
	std::string title;
	std::string content;
	Node(const std::string& ititle, const std::string& icontent) : title(ititle), content(icontent) {}
	Node() : title(""), content("") {}
	inline void Set(const std::string& ititle, const std::string& icontent) {
		title = ititle;
		content = icontent;
	}
};

class TreeNode {
public:

	Node node;
	std::vector<TreeNode*> children;

	TreeNode(const std::string& ititle, const std::string& icontent = "") : node(ititle,icontent){}

	~TreeNode() {
		for (auto child : children) {
			delete child;
		}
	}

	void addChild(TreeNode* child) {
		children.push_back(child);
	}

	TreeNode* getChild(const Node& inode) const {
		for (auto child : children) {
			if (child->node.title == inode.title && child->node.content == inode.content) {
				return child;
			}
		}
		return nullptr;
	}
};

class SJDBuildCatalogCls {
public:
	TreeNode* root;

	SJDBuildCatalogCls() : root(new TreeNode("Root")) {}

	~SJDBuildCatalogCls() {
		delete root;
	}

	bool insertChapter(const std::vector<Node>& path, const Node& node);

	TreeNode* getChapter(const std::vector<Node>& path) const;

};