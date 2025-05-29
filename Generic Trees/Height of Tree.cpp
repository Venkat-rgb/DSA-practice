int maxDepth(Node* root) {
        if(root == NULL) return 0;

        int height = 0;

        for(int i = 0; i < root -> children.size(); ++i) {
            height = max(height, maxDepth(root -> children[i]));
        }

        return height + 1;
    }