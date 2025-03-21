def build_postorder(inorder, preorder):
    # postorder traversal from inorder and preorder
    index_map = {value: i for i, value in enumerate(inorder)}

    def construct(in_left, in_right):
        if in_left > in_right:
            return []
        
        root = preorder.pop(0)  # First element of preorder is root
        root_index = index_map[root]
        
        # Recursively construct left and right subtrees
        left_subtree = construct(in_left, root_index - 1)
        right_subtree = construct(root_index + 1, in_right)
        
        # Postorder = left + right + root
        return left_subtree + right_subtree + [root]
    
    return construct(0, len(inorder) - 1)

# Read input
N = int(input())
inorder = list(map(int, input().split()))
preorder = list(map(int, input().split()))

# Get the postorder traversal and print it
postorder = build_postorder(inorder, preorder)
print(*postorder)
