#include "SJDBuildCatalogCls.h"

bool SJDBuildCatalogCls::insertChapter(const std::vector<Node>& path, const Node& iToInsert) {
	TreeNode* node = root;
	for (auto item : path) {
		TreeNode* child = node->getChild(item);
		if (!child) {
			return false;
		}
		node = child;
	}
	if (node->getChild(iToInsert)) {
		return false; // Node already exists
	}

	node->addChild(new TreeNode(iToInsert.title, iToInsert.content));
	return true;
}

TreeNode* SJDBuildCatalogCls::getChapter(const std::vector<Node>& path) const {
	TreeNode* node = root;
	for (auto item : path) {
		node = node->getChild(item);
		if (!node) {
			return nullptr;
		}
	}
	return node;
}
