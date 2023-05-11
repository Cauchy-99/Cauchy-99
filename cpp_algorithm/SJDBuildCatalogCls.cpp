#include "SJDBuildCatalogCls.h"

bool SJDBuildCatalogCls::insertChapter(const std::vector<std::string>& path, const std::string& title, const std::string& content) {
	TreeNode* node = root;
	for (auto name : path) {
		TreeNode* child = node->getChild(name);
		if (!child) {
			child = new TreeNode(name);
			node->addChild(child);
		}
		node = child;
	}
	if (node->getChild(title)) {
		return false; // Node already exists
	}

	node->addChild(new TreeNode(title,content));
	return true;
}

TreeNode* SJDBuildCatalogCls::getChapter(const std::vector<std::string>& path) const {
	TreeNode* node = root;
	for (auto name : path) {
		node = node->getChild(name);
		if (!node) {
			return nullptr;
		}
	}
	return node;
}
