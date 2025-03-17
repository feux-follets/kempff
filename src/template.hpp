#pragma once

import fmt;

struct Node {
	Node(int value) : value(value) {}

	int value {0};
	Node* left {nullptr};
	Node* right {nullptr};
};

template <typename T, typename... TP>
void traverse(T np, TP... paths) {
	if (!np) {
		return;
	}
	fmt::print("{}\n", np->value);
	(traverse(np->*paths, paths), ...);
}
