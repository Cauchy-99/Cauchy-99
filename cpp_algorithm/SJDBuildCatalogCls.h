#pragma once

#include <iostream>
#include <string>
#include <vector>

// TODO: 
// 1.添加获取父级节点
// 2.目前访问某一个节点，需要全路径，待优化
// 3.
class TreeNode {
public:
	std::string title;
	std::string content;
	std::vector<TreeNode*> children;

	TreeNode(const std::string& ititle, const std::string& icontent = "") : title(ititle), content(icontent) {}

	~TreeNode() {
		for (auto child : children) {
			delete child;
		}
	}

	void addChild(TreeNode* child) {
		children.push_back(child);
	}

	TreeNode* getChild(const std::string& title) const {
		for (auto child : children) {
			if (child->title == title) {
				return child;
			}
		}
		return nullptr;
	}

	void setContent(const std::string& content) {
		this->content = content;
	}

	std::string getContent() const {
		return content;
	}
};
class SJDBuildCatalogCls {
public:
	TreeNode* root;

	SJDBuildCatalogCls() : root(new TreeNode("Root")) {}

	~SJDBuildCatalogCls() {
		delete root;
	}

	bool insertChapter(const std::vector<std::string>& path, const std::string& title, const std::string& content = "");

	TreeNode* getChapter(const std::vector<std::string>& path) const;
};